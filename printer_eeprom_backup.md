# 3D Printer Configuration Backup (Queried via Serial COM8)
# Date: 2026-09-10
# Baud Rate: 250000

## Firmware Information (M115)
- Firmware: Marlin 2.0.9.7 (Compiled Mar 10 2024 16:21:17)
- Author: (Syed, Bravo Dual)
- Machine Type: 3D Printer
- Extruder Count: 2
- UUID: cede2a2f-41a2-4748-9b12-c55c62f367ff
- Free Memory: 3709 bytes
- PlannerBufferBytes: 1216 bytes

## Capabilities
- EEPROM: Active (Cap:EEPROM:1)
- Volumetric Extrusion: Supported (Cap:VOLUMETRIC:1)
- Auto-Report Temperature: Supported (Cap:AUTOREPORT_TEMP:1)
- Thermal Protection: Active (Cap:THERMAL_PROTECTION:1)
- Arcs: Supported (Cap:ARCS:1)
- SD Card: Active (Cap:SDCARD:1)

## Current Configuration & Limits (M503)
- Units: G21 (Millimeters), M149 C (Celsius)
- Filament Diameter: 1.75 mm (M200 T0 D1.75 / M200 T1 D1.75)
- Steps Per Unit (M92):
  - X: 160.00 steps/mm
  - Y: 160.00 steps/mm
  - Z: 800.00 steps/mm
  - E: 180.00 steps/mm
- Maximum Feedrates (M203 in mm/s):
  - X: 300.00 mm/s
  - Y: 300.00 mm/s
  - Z: 5.00 mm/s
  - E: 25.00 mm/s (Maximum extrusion/retraction speed)
- Maximum Accelerations (M201 in mm/s²):
  - X: 3000.00 mm/s²
  - Y: 3000.00 mm/s²
  - Z: 100.00 mm/s²
  - E: 10000.00 mm/s²
- Printing Accelerations (M204 in mm/s²):
  - Print (P): 1000.00 mm/s²
  - Retract (R): 3000.00 mm/s²
  - Travel (T): 3000.00 mm/s²
- Advanced Settings (M205):
  - Junction Deviation: 0.01 mm
  - Minimum segment time: 20000 µs
- Home Offset (M206):
  - X: 0.00 mm
  - Y: 0.00 mm
  - Z: 0.00 mm
- Hotend Offsets (M218):
  - T1: X0.00 Y0.00 Z0.000
- Tool-changing (M217):
  - Z-hop: 2.00 mm
- Hotend PID (M301):
  - E0: P=22.20, I=1.08, D=114.00
  - E1: P=22.20, I=1.08, D=114.00
