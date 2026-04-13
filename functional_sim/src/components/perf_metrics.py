from collections import OrderedDict


class PerfMetrics:
    """
    Container for performance counters.

    Metrics are stored in a dictionary so new counters can be added without
    changing dump formatting logic.

    Glossary (naming churn):
      assembly_instructions_executed — logical scalar ops committed (one per executed
          assembly slot in the model; not the same as dynamic issue count if you fuse packets).
      packets_* / packet_slots_* — VLIW packet shape and fill stats from static decode or
          dynamic execution; compare names to see whether the counter is compile-time vs runtime.
      bytes_stored — SDMA (and similar) bytes written to GMEM; the model increments this.
      bytes_written — kept equal to bytes_stored for older scripts that still read this key.
      bytes_moved — bytes_loaded + bytes_stored (bandwidth for load+store roofline).
      arithmetic_intensity — flops / bytes_moved (0 if bytes_moved == 0).
      arithmetic_intensity_loads — flops / bytes_loaded only (0 if no loads).
      arithmetic_intensity_load_store — same ratio as arithmetic_intensity (flops / bytes_moved).
    """

    def __init__(self):
        self.metrics = OrderedDict()
        self.metrics["flops_total"] = 0
        self.metrics["flops_scalar"] = 0
        self.metrics["flops_vector"] = 0
        self.metrics["flops_matmul"] = 0
        self.metrics["bytes_loaded"] = 0
        self.metrics["bytes_stored"] = 0
        self.metrics["bytes_written"] = 0
        self.metrics["bytes_moved"] = 0
        self.metrics["assembly_instructions_executed"] = 0
        self.metrics["instructions_executed"] = 0

        # Static packet metrics (decoded instruction memory; set at run() start)
        self.metrics["packets_static_total"] = 0
        self.metrics["packets_static_non_nop"] = 0
        self.metrics["packet_slots_total"] = 0
        self.metrics["packet_slots_filled"] = 0
        self.metrics["packet_slots_total_non_nop_packets"] = 0

        # Dynamic packet metrics (each fetch/execute step)
        self.metrics["packets_executed"] = 0
        self.metrics["packets_executed_non_nop"] = 0
        self.metrics["packet_slots_executed"] = 0
        self.metrics["packet_slots_executed_filled"] = 0
        self.metrics["packet_slots_executed_non_nop_packets"] = 0

    def update_derived_metrics(self) -> None:
        flops_total = float(self.metrics.get("flops_total", 0))
        bytes_loaded = float(self.metrics.get("bytes_loaded", 0))
        bytes_stored = float(self.metrics.get("bytes_stored", 0))
        self.metrics["bytes_written"] = bytes_stored
        bytes_moved = bytes_loaded + bytes_stored
        self.metrics["bytes_moved"] = bytes_moved

        if bytes_moved > 0.0:
            self.metrics["arithmetic_intensity"] = flops_total / bytes_moved
            self.metrics["arithmetic_intensity_load_store"] = flops_total / bytes_moved
        else:
            self.metrics["arithmetic_intensity"] = 0.0
            self.metrics["arithmetic_intensity_load_store"] = 0.0

        if bytes_loaded > 0.0:
            self.metrics["arithmetic_intensity_loads"] = flops_total / bytes_loaded
        else:
            self.metrics["arithmetic_intensity_loads"] = 0.0

        packet_slots_total = float(self.metrics.get("packet_slots_total", 0))
        packet_slots_filled = float(self.metrics.get("packet_slots_filled", 0))
        if packet_slots_total > 0.0:
            self.metrics["packet_slot_utilization_pct"] = (
                packet_slots_filled / packet_slots_total
            ) * 100.0
        else:
            self.metrics["packet_slot_utilization_pct"] = 0.0

        packet_slots_total_non_nop = float(
            self.metrics.get("packet_slots_total_non_nop_packets", 0)
        )
        if packet_slots_total_non_nop > 0.0:
            self.metrics["packet_slot_utilization_non_nop_packets_pct"] = (
                packet_slots_filled / packet_slots_total_non_nop
            ) * 100.0
        else:
            self.metrics["packet_slot_utilization_non_nop_packets_pct"] = 0.0

        packet_slots_executed = float(self.metrics.get("packet_slots_executed", 0))
        packet_slots_executed_filled = float(
            self.metrics.get("packet_slots_executed_filled", 0)
        )
        if packet_slots_executed > 0.0:
            self.metrics["packet_slot_utilization_executed_pct"] = (
                packet_slots_executed_filled / packet_slots_executed
            ) * 100.0
        else:
            self.metrics["packet_slot_utilization_executed_pct"] = 0.0

        packet_slots_exec_non_nop = float(
            self.metrics.get("packet_slots_executed_non_nop_packets", 0)
        )
        if packet_slots_exec_non_nop > 0.0:
            self.metrics["packet_slot_utilization_executed_non_nop_packets_pct"] = (
                packet_slots_executed_filled / packet_slots_exec_non_nop
            ) * 100.0
        else:
            self.metrics["packet_slot_utilization_executed_non_nop_packets_pct"] = 0.0

        asm_retired = int(self.metrics.get("assembly_instructions_executed", 0))
        self.metrics["instructions_executed"] = asm_retired

    def increment(self, name: str, amount: int | float = 1) -> None:
        self.metrics[name] = self.metrics.get(name, 0) + amount

    def set_metric(self, name: str, value: int | float) -> None:
        self.metrics[name] = value

    def get_metric(self, name: str, default=0):
        return self.metrics.get(name, default)

    def reset_metric(self, name: str) -> None:
        self.metrics[name] = 0

    def reset_all(self) -> None:
        for key in list(self.metrics.keys()):
            self.metrics[key] = 0

    def dump_to_file(self, filename: str) -> None:
        self.update_derived_metrics()
        with open(filename, "w") as f:
            for name, value in self.metrics.items():
                f.write(f"{name}: {value}\n")