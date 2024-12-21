
# Project Documentation: Gas Detector System with Battery and Supply Management

## Table of Contents
1. **Project Overview**
2. **Hardware Components**
    - MQ9 Gas Sensor
    - Buzzer (PA4)
    - LEDs (Green, Red, Yellow)
    - Relay (PB2)
    - Pushbutton (PB3)
    - ADC Channels
3. **Key Macros and Constants**
    - Control Macros for Hardware Components
    - Power Supply Connection
    - Voltage and Threshold Constants
    - Timing Constants
    - ADC Channels
4. **Struct Definitions**
    - Parameters Struct
5. **Modes of Operation**
    - System Modes
6. **Functions**
    - startLoading()
    - buzzerDull()
    - initializeSystem()
    - initializePorts()
    - handleTestMode()
    - handleCheckBatteryMode()
    - handleDetectMode()
    - handleSensorErrorMode()
    - normalPowerHandler()
    - batteryErrorHandler()
    - supplyErrorHandler()
    - lowBatteryHandler()
7. **Power and Battery Management**
    - Battery Percentage Calculation
    - Supply Mode
8. **Interfacing with the MQ9 Gas Sensor**
    - Sensor Initialization
    - Reading Sensor Value
    - Gas Detection Threshold
9. **Modes of Operation - Detailed Flow**
    - Normal Mode
    - Battery Check Mode
    - Test Mode
    - Gas Detection Mode
10. **Error Handling**
    - Sensor Error Detection
    - Power Supply Error
11. **Interrupt Handling and Delays**
    - Timer Interrupt for ADC Sampling
    - Button Press Interrupt
12. **Code Organization and Modularity**
13. **Future Improvements**

## Overview

This project is designed for a gas detection system that interfaces with various hardware components, such as sensors (MQ9 for gas detection), LEDs, buzzers, and relays. The system monitors the battery and power supply status, indicating errors and status changes through visual feedback (LEDs) and auditory signals (buzzer). The device is powered by a lithium battery with charging control features, and it performs sensor readings through an ADC.

---

## Hardware Components

- **MQ9 Gas Sensor**: Detects gas levels and triggers a response if a certain threshold is reached.
- **Buzzer (PA4)**: Provides an auditory alarm when gas is detected or for error indications.
- **LEDs**: 
  - **Green LED (PC0)**: Indicates normal operation.
  - **Red LED (PC1)**: Indicates an error or an issue.
  - **Yellow LED (PC2)**: Used for additional feedback, such as battery issues.
- **Relay (PB2)**: Used to control external devices or act as an alarm relay when gas is detected.
- **Pushbutton (PB3)**: Allows user interaction with the device for modes like testing and battery checking.
- **ADC Channels**: The system uses several ADC channels to measure voltage levels (battery, gas sensor, etc.).

---

## Key Macros and Constants

### Control Macros for Hardware Components
- **BUZZER_ON**: Turns on the buzzer (PA4 high).
- **BUZZER_OFF**: Turns off the buzzer (PA4 low).
- **LED_GREEN_ON**: Turns on the green LED (PC0 high).
- **LED_GREEN_OFF**: Turns off the green LED (PC0 low).
- **LED_RED_ON**: Turns on the red LED (PC1 high).
- **LED_RED_OFF**: Turns off the red LED (PC1 low).
- **LED_YELLOW_ON**: Turns on the yellow LED (PC2 high).
- **LED_YELLOW_OFF**: Turns off the yellow LED (PC2 low).
- **RELAY_ON**: Turns on the relay (PB2 high).
- **RELAY_OFF**: Turns off the relay (PB2 low).
- **CHARGE_BATTERY_CONTROL**: Controls the battery charging (PA3).

### Power Supply Connection
- **POWER_SUPPLY_CONNECT**: Checks if the power supply is connected (PA6 high).

### Voltage and Threshold Constants
- **VOLTAGE_INVALID_BATTERY**: Threshold for invalid battery voltage (4350mV).
- **MINIMUM_VOLTAGE_VALID**: Minimum valid battery voltage (3300mV).
- **VOLTAGE_LOW_BATTERY**: Threshold for low battery (3400mV).
- **THRESHOLD_DETECT_GAS**: Gas detection threshold (250).
- **PERCENTAGE_LOW_BATTERY**: Percentage indicating low battery (19%).

### Timing Constants
- **START_DELAY**: Start delay (in milliseconds).
- **START_BLINK_ON**: Time the start blink LED stays on.
- **START_BLINK_OFF**: Time the start blink LED stays off.

