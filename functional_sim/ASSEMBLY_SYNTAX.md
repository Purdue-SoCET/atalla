# Assembly Syntax

## Scalar R-Type

add.s rd, rs1, rs2
- Operation: Add (`rd = rs1 + rs2`).
- `rd`: sum output.
- `rs1`: addend A.
- `rs2`: addend B.

sub.s rd, rs1, rs2
- Operation: Subtract (`rd = rs1 - rs2`).
- `rd`: subtraction output.
- `rs1`: minuend.
- `rs2`: subtrahend.

mul.s rd, rs1, rs2
- Operation: Multiply (`rd = rs1 * rs2`).
- `rd`: product output.
- `rs1`: multiplicand.
- `rs2`: multiplier.

div.s rd, rs1, rs2
- Operation: Divide (`rd = rs1 / rs2`).
- `rd`: quotient output.
- `rs1`: dividend.
- `rs2`: divisor.

mod.s rd, rs1, rs2
- Operation: Modulo (`rd = rs1 % rs2`).
- `rd`: remainder output.
- `rs1`: dividend.
- `rs2`: divisor.

or.s rd, rs1, rs2
- Operation: Bitwise OR.
- `rd`: OR result.
- `rs1`: OR input A.
- `rs2`: OR input B.

and.s rd, rs1, rs2
- Operation: Bitwise AND.
- `rd`: AND result.
- `rs1`: AND input A.
- `rs2`: AND input B.

xor.s rd, rs1, rs2
- Operation: Bitwise XOR.
- `rd`: XOR result.
- `rs1`: XOR input A.
- `rs2`: XOR input B.

sll.s rd, rs1, rs2
- Operation: Shift left logical (`rd = rs1 << rs2`).
- `rd`: shifted output.
- `rs1`: value to shift.
- `rs2`: shift amount.

srl.s rd, rs1, rs2
- Operation: Shift right logical.
- `rd`: shifted output.
- `rs1`: value to shift.
- `rs2`: shift amount.

sra.s rd, rs1, rs2
- Operation: Shift right arithmetic.
- `rd`: shifted output.
- `rs1`: signed value to shift.
- `rs2`: shift amount.

slt.s rd, rs1, rs2
- Operation: Set-less-than (signed compare).
- `rd`: compare flag/result.
- `rs1`: compare input A.
- `rs2`: compare input B.

sltu.s rd, rs1, rs2
- Operation: Set-less-than unsigned.
- `rd`: compare flag/result.
- `rs1`: unsigned input A.
- `rs2`: unsigned input B.

add.bf rd, rs1, rs2
- Operation: BF16 add.
- `rd`: BF16 sum.
- `rs1`: BF16 addend A.
- `rs2`: BF16 addend B.

sub.bf rd, rs1, rs2
- Operation: BF16 subtract.
- `rd`: BF16 difference.
- `rs1`: BF16 minuend.
- `rs2`: BF16 subtrahend.

mul.bf rd, rs1, rs2
- Operation: BF16 multiply.
- `rd`: BF16 product.
- `rs1`: BF16 multiplicand.
- `rs2`: BF16 multiplier.

rcp.bf rd, rs1, rs2
- Operation: BF16 reciprocal (`rd = 1 / rs1`).
- `rd`: BF16 reciprocal output.
- `rs1`: BF16 input value.
- `rs2`: unused.

slt.bf rd, rs1, rs2
- Operation: BF16 set-less-than.
- `rd`: BF16 compare flag/result.
- `rs1`: BF16 input A.
- `rs2`: BF16 input B.

sqrt.bf rd, rs1, rs2
- Operation: BF16 square root (`rd = sqrt(rs1)`).
- `rd`: BF16 square-root output.
- `rs1`: BF16 input value.
- `rs2`: unused.

stbf.s rd, rs1, rs2
- Operation: Convert scalar to BF16.
- `rd`: BF16-converted output.
- `rs1`: scalar source value.
- `rs2`: unused.

bfts.s rd, rs1, rs2
- Operation: Convert BF16 to scalar.
- `rd`: scalar-converted output.
- `rs1`: BF16 source value.
- `rs2`: unused.

## Scalar I-Type

addi.s rd, rs1, imm
- Operation: Add immediate.
- `rd`: sum output.
- `rs1`: addend base.
- `imm`: immediate addend.

subi.s rd, rs1, imm
- Operation: Subtract immediate.
- `rd`: subtraction output.
- `rs1`: minuend base.
- `imm`: immediate subtrahend.

muli.s rd, rs1, imm
- Operation: Multiply immediate.
- `rd`: product output.
- `rs1`: multiplicand base.
- `imm`: immediate multiplier.

