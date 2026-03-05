`ifndef SYS_ARR_PKG_VH
`define SYS_ARR_PKG_VH

package sys_arr_pkg;
  parameter N = 32; // dimensions of the systolic array
  parameter DW = 16; // data width
endpackage

function automatic int compute_tree_latency(input int N, add4_lat, add2_lat);
  int n, total_lat;
  begin
    n = N;
    total_lat = 0;
    while (n > 1) begin
      if (n >= 4) total_lat += add4_lat;
      else total_lat += add2_lat;
      if (n > 2)  n = n / 4;
      else n = n / 2;
    end
    return total_lat;
  end
endfunction

function automatic int compute_tree_levels(input int N);
  int n, num_levels;
  begin
    n = N;
    num_levels = 0;
    while (n > 1) begin
      if (n > 2) n = n / 4;
      else n = n / 2;
      num_levels++;
    end
    return num_levels;
  end
endfunction

`endif