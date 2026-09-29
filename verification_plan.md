# AXI Bus Verification Plan

## Coverage Summary (as of last run)

| Metric | Coverage |
|--------|----------|
| Statements | 89.20% |
| Branches | 80.00% |
| Expressions | 75.94% |
| Conditions | 53.75% |
| FSM States | 100.00% |
| FSM Transitions | 53.12% |
| Toggles | 38.96% |
| **Total** | **70.14%** |

---

## 1. axi_skid_buffer

**Description:** Single-entry buffer that holds R-channel data when a downstream master deasserts ready. Used by the read router, one per master.

**Features to Verify:**
- Pass-through data when downstream ready is high
- Buffer incoming data when ready goes low and upstream valid is high
- Drain buffer when ready returns high
- out_val logic: asserted for both pass-through and buffered states
- selected signal gates pass-through (only active when selected)
- Reset clears buffer and full flag

**Test Plan:**

| Test | Description | Status |
|------|-------------|--------|
| Reset initialization | Verify buffer and full flag clear on nRST | DONE |
| Pass-through (ready high) | Data flows directly when downstream ready | TODO |
| Buffer fill (ready low) | Data stored when ready deasserted mid-transfer | TODO |
| Buffer drain | Buffered data drains when ready reasserts | TODO |
| selected gating | No output when not selected even if valid | TODO |
| Back-to-back valid transfers | Consecutive transactions with no gap | TODO |

---

## 2. axi_read_manager

**Description:** Per-master FIFO for AR channel requests. Instantiated four times in axi_read (SP0, SP1, D$, I$). Appends MASTER_ID to outgoing transactions.

**Features to Verify:**
- Accept AR requests via arvalid/arready handshake
- Store requests in FIFO (AR_DEPTH entries)
- Deassert arready when FIFO full (back-pressure to master)
- Pop entries on demand via pop signal from read controller
- req signal asserted when FIFO non-empty
- MASTER_ID correctly appended to sub_ar_channel_t output
- All AR fields preserved: addr, id, size, len, burst
- FIFO pointer wraparound correctness

**Test Plan:**

| Test | Description | Status |
|------|-------------|--------|
| Push/pop one entry | Single transaction in and out | DONE |
| Push/pop three sequential | Three entries pushed then popped in order | DONE |
| Push/pop simultaneously | Push and pop in same cycle | DONE |
| Endless push | Fill FIFO completely | DONE |
| Empty filled FIFO | Pop all entries after filling | DONE |
| FIFO full back-pressure | arready deasserted when full | TODO |
| Reset clears FIFO | All entries invalidated after nRST | TODO |
| FIFO pointer wraparound | Correct behavior past depth boundary | TODO |
| All burst types | FIXED, INCR, WRAP burst field preserved | TODO |
| Maximum burst length | len=15 (16-beat burst) stored and output correctly | TODO |

---

## 3. axi_read_arbiter

**Description:** Round-robin FSM arbiter for four read masters (SP0, SP1, D$, I$). Grant is combinational. Holds in current state when downstream not ready.

**Features to Verify:**
- IDLE state entered when no requests pending
- Each master can be individually granted from IDLE
- Round-robin priority: SP0 → SP1 → D$ → I$ → SP0
- grant_sel output is combinational (same cycle as request)
- Ready-gated: hold current state when ready deasserted
- No re-grant to same master when other masters are pending
- Correct transition from each granted state to the next

**Test Plan:**

| Test | Description | Status |
|------|-------------|--------|
| TC1: IDLE → SP0 | Grant SP0 from idle | DONE |
| TC2: IDLE → SP1 | Grant SP1 from idle | DONE |
| TC3: IDLE → D$ | Grant D$ from idle | DONE |
| TC4: IDLE → I$ | Grant I$ from idle | DONE |
| TC5: One full rotation | SP0 → SP1 → D$ → I$ → SP0 | DONE |
| TC6: Random transitions | Randomized request patterns | DONE |
| TC7: Idle with ready low | No grant issued when not ready | DONE |
| All 4 simultaneous | All four masters request at once | TODO |
| Ready de-assertion mid-grant | Hold grant when ready goes low | TODO |
| Single master monopoly | Only one master requesting continuously | TODO |

