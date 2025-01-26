/*
*   Copyright 2016 Purdue University
*   
*   Licensed under the Apache License, Version 2.0 (the "License");
*   you may not use this file except in compliance with the License.
*   You may obtain a copy of the License at
*   
*       http://www.apache.org/licenses/LICENSE-2.0
*   
*   Unless required by applicable law or agreed to in writing, software
*   distributed under the License is distributed on an "AS IS" BASIS,
*   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*   See the License for the specific language governing permissions and
*   limitations under the License.
*   
*   
*   Filename:     cache_control_if.vh
*   
*   Created by:   John Skubic	
*   Email:        jjs.skubic@gmail.com
*   Date Created: 06/29/2017
*   Description:  Interface between the Pipeline, caches, and memory system
*                 Any actions that control the cache are relayed through this if.
*                 Events that may cause activity on this interface:
*                   - Memory Fences
*                   - Coherence Operations 
*/

`ifndef CACHE_CONTROL_IF_VH
`define CACHE_CONTROL_IF_VH

//`include "bus_ctrl_if.vh"

interface cache_control_if;
  logic icache_clear, icache_flush, iclear_done, iflush_done;
  logic dcache_clear, dcache_flush, dclear_done, dflush_done;
  // Used to signal that instruction depends on state of reservation set.
  // Reservation should always be lost after this goes high.
  logic dcache_reserve;
  // Used to signal that cache line should be locked.
  logic dcache_exclusive;

  modport pipeline (
    output icache_clear, icache_flush, dcache_clear, dcache_flush, dcache_reserve, dcache_exclusive,
    input iclear_done, iflush_done, dclear_done, dflush_done
  );

  modport caches (
    input icache_clear, icache_flush, dcache_clear, dcache_flush, dcache_reserve, dcache_exclusive,
    output iclear_done, iflush_done, dclear_done, dflush_done
  );
  
  modport icache (
    input icache_clear, icache_flush,
    output iclear_done, iflush_done
  );

  modport dcache ( 
    input dcache_clear, dcache_flush, dcache_reserve, dcache_exclusive,
    output dclear_done, dflush_done
  );

endinterface
`endif //CACHE_CONTROL_IF