#!/usr/bin/env python3
"""
Systolic Array Evaluator (AEDP + EDP)
------------------------------------
Parses synthesis markdown reports, converts raw units to standard 
engineering magnitudes, calculates both AEDP (W·mm²·ns²) and 
standard academic EDP (W·ns²), and groups identical architectures.
Outputs both a Top 10 Bar Chart and a Full Design Space Scatter Plot.
"""

import argparse
import logging
import sys
import re
import json
from pathlib import Path
from collections import defaultdict
from typing import Dict, Any, List
import pandas as pd
import plotly.express as px

import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

# ==========================================
# 1. Logging Configuration
# ==========================================
def setup_logger(verbose: bool) -> logging.Logger:
    logger = logging.getLogger("AEDP_Evaluator")
    log_level = logging.DEBUG if verbose else logging.INFO
    logger.setLevel(log_level)
    
    console_handler = logging.StreamHandler(sys.stdout)
    formatter = logging.Formatter('%(asctime)s | %(levelname)-7s | %(message)s', datefmt='%H:%M:%S')
    console_handler.setFormatter(formatter)
    logger.addHandler(console_handler)
    return logger

# ==========================================
# 2. Core Application Logic
# ==========================================
class AedpEvaluator:
    def __init__(self, logger: logging.Logger):
        self.logger = logger

    def calculate_latency(self, mod_name: str) -> int:
        try:
            add_match = re.search(r'addCfg_([01]+)', mod_name)
            align_match = re.search(r'alignTree_([01]+)', mod_name)
            reg_match = re.search(r'alignReg_([01])', mod_name)
            
            if not (add_match and align_match and reg_match):
                return 7
                
            l_align = sum(1 for char in align_match.group(1) if char == '1') + int(reg_match.group(1))
            l_adder = sum(1 for char in add_match.group(1) if char == '1')
            l_backend = 3
            return l_align + l_adder + l_backend
        except Exception:
            return 7

    def parse_markdown_reports(self, input_dir: Path) -> List[Dict[str, Any]]:
        dataset = []
        md_files = list(input_dir.rglob("rpt.md"))
        
        if not md_files:
            self.logger.error(f"No rpt.md files found in {input_dir}")
            return dataset
            
        self.logger.info(f"Found {len(md_files)} markdown reports. Parsing data...")
        
        for file_path in md_files:
            try:
                with open(file_path, 'r', encoding='utf-8') as f:
                    content = f.read()
                    
                mod_match = re.search(r'## Module:\s+(\S+)', content)
                if not mod_match:
                    continue
                mod_name = mod_match.group(1)

                # if "alignTree_00101" not in mod_name:
                #     continue

                latency_cycles = self.calculate_latency(mod_name)
                
                # UPDATED REGEX: Now explicitly captures the unit string in Group 3
                row_matches = re.findall(r'\|\s*([\d\.]+)\s*\|\s*([\d\.]+)\s*([a-zA-Z]*)\s*\|\s*([\d\.]+)\s*\|\s*([\d\.]+)\s*\|\s*([-\d\.]+)\s*\|', content)
                
                for row in row_matches:
                    mhz = float(row[0])
                    raw_power = float(row[1])
                    power_unit = row[2].strip().lower()  # Extracts 'mw', 'uw', 'nw', or 'w'
                    total_area_um2 = float(row[4])       # Shifted to index 4 due to new capture group
                    slack_ps = float(row[5])             # Shifted to index 5
                    
                    # 1. Delay Calculations (ns)
                    target_period_ns = 1000.0 / mhz
                    critical_path_ns = target_period_ns - (slack_ps / 1000.0)
                    total_delay_ns = latency_cycles * critical_path_ns
                    
                    # 2. Dynamic Power Conversion to Watts
                    if 'nw' in power_unit:
                        power_w = raw_power / 1e9       # Divide by 1 Billion
                    elif 'uw' in power_unit:
                        power_w = raw_power / 1e6       # Divide by 1 Million
                    elif 'mw' in power_unit:
                        power_w = raw_power / 1e3       # Divide by 1 Thousand
                    elif 'w' in power_unit:
                        power_w = raw_power           
                    else:
                        power_w = raw_power / 1e3       # Fallback assume mW
                    
                    area_mm2 = total_area_um2 / 1000000.0
                    
                    # 3. Calculate Academic EDP (W * ns^2) -> which equates to (nJ * ns)
                    edp_score = power_w * (total_delay_ns ** 2)

                    # 4. Calculate Industrial AEDP (W * mm^2 * ns^2)
                    aedp_score = area_mm2 * edp_score
                    
                    if slack_ps < 0:
                        self.logger.debug(f"Skipping {mod_name} @ {mhz}MHz — negative slack ({slack_ps} ps)")
                        continue

                    dataset.append({
                        'module_name': mod_name,
                        'frequency_mhz': mhz,
                        'power_w': round(power_w, 4),
                        'area_mm2': round(area_mm2, 6),
                        'slack_ps': slack_ps,
                        'latency_cycles': latency_cycles,
                        'total_delay_ns': round(total_delay_ns, 3),
                        'edp_score': round(edp_score, 4),    # NEW: EDP Added here
                        'edp_units': 'W·ns²',                # NEW: EDP Units 
                        'aedp_score': round(aedp_score, 10),
                        'aedp_units': 'W·mm²·ns²'
                    })
            except Exception as e:
                self.logger.error(f"Failed processing {file_path.name}: {e}")
                
        # Primary sort is still by the holistic AEDP score
        dataset = sorted(dataset, key=lambda x: x['aedp_score'])
        for idx, item in enumerate(dataset, 1):
            item['mod_id'] = f"MOD_{idx:03d}"
            
        return dataset

    def format_group_label(self, items: List[Dict[str, Any]]) -> str:
        ids = [int(item['mod_id'].split('_')[1]) for item in items]
        if len(ids) == 1:
            return f"MOD_{ids[0]:03d}"
        elif len(ids) <= 3:
            return "MOD_" + ", ".join(f"{i:03d}" for i in ids)
        else:
            return f"MOD_{ids[0]:03d}...{ids[-1]:03d} ({len(ids)} configs)"

    def generate_outputs(self, ranked_data: List[Dict[str, Any]], output_dir: Path):
        output_dir.mkdir(parents=True, exist_ok=True)
        
        grouped = defaultdict(list)
        for item in ranked_data:
            grouped[item['aedp_score']].append(item)
            
        unique_scores = sorted(grouped.keys())
        top_10_unique = unique_scores[:10]
        
        # 1. Export JSON 
        json_path = output_dir / "aedp_results_full.json"
        with open(json_path, 'w') as f:
            json.dump(ranked_data, f, indent=4)
            
        # 2. Export Text Map
        map_path = output_dir / "module_id_mapping.txt"
        with open(map_path, 'w') as f:
            f.write(f"{'ID':<7} | {'AEDP (W·mm²·ns²)':<18} | {'Module Target Configuration Name'}\n")
            f.write("-" * 110 + "\n")
            for item in ranked_data:
                f.write(f"{item['mod_id']} | {item['aedp_score']:<18.9f} | {item['module_name']} (@ {item['frequency_mhz']}MHz)\n")
                
        # 3. Generate PNG Bar Graph (Top 10 Unique Tiers)
        bar_png_path = output_dir / "top_10_unique_aedp_plot.png"
        if top_10_unique:
            plot_scores = list(reversed(top_10_unique))
            plot_labels = [self.format_group_label(grouped[score]) for score in plot_scores]
            
            plt.figure(figsize=(10, 6))
            bars = plt.barh(plot_labels, plot_scores, color='#2c3e50', edgecolor='#34495e', height=0.6)
            
            max_score = max(plot_scores)
            for bar in bars:
                width = bar.get_width()
                score_str = f"{width:,.9f}" if width < 1000 else f"{width:,.0f}"
                plt.text(width + (max_score * 0.02), bar.get_y() + bar.get_height() / 2, 
                         score_str, va='center', ha='left', fontsize=10, fontweight='bold', color='#333333')

            plt.xlabel('AEDP Score (W · mm² · ns²)', fontsize=12, fontweight='bold')
            plt.ylabel('Hardware Configuration ID(s)', fontsize=12, fontweight='bold')
            plt.title('Top 10 Unique Pareto-Optimal Performance Tiers', fontsize=14, fontweight='bold', pad=15)
            plt.grid(axis='x', linestyle='--', alpha=0.6)
            plt.gca().spines['top'].set_visible(False)
            plt.gca().spines['right'].set_visible(False)
            
            plt.tight_layout()
            plt.savefig(bar_png_path, dpi=300, bbox_inches='tight')
            plt.close()
            self.logger.info(f"Saved Grouped PNG Bar Graph to: {bar_png_path.name}")

        # 4. Generate Interactive HTML Scatter Plot (Plotly)
        html_path = output_dir / "design_space_interactive.html"
        if ranked_data:
            # Convert our dataset to a Pandas DataFrame for Plotly
            df = pd.DataFrame(ranked_data)
            
            # Generate the interactive plot
            fig = px.scatter(
                df, 
                x="total_delay_ns", 
                y="edp_score", 
                color="aedp_score",
                hover_name="mod_id",  # The big bold title when you hover
                hover_data={
                    "module_name": True,
                    "area_mm2": ":.6f",
                    "power_w": ":.4f",
                    "total_delay_ns": ":.3f",
                    "edp_score": ":.4f",
                    "aedp_score": ":.6f"
                },
                title="Design Space Exploration (Hover for Module Details)",
                labels={
                    "total_delay_ns": "Total Delay (ns)",
                    "edp_score": "Energy-Delay Product - EDP (W·ns²)",
                    "aedp_score": "AEDP (W·mm²·ns²)",
                    "module_name": "RTL Config",
                    "area_mm2": "Area (mm²)",
                    "power_w": "Power (W)"
                },
                color_continuous_scale="Viridis"
            )
            
            # Clean up the visual theme
            fig.update_layout(template="plotly_white", title_font=dict(size=20, family="Arial", color="#333333"))
            
            # Save as a standalone webpage
            fig.write_html(str(html_path))
            self.logger.info(f"Saved Interactive HTML Scatter Plot to: {html_path.name}")

        # 5. Print Console Summary
        print("\n" + "="*135)
        print(" TOP 10 UNIQUE PERFORMANCE TIERS ".center(135, '='))
        print("="*135)
        print(f"{'Tier':<4} | {'Graph ID(s)':<25} | {'Area (mm²)':<12} | {'Power (W)':<10} | {'Delay (ns)':<10} | {'EDP (W·ns²)':<13} | {'AEDP (W·mm²·ns²)':<18}")
        print("-" * 135)
        for rank, score in enumerate(top_10_unique, 1):
            items = grouped[score]
            label = self.format_group_label(items)
            rep = items[0] 
            print(f"{rank:<4} | {label:<25} | {rep['area_mm2']:<12.9f} | {rep['power_w']:<10.4f} | {rep['total_delay_ns']:<10.3f} | {rep['edp_score']:<13.4f} | {score:<18.9f}")
        print("="*135 + "\n")

# ==========================================
# 3. CLI & Execution
# ==========================================
def parse_arguments() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Evaluate and group Systolic Array configurations (AEDP + EDP).")
    default_dir = Path.home() / "atalla/reports/sysarr_32_input_fp_adder"
    
    parser.add_argument('-i', '--input-dir', type=Path, default=default_dir, help="Directory containing reports.")
    parser.add_argument('-o', '--output-dir', type=Path, default=default_dir, help="Directory to save outputs.")
    parser.add_argument('-v', '--verbose', action='store_true', help="Enable debug logging.")
    return parser.parse_args()

def main() -> int:
    args = parse_arguments()
    logger = setup_logger(args.verbose)
    
    input_dir = args.input_dir.expanduser().resolve()
    output_dir = args.output_dir.expanduser().resolve()
    
    evaluator = AedpEvaluator(logger)
    ranked_data = evaluator.parse_markdown_reports(input_dir)
    
    if not ranked_data:
        logger.error("No valid data processed. Exiting.")
        return 1
        
    evaluator.generate_outputs(ranked_data, output_dir)
    return 0

if __name__ == '__main__':
    sys.exit(main())
