#include <Main.h>
//00H to 13H

// Main function
void main() {
	
  
    // Initialize system and ports
    initializeSystem();
    initializePorts();
    S_ADC_Init();   // Initialize ADC
    BUZZER_OFF;         // Turn off the buzzer     
    startLoading();
    // Initial states
    BUZZER_OFF;         // Turn off the buzzer
    LED_GREEN_OFF;      // Turn off the green LED
    LED_RED_OFF;        // Turn off the red LED
    LED_YELLOW_OFF;     // Turn off the yellow LED
    RELAY_ON;           // Turn on the relay
	parameter.PushButtonCounter=0;
	parameter.DisplayClock=0;
    Mode = NORMAL;           // Set mode to normal
    SupplyStatus=NORMAL_POWER;
    // Main loop
    while (1) 
    {
        // Read battery voltage
        parameter.VoltageBattery = COEFFICIENT *S_READ_ADC(ADC_CHANNEL_BATTERY); // Read ADC value for battery voltage and apply coefficient
        parameter.DisplayClock++;       // Increment display clock
        if (parameter.DisplayClock >= DISPLAY_DIGIT) parameter.DisplayClock = 0; // Reset display clock if it exceeds 4
        // Check sensor values
        if (S_READ_ADC(ADC_CHANNEL_SENSOR) < MINIMUM_CURRENT_SENSOR) 
        { 
            Mode = SENSOR_ERROR; // Set mode to sensor error if current sensor value is below minimum
        } 
        else if (S_READ_ADC(ADC_CHANNEL_GAS) > THRESHOLD_DETECT_GAS) 
        {
             Mode = DETECT;       // Set mode to detect if gas value exceeds threshold
        } 
        else 
        {
            // Check pushbutton state
            if (PRESSED_PUSHBUTTON) 
            {
                pushButtonState = 1;  // Set push button state to pressed
                parameter.PushButtonCounter++;  // Increment push button counter
            } 
            else 
            {
                if ((pushButtonState == 1) && (parameter.PushButtonCounter > LONG_PERRESS)) 
                {
                    Mode = TEST;  // Set mode to test if push button was pressed for more than 500 counts
                }
                else if ((pushButtonState == 1) && (parameter.PushButtonCounter < LONG_PERRESS) && (parameter.PushButtonCounter > MINIMUM_PREESS_VALID)) 
                {
                    Mode = CHECK_BATTERY; // Set mode to check battery if push button was pressed for less than 500 counts but more than 10
                    parameter.BatteryPercentage = batteryPercentage(BATTERY_PERCENTAGE(parameter.VoltageBattery)); // Calculate battery percentage
                }
            }
        }
       
  
        if(parameter.VoltageBattery>=VOLTAGE_INVALID_BATTERY)parameter.VoltageBattery=0;
	    if (POWER_SUPPLY_CONNECT) 
		{
		    SupplyStatus = (parameter.VoltageBattery >= MINIMUM_VOLTAGE_VALID) ? NORMAL_POWER : BATTERY_ERROR;
		}
		else 
		{
			if((SupplyStatus==NORMAL_POWER)||(SupplyStatus==BATTERY_ERROR))
		   	SupplyStatus = (parameter.VoltageBattery <= VOLTAGE_LOW_BATTERY) ? LOW_BATTERY : SUPPLY_ERROR;

			if(SupplyStatus==LOW_BATTERY)
			{
				
			  if(parameter.VoltageBattery >= HYSTERESIS_THRESHOLD_UPPER)--counter;
			  else counter =HYSTERESIS_THRESHOLD_COUNTER;
			  if(!counter) SupplyStatus=SUPPLY_ERROR,counter =HYSTERESIS_THRESHOLD_COUNTER;
			}
			if(SupplyStatus==SUPPLY_ERROR)
			{
			 if(parameter.VoltageBattery <= HYSTERESIS_THRESHOLD_LOWER)--counter;
			 else counter = HYSTERESIS_THRESHOLD_COUNTER;
			 if(!counter) SupplyStatus=LOW_BATTERY,counter =HYSTERESIS_THRESHOLD_COUNTER;
			}
		}

	
        // Mode handling
        switch (Mode) {
            case NORMAL:
                // Update gas value if significant change
                if (abs((S_READ_ADC(ADC_CHANNEL_GAS) - parameter.GasValue)) >= 2)
                {
                    parameter.GasValue = S_READ_ADC(ADC_CHANNEL_GAS); // Update gas value 
                }
                // Handle power supply status
                //switch (handleSupplyStatus()){
                switch (SupplyStatus){
                	
	                case NORMAL_POWER:
	                	normalPowerHandler();  // Handle normal power mode
	                break;
	
	                case BATTERY_ERROR:
	                	batteryErrorHandler(); // Handle battery error mode
	                break;
	
	                case SUPPLY_ERROR:
	                	supplyErrorHandler();  // Handle supply error mode
	                break;
	
	                case LOW_BATTERY:
	                	lowBatteryHandler();   // Handle low battery mode
	                break;
                }
            break;

            case TEST:
              handleTestMode();  // Handle test mode
            break;

            case CHECK_BATTERY:
              handleCheckBatteryMode(&parameter.BatteryPercentage); // Handle check battery mode
            break;

            case DETECT:
                handleDetectMode(); // Handle detect mode
            break;

            case SENSOR_ERROR:
                handleSensorErrorMode(); // Handle sensor error mode
            break;
        }
    }
}