divi.s rd, rs1, imm
- Operation: Divide immediate.
- `rd`: quotient output.
- `rs1`: numerator base.
- `imm`: immediate denominator.

modi.s rd, rs1, imm
- Operation: Modulo immediate.
- `rd`: remainder output.
- `rs1`: dividend base.
- `imm`: immediate divisor.

ori.s rd, rs1, imm
- Operation: Bitwise OR immediate.
- `rd`: OR result.
- `rs1`: value input.
- `imm`: OR mask/immediate.

andi.s rd, rs1, imm
- Operation: Bitwise AND immediate.
- `rd`: AND result.
- `rs1`: value input.
- `imm`: AND mask/immediate.

xori.s rd, rs1, imm
- Operation: Bitwise XOR immediate.
- `rd`: XOR result.
- `rs1`: value input.
- `imm`: XOR mask/immediate.

slli.s rd, rs1, imm
- Operation: Shift left logical immediate.
- `rd`: shifted output.
- `rs1`: value to shift.
- `imm`: shift amount (`imm & 0x1F`).

srli.s rd, rs1, imm
- Operation: Shift right logical immediate.
- `rd`: shifted output.
- `rs1`: value to shift.
- `imm`: shift amount (`imm & 0x1F`).

srai.s rd, rs1, imm
- Operation: Shift right arithmetic immediate.
- `rd`: shifted output.
- `rs1`: signed value to shift.
- `imm`: shift amount (`imm & 0x1F`).

slti.s rd, rs1, imm
- Operation: Set-less-than immediate (signed).
- `rd`: compare flag/result.
- `rs1`: compare input.
- `imm`: immediate threshold.

sltui.s rd, rs1, imm
- Operation: Set-less-than immediate (unsigned).
- `rd`: compare flag/result.
- `rs1`: unsigned compare input.
- `imm`: unsigned immediate threshold.

jalr.s rd, rs1, imm
- Operation: Jump-and-link register.
- `rd`: link register (`PC + 4`).
- `rs1`: jump base address.
- `imm`: signed jump offset.

## Branch (BR-Type)

beq.s rs1, rs2, off
- Operation: Branch if equal (with rs1 auto-increment behavior in ISA pseudocode).
- `rs1`: lhs compare source.
- `rs2`: rhs compare source.
- `off`: signed branch offset.

bne.s rs1, rs2, off
- Operation: Branch if not equal (with rs1 auto-increment behavior in ISA pseudocode).
- `rs1`: lhs compare source.
- `rs2`: rhs compare source.
- `off`: signed branch offset.

blt.s rs1, rs2, off
- Operation: Branch if less-than (signed).
- `rs1`: lhs compare source.
- `rs2`: rhs compare source.
- `off`: signed branch offset.

bge.s rs1, rs2, off
- Operation: Branch if greater-or-equal (signed).
- `rs1`: lhs compare source.
- `rs2`: rhs compare source.
- `off`: signed branch offset.

bgt.s rs1, rs2, off
- Operation: Branch if greater-than (signed).
- `rs1`: lhs compare source.
- `rs2`: rhs compare source.
- `off`: signed branch offset.

ble.s rs1, rs2, off
- Operation: Branch if less-or-equal (signed).
- `rs1`: lhs compare source.
- `rs2`: rhs compare source.
- `off`: signed branch offset.

## Scalar Memory (M-Type)

lw.s rd, imm(rs1)
- Operation: Load word from memory.
- `rd`: loaded word destination.
- `rs1`: base address register.
- `imm`: signed byte offset added to `rs1`.

sw.s rs, imm(rs1)
- Operation: Store word to memory.
- `rs`: word data to store.
- `rs1`: base address register.
- `imm`: signed byte offset added to `rs1`.

lhw.s rd, imm(rs1)
- Operation: Load half-word from memory.
- `rd`: loaded half-word destination.
- `rs1`: base address register.
- `imm`: signed byte offset added to `rs1`.

shw.s rs, imm(rs1)
- Operation: Store half-word to memory.
- `rs`: half-word data to store.
- `rs1`: base address register.
- `imm`: signed byte offset added to `rs1`.

## Scalar Immediate (MI-Type)

jal rd, imm
- Operation: Jump-and-link immediate.
- `rd`: link register (`PC + 4`).
- `imm`: signed PC-relative jump offset.

jal imm
- Operation: Jump immediate (no link register write).
- `imm`: signed PC-relative jump offset.

li.s rd, imm
- Operation: Load immediate (pseudo-op behavior per ISA notes).
- `rd`: destination register.
- `imm`: immediate constant to materialize.

lui.s rd, imm
- Operation: Load upper immediate.
- `rd`: destination register.
- `imm`: upper-immediate payload for `rd[31:7]`.

