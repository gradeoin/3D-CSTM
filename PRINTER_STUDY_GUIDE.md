# Complete Technical Study Guide: Bravo Dual 3D Printer

This comprehensive guide serves as your offline reference manual and study companion for your custom **Bravo Dual 3D Printer**. All data in this document was extracted directly from the machine's onboard microcontroller.

---

## 1. Machine Overview & Digital Identity

* **Machine Name:** Bravo Dual
* **Firmware:** Marlin 2.0.9.7 (Compiled March 10, 2024 at 16:21:17)
* **Author / Builder:** (Syed, Bravo Dual)
* **Board UUID:** `cede2a2f-41a2-4748-9b12-c55c62f367ff`
* **Default Baud Rate:** `250,000 baud` (Serial COM port communication speed)
* **Microcontroller:** ATmega2560 (8-bit AVR architecture, 16 MHz clock)
* **SRAM Memory:** 8,192 Bytes total (3,709 Bytes free logic memory)

---

## 2. Physical Build Volume & Geometry

Directly queried from the printer's software endstops (`M211`):

| Axis | Minimum Position | Maximum Position | Total Printable Travel |
| :--- | :--- | :--- | :--- |
| **X Axis** | `0.00 mm` | `275.00 mm` | **275 mm** (Width) |
| **Y Axis** | `0.00 mm` | `240.00 mm` | **240 mm** (Depth) |
| **Z Axis** | `0.00 mm` | `200.00 mm` | **200 mm** (Height) |

> [!TIP]
> **Update Cura Machine Settings:** You can safely expand your Cura bed settings to **275 mm (X) × 240 mm (Y) × 200 mm (Z)** to take full advantage of the entire bed!

---

## 3. Motion System & Calibration (`M503`)

### Motor Steps per Millimeter (`M92`)
* **X Axis:** `160.00 steps/mm`
* **Y Axis:** `160.00 steps/mm`
* **Z Axis:** `800.00 steps/mm` (Standard T8 lead screw with high microstepping)
* **Extruder 0 (E0):** `180.00 steps/mm` (Geared extruder ratio, e.g., Titan / BMG clone)
* **Extruder 1 (E1):** `180.00 steps/mm`

### Maximum Feedrates / Speed Limits (`M203`)
* **X / Y Maximum Speed:** `300.00 mm/s`
* **Z Maximum Speed:** `5.00 mm/s` (or 300 mm/min) — *Never command fast Z moves to prevent lead screw binding!*
* **Extruder Maximum Speed:** `25.00 mm/s` (or 1500 mm/min) — *Keep retraction speed in slicer at 25 mm/s or below.*

### Accelerations (`M201` & `M204`)
* **Default Print Acceleration:** `1,000 mm/s²`
* **Travel Acceleration:** `3,000 mm/s²`
* **Retract Acceleration:** `3,000 mm/s²`
* **Junction Deviation:** `0.01 mm` (`M205 J0.01`)

---

## 4. Thermal Systems & Extrusion Limits

* **Nozzle Diameter:** Standard 0.40 mm
* **Filament Diameter:** 1.75 mm (`M200 T0 D1.75`, `M200 T1 D1.75`)
* **Cold Extrusion Protection:** Enabled (`M302 S170`). The printer will refuse to push filament if the nozzle temperature is below **170 °C** to prevent motor grinding and gear stripping.
* **Hotend PID Tuning (`M301`):**
  * `Kp: 22.20`
  * `Ki: 1.08`
  * `Kd: 114.00`
* **Tool-Change Z-Hop (`M217`):** `2.00 mm` (The carriage hops 2 mm up when switching between nozzles).

---

## 5. Electronics & Wiring Architecture

* **Controller Stack:** Arduino Mega 2560 + RAMPS 1.4 shield.
* **Display & SD:** RepRapDiscount 2004 Smart Controller (20×4 Character LCD) connected via dual 10-pin ribbon cables (`EXP1` & `EXP2`) into the L-shaped RAMPS Smart Adapter.
* **Power Supply:** Industrial 12V SMPS (Switching Power Supply) with perforated metal cage.
* **Leveling System:** Mechanical manual 4-corner thumbscrew leveling.

---

## 6. Slicer Settings Cheat-Sheet (For UltiMaker Cura)

To achieve reliable prints matching your firmware parameters:

* **Printer Size:** `X: 275 mm`, `Y: 240 mm`, `Z: 200 mm`
* **Build Plate Shape:** Rectangular
* **Origin at Center:** Unchecked
* **Heated Bed:** Checked
* **Extruders:** 1 (for single-nozzle mode) or 2 (for dual mode)
* **Filament Diameter:** `1.75 mm`
* **Print Speed:** `45 – 55 mm/s`
* **Outer Wall Speed:** `25 mm/s`
* **Initial Layer Speed:** `20 mm/s`
* **Retraction Speed:** `25 mm/s`
* **Retraction Distance:** `4.0 – 5.5 mm` (Bowden) or `1.0 – 1.5 mm` (Direct Drive)

---

## 7. Files Saved Locally in Your Workspace (`d:\GIThub\3D CSTM\`)

You have a complete offline repository containing everything about this machine:
1. `Configuration.h` — The complete reconstructed Marlin C++ source configuration.
2. `printer_eeprom_backup.md` — The exact raw EEPROM machine settings backup.
3. `wiring_and_circuits.md` — The electrical and pinout blueprint.
4. `full_diagnostic_report.md` — The live sensor and endstop diagnostics.
5. `PRINTER_STUDY_GUIDE.md` — This complete technical guide.
