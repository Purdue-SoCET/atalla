# scripts/run_sim.tcl
# Generic compilation and simulation script
# Expects the following Tcl vars to be set by the caller (Makefile):
#   TB_NAME   - top-level testbench module name (e.g., lane_sequencer_tb)
#   SRCS      - list of all source files to compile (pkgs + DUT + TB)
#   INCS      - list of +incdir+... flags
#   WAVE_ROOT - (optional) directory containing <TB_NAME>.do wavefiles

# --- 1. Validate Inputs ---
if {![info exists TB_NAME]} {
    puts "ERROR: TB_NAME variable not set."
    if {[batch_mode]} { quit -f } else { return }
}

if {![info exists SRCS]} {
    puts "ERROR: SRCS variable (file list) not set."
    if {[batch_mode]} { quit -f } else { return }
}

if {![info exists INCS]} {
    set INCS {}
    puts "NOTE: INCS variable not set. Defaulting to empty."
}

# Default WAVE_ROOT if not provided
if {![info exists WAVE_ROOT]} {
    set WAVE_ROOT "waves"
    puts "NOTE: WAVE_ROOT not set. Defaulting to '$WAVE_ROOT'."
}

puts "------------------------------------------"
puts "run_sim.tcl: starting"
puts "  TB_NAME   = $TB_NAME"
puts "  WAVE_ROOT = $WAVE_ROOT"
puts "------------------------------------------"

# --- 2. Setup Library (no auto-delete) ---
if {![file exists work]} {
    puts "Creating work library..."
    vlib work
}
vmap work work

# --- 3. Split SRCS into package vs non-package ---
set pkg_files {}
set other_files {}

foreach f $SRCS {
    # Heuristic: anything *_pkg.sv or *_pkg.vh is treated as a package unit
    if {[string match "*_pkg.sv" $f] || [string match "*_pkg.vh" $f]} {
        lappend pkg_files $f
    } else {
        lappend other_files $f
    }
}

puts "=========================================="
puts "Compiling Source Files..."
puts "=========================================="
puts "Top Module: $TB_NAME"
puts "Package files:"
foreach f $pkg_files   { puts "  [file normalize $f]" }
puts "Non-package files:"
foreach f $other_files { puts "  [file normalize $f]" }

# --- 4. Compile packages first (rarely change) ---
if {[llength $pkg_files] > 0} {
    puts "------------------------------------------"
    puts "Compiling package files..."
    puts "------------------------------------------"

    if {[catch {vlog -sv -mfcu +define+SQRT_DEBUG {*}$INCS {*}$pkg_files} errMsg]} {
        puts "ERROR: Package compilation failed!"
        puts "Error details:"
        puts $errMsg
        if {[batch_mode]} { quit -f } else { return }
    }
} else {
    puts "No package files detected in SRCS."
}

# --- 5. Compile remaining (DUT + TB) ---
if {[llength $other_files] > 0} {
    puts "------------------------------------------"
    puts "Compiling DUT + TB files..."
    puts "------------------------------------------"

    # No -mfcu here so small edits recompile faster
    if {[catch {vlog -sv +define+SQRT_DEBUG {*}$INCS {*}$other_files} errMsg]} {
        puts "ERROR: Compilation Failed!"
        puts "Error details:"
        puts $errMsg
        if {[batch_mode]} { quit -f } else { return }
    }
} else {
    puts "WARNING: No non-package source files found. Nothing to simulate?"
}

# --- 6. Load Simulation ---
puts "=========================================="
puts "Loading Simulation..."
puts "=========================================="

# You can narrow +acc later (e.g. +acc=/lane_sequencer_tb/*) if you want
if {[catch {vsim -voptargs="+acc" work.$TB_NAME} errMsg]} {
    puts "ERROR: vsim failed to elaborate $TB_NAME"
    puts "Error details:"
    puts $errMsg
    if {[batch_mode]} { quit -f } else { return }
}

# --- 7. Run (Batch vs GUI) ---
if {[batch_mode]} {
    puts "Running in Batch Mode..."
    run -all
    quit -f
} else {
    puts "Running in GUI Mode..."

    # Derive wavefile basename from TB_NAME:
    # If TB_NAME ends with "_tb", strip that suffix (lane_tb -> lane).
    set wave_basename $TB_NAME
    if {[string match "*_tb" $TB_NAME]} {
        set wave_basename [string range $TB_NAME 0 end-3]
    }

    # Wave root (default = waves)
    if {![info exists WAVE_ROOT]} {
        set WAVE_ROOT "waves"
    }

    # Build wavefile path
    set wave_file "$WAVE_ROOT/$wave_basename.do"
    puts "Looking for wave do-file: $wave_file"

    # Load do-file
    if {[file exists $wave_file]} {
        puts "Applying wave do-file: $wave_file"
        do $wave_file
    } else {
        puts "No wave do-file found for $wave_basename, adding all waves."
        add wave -r sim:/*
    }

    wave zoom full

    # AUTO RUN RESTORED
    puts "Starting simulation (GUI)..."
    run -all
    puts "Simulation finished. Inspect waves or re-run manually."
}
