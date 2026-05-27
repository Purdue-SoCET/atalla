#!/usr/bin/env bash
set -euo pipefail

# ================================================
# Multi-Module Shmoo Script for Systolic Adders
# ================================================

# -------- CONFIG --------
NUM_INPUTS=32       # Set this to match your target wrapper directories
PRECISION_BITS=3    # Global variable to overwrite PRECISION_BITS in the top module

FLOWKIT_DIR="$HOME/Flowkit"
SDC_FILE="$FLOWKIT_DIR/scripts/constraints/sysarr_${NUM_INPUTS}_input_fp_adder.sdc"
FILELIST_TCL="$FLOWKIT_DIR/designs/sysarr_${NUM_INPUTS}_input_fp_adder/filelist.tcl"
REPORTS_SRC="$FLOWKIT_DIR/reports"
QOR_FILE="$REPORTS_SRC/syn_opt/qor.rpt"
DEST_BASE="$HOME/atalla/reports/sysarr_${NUM_INPUTS}_input_fp_adder"
MD_FILE="$FLOWKIT_DIR/rpt.md"

# Which MHz to sweep (inclusive).
START_MHZ=1000
END_MHZ=1000 
STEP=-10

# TCL file for Genus commands only
TCL_SCRIPT="$FLOWKIT_DIR/run_timing_report.tcl"

# --- Optional Command Line Argument ---
TARGET_MODULE="${1:-}" 
MODULES_DIR="$(pwd)/master_modules_${NUM_INPUTS}"

# --- load tools once ---
if ! command -v module >/dev/null 2>&1; then
  [ -f /etc/profile.d/modules.sh ] && source /etc/profile.d/modules.sh
fi
module load cadence/ddi

# -------- HELPERS --------

trunc2() {
  awk 'function t(x){return int(x*100)/100} {printf("%.2f", t($0))}' <<<"$1"
}

update_sdc() {
  local period_ps="$1"
  local half_ps="$2"

  awk -v p="$period_ps" -v h="$half_ps" '
    BEGIN {
      new = sprintf("create_clock -name \"clock1\" -period %s -waveform {0.0 %s} [get_ports clk]", p, h)
    }
    /^create_clock[[:space:]]+-name[[:space:]]+"clock1"/ { print new; next }
    { print }
  ' "$SDC_FILE" > "${SDC_FILE}.tmp" && mv "${SDC_FILE}.tmp" "$SDC_FILE"
}

write_tcl() {
  cat >"$TCL_SCRIPT" <<'EOF'

report_timing -max_paths 10 -path_type full > critical_paths.txt
exit
EOF
}

