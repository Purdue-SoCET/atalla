from collections import OrderedDict


class PerfMetrics:
    """
    Container for performance counters.

    Metrics are stored in a dictionary so new counters can be added without
    changing dump formatting logic.
    """

    def __init__(self):
        self.metrics = OrderedDict()
        # Initialize common counters so they are always present in dumps.
        self.metrics["flops_total"] = 0
        self.metrics["flops_scalar"] = 0
        self.metrics["flops_vector"] = 0
        self.metrics["flops_matmul"] = 0
        self.metrics["bytes_loaded"] = 0
        self.metrics["assembly_instructions_executed"] = 0

        # Static packet metrics from decoded instruction memory.
        self.metrics["packets_static_total"] = 0
        self.metrics["packets_static_non_nop"] = 0
        self.metrics["packet_slots_total"] = 0
        self.metrics["packet_slots_filled"] = 0
        self.metrics["packet_slots_total_non_nop_packets"] = 0

        # Runtime packet execution metrics (dynamic, includes loop iterations).
        self.metrics["packets_executed"] = 0
        self.metrics["packets_executed_non_nop"] = 0
        self.metrics["packet_slots_executed"] = 0
        self.metrics["packet_slots_executed_filled"] = 0
        self.metrics["packet_slots_executed_non_nop_packets"] = 0

    def update_derived_metrics(self) -> None:
        flops_total = float(self.metrics.get("flops_total", 0))
        bytes_loaded = float(self.metrics.get("bytes_loaded", 0))
        if bytes_loaded > 0.0:
            self.metrics["arithmetic_intensity"] = flops_total / bytes_loaded
        else:
            self.metrics["arithmetic_intensity"] = 0.0

        packet_slots_total = float(self.metrics.get("packet_slots_total", 0))
        packet_slots_filled = float(self.metrics.get("packet_slots_filled", 0))
        if packet_slots_total > 0.0:
            self.metrics["packet_slot_utilization_pct"] = (packet_slots_filled / packet_slots_total) * 100.0
        else:
            self.metrics["packet_slot_utilization_pct"] = 0.0

        packet_slots_total_non_nop_packets = float(self.metrics.get("packet_slots_total_non_nop_packets", 0))
        if packet_slots_total_non_nop_packets > 0.0:
            self.metrics["packet_slot_utilization_non_nop_packets_pct"] = (
                packet_slots_filled / packet_slots_total_non_nop_packets
            ) * 100.0
        else:
            self.metrics["packet_slot_utilization_non_nop_packets_pct"] = 0.0

        packet_slots_executed = float(self.metrics.get("packet_slots_executed", 0))
        packet_slots_executed_filled = float(self.metrics.get("packet_slots_executed_filled", 0))
        if packet_slots_executed > 0.0:
            self.metrics["packet_slot_utilization_executed_pct"] = (
                packet_slots_executed_filled / packet_slots_executed
            ) * 100.0
        else:
            self.metrics["packet_slot_utilization_executed_pct"] = 0.0

        packet_slots_executed_non_nop_packets = float(self.metrics.get("packet_slots_executed_non_nop_packets", 0))
        if packet_slots_executed_non_nop_packets > 0.0:
            self.metrics["packet_slot_utilization_executed_non_nop_packets_pct"] = (
                packet_slots_executed_filled / packet_slots_executed_non_nop_packets
            ) * 100.0
        else:
            self.metrics["packet_slot_utilization_executed_non_nop_packets_pct"] = 0.0

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
