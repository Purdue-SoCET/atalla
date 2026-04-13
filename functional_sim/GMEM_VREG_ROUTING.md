# Simulator / compiler memory routing (not in ISA CSV)

This documents the **intentional contract** between the functional simulator and
emitters when `vreg.ld` / `vreg.st` must distinguish **scratchpad rows** from
**GMEM (linear BF16)** and **compiler spill** paths. The ISA spreadsheet only
names the mnemonics; routing rules live here so reviewers do not re-derive them.

## Scratchpad-only kernels

If every `vreg.*` access uses **scratchpad base + row indices** that never satisfy
the GMEM or spill predicates below, behavior matches “pure scratchpad” and no
DRAM traffic is implied.

## Predicates (full sim + compiler; align with your branch’s `functional_sim.py`)

When implemented, routing typically combines:

- **Spill / expansion temps**: scalars **`$253`–`$254`** (or the builder’s chosen
  temps) may hold packed addresses or metadata; treat them as **not** ordinary
  program addresses in reviews.
- **Row / alias register (e.g. `x33` / `$33`)**: used in expansions where the
  effective row or spill slot participates in the address; document the exact
  comparison in code when you touch routing.
- **Linear BF16 band**: byte addresses **`>= 0x1000`** (or the configured
  threshold) route as **GMEM linear BF16**, not scratchpad row-major indexing.
- **Spill / scratchpad boundary (e.g. `768`)**: addresses falling in the
  configured **spill band** use the spill path; exact numeric bound must match
  `functional_sim.py` and `build.py` on your branch.

**Rule of thumb:** if an address hits **GMEM** or **spill** predicates, the sim
performs the corresponding access; otherwise **scratchpad** semantics apply.

## Emitters

Kernel builders that use **five-operand** `scpad.ld` / `scpad.st` sugar assume
metadata matches tile shape; see comments on SDMA in `build.py` and metadata
decode in `src/functional_sim.py`. Prefer explicit **`rs3`** when stride ≠ encoded
tile width.