run_flow_for_mhz() {
  local mod_name="$1"
  local mhz="$2"

  echo "    ==============================================="
  echo "    STARTING GENUS SYNTHESIS FOR ${mhz} MHz"
  echo "    ==============================================="
  cd "$FLOWKIT_DIR"

  # === FIX 1: PREVENT STALE DATA REUSE ===
  # Delete the reports directory from the previous run before starting
  echo "    [DEBUG] Clearing old reports..."
  rm -rf "$REPORTS_SRC"

  # === FIX 2: PREVENT FLOWKIT I/O CRASHES ===
  # Explicitly create tracking directories required by Flowkit
  mkdir -p "$FLOWKIT_DIR/flow.status.d"
  mkdir -p "$FLOWKIT_DIR/flow.metrics.d"
  # =======================================
  
  flowtool -reset -to synthesis
  flowtool -flow run_syn_opt -interactive_run -isolate step < "$TCL_SCRIPT"

  sleep 2

  if [[ ! -d "$REPORTS_SRC" ]]; then
    echo "    ! ERROR: Reports directory $REPORTS_SRC does not exist!"
    return 1
  fi

  if [[ ! -f "$QOR_FILE" ]]; then
    echo "    ! WARNING: QOR file $QOR_FILE not found!"
    echo "    ! Available files in $REPORTS_SRC:"
    ls -la "$REPORTS_SRC" || true
    if [[ -d "$REPORTS_SRC/syn_opt" ]]; then
      echo "    ! Files in $REPORTS_SRC/syn_opt:"
      ls -la "$REPORTS_SRC/syn_opt" || true
    fi
    return 1
  fi

  local dest="$DEST_BASE/$mod_name/reports_${mhz}MHz"
  mkdir -p "$dest"
  
  if [[ -d "$REPORTS_SRC" ]]; then
    cp -r "$REPORTS_SRC"/* "$dest"/ 2>/dev/null || {
      echo "    ! Warning: Some files may not have been copied"
    }
    echo "    Reports successfully archived to $dest"
  fi

  echo "    Cleaning up Genus temporary databases and logs..."
  rm -rf "$FLOWKIT_DIR/logs" "$FLOWKIT_DIR/dbs" "$FLOWKIT_DIR/flow.metrics.d" "$FLOWKIT_DIR/flow.status.d" "$FLOWKIT_DIR/timingReports" 2>/dev/null || true
  rm -f "$FLOWKIT_DIR"/flow* 2>/dev/null || true
}

parse_qor_fields() {
  local qor="$1"
  
  echo "    [DEBUG] Timing section from QOR:" >&2
  awk '/Analysis.*Cost.*Critical/,/^-{10,}/{print "      " $0}' "$qor" >&2
  
  local slack
  slack="$(awk '
    /View[[:space:]]+Group[[:space:]]+Path Slack/ { in_section=1; next }
    /-{10,}/ && in_section==1 { in_section=2; next }
    in_section==2 && /clock1/ { print $3; exit }
  ' "$qor")"
  echo "    [DEBUG] Parsed slack: ${slack:-FAILED}" >&2

  # NEW: Extracting Cell Area
  local cell_area
  cell_area="$(awk '$1=="Cell" && $2=="Area" {print $3; exit}' "$qor")"
  echo "    [DEBUG] Parsed cell area: ${cell_area:-FAILED}" >&2

  local area
  area="$(awk '/^Total Area \(Cell\+Physical\+Net\)/{print $NF}' "$qor")"
  echo "    [DEBUG] Parsed total area: ${area:-FAILED}" >&2

  local power
  power="$(awk '/^Total Power/{printf "%s %s", $(NF-1), $NF}' "$qor")"
  echo "    [DEBUG] Parsed power: ${power:-FAILED}" >&2

  # Return 4 variables separated by pipes
  printf "%s|%s|%s|%s" "${power:-NA}" "${cell_area:-NA}" "${area:-NA}" "${slack:-NA}"
}

update_md() {
  local mod="$1" mhz="$2" power="$3" cell_area="$4" area="$5" slack="$6"
  
  # NEW: Added cell_area to the row formatting
  local row="|${mhz} | ${power} | ${cell_area} | ${area} | ${slack} |"
  
  local md_dest="$DEST_BASE/$mod/rpt.md" 
  
  if [[ ! -f "$md_dest" ]]; then
    echo "# Synthesis QoR Sweep Results" > "$md_dest"
  fi

  # NEW: Updated the header to include 5 columns
  if ! grep -q "^## Module: $mod" "$md_dest"; then
    cat >>"$md_dest" <<HDR
## Module: $mod
| clk (MHz) | Power | Cell Area | Total Area | Slack |
|---|---|---|---|---|
HDR
  fi

  awk -v mod="$mod" -v mhz="$mhz" -v row="$row" '
    BEGIN { in_target_mod = 0; replaced = 0 }
    /^## Module:/ {
      if ($0 == "## Module: " mod) in_target_mod = 1
      else in_target_mod = 0
    }
    in_target_mod == 1 && $0 ~ ("^\\|" mhz "[[:space:]]\\|") {
      $0 = row
      replaced = 1
    }
    { print $0 }
    END {
      if (replaced == 0) print "APPEND_REQUIRED_FLAG"
    }
  ' "$md_dest" > "${md_dest}.tmp"

  if tail -n 1 "${md_dest}.tmp" | grep -q "APPEND_REQUIRED_FLAG"; then
    sed '$d' "${md_dest}.tmp" > "$md_dest"
    echo "$row" >> "$md_dest"
  else
    mv "${md_dest}.tmp" "$md_dest"
  fi
  rm -f "${md_dest}.tmp"
}

# -------- PRE-CHECKS --------
if [[ ! -d "$MODULES_DIR" ]]; then
    echo "Error: Directory $MODULES_DIR not found. Run this script from the directory containing master_modules_${NUM_INPUTS}."
    exit 1
fi

if [[ -n "$TARGET_MODULE" ]]; then
    if [[ -d "$MODULES_DIR/$TARGET_MODULE" ]]; then
        modules=("$MODULES_DIR/$TARGET_MODULE")
    else
        echo "Error: Target module directory $MODULES_DIR/$TARGET_MODULE not found."
        exit 1
    fi
else
    modules=("$MODULES_DIR"/*/)
fi

write_tcl

TOTAL_START=$SECONDS

