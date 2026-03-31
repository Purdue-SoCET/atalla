`ifndef LFC_UUID_TRANSACTION_SV
`define LFC_UUID_TRANSACTION_SV

import uvm_pkg::*;
`include "uvm_macros.svh"

/* Minimal transaction carrying (bank, uuid) captured at miss time.
Used exclusively for UUID cross-time linkage checking. Note, this transaction flows from the CPU active monitor to the scoreboard,
which is an intentional exception to the active->predictor / passive->scoreboard architectural boundary. See lfc_environment.sv. */
class lfc_uuid_transaction extends uvm_sequence_item;
  `uvm_object_utils(lfc_uuid_transaction)

  int          bank;
  logic [3:0]  uuid;

  function new(string name = "lfc_uuid_transaction");
    super.new(name);
  endfunction
endclass

`endif

