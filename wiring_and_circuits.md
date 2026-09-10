# Bravo Dual (RAMPS 1.4 + Arduino Mega 2560) Wiring & Circuit Blueprint

This document is the complete electrical and wiring reference for your custom **Bravo Dual 3D Printer**, based on your Arduino Mega 2560 + RAMPS 1.4 shield and RepRapDiscount 2004 Smart Controller.

---

## 1. Power Supply Wiring (SMPS to RAMPS 1.4)

The industrial switching power supply (SMPS) connects to the **green 4-pin screw terminal block** on the bottom-left edge of the RAMPS 1.4 board.

| Power Supply Terminal | RAMPS 1.4 Terminal | Wire Gauge / Role | Notes |
| :--- | :--- | :--- | :--- |
| **+V** (12V) | **5A (+) Input** | 16–18 AWG | Powers logic, stepper motors, and hotends |
| **-V / COM** (GND) | **5A (-) Ground** | 16–18 AWG | Ground return for 5A rail |
| **+V** (12V) | **11A (+) Input** | 14 AWG (Thick) | Dedicated high-current rail for Heated Bed |
| **-V / COM** (GND) | **11A (-) Ground** | 14 AWG (Thick) | Ground return for Heated Bed |

> [!WARNING]
> Never reverse the polarity (+ and -). Reversing 12V and Ground will instantly blow the polyfuses and diode D1 on the RAMPS board.

---

## 2. External Heated Bed MOSFET Module Wiring (Confirmed 6-Wire Hookup)

Your printer features an external high-power MOSFET expansion module to isolate the heated bed current from the RAMPS board. It has exactly **6 wires**:

```
                       ┌─────────────────────────────────────────┐
[ 12V Power Supply ] ──┤ Power Input (+/-)                       │
  (2 heavy wires)      │                                         │
                       │    EXTERNAL HIGH-POWER MOSFET MODULE    │── [ Heated Bed Element ]
[ RAMPS D8 Output ]  ──┤ Control/Trigger Input (Signal +/-)      │     (2 wires: Red & Black)
  (2 signal wires)     │                                         │
                       └─────────────────────────────────────────┘
```

| Pair | Connection From | Connection To | Wire Type / Colors | Function |
| :--- | :--- | :--- | :--- | :--- |
| **1 & 2** | **12V Power Supply** (+V / COM) | **Power In** on MOSFET module | Heavy gauge | Delivers full high-current DC power directly from PSU |
| **3 & 4** | **RAMPS 1.4 D8 Terminal** | **Control Input** on MOSFET module | Thin signal wires | Low-current switching signal from Marlin firmware |
| **5 & 6** | **Bed Output** on MOSFET module | **Heated Bed Element** | Red (+) & Black (-) | Carries switched high current to heat the bed |

---

## 3. High-Power Outputs on RAMPS 1.4 (D10, D9, D8)

| Terminal | Function in Dual Extruder Mode (`EEB`) | Voltage / Current |
| :--- | :--- | :--- |
| **D10** | **Hotend 1 Heater Cartridge (T0)** | 12V, ~3.5A (40W) |
| **D9** | **Hotend 2 Heater Cartridge (T1)** | 12V, ~3.5A (40W) |
| **D8** | **Trigger Signal to External MOSFET** | 12V signal level (low mA) |

---

## 3. Stepper Motor Connections (4-Pin Headers)

RAMPS 1.4 has 5 stepper driver sockets (X, Y, Z, E0, E1). Each socket has a 4-pin header for the stepper motor cable:

| Driver Slot | Controlled Axis | Cable Colors (Typical GT2/NEMA 17) | Notes |
| :--- | :--- | :--- | :--- |
| **X** | X-Carriage (Left/Right) | Red, Blue, Green, Black (2 coil pairs) | 160.00 steps/mm |
| **Y** | Y-Bed (Front/Back) | Red, Blue, Green, Black | 160.00 steps/mm |
| **Z** | Z-Axis Lead Screws | Red, Blue, Green, Black | 800.00 steps/mm (RAMPS has two parallel 4-pin Z headers) |
| **E0** | Extruder 1 Motor | Red, Blue, Green, Black | 180.00 steps/mm |
| **E1** | Extruder 2 Motor | Red, Blue, Green, Black | 180.00 steps/mm |

> [!IMPORTANT]
> Never plug or unplug stepper motor cables while the power supply is turned on. Doing so creates back-EMF voltage spikes that instantly destroy the stepper driver chips (A4988 / DRV8825).

---

## 4. Temperature Sensors (Thermistors - 2-Pin Headers)

Located in the 6-pin bank marked `T0`, `T1`, `T2`:

| Pin Header | Sensor Function | Typical Sensor Type | Polarity |
| :--- | :--- | :--- | :--- |
| **T0** | **Hotend 1 Thermistor** | 100k NTC 3950 | No polarity (reversable) |
| **T1** | **Hotend 2 Thermistor** | 100k NTC 3950 | No polarity |
| **T2** | **Heated Bed Thermistor** | 100k NTC 3950 | No polarity |

---

## 5. Endstops (Limit Switches - 3-Pin Headers)

Located on the top-right edge in a 3×6 pin grid (Signal, GND, VCC). Standard 3D printers only use **Signal** and **GND**:

| Header | Axis | Default Trigger State |
| :--- | :--- | :--- |
| **X-Min** | X Axis Left Home | Triggered when carriage hits left limit switch |
| **Y-Min** | Y Axis Bed Front Home | Triggered when bed moves to front switch |
| **Z-Min** | Z Axis Bed Bottom Home | Triggered when nozzle reaches bed height |

---

## 6. LCD & SD Card Display Ribbon Cables

The **RepRapDiscount 2004 Smart Controller** connects via the L-shaped "Smart Adapter" plugged into the AUX-3 and AUX-4 headers:

* **EXP1 Ribbon Cable:** Drives the LCD text display, rotary encoder knob, and beeper.
* **EXP2 Ribbon Cable:** Drives the full-size SD card reader SPI bus (MISO, MOSI, SCK, CS) and the Stop/Kill button.
* *Note:* If the LCD lights up blue but displays no text, EXP1 and EXP2 are plugged in reversed.
