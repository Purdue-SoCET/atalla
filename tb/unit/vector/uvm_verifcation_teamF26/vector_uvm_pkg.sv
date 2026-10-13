
package vector_uvm_pkg;
    import uvm_pkg::*;
    import vector_pkg::*;

    `include "uvm_macros.svh"

    // 1. Transaction
    `include "agents/lane_agent/lane_item.sv"

    // 2. Sequencer
    `include "agents/lane_agent/lane_sequencer.sv"

    // 3. Driver
    `include "agents/lane_agent/lane_driver.sv"

    // 4. Agent
    `include "agents/lane_agent/lane_agent.sv"

    // 5. Sequences
    `include "sequences/lane/lane_base_sequence.sv"
    `include "sequences/lane/lane_add_sequence.sv"

    // 6. Environment (add when implemented)
    `include "env/vector_env.sv"

    // 7. Tests (add when implemented)
    `include "tests/vector_base_test.sv"
    `include "tests/vector_add_test.sv"

endpackage