### ADC Channels
- **ADC_CHANNEL_GAS**: Channel used for gas sensor readings (channel 0).
- **ADC_CHANNEL_SENSOR**: Channel for additional sensors (channel 1).
- **ADC_CHANNEL_BATTERY**: Channel used to measure battery voltage (channel 2).

---

## Struct Definitions

### Parameters Struct
This struct holds various parameters related to the system's state, including battery information, gas readings, and user input.

```c
typedef struct Parameters {
    float VoltageBattery;       // Battery voltage in millivolts
    unsigned char BatteryPercentage; // Battery percentage
    unsigned short GasValue;    // Gas sensor value
    unsigned short PushButtonCounter; // Counter for button presses
    unsigned char DisplayClock;  // Used for display management
} Parameters;
```

The struct is instantiated as `parameter` and used throughout the program.

---

## Modes of Operation

### System Modes
The system operates in the following modes:

1. **NORMAL**: The system is running normally, monitoring gas levels, battery status, and performing regular functions.
2. **CHECK_BATTERY**: This mode checks the battery voltage and determines if the system needs charging or if the battery is low.
3. **TEST**: The system runs a self-test to verify that the hardware components (e.g., LEDs, buzzer) are functioning properly.
4. **DETECT**: The system is actively detecting gas levels and can trigger the buzzer and relay if gas is detected above a threshold.
5. **SENSOR_ERROR**: This mode is activated when a sensor error occurs, signaling a problem with the sensor.

---

## Functions

### `startLoading()`
Initializes the loading sequence of the system. It likely handles delays and prepares the system for operation.

### `buzzerDull(short *Counter)`
Controls the buzzer in a dull mode. The `Counter` pointer is used to manage the duration or frequency of buzzer activity.

### `initializeSystem()`
Initializes all the system settings, including hardware setup (ports, ADC, timers).

### `initializePorts()`
Sets up the input/output ports, configuring pins for the LEDs, buzzer, and other peripherals.

### `handleTestMode()`
Handles the test mode, ensuring that all hardware components (like LEDs and buzzer) are functional.

### `handleCheckBatteryMode(char *percentageBattery)`
Monitors battery voltage and checks whether it falls within acceptable levels.

### `handleDetectMode()`
Activates the gas detection system, reading the gas sensor and triggering the buzzer/relay as needed.

### `handleSensorErrorMode()`
Manages scenarios where a sensor error is detected, ensuring the system responds appropriately (e.g., activating error LEDs).

### `normalPowerHandler()`
Handles normal power operation. Ensures the system remains operational and efficiently manages resources.

### `batteryErrorHandler()`
Handles scenarios where there is a battery error, such as a very low or invalid battery voltage.

### `supplyErrorHandler()`
Handles power supply errors, including issues with the external power source or charging circuit.

### `lowBatteryHandler()`
Monitors battery status and responds when the battery is low, such as turning on the low battery LED or activating the buzzer.

---

## Power and Battery Management

### Battery Percentage Calculation
The system calculates battery percentage based on the battery voltage using the following formula:

```c
#define BATTERY_PERCENTAGE(VoltageBattery) (a * VoltageBattery - b)
```

Where `a` and `b` are constants derived from the battery's voltage curve.

### Supply Mode
The system distinguishes between different supply modes:
- **NORMAL_POWER**: Normal operation when the battery and power supply are within safe levels.
- **BATTERY_ERROR**: Indicates that there is a problem with the battery.
- **SUPPLY_ERROR**: Indicates an issue with the external power supply.
- **LOW_BATTERY**: Triggers when the battery voltage is too low for proper operation.

The `handleSupplyStatus()` function handles switching between these supply modes.

---

## Interfacing with the MQ9 Gas Sensor

### Sensor Initialization
The MQ9 gas sensor is initialized using specific ADC channels to monitor gas levels.

### Reading Sensor Value
The system reads the ADC value from the MQ9 sensor to determine gas concentration.

### Gas Detection Threshold
If the gas concentration exceeds a predefined threshold, the system activates the buzzer and relay.

---

## Modes of Operation - Detailed Flow

### Normal Mode
In this mode, the system operates normally, continuously monitoring the gas levels and battery voltage.

### Battery Check Mode
This mode checks the battery voltage to ensure the device is operating with a valid and safe battery level.

### Test Mode
The system performs a self-test to verify the functionality of the hardware components.

### Gas Detection Mode
The system detects gas concentration and activates the buzzer and relay if the concentration exceeds a certain threshold.

---

## Error Handling

### Sensor Error Detection
When a sensor error is detected, the system handles it by activating appropriate error LEDs.

### Power Supply Error
In case of power supply failure, the system ensures safety measures are implemented and user feedback is given through LEDs or buzzer.
