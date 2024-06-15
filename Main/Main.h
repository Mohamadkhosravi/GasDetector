
#ifndef _MAIN_H_
#define _MAIN_H_

#include <ht67f2432.h>
#include <Display.h>
#include <ADC.h>

// Control Buzzer
#define BUZZER_ON       _pa4= 1    // Turn the buzzer on (set port A, pin 4 high)
#define BUZZER_OFF      _pa4= 0    // Turn the buzzer off (set port A, pin 4 low)

// Control Green LED
#define LED_GREEN       _pc0       // Define LED_GREEN as port C, pin 0
#define LED_GREEN_ON    _pc0= 1    // Turn the green LED on (set port C, pin 0 high)
#define LED_GREEN_OFF   _pc0= 0    // Turn the green LED off (set port C, pin 0 low)

// Control Red LED
#define LED_RED_ON      _pc1= 1    // Turn the red LED on (set port C, pin 1 high)
#define LED_RED_OFF     _pc1= 0    // Turn the red LED off (set port C, pin 1 low)

// Control Yellow LED
#define LED_YELLOW_ON   _pc2= 1    // Turn the yellow LED on (set port C, pin 2 high)
#define LED_YELLOW_OFF  _pc2= 0    // Turn the yellow LED off (set port C, pin 2 low)

// Control Relay
#define RELAY_ON        _pb2= 1    // Turn the relay on (set port B, pin 2 high)
#define RELAY_OFF       _pb2= 0    // Turn the relay off (set port B, pin 2 low)

// Timer Interrupt Flag
#define TIMER_COUNTER_INTERRUPT    _tb0f  // Timer interrupt flag

// Pushbutton State
#define PRESSED_PUSHBUTTON         _pb3==0  // Check if the pushbutton is pressed (active low)

// Power Supply Connection States
#define POWER_SUPPLY_CONNECT     1    // Power supply is connected
#define POWER_SUPPLY_DISCONNECT  0    // Power supply is disconnected

// Voltage and Sensor Thresholds
#define MINIMUM_VOLTAGE_VALID   3300  // Minimum valid voltage (in mV)
#define THRESHOLD_DETECT_GAS    250   // Threshold for gas detection
#define VOLTAGE_LOW_BATTERY     3400  // Voltage indicating low battery (in mV)
#define PERCENTAGE_LOW_BATTERY  19    // Battery percentage indicating low battery
#define MINIMUM_CURRENT_SENSOR  5     // Minimum current sensor value

// Timing Constants
#define START_DELAY             15000  // Start delay (in ms)
#define START_BLINK_ON          1000   // Start blink on duration (in ms)
#define START_BLINK_OFF         2000   // Start blink off duration (in ms)
#define BATTERY_ERROR_BLINK_ON  1000   // Battery error blink on duration (in ms)
#define BATTERY_ERROR_BLINK_OFF 2000   // Battery error blink off duration (in ms)
#define SUPPLY_ERROR_BLINK_ON   1000   // Supply error blink on duration (in ms)
#define SUPPLY_ERROR_BLINK_OFF  2000   // Supply error blink off duration (in ms)
#define LOW_BATTERY_BLINK_ON    300    // Low battery blink on duration (in ms)
#define LOW_BATTERY_BLINK_OFF   600    // Low battery blink off duration (in ms)

// Display Values
#define TEST_DISPLAY_VIEW       8888  // Display value for testing
#define DETECT_DISPLAY_VIEW     THRESHOLD_DETECT_GAS  // Display value for gas detection

// Timeouts
#define TEST_TIMEOUT            1000  // Test timeout (in ms)
#define CHECK_BATTERY_TIMEOUT   500   // Battery check timeout (in ms)

// ADC and Battery Calculation Constants
#define AVDD                    5000.0            // Analog supply voltage (in mV)
#define COEFFICIENT             4.8875855327      // Coefficient for ADC conversion (AVDD/1023.0)
#define b                       338.421           // Constant for battery percentage calculation
#define a                       0.105263          // Slope for battery percentage calculation
#define BATTERY_PERSENTAGE(VoltageBattery)(a*VoltageBattery-b)  // Macro to calculate battery percentage

// Variable Declarations
float voltage_battery = 0;        // Variable to store battery voltage
char displayClock = 0;            // Variable for display clock
char bufferVdd = 0;               // Buffer for Vdd value
unsigned short GasValue = 0;      // Variable to store gas sensor value
bit pushButtonState = 0;          // Variable to store pushbutton state
unsigned int pushButtonCounter = 0; // Counter for pushbutton press duration

// Union for Parameters
typedef union parameter{
    unsigned int Counter;         // Counter parameter
} Parameters;
Parameters Parameter;

// Mode Enumeration
typedef enum {
    NORMAL,
    CHECK_BATTERY,
    TEST,
    DETECT,
    SENSOR_ERROR
} mode;
mode Mode;

// Supply Mode Enumeration
typedef enum {
    NORMAL_POWER, 
    BATTERY_ERROR,
    SUPPLY_ERROR,
    LOW_BATTERY
} SupplyMode;
SupplyMode SupplyStatus;

// Function Prototypes
void buzzerDull(short *Counter);                  // Function to control the buzzer
void initializeSystem();                          // Function to initialize the system
void initializePorts();                           // Function to initialize ports
void handleTestMode();                            // Function to handle test mode
void handleCheckBatteryMode();                    // Function to handle check battery mode
void handleDetectMode();                          // Function to handle detect mode
void handleSensorErrorMode();                     // Function to handle sensor error mode
void normalPowerHandler(void);                    // Handler for normal power mode
void batteryErrorHandler(void);                   // Handler for battery error mode
void supplyErrorHandler(void);                    // Handler for supply error mode
void lowBatteryHandler(void);                     // Handler for low battery mode
char batteryPercentage(char percentOfBattery);    // Function to calculate battery percentage
/*void initializeTimers();*/
//SupplyMode handleSupplyStatus();
/*void PowerSuplyManagemante( SupplyMode *SupplyStatus,int *displayClock);*/
/*char batteryPercentage(float *voltage_battery);*/
//typedef void (*SupplyManage[4])(void);
//SupplyManage supplyHandlers = {normalPowerHandler, batteryErrorHandler, supplyErrorHandler, lowBatteryHandler};
 
 
 
 
 
#endif