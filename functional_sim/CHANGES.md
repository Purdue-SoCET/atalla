## ISA version and compatibility notes

This repo is aligned to the updated ISA semantics already integrated in `functional_sim`:

- Updated opcode/decode/build handling for current ISA CSV definitions.
- Updated SDMA control handling (`sdma_ctl_from_reg` path).
- Updated `vreg.ld/st` handling with max-index row/col semantics (`N-1` usage).
- Added scalar/vector op support used by updated kernels (`div.s`, `sqrt.bf`, `div.vv`, `div.vs`).

Backward compatibility notes:

- Compatibility aliases remain for older generator paths where needed (for example `divi.vi` handling in sim/build mappings).
- Practical goal is that legacy kernels and updated-ISA kernels both execute on the same `functional_sim` backend.

## Important operational note

- `python -m functional_sim.<builder_module>`
- `python functional_sim/validate_kernels.py`
