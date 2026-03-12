# ================================================
# shmoo script for sysarr_n_input_fp_adder_noretime
# Made by: Mixuan Pan 
# Last modified: 3/10, 2026 
#
# What this script does: 
#   modify sdc file for different clock speed 
#   run synthesis 
#   copy the reports file to a different folder 
# 
# commands to run: 
#   chmod +x shmoo_sysarr_n_input_fp_adder_noretime.sh 
#   ./shmoo_sysarr_n_input_fp_adder_noretime.sh 
# ================================================

#!/usr/bin/env bash
set -euo pipefail

# -------- CONFIG --------
FLOWKIT_DIR="$HOME/Flowkit2/Flowkit"
SDC_FILE="$FLOWKIT_DIR/scripts/constraints/sysarr_n_input_fp_adder_noretime.sdc"
REPORTS_SRC="$FLOWKIT_DIR/reports"
QOR_FILE="$REPORTS_SRC/syn_opt/qor.rpt"
DEST_BASE="$HOME/atalla/reports/sysarr_n_input_fp_adder_noretime"
MD_FILE="$FLOWKIT_DIR/rpt.md"

# Which MHz to sweep (inclusive). Edit as needed.
START_MHZ=700 # 1 GHZ 
END_MHZ=400 
STEP=-100     # go down by 5 MHz; use +5 if going up

# TCL file for Genus commands only (not flowtool commands)
TCL_SCRIPT="$FLOWKIT_DIR/run_timing_report.tcl"

# --- load tools once, BEFORE the loop ---
if ! command -v module >/dev/null 2>&1; then
  [ -f /etc/profile.d/modules.sh ] && source /etc/profile.d/modules.sh
fi
module load cadence/ddi

# -------- HELPERS --------

# Truncate to 2 decimals (no rounding). arg1: float
trunc2() {
  awk 'function t(x){return int(x*100)/100} {printf("%.2f", t($0))}' <<<"$1"
}

# Update the single create_clock line in SDC with new period/waveform
update_sdc() {
  local period_ps="$1"   # e.g., 1709.40
  local half_ps="$2"     # e.g., 854.70

  # Build the new create_clock line, then replace the existing one for clock1
  awk -v p="$period_ps" -v h="$half_ps" '
    BEGIN {
      new = sprintf("create_clock -name \"clock1\" -period %s -waveform {0.0 %s} [get_ports clk]", p, h)
    }
    /^create_clock[[:space:]]+-name[[:space:]]+"clock1"/ { print new; next }
    { print }
  ' "$SDC_FILE" > "${SDC_FILE}.tmp" && mv "${SDC_FILE}.tmp" "$SDC_FILE"
}

# Create the TCL script with ONLY Genus commands (no flowtool calls)
write_tcl() {
  cat >"$TCL_SCRIPT" <<'EOF'
# Genus TCL for timing report only
# The synthesis has already been run by flowtool in bash
report_timing -max_paths 10 -path_type full > critical_paths.txt
exit
EOF
}

