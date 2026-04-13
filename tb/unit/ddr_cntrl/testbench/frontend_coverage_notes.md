# Frontend Condition Coverage Notes

## Coverage Gap: Line 91 `frontend_arb` (file: `frontend_arb_nb.sv`)

### Expression
```
((pri && rqst_select[~pri]) || (~pri && rqst_select[pri]))
```

### Uncovered term
- **`rqst_select[~pri]`**: `_1` hit, `_0` NOT hit. Need `_0` for output→0.

### Analysis
- `rqst_select = {request_l, request_s}` → `[0]=request_s`, `[1]=request_l`.
- When `pri=1`: `rqst_select[~pri] = rqst_select[0] = request_s`.
- When `pri=0`: `rqst_select[~pri] = rqst_select[1] = request_l`.

For MC/DC, `rqst_select[~pri]` must be the **deciding factor** for output→0:
- Requires `pri=1` (so the AND gate in the first clause makes `rqst_select[~pri]` matter).
- Then `rqst_select[~pri] = request_s = 0` → first clause = `1 && 0 = 0`.
- Second clause = `~pri(=0) && X = 0` (automatically false).
- Output = 0. `rqst_select[~pri]=0` is the deciding factor. ✓

### Structural reachability problem
The condition `(pri && rqst_select[~pri]) || (~pri && rqst_select[pri])` simplifies to
`request_s` regardless of `pri`. Since `pri` only toggles to 1 when `request_s=1`,
and `request_s` is a registered STQ output, `pri=1 && request_s=0` is **structurally
unreachable** through normal operation. Solution: use hierarchical `force` on `pri`.

## Tests Added (Round 4)

### Test 51: `test_rqst_select_not_pri_zero`
- Forces `DUT.ARB.pri = 1` while queues are empty (`request_s=0, request_l=0`).
- Hits **case 5**: `pri=1, request_s=0, request_l=0` → `rqst_select[~pri]=0`, output=0.
- Also exercises with `request_l=1` (case 6) by driving a read after force.

### Test 52: `test_partial_bank_queues`
- Drives traffic with **partial `fe_full`** patterns (not all banks full).
- Exercises the BQ push conditions with mixed blocking.
- Dynamic fe_full toggling: `16'h000F` → `16'hFF00` → `16'hA5A5` → `0`.

## User Requests
- Cover rqst_select[~pri]=0 condition for MC/DC on line 91.
- Test where not all bank queues are full (partial fe_full).
- Cover LQ request_l=0 for MC/DC on lines 76 and 87.
- No command requests (no interactive stops).
