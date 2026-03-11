#!/usr/bin/env python3
import os
import re
import glob

def parse_qor(filepath):
    with open(filepath) as f:
        text = f.read()

    cell_area = re.search(r'^Cell Area\s+([\d.]+)', text, re.M)
    total_area = re.search(r'Total Area \(Cell\+Physical\+Net\)\s+([\d.]+)', text)
    total_power = re.search(r'Total Power\s+([\d.]+)\s+nW', text)
    # Slack is in the timing table: "view_1p2_25  clock1   <slack>  <TNS>  <paths>"
    slack = re.search(r'view_1p2_25\s+clock1\s+([\d.-]+)\s+[\d.-]+\s+\d+', text)

    return {
        'cell_area': cell_area.group(1) if cell_area else 'N/A',
        'total_area': total_area.group(1) if total_area else 'N/A',
        'total_power': total_power.group(1) if total_power else 'N/A',
        'slack': slack.group(1) if slack else 'N/A',
    }

def collect_data(design_dir):
    rows = []
    for report_dir in sorted(glob.glob(os.path.join(design_dir, 'reports_*MHz'))):
        freq_match = re.search(r'reports_(\d+)MHz', report_dir)
        if not freq_match:
            continue
        freq = int(freq_match.group(1))
        qor_path = os.path.join(report_dir, 'syn_opt', 'qor.rpt')
        if not os.path.isfile(qor_path):
            continue
        data = parse_qor(qor_path)
        rows.append((freq, data))
    rows.sort(key=lambda x: x[0])
    return rows

def write_table(f, title, rows):
    f.write(f'## {title}\n\n')
    f.write('| Clock Speed (MHz) | Total Area | Cell Area | Total Power (nW) | Slack |\n')
    f.write('|---|---|---|---|---|\n')
    for freq, d in rows:
        f.write(f"| {freq} | {d['total_area']} | {d['cell_area']} | {d['total_power']} | {d['slack']} |\n")
    f.write('\n')

if __name__ == '__main__':
    add_rows = collect_data('add_fp32_45nm')
    mul_rows = collect_data('mul_bf_45nm')

    with open('qor_summary.md', 'w') as f:
        f.write('# QoR Summary\n\n')
        write_table(f, 'add_fp32_45nm', add_rows)
        write_table(f, 'mul_bf_45nm', mul_rows)

    print(f'Done — wrote qor_summary.md ({len(add_rows)} add_fp32 rows, {len(mul_rows)} mul_bf rows)')