---

## 4. axi_read_router

**Description:** Routes R-channel read data back to the correct master based on MID bits in the response. Contains one axi_skid_buffer instance per master (SP0, SP1, D$, I$).

**Features to Verify:**
- Route to SP0 based on MID field
- Route to SP1 based on MID field
- Route to D$ based on MID field
- Route to I$ based on MID field
- r_ready to subordinate controlled by destination skid buffer availability
- Independent back-pressure per master (one master's stall does not block others)
- MID field extracted correctly from response ID

**Test Plan:**

| Test | Description | Status |
|------|-------------|--------|
| I$ pass-through | Single response to I$ with ready high | DONE |
| D$ pass-through | Single response to D$ with ready high | DONE |
| SP0 pass-through | Single response to SP0 with ready high | DONE |
| SP1 pass-through | Single response to SP1 with ready high | DONE |
| I$ back-pressure | Two responses with ready low, first held | DONE |
| D$ back-pressure | Two responses with ready low, first held | DONE |
| SP0 back-pressure | Two responses with ready low, first held | DONE |
| SP1 back-pressure | Two responses with ready low, first held | DONE |
| Concurrent multi-master | Simultaneous responses to different masters | TODO |
| Skid buffer full | r_ready deasserted when skid buffer full | TODO |
| Multi-beat burst routing | All beats of a burst routed to same master | TODO |

---

## 5. axi_read (integration)

**Description:** Top-level read path. Integrates four axi_read_manager instances, axi_read_arbiter, AR MUX, and axi_read_router into a complete read datapath.

**Features to Verify:**
- End-to-end AR request from any master reaches subordinate
- End-to-end R response from subordinate reaches correct master
- AR MUX selects correct manager output per arbiter grant
- AR pop signaled to correct manager after transaction fires
- Concurrent AR requests from multiple masters arbitrated correctly
- Scoreboard: every AR transaction in is matched with an R response out to the correct master

**Test Plan:**

| Test | Description | Status |
|------|-------------|--------|
| Smoke AR test | 4 random AR transactions, random back-pressure | DONE |
| Pressure AR test | 50 AR transactions from random masters | DONE |
| Idle AR test | Bus idle, no spurious activity | DONE |
| Smoke R test | 1 end-to-end R transaction | DONE |
| Pressure R test | 50 R transactions from random masters | DONE |
| Idle R test | ready signals toggled, no data corruption | DONE |
| All 4 masters simultaneous | AR requests from SP0, SP1, D$, I$ at once | TODO |
| AR FIFO full back-pressure | All manager FIFOs fill, arready deasserted | TODO |
| Maximum burst length | len=15 end-to-end | TODO |

---

## 6. axi_write_manager

**Description:** Per-master dual FIFO holding AW and W channel data. Instantiated three times (SP0, SP1, D$). Exposes head of each FIFO to the write driver. wr_ready is asserted only when AW is not full and W has at least 8 free slots.

**Features to Verify:**
- Accept AW requests via awvalid/awready handshake
- Accept W beats via wvalid/wready handshake
- awready deasserted when AW FIFO full
- wready deasserted when W FIFO full
- wr_ready threshold: only high when W has 8+ free slots AND AW not full
- head_awvalid and head_wvalid expose FIFO front
- aw_pop and w_pop drain entries independently
- MASTER_ID appended correctly to mid_id field
- Independent AW and W FIFO pointer management

**Test Plan:**

| Test | Description | Status |
|------|-------------|--------|
| TC1: Single write | 1 AW + 1 W beat pushed and popped | DONE |
| TC2: Single read | Read single entry back from FIFO | DONE |
| TC3: Multi-beat write (8 beats) | 8 W beats for one AW transaction | DONE |
| TC4: Multi-beat read | Read 8-beat transaction from FIFO | DONE |
| TC5: Fill FIFO | Push until FIFO full | DONE |
| TC6: Empty filled FIFO | Pop all entries after filling | DONE |
| AW full back-pressure | awready deasserted when AW FIFO full | TODO |
| W full back-pressure | wready deasserted when W FIFO full | TODO |
| wr_ready threshold | Exactly 8 W slots free boundary condition | TODO |
| Simultaneous aw_pop and w_pop | Both FIFOs drain in same cycle | TODO |
| Reset clears both FIFOs | Both FIFOs empty after nRST | TODO |

---

## 7. axi_write_arbiter

**Description:** 3-master FSM arbiter (SP0, SP1, D$). Holds a grant for the full burst length by decrementing a beat counter on each w_fire. Issues aw_pop to the write manager at burst completion. Priority from IDLE: SP0 > SP1 > D$.

**Features to Verify:**
- IDLE entered when no requests or skid_ready_w is low
- Grant SP0, SP1, D$ individually from IDLE
- Beat counter initialized from burst length on grant
- Counter decrements on each w_fire
- Grant held until counter reaches zero
- aw_pop issued at burst end
- Round-robin priority: SP0→SP1→D$, SP1→D$→SP0, D$→SP0→SP1
- No grant switch during an active burst
- skid_ready_w gates all grants

**Test Plan:**

| Test | Description | Status |
|------|-------------|--------|
| TC1: Reset initial state | Verify IDLE and zero outputs after reset | DONE |
| TC2: Ready-gated hold (SP0, SP1, D$) | Stay IDLE when skid_ready_w low | DONE |
| TC3: Latch and decrement | 1, 4, 8, 16 beat bursts, counter behavior | DONE |
| TC4: Two consecutive requests same master | Second request after first completes | DONE |
| TC5: Priority under contention | 6 sub-cases: SP0/SP1/D$ combinations | DONE |
| TC6: Stay on same grant | Continuous grants to same master (3 sub-cases) | DONE |
| TC7: Random requests | Randomized request patterns | DONE |
| All 3 simultaneous | All three masters request at once | TODO |
| Grant held during burst | Verify no early switch before counter=0 | TODO |
| aw_pop timing | aw_pop fires exactly at counter=0, not before | TODO |
| w_fire de-assertion | Counter holds when w_fire deasserted mid-burst | TODO |

---

## 8. axi_write_driver

**Description:** Serializes AW and W data from the arbitration-selected write manager into AW and W skid buffers, then drives them to the subordinate AXI port. Tracks same_txn to keep AW and W in lockstep. Detects grant_switch to stop loading on arbitration changes.

**Features to Verify:**
- Load AW entry from granted manager into AW skid buffer
- Load W beats from granted manager into W skid buffer
- Drive awvalid/awready handshake to subordinate
- Drive wvalid/wready handshake to subordinate
- wlast asserted on final beat of burst
- same_txn enforcement: AW and W from same transaction stay together
- grant_switch: stop loading W beats when grant changes
- AW and W skid buffers operate independently
- AW skid buffer full prevents new AW load

**Test Plan:**

| Test | Description | Status |
|------|-------------|--------|
| TC1: Reset initial state | Verify zero state after nRST | DONE |
| TC2: Send SP0 request | AW+W from SP0 driven to subordinate | DONE |
| TC3: Send SP1 request | AW+W from SP1 driven to subordinate | DONE |
| TC4: Send D$ request | AW+W from D$ driven to subordinate | DONE |
| Multi-beat burst | wlast on final beat, all beats forwarded | TODO |
| AW back-pressure | awready low from subordinate, skid buffer fills | TODO |
| W back-pressure | wready low from subordinate, skid buffer fills | TODO |
| Grant switch mid-burst | W loading halts on arbitration change | TODO |
| same_txn lockstep | AW and W only from matching transaction | TODO |

---

## 9. axi_write_router

**Description:** Routes B-channel (write response) from the subordinate back to the correct master (SP0, SP1, D$) based on MID bits. One skid buffer per master. b_i_ready to subordinate is gated by destination buffer availability.

**Features to Verify:**
- Route B response to SP0 based on MID
- Route B response to SP1 based on MID
- Route B response to D$ based on MID
- b_i_ready deasserted to subordinate when destination buffer full
- Independent back-pressure per master
- Skid buffer drains correctly when master asserts b_ready

**Test Plan:**

| Test | Description | Status |
|------|-------------|--------|
| TC1: Route to SP0 | Single response routed to SP0 | DONE |
| TC2: Route to SP1 | Single response routed to SP1 | DONE |
| TC3: Route to D$ | Single response routed to D$ | DONE |
| TC4: SP0 with ready low | Second response blocked, first held | DONE |
| TC5: SP1 with ready low | Second response blocked, first held | DONE |
| TC6: D$ with ready low | Second response blocked, first held | DONE |
| Simultaneous multi-master | Responses to all three masters concurrently | TODO |
| Skid buffer full | b_i_ready deasserted when buffer full | TODO |
| Reset clears buffers | All skid buffers empty after nRST | TODO |

---

## 10. axi_write_top (integration)

**Description:** Top-level write path. Integrates three axi_write_manager instances, axi_write_arbiter, axi_write_driver, and axi_write_router. Manages in_burst tracking per master to gate AW/W valid correctly during multi-beat transactions.

**Features to Verify:**
- End-to-end write from each master reaches subordinate AW/W channels
- B-channel response routed back to correct master
- in_burst flag set on first beat and cleared on wlast
- wr_ready per master correctly reflects manager state
- Back-to-back bursts from same master
- Concurrent writes from multiple masters arbitrated correctly

**Test Plan:**

| Test | Description | Status |
|------|-------------|--------|
| TEST 1: SP0 write burst | Single burst from SP0 to subordinate | DONE |
| TEST 2: SP1 write burst | Single burst from SP1 to subordinate | DONE |
| TEST 3: DCACHE write burst | Single burst from D$ to subordinate | DONE |
| TEST 4: SP0 back-to-back bursts | Two consecutive bursts from SP0 | DONE |
| TEST 5: SP1 back-to-back bursts | Two consecutive bursts from SP1 | DONE |
| D$ back-to-back bursts | Two consecutive bursts from D$ | TODO |
| Concurrent 3-master writes | SP0, SP1, D$ all writing simultaneously | TODO |
| Subordinate back-pressure | awready/wready held low during transfer | TODO |
| B-channel response check | Verify B response reaches correct master | TODO |
| in_burst flag on reset | Flag cleared correctly after nRST | TODO |

---

## 11. axi (top-level integration)

**Description:** Top-level module instantiating axi_read and axi_write_top on a shared bus interface. Both paths share CLK, nRST, and the axi_bus_if interface to all masters and the subordinate.

**Features to Verify:**
- End-to-end AR/R read path (all 4 masters)
- End-to-end AW/W/B write path (all 3 masters)
- Read and write paths operate concurrently without interference
- Scoreboard: every AR in produces matching R out to correct master
- Scoreboard: every AW/W in produces matching B response to correct master
- All transactions complete with no deadlock

**Test Plan:**

| Test | Description | Status |
|------|-------------|--------|
| Smoke AR test | 4 random AR transactions | DONE |
| Pressure AR test | 50 AR transactions, random masters | DONE |
| Idle AR test | No spurious activity when idle | DONE |
| Smoke R test | 1 end-to-end R transaction | DONE |
| Pressure R test | 50 R transactions, random masters | DONE |
| Idle R test | ready signals toggled, no corruption | DONE |
| Smoke write test | 3 random AW/W transactions | DONE |
| Pressure write test | 50 write transactions, random masters | DONE |
| Idle write test | No spurious write activity when idle | DONE |
| Consecutive write test | 6 back-to-back writes from master 1 | DONE |
| Concurrent read + write | Read and write from same master simultaneously | TODO |
| All masters active | All 4 read + all 3 write masters at once | TODO |
| B-channel scoreboard | Verify B responses in top-level scoreboard | TODO |
| Maximum burst length | len=15 on both AR and AW channels | TODO |
| Deadlock detection | Timeout watchdog fires if progress stalls | TODO |
