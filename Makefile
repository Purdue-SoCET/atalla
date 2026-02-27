# ──────────────────────────────────────────────────────────────
#  Atalla Simulation Makefile
# ──────────────────────────────────────────────────────────────
#  Usage:
#    make <module>.sim          – command-line simulation (full visibility)
#    make <module>.sim ACC=1    – with +acc=npr (nets/ports/regs visible)
#    make <module>.sim ACC=0    – fully optimized (fastest, no visibility)
#    make <module>.wav          – GUI simulation (with waves)
#    make <module>.sim FILELIST=path/to/custom.f
#    make clean
#
#  If <module>.f exists in tb/, it is used as the filelist
#  automatically. A FILELIST= argument overrides everything.
# ──────────────────────────────────────────────────────────────

SHELL := /bin/bash

# ── Directories ──────────────────────────────────────────────
TOPDIR   := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
RTLDIR   := $(TOPDIR)rtl
TBDIR    := $(TOPDIR)tb
WAVEDIR  := $(TOPDIR)waves
WORKLIB  := work

# ── Tools ────────────────────────────────────────────────────
VLIB ?= vlib
VLOG ?= vlog
VOPT ?= vopt
VSIM ?= vsim

# ── Performance ──────────────────────────────────────────────
# ACC=2 (default): +acc (full visibility)
# ACC=1          : +acc=npr (nets, ports, registers visible)
# ACC=0          : fully optimized, no signal visibility (fastest)
ACC ?= 2

# ── Include paths (every directory under rtl/) ───────────────
INCFLAGS := $(shell find $(RTLDIR) -type d -print 2>/dev/null | sed 's/^/+incdir+/')

# ── Source collection ────────────────────────────────────────
# Packages first, then everything else
PKG_SRCS := $(shell find $(RTLDIR) -type f \( -name "*_pkg.sv" -o -name "pkg_*.sv" \) 2>/dev/null | sort)
RTL_SRCS := $(shell find $(RTLDIR) -type f -name "*.sv" ! -name "*_pkg.sv" ! -name "pkg_*.sv" 2>/dev/null | sort)

# ── Helpers ──────────────────────────────────────────────────
# Extract the module name from the target (e.g. "foo" from "foo.sim")
MOD = $(basename $@)
TB_TOP = $(MOD)_tb

# Find the testbench file (search recursively under tb/)
find_tb = $(shell find $(TBDIR) -type f -name "$(1)_tb.sv" 2>/dev/null | head -1)

# Auto-detect a .f filelist: FILELIST= overrides, then check rtl/filelists/, then tb/
find_filelist = $(shell \
	if [ -n "$(FILELIST)" ]; then echo "$(FILELIST)"; \
	elif [ -f "$(RTLDIR)/filelists/$(1).f" ]; then echo "$(RTLDIR)/filelists/$(1).f"; \
	elif [ -f "$(TBDIR)/$(1).f" ]; then echo "$(TBDIR)/$(1).f"; \
	fi)

# ── Compile target ───────────────────────────────────────────
# $(1) = module name
define do_compile
	@TB_FILE="$(call find_tb,$(1))"; \
	if [ -z "$$TB_FILE" ]; then \
		echo "[error] testbench not found: $(1)_tb.sv (searched $(TBDIR))"; exit 1; \
	fi; \
	FL="$(call find_filelist,$(1))"; \
	if [ -n "$$FL" ]; then \
		if [ ! -f "$$FL" ]; then \
			echo "[error] filelist not found: $$FL"; exit 1; \
		fi; \
		echo "[compile] using filelist: $$FL"; \
		SRCS="-f $$FL"; \
	else \
		echo "[compile] using all rtl/ sources"; \
		SRCS="$(PKG_SRCS) $(RTL_SRCS)"; \
	fi; \
	[ -d $(WORKLIB) ] || $(VLIB) $(WORKLIB); \
	echo "[compile] vlog $(1)_tb ..."; \
	$(VLOG) -sv -mfcu -work $(WORKLIB) +acc \
		$(INCFLAGS) \
		$$SRCS $$TB_FILE; \
	echo "[compile] done"
endef

# ── Pattern rules ────────────────────────────────────────────

# Command-line simulation (optimized by default)
%.sim:
	$(call do_compile,$(MOD))
ifeq ($(ACC),2)
	@echo "[opt] vopt $(TB_TOP) with +acc (full visibility) ..."
	$(VOPT) +acc $(WORKLIB).$(TB_TOP) -o $(TB_TOP)_opt -work $(WORKLIB)
else ifeq ($(ACC),1)
	@echo "[opt] vopt $(TB_TOP) with +acc=npr (nets/ports/regs) ..."
	$(VOPT) +acc=npr $(WORKLIB).$(TB_TOP) -o $(TB_TOP)_opt -work $(WORKLIB)
else
	@echo "[opt] vopt $(TB_TOP) (fully optimized) ..."
	$(VOPT) $(WORKLIB).$(TB_TOP) -o $(TB_TOP)_opt -work $(WORKLIB)
endif
	@echo "[sim] running $(TB_TOP)_opt (command-line) ..."
	$(VSIM) -c $(WORKLIB).$(TB_TOP)_opt \
		-do "run -all; quit -f"

# GUI simulation with waves
%.wav:
	$(call do_compile,$(MOD))
	@echo "[opt] vopt $(TB_TOP) with +acc (full visibility) ..."
	$(VOPT) +acc $(WORKLIB).$(TB_TOP) -o $(TB_TOP)_opt -work $(WORKLIB)
	@echo "[sim] launching $(TB_TOP)_opt (GUI) ..."
	@WAVEDO="$(WAVEDIR)/$(MOD).do"; \
	if [ -f "$$WAVEDO" ]; then \
		echo "[sim] loading wave script: $$WAVEDO"; \
		$(VSIM) $(WORKLIB).$(TB_TOP)_opt \
			-do "view wave; do $$WAVEDO; run -all" -onfinish stop; \
	else \
		echo "[sim] no wave .do file found, opening blank wave viewer"; \
		$(VSIM) $(WORKLIB).$(TB_TOP)_opt \
			-do "add wave -r /*; run -all" -onfinish stop; \
	fi

# ── Utility targets ─────────────────────────────────────────
.PHONY: clean
clean:
	rm -rf $(WORKLIB) transcript vsim.wlf modelsim.ini obj_dir