// Function to handle test mode
void handleTestMode(void) {
   static int counter = 0;
    counter++;
    BUZZER_ON;             // Turn on the buzzer
    RELAY_ON;              // Turn on the relay
    LED_RED_ON;            // Turn on the red LED
    LED_GREEN_ON;          // Turn on the green LED
    LED_YELLOW_ON;         // Turn on the yellow LED
    Display(TEST_DISPLAY_VIEW, '0', &parameter.DisplayClock); // Display test view
    pushButtonState = 0;   // Reset push button state
    parameter.PushButtonCounter = 0; // Reset push button counter

    if (counter > TEST_TIMEOUT) {
        counter = 0;      // Reset counter
        BUZZER_OFF;       // Turn off the buzzer
        LED_GREEN_OFF;    // Turn off the green LED
        LED_RED_OFF;      // Turn off the red LED
        LED_YELLOW_OFF;   // Turn off the yellow LED
        Mode = NORMAL;    // Set mode to normal
    }
}

// Function to handle check battery mode
void handleCheckBatteryMode(char *persentageBattery) {
  static int counter = 0;
    counter++;
    if (*persentageBattery <= PERCENTAGE_LOW_BATTERY) {
        //DisplayBatteryLOW(parameter.DisplayClock); // Display low battery if percentage is below threshold
          DisplayError('L',parameter.DisplayClock);
    } else {
        Display(*persentageBattery, 'b', &parameter.DisplayClock); // Display battery percentage
    }

    pushButtonState = 0;   // Reset push button state
    parameter.PushButtonCounter = 0; // Reset push button counter

    if (counter > CHECK_BATTERY_TIMEOUT) {
        Mode = NORMAL;     // Set mode to normal
        counter = 0;       // Reset counter
    }
}


void startLoading(void)
{
  static unsigned int  DelayCounter = START_DELAY; // Set push button counter to start delay
  static unsigned int  Counter=0;
    // Start-up sequence
    do {
        --DelayCounter;  // Decrement push button counter
       Counter++;  // Increment parameter counter

        // Blinking LEDs during start delay
        if (Counter < START_BLINK_ON) {
            LED_GREEN_ON;     // Turn on the green LED
            LED_YELLOW_ON;    // Turn on the yellow LED
            LED_RED_ON;       // Turn on the red LED
        } else {
            LED_GREEN_OFF;    // Turn off the green LED
            LED_YELLOW_OFF;   // Turn off the yellow LED
            LED_RED_OFF;      // Turn off the red LED
        }

        if (Counter > START_BLINK_OFF) {
            Counter = 0; 
            parameter.DisplayClock++;         // Increment display clock
        }

        // Display loading sequence
		int i =8;
		for ( i = 8; i > 0; i--)
		{
		  DisplayLoading(parameter.DisplayClock - i);
		}

        if (parameter.DisplayClock > 7) {
            Counter= 0;  // Reset parameter counter
            parameter.DisplayClock = 0;       // Reset display clock
        }

    } while (DelayCounter); // Continue until push button counter is zero

    // Reset counters and set initial mode
    DelayCounter=0;
    Counter = 0;   // Reset parameter counter
    parameter.DisplayClock = 0;        // Reset display clock	
	

}

// Function to handle gas detection mode
void handleDetectMode(void) {
    BUZZER_ON;             // Turn on the buzzer
    RELAY_ON;              // Turn on the relay
    LED_RED_ON;            // Turn on the red LED
    LED_GREEN_ON;          // Turn on the green LED
    LED_YELLOW_ON;         // Turn on the yellow LED
    Display(DETECT_DISPLAY_VIEW, '0', &parameter.DisplayClock); // Display gas detection view
}

