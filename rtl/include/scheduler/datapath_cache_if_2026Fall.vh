/*
  Eric Villasenor
  evillase@gmail.com

  holds datapath and cache interface signals
*/
`ifndef DATAPATH_CACHE_IF_VH
`define DATAPATH_CACHE_IF_VH

`include "atalla_isa_types.vh"

interface datapath_cache_if;
  import atalla_isa_pkg::*;

  logic halt;


  // I-cache request channel
  logic                if_req_valid, if_req_ready;
  address_t            if_req_pc;
  logic                if_req_pred_taken;
  address_t            if_req_pred_target;
  logic [3:0]          if_req_epoch;

  // I-cache response channel
  logic                if_resp_valid, if_resp_ready;
  address_t            if_resp_pc;
  instruction_packet_t if_resp_packet;
  logic                if_resp_pred_taken;
  address_t            if_resp_pred_target;
  logic [3:0]          if_resp_epoch;

  // D-cache signals
  logic  dhit, datomic, dmemREN, dmemWEN, flushed;
  word_t dmemload, dmemstore, dmemaddr;

  modport dp (
    input   if_req_ready,
            if_resp_valid, if_resp_pc, if_resp_packet,
            if_resp_pred_taken, if_resp_pred_target, if_resp_epoch,
            dhit, dmemload,
    output  halt,
            if_req_valid, if_req_pc,
            if_req_pred_taken, if_req_pred_target, if_req_epoch,
            if_resp_ready,
            dmemREN, dmemWEN, datomic,
            dmemstore, dmemaddr
  );

  modport cache (
    input   halt,
            if_req_valid, if_req_pc,
            if_req_pred_taken, if_req_pred_target, if_req_epoch,
            if_resp_ready,
            dmemREN, dmemWEN, datomic,
            dmemstore, dmemaddr,
    output  if_req_ready,
            if_resp_valid, if_resp_pc, if_resp_packet,
            if_resp_pred_taken, if_resp_pred_target, if_resp_epoch,
            dhit, dmemload, flushed
  );

  modport icache (
    input   if_req_valid, if_req_pc,
            if_req_pred_taken, if_req_pred_target, if_req_epoch,
            if_resp_ready,
    output  if_req_ready,
            if_resp_valid, if_resp_pc, if_resp_packet,
            if_resp_pred_taken, if_resp_pred_target, if_resp_epoch
  );

  modport dcache (
    input   halt, dmemREN, dmemWEN,
            datomic, dmemstore, dmemaddr,
    output  dhit, dmemload, flushed
  );
endinterface

`endif