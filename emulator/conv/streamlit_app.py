import numpy as np
import pandas as pd
import streamlit as st
import matplotlib.pyplot as plt
import matplotlib.colors as mcolors

from im2col import SYSTOLIC_ARRAY_SIZE, SimConfig, ImplicitIm2colSystolicSim, direct_conv_hwc
from psum_router import simulate_with_routing

# Stable color per output channel index for psum bar and writeback table
def _channel_color(c, cmap_name="tab10"):
    cmap = plt.get_cmap(cmap_name)
    return mcolors.to_hex(cmap(c % 10 if cmap_name == "tab10" else (c % 20) / 20))


def _array_to_df(arr):
    return pd.DataFrame(arr)


def _list_to_df(rows, columns=None):
    return pd.DataFrame(rows, columns=columns)


def _draw_systolic_grid(weight_pad, input_row, psum_row, array_size, n_rows, n_batch, n_start, cols_label, step_label=""):
    """Weight tile; input row colored by flattened index; psum row colored by output channel/batch index."""
    fig, axes = plt.subplots(1, 3, figsize=(14, 4.5))
    w = np.array(weight_pad, dtype=float).reshape(array_size, array_size)
    valid = np.isfinite(w)
    vmin_w = np.nanmin(w) if np.any(valid) else 0
    vmax_w = np.nanmax(w) if np.any(valid) else 1
    im0 = axes[0].imshow(w, cmap="viridis", vmin=vmin_w, vmax=vmax_w)
    axes[0].set_title("1. Weight tile (PE array)")
    axes[0].set_xlabel(f"cols = {cols_label}")
    axes[0].set_ylabel("rows = kernel dims (r,s,c)")
    axes[0].set_aspect("equal")
    plt.colorbar(im0, ax=axes[0], label="weight value")

    # Input row: color by flattened kernel index (0 .. n_rows-1); gray = idle
    input_idx = np.full((1, array_size), -1, dtype=float)
    for j in range(min(n_rows, array_size)):
        input_idx[0, j] = j
    # Use a high-contrast discrete colormap (one distinct hue per index)
    if n_rows > 0:
        colors = [plt.cm.hsv(i / max(1, n_rows)) for i in range(n_rows)]
        cmap_in = mcolors.ListedColormap(colors)
    else:
        cmap_in = plt.get_cmap("Greys")
    cmap_in.set_bad(color="lightgray")
    im1 = axes[1].imshow(
        np.ma.masked_where(input_idx < 0, input_idx),
        cmap=cmap_in,
        vmin=-0.5,
        vmax=max(0.5, n_rows - 0.5),
    )
    axes[1].set_title("2. Input row (color = flattened index)")
    axes[1].set_xlabel("kernel dim index (r,s,c) order")
    axes[1].set_ylabel("single row")
    axes[1].set_aspect("equal")
    cbar1 = plt.colorbar(im1, ax=axes[1], label="flattened index")
    if n_rows <= 20 and n_rows > 0:
        cbar1.set_ticks(list(range(n_rows)))

    # Psum row: color by output channel index (same palette as writeback table: tab10 modulo)
    psum_color_idx = np.full((1, array_size), -1, dtype=float)
    for j in range(min(n_batch, array_size)):
        psum_color_idx[0, j] = (n_start + j) % 10
    cmap_out = plt.get_cmap("tab10").copy()
    cmap_out.set_bad(color="lightgray")
    im2 = axes[2].imshow(np.ma.masked_where(psum_color_idx < 0, psum_color_idx), cmap=cmap_out, vmin=0, vmax=9)
    axes[2].set_title("3. Partial sums (color = C_out index)")
    axes[2].set_xlabel("output channel index")
    axes[2].set_ylabel("single row")
    axes[2].set_aspect("equal")
    cbar2 = plt.colorbar(im2, ax=axes[2], label="C_out index (mod 10)")
    cbar2.set_ticks(range(10))
    cbar2.set_ticklabels([str(i) for i in range(10)])

    if step_label:
        fig.suptitle(step_label)
    plt.tight_layout()
    return fig


st.set_page_config(page_title="Implicit Im2col Systolic Sim", layout="wide")

