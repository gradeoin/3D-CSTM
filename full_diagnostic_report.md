# Live Diagnostics Extraction Report — Bravo Dual 3D Printer

- **Extraction Time:** 2026-09-10 13:10:49
- **Connection:** COM8 @ 250,000 baud
- **Status:** Complete (100% Non-Intrusive, Safe Read-Only Extraction)

---

## 1. System Identity & Firmware
* **Firmware:** Marlin 2.0.9.7 (Compiled March 10, 2024 at 16:21:17)
* **Author / Machine Tag:** `(Syed, Bravo Dual)`
* **Architecture:** Arduino Mega 2560 (8-bit AVR, 16 MHz)
* **Motherboard Shield:** RAMPS 1.4 / 1.6 (`BOARD_RAMPS_14_EEB`)
* **Available RAM:** 3,709 Bytes free (out of 8,192 Bytes)
* **Motion Buffer:** 1,216 Bytes
* **Machine UUID:** `cede2a2f-41a2-4748-9b12-c55c62f367ff`

---

## 2. Live Sensors & Temperatures
* **Hotend 0 (T0):** `30.42 °C` (Healthy, room ambient)
* **Hotend 1 (T1):** `30.60 °C` (Healthy, room ambient)
* **Heated Bed (B):** `29.55 °C` (Healthy, room ambient)
* *Note:* All 3 thermistor channels are actively reading and calibrated within 1°C of each other.

---

## 3. Limit Switches / Endstop States (`M119`)
* **X-Min:** `TRIGGERED` (Toolhead is currently resting at the X home switch)
* **Y-Min:** `TRIGGERED` (Bed is currently resting at the Y home switch)
* **Z-Min:** `OPEN` (Z axis is raised above the bed)
* **Z-Max:** `OPEN`

---

## 4. Hardware Architecture Details
* **Stepper Drivers:** Standalone StepStick drivers (A4988 or DRV8825) configured via physical microstep jumpers under the drivers on the RAMPS board. (M122 UART bus not present).
* **Bed Leveling:** Manual mechanical 4-corner screw leveling (`M420` auto-leveling is disabled).
* **Extruders:** 2 Physical Extruders configured with a 2.0 mm Z-hop on tool change (`M217 Z2.00`).

---

## 5. Files Currently on Your SD Card (`M20`)
1. `CFFFP_~1.GCO` (1.85 MB) — `CFFFP_COLOUR DESKBUDDY2.0.gcode` (Your 2.3-hour print)
2. `MINI_D~1.GCO` (763 KB) — `MINI_DESKBUDDY_20MIN.gcode`

---

## 6. Motor Motion & Stepping Constants (`M503`)
* **X Axis:** `160.00 steps/mm` | Max Speed: `300 mm/s` | Max Accel: `3000 mm/s²`
* **Y Axis:** `160.00 steps/mm` | Max Speed: `300 mm/s` | Max Accel: `3000 mm/s²`
* **Z Axis:** `800.00 steps/mm` | Max Speed: `5 mm/s`   | Max Accel: `100 mm/s²`
* **Extruders (E0/E1):** `180.00 steps/mm` | Max Speed: `25 mm/s` | Max Accel: `10000 mm/s²`
* **Default Printing Acceleration:** `1000 mm/s²`
* **Travel Acceleration:** `3000 mm/s²`
* **Hotend PID Constants:** `P=22.20, I=1.08, D=114.00`
