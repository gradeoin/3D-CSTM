/**
 * Marlin 3D Printer Firmware Configuration Backup
 * Reconstructed from EEPROM & Firmware Telemetry
 * Machine: Bravo Dual
 * Author: (Syed, Bravo Dual)
 * Date Extracted: 2026-09-10
 */

#pragma once

#define CONFIGURATION_H_VERSION 02000907

#define STRING_CONFIG_H_AUTHOR "(Syed, Bravo Dual)"
#define CUSTOM_MACHINE_NAME "Bravo Dual"

#define SERIAL_PORT 0
#define BAUDRATE 250000

#ifndef MOTHERBOARD
  #define MOTHERBOARD BOARD_RAMPS_14_EEB
#endif

// Extruders
#define EXTRUDERS 2
#define DEFAULT_NOMINAL_FILAMENT_DIA 1.75

// Thermal Settings
#define TEMP_SENSOR_0 1
#define TEMP_SENSOR_1 1
#define TEMP_SENSOR_BED 1

#define HEATER_0_MINTEMP   5
#define HEATER_0_MAXTEMP 275
#define HEATER_1_MINTEMP   5
#define HEATER_1_MAXTEMP 275
#define BED_MINTEMP        5
#define BED_MAXTEMP      120

#define PREVENT_COLD_EXTRUSION
#define EXTRUDE_MINTEMP 170

// PID Settings (Queried from M301)
#define PIDTEMP
#define DEFAULT_Kp 22.20
#define DEFAULT_Ki  1.08
#define DEFAULT_Kd 114.00

// Kinematics & Bed Size (Queried from M211)
#define X_BED_SIZE 275
#define Y_BED_SIZE 240
#define Z_MAX_POS  200

#define X_MIN_POS 0
#define Y_MIN_POS 0
#define Z_MIN_POS 0

// Endstops
#define USE_XMIN_PLUG
#define USE_YMIN_PLUG
#define USE_ZMIN_PLUG

// Stepper Drivers (Texas Instruments DRV8825 at 1/32 microstepping)
#define X_DRIVER_TYPE  DRV8825
#define Y_DRIVER_TYPE  DRV8825
#define Z_DRIVER_TYPE  DRV8825
#define E0_DRIVER_TYPE DRV8825
#define E1_DRIVER_TYPE DRV8825

// Motion Steps (Queried from M92)
#define DEFAULT_AXIS_STEPS_PER_UNIT   { 160.0, 160.0, 800.0, 180.0 }

// Maximum Feedrates (Queried from M203 in mm/s)
#define DEFAULT_MAX_FEEDRATE          { 300, 300, 5, 25 }

// Accelerations (Queried from M201 & M204 in mm/s^2)
#define DEFAULT_MAX_ACCELERATION      { 3000, 3000, 100, 10000 }
#define DEFAULT_ACCELERATION          1000
#define DEFAULT_RETRACT_ACCELERATION  3000
#define DEFAULT_TRAVEL_ACCELERATION   3000

// Junction Deviation (Queried from M205)
#define CLASSIC_JERK
#define JUNCTION_DEVIATION_MM 0.01

// Tool Offsets (Queried from M218)
#define HOTEND_OFFSET_X { 0.0, 0.0 }
#define HOTEND_OFFSET_Y { 0.0, 0.0 }
#define HOTEND_OFFSET_Z { 0.0, 0.0 }

// Tool Change
#define TOOLCHANGE_ZRAISE 2.0

// Controller & Display
#define REPRAP_DISCOUNT_SMART_CONTROLLER
#define SDSUPPORT
#define EEPROM_SETTINGS
