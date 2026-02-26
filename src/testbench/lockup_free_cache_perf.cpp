#include "svdpi.h"
#include <fstream>
#include <iostream>
#include <ostream>

extern "C" {

static std::ofstream out;

static long long total_hits = 0;
static long long total_misses = 0;
static long long total_latency = 0;

void cache_update_hit() {
  total_hits++;
  total_latency++;
}

void cache_update_miss() { total_misses++; }

void cache_update_in_flight(int in_flight) { total_latency += in_flight; }

static long long prev_reqs = 0;
static long long prev_latency = 0;

void print_cache_perf(int cycle) {
  long long total_reqs = total_hits + total_misses;
  long long interval_reqs = total_reqs - prev_reqs;
  long long interval_latency = total_latency - prev_latency;

  long long avg_lat =
      (interval_reqs > 0) ? (interval_latency / interval_reqs) : 0;

  prev_reqs = total_reqs;
  prev_latency = total_latency;

  if (!out.is_open()) {
    out.open("cache_perf.csv", std::ios::trunc | std::ios::out);
    out << "cycle,hits,misses,avg_lat\n";
  }

  out << cycle << "," << total_hits << "," << total_misses << "," << avg_lat
      << "\n";
  out.flush();

  std::cout << "--- Cycle " << cycle << " ---\n";
  std::cout << "[CACHE]\n";
  std::cout << "  Hits:       " << total_hits << "\n";
  std::cout << "  Misses:     " << total_misses << "\n";
  std::cout << "  Avg Lat:    " << avg_lat << "\n";
  std::cout << "--------------------------------\n";
}
}