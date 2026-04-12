# Instruction packing vs scheduling

Several **independent** mechanisms produce VLIW-style instruction memory (packet width 4 in this tree). They **do not** share one implementation. Comparing “slot %” across paths requires naming **which packer** produced the `.in`.

## 1. `emit_test_format` (`build.py`)

- **Input:** `assemble_file` output — list of `(hex40, comment)` per **logical** asm statement (after `expand_vreg_*` / `expand_scpad_*`).
- **Behavior:** Groups `virtual_packet_size` instructions (default **1**), pads each group to `REAL_PACKET_SIZE` (4) with `nop.s`.
- **Effect:** Mostly **one real op per instr-mem row** when `virtual_packet_size == 1` → ~25% static slot fill for many kernels unless you pass a larger virtual size.
- **Latency:** Does **not** model FU latency or insert bubbles; branch offsets match **linear** asm order.

## 2. `emit_test_format_graph` (`build.py`)

- **Input:** asm string → `assemble_file` → dependency metadata from `convert_instructions`.
- **Packing:** `greedy_pack_program_order` with **all ready times 0** — **static** same-packet grouping only (RAW/WAW, one memory op per packet, control isolated). **No** cycle-accurate scheduling.
- **Comment** in source: intentional — inserting latency bubbles would **change PC layout** and break branch immediates for graph-packed images.
- **Use:** `build_conv*.py --graph`, etc., for **higher static slot fill** without changing the **algorithm** (FLOPs / SDMA bytes unchanged).

## 3. `greedy_pack` (`build.py`)

- **Used by:** some handwritten generators (e.g. attention, softmax graph path) that build **explicit** `dependency_instrs` + **non-zero** `ready_time` from `instruction_latency.latency`.
- **Difference from §2:** can reorder within constraints using **ready times**; still **static** image generation, not the emulator loop.

## 4. `build_compiler.schedule_program` (`build_compiler.py`)

- **Input:** normalized asm (after **7→5** VM and **5→3** SDMA expansions here), then `parse_program`.
- **Behavior:** List scheduling with per-mnemonic **latency** map, **structural** limits (e.g. one vector op per packet, one memory op per packet), label/basic-block boundaries.
- **Output:** Relocated encodings + `emit_packet_format` — primary path for **ppci**-emitted `.s` → `.in`.
- **Not** the same as `greedy_pack` / `emit_test_format_graph` (different hazard rules and relocation).

## 5. `functional_sim.run`

- **Dynamic** metrics: `packets_executed`, `assembly_instructions_executed`, executed slot-fill percentages — these reflect **how many times** the fetch loop runs (loops re-fetch), not only static row count.

---

**Practical rule:** For apples-to-apples **performance** comparisons, fix **one** packaging path per experiment (e.g. always `emit_test_format` **or** always `build_compiler.compile_asm` **or** always `--graph`), and record which one in the CSV / notes.