# -------- OUTER LOOP: ITERATE OVER MODULES --------
for mod_path in "${modules[@]}"; do
  mod_path="${mod_path%/}" # strip trailing slash
  mod_name="$(basename "$mod_path")"

  MOD_START=$SECONDS

  echo ""
  echo "############################################################"
  echo "PROCESSING MODULE: $mod_name"
  echo "############################################################"

  top_sv="$mod_path/sysarr_${NUM_INPUTS}_input_fp_adder.sv"
  if [[ -f "$top_sv" ]]; then
    sed -i -E "s/(parameter\s+PRECISION_BITS\s*=\s*)[0-9]+/\1$PRECISION_BITS/" "$top_sv"
    echo "  -> Set PRECISION_BITS to $PRECISION_BITS in $top_sv"
  else
    echo "  ! Error: Could not find top module wrapper at $top_sv"
    continue
  fi

  echo "  -> Generating new $FILELIST_TCL"
  cat > "$FILELIST_TCL" <<EOF
set listofdirs {}
lappend listofdirs "/home/asicfab/a/karania/atalla/rtl/include/systolic_array"
set_db init_hdl_search_path \$listofdirs

read_hdl -sv -define {NOIP SYNTHESIS} "$mod_path/sysarr_${NUM_INPUTS}_input_fp_adder.sv"
read_hdl -sv -define {NOIP SYNTHESIS} "$mod_path/add${NUM_INPUTS}_tree.sv"
read_hdl -sv -define {NOIP SYNTHESIS} "$mod_path/sysarr_${NUM_INPUTS}_aligner_tree.sv"
EOF

  mkdir -p "$DEST_BASE/$mod_name"

  echo "  -> Starting frequency sweep from ${START_MHZ} MHz to ${END_MHZ} MHz"
  mhz="$START_MHZ"
  while : ; do
    RUN_START=$SECONDS

    TARGET_QOR_FILE="$DEST_BASE/$mod_name/reports_${mhz}MHz/syn_opt/qor.rpt"
    if [[ -f "$TARGET_QOR_FILE" ]]; then
      echo ""
      echo "    >>> [SKIP] ${mhz} MHz already synthesized. Found reports at reports_${mhz}MHz/"
      echo "    >>> Updating Markdown table from existing data..."
      
      # NEW: Extracting the 4th variable (cell_area)
      IFS='|' read -r power cell_area area slack <<<"$(parse_qor_fields "$TARGET_QOR_FILE")"
      update_md "$mod_name" "$mhz" "$power" "$cell_area" "$area" "$slack"
      
    else
      raw_period=$(awk -v f="$mhz" 'BEGIN{printf("%.9f", 1000000.0/f)}')
      raw_half=$(awk -v p="$raw_period" 'BEGIN{printf("%.9f", p/2.0)}')

      period_ps=$(trunc2 "$raw_period")
      half_ps=$(trunc2 "$raw_half")

      echo ""
      echo "    >>> Setup: ${mhz} MHz (period=${period_ps} ps, half-period=${half_ps} ps)"

      update_sdc "$period_ps" "$half_ps"

      if run_flow_for_mhz "$mod_name" "$mhz"; then
        if [[ -f "$QOR_FILE" ]]; then
          IFS='|' read -r power cell_area area slack <<<"$(parse_qor_fields "$QOR_FILE")"
          update_md "$mod_name" "$mhz" "$power" "$cell_area" "$area" "$slack"
          echo "    >>> Result parsed: Power=$power, Cell Area=$cell_area, Total Area=$area, Slack=$slack"
        fi
      else
        echo "    ! Synthesis flow failed or errored out for ${mhz} MHz"
        
        # === FIX 3: LOG FAILURES IN MD ===
        # Explicitly write FAILED to the markdown table so you don't have gaps
        update_md "$mod_name" "$mhz" "FAILED" "FAILED" "FAILED" "FAILED"
      fi

      RUN_TIME=$(( SECONDS - RUN_START ))
      echo "    >>> Time elapsed for ${mhz} MHz run: $((RUN_TIME / 60))m $((RUN_TIME % 60))s"
    fi

    # Step logic
    if (( STEP > 0 )); then
      (( mhz += STEP ))
      (( mhz > END_MHZ )) && break || true
    else
      (( mhz += STEP ))
      (( mhz < END_MHZ )) && break || true
    fi
  done
  
  MOD_TIME=$(( SECONDS - MOD_START ))
  echo "============================================================"
  echo "MODULE $mod_name COMPLETED in $((MOD_TIME / 60))m $((MOD_TIME % 60))s"
  echo "============================================================"
done

TOTAL_TIME=$(( SECONDS - TOTAL_START ))
echo ""
echo "############################################################"
echo "ALL REQUESTED MODULES COMPLETE!"
echo "Total Script Execution Time: $((TOTAL_TIME / 60))m $((TOTAL_TIME % 60))s"
echo "Detailed QoR Reports archived in: $DEST_BASE/"
echo "############################################################"
