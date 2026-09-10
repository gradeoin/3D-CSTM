# Bravo Dual (RAMPS 1.4 + Arduino Mega 2560) Wiring & Circuit Blueprint

This document is the complete electrical and wiring reference for your custom **Bravo Dual 3D Printer**, based on your Arduino Mega 2560 + RAMPS 1.4 shield and RepRapDiscount 2004 Smart Controller.

---

## 1. Power Supply Star Distribution (Confirmed 4-Wire Independent Feeds)

The industrial 12V SMPS power supply uses a **dedicated Star Distribution** topology with **4 wires** leaving its DC output terminals (+V and -V/COM):

```
                                  ┌───► [ Pair A: 2 Heavy Wires ] ──► Makerbase MKS MOS25 (Bed Module)
[ 12V Industrial Power Supply ] ──┤
                                  └───► [ Pair B: 2 Heavy Wires ] ──► RAMPS 1.4 4-Pin Green Plug (5A Rail)
```

| Wire Pair | Origin (Power Supply) | Destination | Current / Role | Advantage |
| :--- | :--- | :--- | :--- | :--- |
| **Pair A (2 Wires)** | **+V** and **COM (-)** | **MKS MOS25 Module** (`DC IN`) | ~12–15A (High Power) | Feeds maximum current straight to the bed without passing through RAMPS. |
| **Pair B (2 Wires)** | **+V** and **COM (-)** | **RAMPS 1.4 Green Plug** (5A Pins) | ~3–5A (Logic/Motors) | Dedicated clean power for Arduino Mega, 5x DRV8825 drivers, and hotends. |

> [!NOTE]
> **Why this Star topology is superior:** When the heated bed draws 15 Amps, it causes zero voltage sag on the stepper motors or Arduino board because RAMPS has its own independent wire pair straight back to the power supply terminals!

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

## 5. Endstops (Confirmed 4 Mechanical Limit Switches)

Your printer features **4 snap-action mechanical limit switches** (kill switches) for axis homing and travel limits, plugged into the 3×6 endstop header pins on the top-right of RAMPS:

| Endstop Switch | Location on Machine | RAMPS Pin Header | Function |
| :--- | :--- | :--- | :--- |
| **X-Min (1)** | X-Axis Left Carriage | `X-MIN` (Pin 3) | Homes X axis to 0.00 mm (Triggered at home) |
| **Y-Min (1)** | Y-Axis Front Bed Frame | `Y-MIN` (Pin 14) | Homes Y axis to 0.00 mm (Triggered at home) |
| **Z-Min (1)** | Z-Axis Lower Gantry | `Z-MIN` (Pin 18) | Sets nozzle bed height reference (0.00 mm) |
| **Z-Max (1)** | Z-Axis Upper Top Frame | `Z-MAX` (Pin 19) | Emergency upper height ceiling / dual-Z alignment |

---

## 6. LCD & SD Card Display Wiring (Red L-Shaped Smart Adapter)

The **RepRapDiscount 2004 Smart Controller** connects directly to the top of the RAMPS board via its dedicated **Red L-Shaped Smart Adapter PCB**:

```
[ LCD 2004 Display Board ]
          │
          ├── [ EXP1 Ribbon Cable ] ──► Top Socket on Red Smart Adapter ──► (LCD Text, Knob, Buzzer)
          └── [ EXP2 Ribbon Cable ] ──► Bottom Socket on Red Smart Adapter ──► (SD Card SPI, Reset Button)
                                                 │
                                                 ▼
                              [ Red L-Shaped Smart Adapter PCB ]
                                                 │ (Plugs directly on top of)
                              [ RAMPS 1.4 AUX-3 & AUX-4 Headers ]
```

* **EXP1 Ribbon Cable:** Drives the 20×4 LCD text display, rotary click knob, and piezo beeper.
* **EXP2 Ribbon Cable:** Drives the full-size SD card reader SPI bus (MISO, MOSI, SCK, CS) and emergency Stop button.
* *Note:* If the LCD screen lights up blue but shows no text, the EXP1 and EXP2 cables are plugged in reversed.
