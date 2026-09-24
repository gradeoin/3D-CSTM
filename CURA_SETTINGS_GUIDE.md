# 🖨️ UltiMaker Cura Complete Setup & Slicing Guide — Bravo Dual

This guide contains the exact settings to configure **UltiMaker Cura** for your custom **Bravo Dual 3D Printer**.

---

## 1. Machine Setup (Add Custom Printer)

1. In Cura, go to **Settings > Printer > Add Printer...**
2. Choose **Non-UltiMaker printer > Add a non-networked printer**.
3. Scroll down to **Custom** and select **Custom FFF printer**.
4. Set Printer name to: `Bravo Dual` and click **Add**.

---

## 2. Machine Settings Window

Enter the exact physical dimensions and options extracted from your Marlin firmware:

### 🔲 "Printer" Tab

| Setting | Value | Notes |
| :--- | :--- | :--- |
| **X (Width)** | `275 mm` | Extracted from firmware (`M211`) |
| **Y (Depth)** | `240 mm` | Extracted from firmware (`M211`) |
| **Z (Height)** | `200 mm` | Extracted from firmware (`M211`) |
| **Build plate shape** | `Rectangular` | |
| **Origin at center** | **Unchecked** | Front-left is (0,0) |
| **Heated bed** | **Checked** | Uses external MKS MOS25 MOSFET |
| **Heated build volume** | Unchecked | |
| **G-code flavor** | `Marlin` | |

#### Start G-code (Copy & Paste):
```gcode
; --- Bravo Dual Start G-code ---
G21 ; Metric values
G90 ; Absolute positioning
M82 ; Set extruder to absolute mode
M107 ; Start with fan off
M140 S{material_bed_temperature_layer_0} ; Start heating bed
M104 S{material_print_temperature_layer_0} ; Start heating extruder
M190 S{material_bed_temperature_layer_0} ; Wait for bed to reach temp
M109 S{material_print_temperature_layer_0} ; Wait for extruder to reach temp
G28 ; Home all axes (X, Y, Z)
G1 Z5.0 F3000 ; Move Z up 5mm
G1 X5 Y10 F3000 ; Move to prime start position
G1 Z0.3 F1000 ; Lower nozzle to 0.3mm
G92 E0 ; Reset extruder position
G1 Y150 E15 F1200 ; Draw first purge line
G1 X5.4 F3000 ; Move across slightly
G1 Y20 E30 F1200 ; Draw second purge line
G92 E0 ; Reset extruder position
G1 Z2.0 F3000 ; Move Z up
; --- End Start G-code ---
```

#### End G-code (Copy & Paste):
```gcode
; --- Bravo Dual End G-code ---
M400 ; Finish all current moves
G91 ; Relative positioning
G1 Z5 F1000 ; Z-hop 5mm to clear print
G1 E-1 F1500 ; Quick 1mm retraction
G90 ; Absolute positioning
G1 X0 Y220 F3000 ; Present finished print to the front
M104 S0 ; Turn off hotend heater
M140 S0 ; Turn off bed heater
M107 ; Turn off part cooling fan
M84 X Y E ; Disable X, Y, and E steppers (leave Z engaged to prevent bed drop)
; --- End of Print ---
```

---

### 🔲 "Extruder 1" Tab

| Setting | Value | Notes |
| :--- | :--- | :--- |
| **Nozzle size** | `0.4 mm` | Standard brass MK8 nozzle |
| **Compatible material diameter** | `1.75 mm` | Standard filament diameter |
| **Nozzle offset X** | `0.0 mm` | |
| **Nozzle offset Y** | `0.0 mm` | |

---

## 3. Recommended Print Profile Settings (PLA Filament)

Use these settings in the main Cura print sidebar for standard, reliable quality:

### 📐 Quality
* **Layer Height:** `0.20 mm` (Standard quality)
* **Initial Layer Height:** `0.28 mm` (Thicker first layer compensates for bed variance and improves adhesion)
* **Line Width:** `0.40 mm`

### 🧱 Walls & Top/Bottom (Shell)
* **Wall Thickness:** `1.2 mm` (3 wall lines)
* **Wall Line Count:** `3`
* **Outer Wall Wipe Distance:** `0.2 mm`
* **Top/Bottom Thickness:** `0.8 mm` (4 layers)
* **Top Layers:** `4`
* **Bottom Layers:** `4`
* **Z Seam Alignment:** `User Specified` -> `Back` (hides seam at the back)

### 🪹 Infill
* **Infill Density:** `15% – 20%` (20% for strong functional parts)
* **Infill Pattern:** `Gyroid` or `Grid` (Gyroid provides equal strength in all directions and prevents nozzle collision)

### 🌡️ Material (PLA)
* **Printing Temperature:** `200 °C` (or 205 °C for high-speed/matte PLA)
* **Initial Layer Printing Temperature:** `205 °C` (better bed bonding)
* **Build Plate Temperature:** `60 °C`
* **Initial Layer Build Plate Temperature:** `60 °C`

### ⚡ Speed (Matches Firmware Acceleration Limits)
* **Print Speed:** `50 mm/s`
* **Infill Speed:** `50 mm/s`
* **Wall Speed:** `25 mm/s` (slow outer walls for sharp detail)
* **Outer Wall Speed:** `25 mm/s`
* **Inner Wall Speed:** `35 mm/s`
* **Initial Layer Speed:** `20 mm/s` (Slow speed ensures first layer sticks firmly)
* **Travel Speed:** `120 mm/s`
* **Z-Axis Speed:** `5 mm/s` (Firmware limit)

### 🔄 Travel & Retraction (⚠️ CRITICAL SETTING)
Because your printer uses a **Direct-Drive MK8 Extruder** (motor mounted right above the nozzle):
* **Enable Retraction:** **Checked**
* **Retraction Distance:** **`1.0 mm`** (Range: `0.8 – 1.2 mm`)
  > ⚠️ **NEVER use Bowden settings (5–6 mm)!** Pulling molten plastic 5 mm up will freeze inside the cold heatbreak and cause a complete throat clog.
* **Retraction Speed:** **`25 mm/s`** (Marlin firmware limit)
* **Retract at Layer Change:** Checked
* **Combing Mode:** `Within Infill` (Reduces travel over finished surfaces)
* **Z Hop When Retracted:** `Disabled` (or `0.2 mm` if crossing delicate supports)

### ❄️ Cooling
* **Enable Print Cooling:** **Checked**
* **Fan Speed:** `100%`
* **Regular Fan Speed at Layer:** `3` (Fan off for layers 1 & 2 to prevent warping)

### 🧲 Build Plate Adhesion
* **Build Plate Adhesion Type:** 
  * Use **`Skirt`** (3 lines) if your bed is well-leveled and part has a large flat base.
  * Use **`Brim`** (5 mm width) if the part is tall, thin, or prone to corner warping.

---

## 4. Quick Checklist Before Hitting Print

1. **Clean the Bed:** Wipe the glass/sticker surface with Isopropyl Alcohol (IPA) or warm soapy water.
2. **Level the 4 Corners:** Slide a regular A4 sheet of paper under the nozzle at all 4 corners; adjust thumbwheels until you feel slight friction.
3. **Preheat via LCD:** Warm the bed to 60°C and nozzle to 200°C before starting to verify sensors.
4. **Watch Layer 1:** Stay with the machine for the first layer — if the line is squished flat and solid, the print will succeed!
