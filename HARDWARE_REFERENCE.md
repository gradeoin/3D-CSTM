# RAMPS 1.4 & Arduino Mega 2560 Hardware Reference

This reference manual documents the low-level hardware pin mappings, motor driver VREF tuning, and diagnostic procedures for the **Bravo Dual (RAMPS 1.4 + Arduino Mega 2560)**.

---

## 1. Arduino Mega 2560 to RAMPS 1.4 Pin Mapping

In Marlin firmware, the pins are assigned according to `pins_RAMPS.h`. Below is the master lookup table:

### High-Power MOSFET Outputs
| Function | Physical RAMPS Terminal | ATmega2560 Digital Pin | PWM Capable | Notes |
| :--- | :--- | :--- | :--- | :--- |
| **Hotend 1 Heater (T0)** | **D10** | `PIN 10` | Yes | 12V ~3.5A heater cartridge |
| **Hotend 2 Heater (T1)** | **D9** | `PIN 9` | Yes | 12V ~3.5A heater cartridge |
| **Heated Bed** | **D8** | `PIN 8` | Yes | 12V ~11A high-current MOSFET |

### Stepper Motor Pins
| Axis | Step Pin | Direction Pin | Enable Pin | Notes |
| :--- | :--- | :--- | :--- | :--- |
| **X Axis** | `PIN 54` (A0) | `PIN 55` (A1) | `PIN 38` | Low = Enabled |
| **Y Axis** | `PIN 60` (A6) | `PIN 61` (A7) | `PIN 56` (A2) | Low = Enabled |
| **Z Axis** | `PIN 46` | `PIN 48` | `PIN 62` (A8) | Low = Enabled |
| **Extruder 0 (E0)**| `PIN 26` | `PIN 28` | `PIN 24` | Low = Enabled |
| **Extruder 1 (E1)**| `PIN 36` | `PIN 34` | `PIN 30` | Low = Enabled |

### Temperature Sensors (Analog Pins)
| Sensor | RAMPS Header | ATmega2560 Analog Pin | Sensor Type |
| :--- | :--- | :--- | :--- |
| **Hotend 1 (T0)** | `T0` | `PIN 67` (Analog 13) | 100k NTC 3950 |
| **Hotend 2 (T1)** | `T1` | `PIN 69` (Analog 15) | 100k NTC 3950 |
| **Heated Bed** | `T2` | `PIN 68` (Analog 14) | 100k NTC 3950 |

### Limit Switches (Endstops)
| Endstop | RAMPS Header | ATmega2560 Digital Pin | Pullup |
| :--- | :--- | :--- | :--- |
| **X-Min** | `X-MIN` | `PIN 3` | Internal Pullup (Triggered = LOW) |
| **Y-Min** | `Y-MIN` | `PIN 14` | Internal Pullup (Triggered = LOW) |
| **Z-Min** | `Z-MIN` | `PIN 18` | Internal Pullup (Triggered = LOW) |

---

## 2. Stepper Driver Tuning (VREF Calculation)

> [!NOTE]
> **CONFIRMED HARDWARE:** All 5 stepper driver slots (X, Y, Z, E0, E1) on your RAMPS 1.4 board are equipped with **Texas Instruments DRV8825** (Purple PCB) modules running at **1/32 microstepping**! This explains why your steps/mm are doubled (160 steps/mm for X/Y and 800 steps/mm for Z).

### For DRV8825 Drivers (Purple PCB):
Formula:
$$V_{REF} = \frac{I_{max}}{2} \quad \Longleftrightarrow \quad I_{max} = 2 \times V_{REF}$$

* Your boards feature the **`R250`** / `0.250 Ω` current sense resistors.
* For typical NEMA 17 motors running at ~0.9A to 1.0A:
  * **Recommended $V_{REF}$:** **`0.45 V – 0.55 V`**
* **Key Specs:**
  * Microstepping: Up to **1/32 microstep** (smoother and quieter than A4988)
  * Peak Current: Up to **2.5A** with heatsink
  * 4-layer PCB with exposed thermal ground pad ("cooling pads") for heat dissipation.

> [!CAUTION]
> When measuring $V_{REF}$ with a multimeter: Put the red probe on the metal screw of the trimpot and black probe on DC Ground (or power supply -V). Use a ceramic or insulated screwdriver to prevent short-circuiting adjacent driver pins!

---

## 3. How to Compile & Flash the Source Code (Offline or Online)

You now have the full source tree in `Marlin-2.0.9.7/`. You can compile it using either:

### Method A: VS Code + PlatformIO (Recommended)
1. Install **VS Code** and open the `Marlin-2.0.9.7` folder.
2. Install the **PlatformIO IDE** extension.
3. PlatformIO will automatically detect the board as `mega2560`.
4. Click the checkmark icon (`✓`) in the bottom status bar to **Build**.
5. Plug in the USB cable and click the arrow icon (`→`) to **Upload**.

### Method B: Arduino IDE
1. Open the Arduino IDE.
2. Go to **File > Open** and open `Marlin-2.0.9.7/Marlin/Marlin.ino`.
3. Under **Tools**:
   * **Board:** `Arduino Mega or Mega 2560`
   * **Processor:** `ATmega2560 (Mega 2560)`
   * **Port:** `COM8`
4. Click **Verify** (Compile) or **Upload**.