with st.sidebar:
    st.header("Config")
    N = st.number_input("N (batch)", min_value=1, value=1, step=1)
    H = st.number_input("H", min_value=1, value=8, step=1)
    W = st.number_input("W", min_value=1, value=8, step=1)
    C = st.number_input("C (Cin)", min_value=1, value=3, step=1)
    K = st.number_input("K (Cout)", min_value=1, value=2, step=1)
    R = st.number_input("R (kernel height)", min_value=1, value=3, step=1)
    S = st.number_input("S (kernel width)", min_value=1, value=3, step=1)
    mapping_choice = st.selectbox(
        "Mapping",
        ["k_rows_n_cols", "batch_parallel"],
        format_func=lambda x: "K-rows / C_out-cols (inference)" if x == "k_rows_n_cols" else "Batch-parallel (cols=N)",
        index=0,
    )
    st.caption(f"Systolic array: {SYSTOLIC_ARRAY_SIZE}×{SYSTOLIC_ARRAY_SIZE} (fixed).")
    stride = st.number_input("Stride", min_value=1, value=1, step=1)
    pad = st.number_input("Pad", min_value=0, value=0, step=1)
    seed = st.number_input("Seed", min_value=0, value=0, step=1)
    use_sequential_init = st.checkbox("Sequential init (0,1,2,… for IFMap/weights; else random)", value=True)
    max_logs = st.number_input("Max iterations to log", min_value=0, value=32, step=1)

    run = st.button("Run simulation", type="primary")


# Avoid sending huge data to browser (Streamlit message size limit ~200 MB)
MAX_UNFOLDED_ELEMENTS = 500_000  # ~4 MB; larger runs skip storing unfolded

if run:
    cfg = SimConfig(
        N=int(N),
        H=int(H),
        W=int(W),
        C=int(C),
        K=int(K),
        R=int(R),
        S=int(S),
        stride=int(stride),
        pad=int(pad),
        seed=int(seed),
        use_sequential_init=use_sequential_init,
    )
    sim = ImplicitIm2colSystolicSim(cfg)
    Ho = (cfg.H + 2 * cfg.pad - cfg.R) // cfg.stride + 1
    Wo = (cfg.W + 2 * cfg.pad - cfg.S) // cfg.stride + 1
    M, K_flat = cfg.N * Ho * Wo, cfg.R * cfg.S * cfg.C
    if M * K_flat <= MAX_UNFOLDED_ELEMENTS:
        unfolded = sim.explicit_im2col_channel_first()
    else:
        unfolded = None  # too large; Unfolded tab will show message
    ref = direct_conv_hwc(sim.ifmap, sim.weights, stride=cfg.stride, pad=cfg.pad)
    ofmap, logs, util_stats = sim.simulate(trace=True, max_logs=int(max_logs), mapping=mapping_choice)
    diff = float(np.max(np.abs(ref - ofmap)))

    # PSUM routing & timing (K-rows only for now)
    routing_result = None
    if mapping_choice == "k_rows_n_cols":
        sim_routed = ImplicitIm2colSystolicSim(cfg)
        routing_result = simulate_with_routing(sim_routed)

    st.session_state["sim"] = sim
    st.session_state["unfolded"] = unfolded
    st.session_state["ofmap"] = ofmap
    st.session_state["logs"] = logs
    st.session_state["ref"] = ref
    st.session_state["diff"] = diff
    st.session_state["util_stats"] = util_stats
    st.session_state["mapping"] = mapping_choice
    st.session_state["routing_result"] = routing_result