# Run the tool flow for one frequency
run_flow_for_mhz() {
  local mhz="$1"

  echo "  Running synthesis and optimization..."
  cd "$FLOWKIT_DIR"
  
  # Run flowtool commands in bash (not in TCL)
  flowtool -reset -to synthesis
  
  # Run syn_opt flow and feed it the TCL script for the report
  flowtool -flow run_syn_opt -interactive_run -isolate step < "$TCL_SCRIPT"

  # Wait a moment for reports to be written
  sleep 2

  # Verify reports exist before copying
  if [[ ! -d "$REPORTS_SRC" ]]; then
    echo "  ! ERROR: Reports directory $REPORTS_SRC does not exist!"
    return 1
  fi

  if [[ ! -f "$QOR_FILE" ]]; then
    echo "  ! WARNING: QOR file $QOR_FILE not found!"
    echo "  ! Available files in $REPORTS_SRC:"
    ls -la "$REPORTS_SRC" || true
    if [[ -d "$REPORTS_SRC/syn_opt" ]]; then
      echo "  ! Files in $REPORTS_SRC/syn_opt:"
      ls -la "$REPORTS_SRC/syn_opt" || true
    fi
  fi

  # Copy reports to labeled folder
  local dest="$DEST_BASE/reports_${mhz}MHz"
  mkdir -p "$dest"
  
  # Copy everything from reports directory
  if [[ -d "$REPORTS_SRC" ]]; then
    cp -r "$REPORTS_SRC"/* "$dest"/ 2>/dev/null || {
      echo "  ! Warning: Some files may not have been copied"
    }
    echo "  Reports copied to $dest"
  else
    echo "  ! ERROR: Could not copy reports - source directory missing"
    return 1
  fi

  # Cleanup: delete temporary directories and flow* files
  echo "  Cleaning up temporary files..."
  rm -rf "$FLOWKIT_DIR/logs" "$FLOWKIT_DIR/dbs" "$FLOWKIT_DIR/flow.metrics.d" "$FLOWKIT_DIR/flow.status.d" "$FLOWKIT_DIR/timingReports" 2>/dev/null || true
  rm -f "$FLOWKIT_DIR"/flow* 2>/dev/null || true
  echo "  Cleanup complete"
}

# Extract Slack, Total Power, Total Area from qor.rpt
parse_qor_fields() {
  local qor="$1"
  
  # Debug: show the relevant section
  echo "  [DEBUG] Timing section from QOR:" >&2
  awk '/^Analysis.*View.*Group/,/^-{10,}/{print "    " $0}' "$qor" >&2
  
  # Slack parsing: Find the table with headers, then get the view_1p2_25 clock1 line
  # Format is:
  # Analysis   Cost      Critical  Violating
  # View       Group     Path Slack    TNS    Paths
  # -----------------------------------------------
  # view_1p2_25  clock1    0.8      0.0       0
  
  local slack
  # Look for the second occurance of the line starting with view_1p2_25, followed by clock1, then extract the 3rd field
  slack="$(awk '/^view_1p2_ 25[[:space:]]+clock1/{count++; if(count==2){print $3; exit}}' "$qor")"
  
  # If that didn't work, try a more flexible approach
  if [[ -z "${slack:-}" ]]; then
    # Find the section between "View" and dashes, then get clock1 line
    slack="$(awk '
      /^View.*Group.*Slack/ { in_section=1; next }
      /^-{10,}/ && in_section { in_section=2; next }
      in_section==2 && /clock1/ { print $3; exit }
    ' "$qor")"
  fi

  echo "  [DEBUG] Parsed slack: ${slack:-FAILED}" >&2

  # Total Area (Cell+Physical+Net): the number after the label
  local area
  area="$(awk '/^Total Area \(Cell\+Physical\+Net\)/{print $NF}' "$qor")"
  echo "  [DEBUG] Parsed area: ${area:-FAILED}" >&2

  # Total Power: "2257190.959 nW" format
  local power
  power="$(awk '/^Total Power/{printf "%s %s", $(NF-1), $NF}' "$qor")"
  echo "  [DEBUG] Parsed power: ${power:-FAILED}" >&2

  printf "%s|%s|%s" "${power:-NA}" "${area:-NA}" "${slack:-NA}"
}

# Ensure MD header exists; if a row for MHz exists, replace it; else append.
update_md() {
  local mhz="$1" power="$2" area="$3" slack="$4"

  if [[ ! -f "$MD_FILE" ]] || ! grep -q '^bf_mul area & power report' "$MD_FILE"; then
    cat >"$MD_FILE" <<'HDR'
bf_mul area & power report for different clock speed (MHz)

| clk (MHz) | Power | Area| slack |
|---|---|---| ---|
HDR
  fi

  # Build row text (e.g. |600 | 2396831.544 nW | 6477.849 | 0.0 |)
  local row="|${mhz} | ${power} | ${area} | ${slack} |"

  # Replace existing MHz row or append
  if grep -qE "^\|${mhz}[[:space:]]\|" "$MD_FILE"; then
    # BSD/GNU compatible: write to tmp then swap
    awk -v mhz="$mhz" -v row="$row" '
      BEGIN{re= "^\\|" mhz "[[:space:]]\\|"}
      $0 ~ re {$0=row}
      {print}
    ' "$MD_FILE" > "$MD_FILE.tmp" && mv "$MD_FILE.tmp" "$MD_FILE"
  else
    echo "$row" >> "$MD_FILE"
  fi
}

# -------- MAIN LOOP --------

mkdir -p "$DEST_BASE"
write_tcl

echo "Starting frequency sweep from ${START_MHZ} MHz to ${END_MHZ} MHz (step: ${STEP})"
echo ""

mhz="$START_MHZ"
while : ; do
  # Compute period (ps) and half-period (ps), trunc to 2 decimals
  # period_ps = 1e6 / MHz (because units are ps)
  raw_period=$(awk -v f="$mhz" 'BEGIN{printf("%.9f", 1000000.0/f)}')
  raw_half=$(awk -v p="$raw_period" 'BEGIN{printf("%.9f", p/2.0)}')

  period_ps=$(trunc2 "$raw_period")
  half_ps=$(trunc2 "$raw_half")

  echo "=== ${mhz} MHz → period=${period_ps} ps, waveform={0.0 ${half_ps}} ps ==="

  # 1) Update SDC
  update_sdc "$period_ps" "$half_ps"
  echo "  SDC updated"

  # 2) Run flow and archive reports
  if run_flow_for_mhz "$mhz"; then
    # 3) Parse qor.rpt and update markdown
    if [[ -f "$QOR_FILE" ]]; then
      IFS='|' read -r power area slack <<<"$(parse_qor_fields "$QOR_FILE")"
      update_md "$mhz" "$power" "$area" "$slack"
      echo "  → Final: Power=$power, Area=$area, Slack=$slack"
    else
      echo "  ! Warning: $QOR_FILE not found; skipping MD update."
    fi
  else
    echo "  ! Flow failed for ${mhz} MHz"
  fi

  echo ""

  # Iterate MHz
  if (( STEP > 0 )); then
    (( mhz += STEP ))
    (( mhz > END_MHZ )) && break
  else
    (( mhz += STEP ))
    (( mhz < END_MHZ )) && break
  fi
done

echo "========================================="
echo "Sweep complete!"
echo "Results: $MD_FILE"
echo "Reports: $DEST_BASE/"
echo "========================================="