// Function to handle sensor error mode
void handleSensorErrorMode(void) {
    BUZZER_ON;             // Turn on the buzzer
    RELAY_ON;              // Turn on the relay
    LED_RED_ON;            // Turn on the red LED
    LED_GREEN_ON;          // Turn on the green LED
    LED_YELLOW_ON;         // Turn on the yellow LED
   // DisplaySensorError(parameter.DisplayClock); // Display sensor error
    DisplayError('S',parameter.DisplayClock);
}

// Function to calculate battery percentage
char batteryPercentage(char percentOfBattery) {
    static char buffer = 0;
    if (percentOfBattery > 95) {
        percentOfBattery = 100; // Cap battery percentage at 100
    } else if (percentOfBattery <= 19) {
        percentOfBattery = 0;   // Set battery percentage to 0 if below threshold
    }
    buffer = percentOfBattery;
    if (abs(percentOfBattery - buffer) >= 10) {
        buffer = percentOfBattery; // Update buffer if significant change
    }
    return buffer;
}

// Function to handle normal power mode
void normalPowerHandler(void) {
    static int Counter=0; 
	BUZZER_OFF;
    LED_GREEN_ON;          // Turn on the green LED
    LED_RED_OFF;           // Turn off the red LED
    LED_YELLOW_OFF;        // Turn off the yellow LED
    Display(parameter.GasValue, '0', &parameter.DisplayClock); // Display gas value
   // Display(parameter.VoltageBattery, '0', &parameter.DisplayClock); // Display VoltageBattery value
}

// Function to handle battery error mode
void batteryErrorHandler(void) {
    static int Counter =BATTERY_ERROR_BLINK_OFF;
    LED_GREEN_OFF;         // Turn off the green LED
    LED_RED_OFF;           // Turn off the red LED
    LED_YELLOW_ON;         // Turn on the yellow LED
    ++Counter;
    if (Counter < BATTERY_ERROR_BLINK_ON) {
    	
        Display(parameter.GasValue, '0', &parameter.DisplayClock); // Display gas value
    } else 
    {
       // DisplayBatteryError(parameter.DisplayClock);// Display low battery 
          DisplayError('b',parameter.DisplayClock);
    }
    buzzerDull(&Counter); // Handle buzzer dull
    if (Counter > BATTERY_ERROR_BLINK_OFF)
        Counter = 0;      // Reset counter
}

// Function to handle supply error mode
void supplyErrorHandler(void) {
    static int Counter = 0;
    LED_GREEN_OFF;         // Turn off the green LED
    LED_RED_OFF;           // Turn off the red LED
    LED_YELLOW_ON;         // Turn on the yellow LED
    ++Counter;
    if (Counter < SUPPLY_ERROR_BLINK_ON) {
        Display(parameter.GasValue, '0', &parameter.DisplayClock); // Display gas value
    } else {
       // DisplaySupplyError(parameter.DisplayClock); // Display supply error
         DisplayError('P',parameter.DisplayClock);
    }

    buzzerDull(&Counter); // Handle buzzer dull
    if (Counter > SUPPLY_ERROR_BLINK_OFF)
        Counter = 0;      // Reset counter
}

// Function to handle low battery mode
void lowBatteryHandler(void) {
    static int Counter = 0;
    LED_GREEN_OFF;         // Turn off the green LED
    LED_YELLOW_ON;         // Turn on the yellow LED
     ++Counter;
    if (Counter >= LOW_BATTERY_BLINK_ON) {
        BUZZER_ON;         // Turn on the buzzer
        LED_RED_ON;        // Turn on the red LED
        Display(parameter.GasValue, '0', &parameter.DisplayClock); // Display gas value
    } else {
        LED_RED_OFF;       // Turn off the red LED
        BUZZER_OFF;        // Turn off the buzzer
        //DisplayBatteryLOW(parameter.DisplayClock); // Display low battery
          DisplayError('L',parameter.DisplayClock);
    }
    if (Counter >= LOW_BATTERY_BLINK_OFF) {
        Counter = 0;       // Reset counter
    }
}

