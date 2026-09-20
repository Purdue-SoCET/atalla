#!/package/python3/3.11.9/bin/python3
"""
Profiling wrapper for systolic_array_tb.py
Run: python profile_systolic_tb.py
Generates: profile_report.txt (text summary) and profile_data.prof (raw data)
"""
import cProfile
import pstats
import io
from pathlib import Path

SCRIPT_DIR = Path(__file__).parent
PROFILE_DATA = SCRIPT_DIR / "profile_data.prof"
PROFILE_REPORT = SCRIPT_DIR / "profile_report.txt"

# Profile the testbench main module
profiler = cProfile.Profile()
profiler.enable()

# Execute the testbench script
exec(open(SCRIPT_DIR / "systolic_array_tb.py").read())

profiler.disable()

# Save raw profile data
profiler.dump_stats(str(PROFILE_DATA))

# Generate human-readable report
buf = io.StringIO()

print("=" * 80, file=buf)
print("PROFILING REPORT FOR systolic_array_tb.py", file=buf)
print("=" * 80, file=buf)

# Top functions by cumulative time
print("\n\n--- TOP 40 FUNCTIONS BY CUMULATIVE TIME ---\n", file=buf)
stats = pstats.Stats(profiler, stream=buf)
stats.strip_dirs()
stats.sort_stats("cumulative")
stats.print_stats(40)

# Top functions by total (self) time
print("\n\n--- TOP 40 FUNCTIONS BY TOTAL (SELF) TIME ---\n", file=buf)
stats2 = pstats.Stats(profiler, stream=buf)
stats2.strip_dirs()
stats2.sort_stats("tottime")
stats2.print_stats(40)

# Callers of the hottest functions
print("\n\n--- CALLERS OF HOT FUNCTIONS ---\n", file=buf)
stats3 = pstats.Stats(profiler, stream=buf)
stats3.strip_dirs()
stats3.sort_stats("tottime")
stats3.print_callers(20)

report = buf.getvalue()

# Write to file
PROFILE_REPORT.write_text(report)

# Also print to stdout
print(report)
print(f"\nProfile report saved to: {PROFILE_REPORT}")
print(f"Raw profile data saved to: {PROFILE_DATA}")