## Special (S-Type)

nop.s
- Operation: No operation.
- No operands.

halt.s
- Operation: Halt program execution.
- No operands.

## Vector-Vector (VV-Type)

add.vv vd, vs1, vs2, mask, sac
- Operation: Element-wise add.
- `vd`: vector destination.
- `vs1`: vector input A.
- `vs2`: vector input B.
- `mask`: lane-enable mask register index.
- `sac`: vector control field.

sub.vv vd, vs1, vs2, mask, sac
- Operation: Element-wise subtract.
- `vd`: vector destination.
- `vs1`: vector minuend.
- `vs2`: vector subtrahend.
- `mask`: lane-enable mask register index.
- `sac`: vector control field.

mul.vv vd, vs1, vs2, mask, sac
- Operation: Element-wise multiply.
- `vd`: vector destination.
- `vs1`: vector multiplicand.
- `vs2`: vector multiplier.
- `mask`: lane-enable mask register index.
- `sac`: vector control field.

gemm.vv vd, vs1, vs2, mask, sac
- Operation: GEMM/systolic-array accumulate (`vd = vs1 * weights + vs2`).
- `vd`: vector destination/output.
- `vs1`: vector activation/input tile.
- `vs2`: vector partial-sum input.
- `mask`: lane-enable mask register index.
- `sac`: vector control field.

## Vector-Immediate (VI-Type)

expi.vi vd, vs1, imm, mask
- Operation: Element-wise exponentiation (`exp(vs1[i])`).
- `vd`: vector destination.
- `vs1`: vector source.
- `imm`: reserved/control immediate (not used in core exp math).
- `mask`: lane-enable mask register index.

not.vi vd, vs1, imm, mask
- Operation: Element-wise bitwise NOT.
- `vd`: vector destination.
- `vs1`: vector source.
- `imm`: reserved/control immediate.
- `mask`: lane-enable mask register index.

shift.vi vd, vs1, imm, mask
- Operation: Vector lane shift by immediate control.
- `vd`: vector destination.
- `vs1`: vector source.
- `imm`: shift control (`imm[23]` direction, `imm[22:0]` amount encoding per ISA docs).
- `mask`: lane-enable mask register index.

lw.vi vd, vs1, imm, mask
- Operation: Load weight payload to systolic array path.
- `vd`: destination/control vector.
- `vs1`: weight source vector.
- `imm`: weight-load mode/control immediate.
- `mask`: lane-enable mask register index.

rsum.vi vd, vs1, imm, mask
- Operation: Vector reduction sum.
- `vd`: vector destination (broadcast/selected lane behavior by `imm`).
- `vs1`: vector source to reduce.
- `imm`: reduction mode + target-lane control bits.
- `mask`: lane-enable mask register index.

rmin.vi vd, vs1, imm, mask
- Operation: Vector reduction min.
- `vd`: vector destination (broadcast/selected lane behavior by `imm`).
- `vs1`: vector source to reduce.
- `imm`: reduction mode + target-lane control bits.
- `mask`: lane-enable mask register index.

rmax.vi vd, vs1, imm, mask
- Operation: Vector reduction max.
- `vd`: vector destination (broadcast/selected lane behavior by `imm`).
- `vs1`: vector source to reduce.
- `imm`: reduction mode + target-lane control bits.
- `mask`: lane-enable mask register index.

## Vector-Scalar (VS-Type)

add.vs vd, vs1, rs1, mask
- Operation: Element-wise add scalar.
- `vd`: vector destination.
- `vs1`: vector input.
- `rs1`: scalar addend.
- `mask`: lane-enable mask register index.

sub.vs vd, vs1, rs1, mask
- Operation: Element-wise subtract scalar.
- `vd`: vector destination.
- `vs1`: vector input.
- `rs1`: scalar subtrahend.
- `mask`: lane-enable mask register index.

mul.vs vd, vs1, rs1, mask
- Operation: Element-wise multiply scalar.
- `vd`: vector destination.
- `vs1`: vector input.
- `rs1`: scalar multiplier.
- `mask`: lane-enable mask register index.

## Mask/Move

mv.mts rd, vms
- Operation: Move mask register to scalar register.
- `rd`: scalar destination.
- `vms`: mask source register.

mv.stm vmd, rs1
- Operation: Move scalar register to mask register.
- `vmd`: mask destination register.
- `rs1`: scalar source register.

## Vector/Mask Compare (MVV-Type)

mgt.mvv vmd, vs1, vs2, mask
- Operation: Vector compare greater-than into mask.
- `vmd`: mask destination.
- `vs1`: compare input A.
- `vs2`: compare input B.
- `mask`: lane-enable mask register index.