// Function to handle buzzer dull
void buzzerDull(short *Counter) {
    if ((*Counter > 1920) && (*Counter < 1950)) {
        BUZZER_ON;         // Turn on the buzzer
    } else if ((*Counter > 1950) && (*Counter < 1970)) {
        BUZZER_OFF;        // Turn off the buzzer
    } else if (*Counter > 1970) {
        BUZZER_ON;         // Turn on the buzzer
    } else {
        BUZZER_OFF;        // Turn off the buzzer
    }
}

// Function to initialize the system
void initializeSystem() {
    _cks0 = 0;
    _cks1 = 0;
    _cks2 = 0;
    _fss = 0;
    _fsiden = 1;
    _wdtc = 0b10101111;   // Watchdog timer configuration
    _lvrc = 0b10100101;   // Low voltage reset configuration
}

void initializePorts()
{
	_lvpu = 0;
	_pac &= 0b01000001;
	_pac |= 0b00000110;
	_pbc &= 0b00000000;
	_pbc |= 0b00001011;
	_pcc &= 0b00000000;
	_pcc |= 0b00000000;
	_pdc &= 0b00000000;
	_pdc |= 0b00000000;
	_pas1 = 0b00000000;
	_pas0 = 0b00001000;
	_pbs1 = 0b00000000;
	_pbs0 = 0b00001010;
	_pcs1 = 0b00000000;
	_pcs0 = 0b00000000;
	_pds0 = 0b00000000;
	_pbpu3 = 1;
//	_papu3=0;
}
/*

unsigned char useBank4(unsigned char address , unsigned char data) {

_bp = 0b00000100;
_mp1 = address; 
_iar1 = data; 
return _iar1;
    
}


SupplyMode handleSupplyStatus( void) 
{

//	Display(handleSupplyStatus(*VoltageBattery,'0', &parameter.DisplayClock);
   static SupplyMode SupplyStatus;
   /*=================================*
     	Supply |battery|   Mode    
	---------------------------------
		   1   |   1   | normal     
	----------------------------------
		   1   |   0   | Battery Error
	----------------------------------
		   0   |   1   | Supply Error
	----------------------------------
		   0   | <limit| Low Battery
	*=================================*/
	 // Determine supply status
      // Determine supply status
/*		// Determine initial supply status
if (POWER_SUPPLY_CONNECT) {
    SupplyStatus = (parameter.VoltageBattery > MINIMUM_VOLTAGE_VALID) ? NORMAL_POWER : BATTERY_ERROR;
} else {
    SupplyStatus = (parameter.VoltageBattery <= VOLTAGE_LOW_BATTERY) ? LOW_BATTERY : SUPPLY_ERROR;
}

// Manage hysteresis to prevent rapid status changes at boundary voltages
if ((SupplyStatus == NORMAL_POWER && parameter.VoltageBattery <= HYSTERESIS_THRESHOLD_LOWER) ||
    (SupplyStatus == SUPPLY_ERROR && parameter.VoltageBattery <= HYSTERESIS_THRESHOLD_LOWER)) {
    SupplyStatus = BATTERY_ERROR;
} else if ((SupplyStatus == BATTERY_ERROR && parameter.VoltageBattery > HYSTERESIS_THRESHOLD_UPPER) ||
           (SupplyStatus == LOW_BATTERY && parameter.VoltageBattery > HYSTERESIS_THRESHOLD_UPPER)) {
    SupplyStatus = NORMAL_POWER;
} else if (SupplyStatus == LOW_BATTERY && parameter.VoltageBattery > HYSTERESIS_THRESHOLD_UPPER) {
    SupplyStatus = SUPPLY_ERROR;
}
		
		
	return SupplyStatus;
	
}

*/
//void PowerSuplyManagemante( SupplyMode *SupplyStatus,int *parameter.DisplayClock){
//				
//	switch(*SupplyStatus)
//	{
//		case NORMAL_POWER:
//		normalPowerHandler();
//		break;
//	
//		case BATTERY_ERROR:
//			batteryErrorHandler();
//		break;
//		
//		case SUPPLY_ERROR:
//			supplyErrorHandler();
//		break;
//	
//		case LOW_BATTERY:
//			lowBatteryHandler();
//		break;
//	}
//														
//}

//
//void initializeTimers()
//{
//	_tb0on = 1;
//	_clksel0 = 1;
//	_clksel1 = 1;
//	_tb00 = 1;
//	_tb01 = 0;
//	_tb02 = 0;
//	_tb0e = 1;
//	_tb1on = 1;
//	_tb10 = 1;
//	_tb11 = 1;
//	_tb12 = 1;
//	_tb1e = 1;
//	_vbgen = 1;
//}
