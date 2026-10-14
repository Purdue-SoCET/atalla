
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

    // 4. Monitor transaction
    `include "agents/lane_agent/lane_result_item.sv"

    // 5. Monitor
    `include "agents/lane_agent/lane_monitor.sv"

    // 6. Agent
    `include "agents/lane_agent/lane_agent.sv"

    // 7. Sequences
    `include "sequences/lane/lane_base_sequence.sv"
    `include "sequences/lane/lane_add_sequence.sv"

    // 8. Scoreboard
    `include "env/vector_scoreboard.sv"

    // 9. Environment (add when implemented)
    `include "env/vector_env.sv"

    // 10. Tests (add when implemented)
    `include "tests/vector_base_test.sv"
    `include "tests/vector_add_test.sv"

endpackage