mlt.mvv vmd, vs1, vs2, mask
- Operation: Vector compare less-than into mask.
- `vmd`: mask destination.
- `vs1`: compare input A.
- `vs2`: compare input B.
- `mask`: lane-enable mask register index.

meq.mvv vmd, vs1, vs2, mask
- Operation: Vector compare equal into mask.
- `vmd`: mask destination.
- `vs1`: compare input A.
- `vs2`: compare input B.
- `mask`: lane-enable mask register index.

mneq.mvv vmd, vs1, vs2, mask
- Operation: Vector compare not-equal into mask.
- `vmd`: mask destination.
- `vs1`: compare input A.
- `vs2`: compare input B.
- `mask`: lane-enable mask register index.

## Vector/Mask Compare (MVS-Type)

mgt.mvs vmd, vs1, rs1, mask
- Operation: Vector-scalar compare greater-than into mask.
- `vmd`: mask destination.
- `vs1`: vector compare input.
- `rs1`: scalar compare input.
- `mask`: lane-enable mask register index.

mlt.mvs vmd, vs1, rs1, mask
- Operation: Vector-scalar compare less-than into mask.
- `vmd`: mask destination.
- `vs1`: vector compare input.
- `rs1`: scalar compare input.
- `mask`: lane-enable mask register index.

meq.mvs vmd, vs1, rs1, mask
- Operation: Vector-scalar compare equal into mask.
- `vmd`: mask destination.
- `vs1`: vector compare input.
- `rs1`: scalar compare input.
- `mask`: lane-enable mask register index.

mneq.mvs vmd, vs1, rs1, mask
- Operation: Vector-scalar compare not-equal into mask.
- `vmd`: mask destination.
- `vs1`: vector compare input.
- `rs1`: scalar compare input.
- `mask`: lane-enable mask register index.

## Vector Register Load/Store (VM-Type)

**ISA encoding (40-bit VM, see bit-spec):** `sid` in bits 36–37, `num_cols` in 31–35, `rs2` row offset, `rs1` base, `vd`/`vs`.

vreg.ld vd, rs1, rs2, num_cols, sid
- Operation: Vector load into `vd`. Default path is scratchpad: `rs1` is the scratchpad **byte address** of the tile base (`spad_addr`); `rs2` is the **row offset** (plain row counter, 0..31 in typical use); effective scratchpad row is **`addr_to_row(rs1) + rs2`**. **`num_cols + 1`** lanes are transferred (`num_cols` is 0-indexed max column, **0..31**). **`sid`**: **0** = SP0, **1** = SP1 (other values reserved / rejected by strict assembler). The emulator may also route `rs1` to **linear spill** or **packed BF16 in GMEM** when address predicates match (see `scpad_ls.py` / `GMEM_VREG_ROUTING.md`).

vreg.st vs, rs1, rs2, num_cols, sid
- Operation: Vector store from `vs`. Same addressing and optional GMEM/spill routing as `vreg.ld`.
- `vs`: vector source.
- `rs1`, `rs2`, `num_cols`, `sid`: same as `vreg.ld`.

**Legacy 7-operand textual form** (`vreg.* …, cols, rows, sid, imm, row`) is accepted only as **input to `assemble_file` / `build_compiler.compile_asm`**, which lowers it to the 5-operand VM form via `expand_vreg_seven_operand_asm` in `build.py`.

## Scratchpad DMA (SDMA)

**Encoded form (3-operand VM):** `scpad.ld rs1, rs2, rs3` / `scpad.st rs1, rs2, rs3`.

- `rs1`: scratchpad byte address of tile base (`spad_addr`).
- `rs2`: DRAM byte address (`dram_addr`).
- `rs3`: packed metadata `{sid[31:30], num_rows[29:25], num_cols[24:20], full_num_cols[19:0]}`. `num_rows` and `num_cols` are 0-indexed tile max indices (`31` encodes width/height **32** in that dimension). `full_num_cols` is the full matrix width in elements and is used as **DRAM row stride** for subtile DMA.

**Convenience 5-operand form** in assembly sources:

scpad.ld rs1, rs2, num_cols, num_rows, sid
- Operation: DMA load from global memory into scratchpad tile.
- Expanded by `expand_scpad_five_operand_asm` in `build.py` into `lui`/`addi` metadata setup + 3-operand `scpad.ld`.

scpad.st rs1, rs2, num_cols, num_rows, sid
- Operation: DMA store from scratchpad tile into global memory.
- Same expansion path as `scpad.ld`.

## Vector-To-Scalar Move (VTS)

vmov.vts rd, vs1, imm
- Operation: Move one vector lane element to scalar register.
- `rd`: scalar destination.
- `vs1`: vector source register.
- `imm`: lane index to read.