if "sim" in st.session_state:
    sim = st.session_state["sim"]
    unfolded = st.session_state["unfolded"]
    ofmap = st.session_state["ofmap"]
    logs = st.session_state["logs"]
    ref = st.session_state["ref"]
    diff = st.session_state["diff"]
    util_stats = st.session_state.get("util_stats", {})
    sz = SYSTOLIC_ARRAY_SIZE

    tab_names = ["IFMap", "Weights", "Unfolded", "Utilization", "Systolic array", "Iteration", "PSUM Routing", "Output"]
    tabs = st.tabs(tab_names)
    routing_result = st.session_state.get("routing_result")

    with tabs[0]:
        st.subheader("IFMap (HWC)")
        n_idx = st.number_input("Batch index", min_value=0, max_value=sim.cfg.N - 1, value=0, step=1, key="n_idx")
        c_idx = st.number_input("Channel index", min_value=0, max_value=sim.cfg.C - 1, value=0, step=1, key="c_idx")
        st.write(f"IFMap[n={n_idx}, :, :, c={c_idx}]")
        st.dataframe(_array_to_df(sim.ifmap[int(n_idx), :, :, int(c_idx)]))

    with tabs[1]:
        st.subheader("Weights (R,S,C,K)")
        r_idx = st.number_input("r index", min_value=0, max_value=sim.cfg.R - 1, value=0, step=1, key="r_idx")
        s_idx = st.number_input("s index", min_value=0, max_value=sim.cfg.S - 1, value=0, step=1, key="s_idx")
        st.write(f"Weights[r={r_idx}, s={s_idx}] (C x K)")
        st.dataframe(_array_to_df(sim.weights[int(r_idx), int(s_idx), :, :]))

    with tabs[2]:
        st.subheader("Unfolded IFMap (channel-first order)")
        if unfolded is not None:
            st.dataframe(_array_to_df(unfolded))
        else:
            st.warning("Unfolded matrix too large to display (would exceed browser message limit). Reduce H×W×C or view Utilization / run sweep_utilization.py for metrics.")

    with tabs[3]:
        st.subheader("Utilization")
        if util_stats:
            mapping_name = util_stats.get("mapping", "")
            st.caption(f"Mapping: {'K-rows / C_out-cols' if mapping_name == 'k_rows_n_cols' else 'Batch-parallel'}")
            st.metric("PE utilization", f"{util_stats.get('utilization', 0):.2%}")
            st.write("Total PE cycles (active):", util_stats.get("total_pe_cycles", 0))
            st.write("Total possible PE cycles:", util_stats.get("total_possible_pe_cycles", 0))
        else:
            st.info("Run simulation for utilization metrics.")

    with tabs[4]:
        st.subheader("Systolic array (movement & psum writeback)")
        with st.expander("How to interpret the systolic array", expanded=True):
            st.markdown("""
            **Dataflow (K-rows / C_out-cols):** Weights are loaded into the PE array: **rows** = kernel dimensions (r,s,c), **columns** = output channels. Each **step** processes one (K-tile, N-tile) and one output position (oh,ow). For that position we stream one **input row** (the receptive field, length K) and get one **partial-sum row** (length N_tile).

            - **1. Weight tile:** 32×32 PE grid. Filled region = current weight block (rows = kernel dims in this tile, cols = output channels in this tile). Empty (gray) = idle PEs. Values = weight coefficients (colorbar = scale).
            - **2. Input row:** One row of the (M,K) matrix = **receptive field** for this (oh,ow). **Color = flattened kernel index** (0, 1, … in (r,s,c) order) so you can see which kernel dim each cell is; gray = idle.
            - **3. Partial sums:** Result of (input_row @ weight_tile). **Color = output channel index** (C_out); matches the writeback table below. Gray = idle.
            """)
        if not logs:
            st.info("No logs. Increase 'Max iterations to log' and run.")
        elif logs and isinstance(logs[0], dict) and "weight_block" in logs[0]:
            num_steps = len(logs)
            if num_steps > 1:
                step_idx = st.slider("Step", 0, num_steps - 1, 0, key="step_idx")
            else:
                step_idx = 0
                if num_steps == 1:
                    st.caption("1 step logged (use slider when more steps are available).")
            entry = logs[int(step_idx)]
            n_rows, n_batch = entry["n_rows"], entry["n_batch"]
            is_k_rows = "k_start" in entry
            n_start = entry.get("n_start", 0)
            tl = entry.get("timeline", [])
            # For now, always show the first logged cycle for this step.
            cycle_idx = 0
            row_inputs = tl[0]["row_inputs"][:sz] if tl else ([0.0] * sz)
            psum_row = tl[0]["partial_sums"][:sz] if tl else ([0.0] * sz)
            if len(psum_row) < sz:
                psum_row = list(psum_row) + [np.nan] * (sz - len(psum_row))
            weight_pad = np.full((sz, sz), np.nan, dtype=float)
            weight_pad[:n_rows, :n_batch] = entry["weight_block"]
            step_label = (
                f"Step {step_idx} (oh,ow)=({entry.get('oh', 0)},{entry.get('ow', 0)}) "
                + (f"k_start={entry.get('k_start')} n_start={n_start} |" if is_k_rows else f"k={entry.get('k')} batch_start={entry.get('batch_start')} row_start={entry.get('row_start')} |")
                + f" n_rows={n_rows} n_cols={n_batch} | pe_util={entry.get('pe_util', 0):.2%}"
            )
            cols_label = "output channels (C_out)" if is_k_rows else "batch (N)"
            fig = _draw_systolic_grid(
                weight_pad.flatten().tolist(),
                row_inputs,
                psum_row,
                sz,
                n_rows,
                n_batch,
                n_start,
                cols_label,
                step_label=step_label,
            )
            st.pyplot(fig)
            plt.close()

            # Index mapping for this step
            st.markdown("**Index mapping for this step**")
            idx_col, col_col = st.columns(2)
            cfg = sim.cfg
            base_row_idx = entry.get('k_start', entry.get('row_start', 0))
            with idx_col:
                st.caption("Input / kernel rows → (r,s,c) (flattened index)")
                idx_rows = []
                span = cfg.S * cfg.C
                for local_idx in range(n_rows):
                    flat_idx = base_row_idx + local_idx
                    r = flat_idx // span
                    rem = flat_idx % span
                    s = rem // cfg.C
                    c = rem % cfg.C
                    idx_rows.append({"flat_idx": flat_idx, "r": r, "s": s, "c": c})
                st.dataframe(pd.DataFrame(idx_rows))
            with col_col:
                if is_k_rows:
                    st.caption("Weight columns → C_out indices for this tile")
                    col_rows = [{"local_col": j, "C_out": n_start + j} for j in range(n_batch)]
                else:
                    batch_start = entry.get('batch_start', 0)
                    st.caption("Weight columns → batch indices for this tile")
                    col_rows = [{"local_col": j, "batch": batch_start + j} for j in range(n_batch)]
                st.dataframe(pd.DataFrame(col_rows))

            st.markdown("---")
            st.subheader("Psum writeback")
            oh, ow = entry.get("oh", 0), entry.get("ow", 0)
            psums = entry.get("partial_sums", [])
            if is_k_rows:
                n_b = entry.get("n_b", 0)
                st.markdown(f"**This step accumulates into:** `OFMap[batch={n_b}, oh={oh}, ow={ow}, channels {n_start}:{n_start + len(psums)}]`")
                st.markdown("Operation: `OFMap[n_b, oh, ow, n_start:n_end] += partial_sums` (add these values to existing partial sums from previous K-tiles).")
                ofmap_spatial = ofmap[n_b, :, :, 0]
                fig2, ax = plt.subplots(figsize=(2, 2))
                ax.imshow(ofmap_spatial, cmap="gray")
                ax.plot(ow, oh, "ro", markersize=6, fillstyle="none", markeredgewidth=2, label=f"({oh},{ow})")
                ax.set_xlabel("ow")
                ax.set_ylabel("oh")
                ax.set_title(f"Writeback (oh,ow)=({oh},{ow})")
                ax.legend(fontsize=6)
                ax.tick_params(axis="both", labelsize=6)
                col1, _ = st.columns([1, 3])
                with col1:
                    st.pyplot(fig2)
                plt.close()
                ofmap_k = ofmap.shape[3]
                ch_end = min(n_start + len(psums), ofmap_k)
                st.write("Channel slice updated this step (C_out indices", n_start, "..", ch_end - 1, "); colors match psum bar above:")
                df_psum = pd.DataFrame(np.array(psums).reshape(1, -1), columns=[n_start + j for j in range(len(psums))])
                st.dataframe(
                    df_psum.style.apply(
                        lambda row: [f"background-color: {_channel_color(n_start + j)}" for j in range(len(row))],
                        axis=1,
                    )
                )
            else:
                batch_start = entry.get("batch_start", 0)
                batch_end = batch_start + len(psums)
                k_out = entry.get("k", 0)
                st.markdown(f"**This step accumulates into:** `OFMap[batch={batch_start}:{batch_end}, oh={oh}, ow={ow}, channel k={k_out}]`")
                st.markdown("Operation: one PSUM per batch index; `OFMap[n, oh, ow, k] += partial_sums[n-batch_start]`.")
                ofmap_spatial = ofmap[min(batch_start, ofmap.shape[0] - 1), :, :, k_out]
                fig2, ax = plt.subplots(figsize=(2, 2))
                ax.imshow(ofmap_spatial, cmap="gray")
                ax.plot(ow, oh, "ro", markersize=6, fillstyle="none", markeredgewidth=2, label=f"({oh},{ow})")
                ax.set_xlabel("ow")
                ax.set_ylabel("oh")
                ax.set_title(f"Writeback (oh,ow)=({oh},{ow}) k={k_out}")
                ax.legend(fontsize=6)
                ax.tick_params(axis="both", labelsize=6)
                col1, _ = st.columns([1, 3])
                with col1:
                    st.pyplot(fig2)
                plt.close()
                st.write("PSUMs (one per batch index):", psums)
        else:
            st.info("Run simulation to see systolic grid.")

    with tabs[5]:
        st.subheader("Iteration log")
        if not logs:
            st.info("No logs stored.")
        else:
            num_logs = len(logs)
            if num_logs > 1:
                idx = st.slider("Iteration index", 0, num_logs - 1, 0, key="iter_idx")
            else:
                idx = 0
            entry = logs[int(idx)]
            if "weight_block" in entry:
                if "k_start" in entry:
                    st.write(f"k_start={entry['k_start']} n_start={entry['n_start']} (oh,ow)=({entry.get('oh',0)},{entry.get('ow',0)}) m={entry.get('m',0)}")
                else:
                    st.write(f"(oh,ow)=({entry['oh']},{entry['ow']}) k={entry['k']} batch_start={entry.get('batch_start')} row_start={entry.get('row_start')}")
                st.write("n_rows:", entry["n_rows"], "n_cols:", entry["n_batch"], "pe_util:", f"{entry.get('pe_util', 0):.2%}")
                st.write("Weight block:")
                st.dataframe(_array_to_df(entry["weight_block"]))
                st.write("Input block:")
                st.dataframe(_array_to_df(entry["input_block"]))
                st.write("Partial sums:", entry["partial_sums"])
            else:
                st.write(entry)

    with tabs[6]:
        st.subheader("PSUM Buffer Routing")
        if routing_result is None:
            st.info("PSUM routing is available for K-rows / C_out-cols mapping. Select that mapping and run.")
        else:
            st.markdown(f"**Routing verification:** {'PASS' if routing_result['verified'] else 'FAIL'} "
                        f"(max abs diff = {routing_result['max_abs_diff']:.2e})")

            with st.expander("Routing Algorithm", expanded=True):
                st.markdown("""
**Direct-mapped routing:** `column c → buffer c` (no crossbar needed).

**Conflict-freedom:** Each output cycle, columns 0–31 produce values simultaneously.
`buffer_index = column_index` → all 32 targets are distinct. No conflicts, ever.

**K-tile accumulation:** Same column always maps to same buffer. Partial sums from
successive K-tiles accumulate in-place. After all K-tiles for a C_out tile: drain to VREGs.

**Loop ordering (critical):** C_out tiles outer, K tiles inner — so all K-tile partials
accumulate in the same buffer set before draining.
                """)

    with tabs[7]:
        st.subheader("Output")
        st.write("OFMap (HWC), channel 0:")
        st.dataframe(_array_to_df(ofmap[0, :, :, 0]))
        st.write("Direct conv reference, channel 0:")
        st.dataframe(_array_to_df(ref[0, :, :, 0]))
        st.write(f"Max abs diff: {diff}")
        st.write("PASS" if diff < 1e-6 else "FAIL")

else:
    st.info("Set parameters and click 'Run simulation'.")
