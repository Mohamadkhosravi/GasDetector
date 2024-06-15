#include <Main.h>

void main()
{

	initializeSystem();
	initializePorts();
	S_ADC_Init();
	BUZZER_OFF;
	LED_GREEN_OFF;
	LED_RED_OFF;
	LED_YELLOW_OFF;
	RELAY_ON;
	pushButtonCounter = START_DELAY;
	
	do{
		--pushButtonCounter;
		Parameter.Counter++;
		if (Parameter.Counter < START_BLINK_ON)
		{
			LED_GREEN_ON;
			LED_YELLOW_ON;
			LED_RED_ON;
		}
		else
		{
			LED_GREEN_OFF;
			LED_YELLOW_OFF;
			LED_RED_OFF;
		}
		if (Parameter.Counter > START_BLINK_OFF)
		{

			Parameter.Counter = 0;
			displayClock++;
		}
		DisplayLoading(displayClock - 8);
		DisplayLoading(displayClock - 7);
		DisplayLoading(displayClock - 6);
		DisplayLoading(displayClock - 5);
		DisplayLoading(displayClock - 4);
		DisplayLoading(displayClock - 3);
		DisplayLoading(displayClock - 2);
		DisplayLoading(displayClock - 1);
		DisplayLoading(displayClock);
		if (displayClock > 7)
		{
			Parameter.Counter = 0;
			displayClock = 0;
		}
		
		
	}while(pushButtonCounter);

	pushButtonCounter = 0;
	Parameter.Counter = 0;
	displayClock = 0;
	Mode = NORMAL;
	while (1)
	{

		voltage_battery = COEFFICIENT * S_READ_ADC(2);
		displayClock++;
		if (displayClock >= 4)displayClock = 0;

	//	Parameter.GasValue = S_READ_ADC(0);

		if (S_READ_ADC(1) < MINIMUM_CURRENT_SENSOR)
		{
			Mode = SENSOR_ERROR;
		}
		else if (S_READ_ADC(0)> THRESHOLD_DETECT_GAS)
		{
			Mode = DETECT;
		}
		else
		{
			

			if (PRESSED_PUSHBUTTON)
			{
				pushButtonState = 1;
				pushButtonCounter++;
			}
			else
			{

				if ((pushButtonState == 1) && (pushButtonCounter > 500))
				{
					Mode = TEST;
				}
				else if ((pushButtonState == 1) && (pushButtonCounter < 500) && (pushButtonCounter > 10))
				{
					Mode = CHECK_BATTERY;
					bufferVdd=batteryPercentage(BATTERY_PERSENTAGE(voltage_battery));
				}
			}
		}
		
		
	if((POWER_SUPPLY_CONNECT)&& (voltage_battery > MINIMUM_VOLTAGE_VALID))
	{
		SupplyStatus= NORMAL_POWER;
	}
	else if ((POWER_SUPPLY_CONNECT) && (voltage_battery <= MINIMUM_VOLTAGE_VALID))
	{
		SupplyStatus=  BATTERY_ERROR;
	}
	else if ((POWER_SUPPLY_DISCONNECT) && (voltage_battery <= VOLTAGE_LOW_BATTERY))
	{
		SupplyStatus= LOW_BATTERY;
	}
	else if ((POWER_SUPPLY_DISCONNECT) && (voltage_battery > VOLTAGE_LOW_BATTERY))
	{
		SupplyStatus= SUPPLY_ERROR;
	}		
		
	
	//	SupplyStatus=handleSupplyStatus(&voltage_battery));
//		SupplyStatus = NORMAL_POWER;
		
		switch (Mode)
		{
			 case NORMAL:
				
				if (abs((S_READ_ADC(0) - GasValue)) >= 2)
				{
					GasValue = S_READ_ADC(0);
				}
			//	switch(handleSupplyStatus(&voltage_battery))
			    switch(SupplyStatus)
				{
					case NORMAL_POWER:
						normalPowerHandler();
					break;
					
					case BATTERY_ERROR:
						batteryErrorHandler();
					break;
					
					case SUPPLY_ERROR:
						 supplyErrorHandler();
					break;
				
					case LOW_BATTERY:
						lowBatteryHandler();
					break;
				}
			
			break;
	        case TEST:
	            handleTestMode();
	            break;
	
	        case CHECK_BATTERY:
	            handleCheckBatteryMode(&bufferVdd);
	        break;
	
	        case DETECT:
	            handleDetectMode();
	        break;
	
	        case SENSOR_ERROR:
	            handleSensorErrorMode();
	        break;
	        }
	}
}

void handleTestMode(void) {
   static int counter = 0;
   counter++;
   BUZZER_ON;
   RELAY_ON;
   LED_RED_ON;
   LED_GREEN_ON;
   LED_YELLOW_ON;
   Display(TEST_DISPLAY_VIEW, '0', &displayClock);
   pushButtonState = 0;
   pushButtonCounter = 0;

   if (counter > TEST_TIMEOUT) {
       counter = 0;
	   BUZZER_OFF;
	   LED_GREEN_OFF;
	   LED_RED_OFF;
	   LED_YELLOW_OFF;
       Mode = NORMAL;
   }
}

void handleCheckBatteryMode(char *persentageBattery) {
    static int counter = 0;
    counter++;

    if (*persentageBattery <= PERCENTAGE_LOW_BATTERY) 
    {	
        DisplayBatteryLOW(displayClock);
    }
    else
    {
        Display(*persentageBattery, 'b', &displayClock);
    }

    pushButtonState = 0;
    pushButtonCounter = 0;

    if (counter > CHECK_BATTERY_TIMEOUT) {
        Mode = NORMAL;
        counter = 0;
    }
}

void handleDetectMode(void) {
    BUZZER_ON;
    RELAY_ON;
    LED_RED_ON;
    LED_GREEN_ON;
    LED_YELLOW_ON;
    Display(DETECT_DISPLAY_VIEW, '0', &displayClock);
}

void handleSensorErrorMode(void) {
    BUZZER_ON;
    RELAY_ON;
    LED_RED_ON;
    LED_GREEN_ON;
    LED_YELLOW_ON;
    DisplaySensorError(displayClock);
}

char batteryPercentage(char percentOfBattery)
{
	static char buffer=0;
   // char percentOfBattery = 100;
    //BATTERY_PERSENTAGE(*voltageBattery);
	
	if (percentOfBattery > 95)
	{
		percentOfBattery = 100;
	}
	else if (percentOfBattery <= 19)
	{
		percentOfBattery = 0;
	}
		buffer = percentOfBattery;
	if (abs(percentOfBattery - buffer) >= 10)
	{
		buffer = percentOfBattery;
	}
	return buffer;
}

void normalPowerHandler(void) {

	LED_GREEN_ON;
	LED_RED_OFF;
	LED_YELLOW_OFF;

	Display(GasValue, '0', &displayClock);

}

void batteryErrorHandler(void) {
	static int Counter = 0;
	LED_GREEN_OFF;
	LED_RED_OFF;
	LED_YELLOW_ON;
	Counter++;
	          
	if (Counter < BATTERY_ERROR_BLINK_ON)
	{
		Display(GasValue, '0', &displayClock);
	}
	else
	{
		DisplayBatteryLOW(displayClock);
	}
	buzzerDull(&Counter);
	if (Counter > BATTERY_ERROR_BLINK_OFF)
	Counter = 0;

}

void supplyErrorHandler(void) {
	
	static int Counter = 0;
	LED_GREEN_OFF;
	LED_RED_OFF;
	LED_YELLOW_ON;
	Counter++;
	
	if (Counter < SUPPLY_ERROR_BLINK_ON)
	{
		Display(GasValue, '0', &displayClock);
	}
	else
	{
		DisplaySupplyError(displayClock);
	}
	
	buzzerDull(&Counter);
	if (Counter > SUPPLY_ERROR_BLINK_OFF)
		Counter = 0;	
	
}

void lowBatteryHandler(void) {
	static int Counter = 0;
	LED_GREEN_OFF;
	LED_YELLOW_ON;

	Counter++;
	
	if (Counter >= LOW_BATTERY_BLINK_ON)
	{
		BUZZER_ON;
		LED_RED_ON;
		Display(GasValue, '0', &displayClock);
	}
	else
	{
		LED_RED_OFF;
		BUZZER_OFF;
		DisplayBatteryLOW(displayClock);
	}
	if (Counter >= LOW_BATTERY_BLINK_OFF)
	{
		Counter = 0;
	}
   
}


void buzzerDull(short *Counter)
{
	
	
	
	if ((*Counter > 1920) && (*Counter < 1950))
	{
		BUZZER_ON;
	}
	else if ((*Counter > 1950) && (*Counter < 1970))
	{
		BUZZER_OFF;
	}
	else if (*Counter > 1970)
	{
		BUZZER_ON;
	}
	else
	{
		BUZZER_OFF;
	}
}

void initializeSystem()
{
	_cks0 = 0;
	_cks1 = 0;
	_cks2 = 0;
	_fss = 0;
	_fsiden = 1;
	_wdtc = 0b10101111;
	_lvrc = 0b10100101;
}

void initializePorts()
{
	_lvpu = 0;
	_pac &= 0b01101001;
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
}
/*
SupplyMode handleSupplyStatus( int *voltage_battery) {

//	Display(handleSupplyStatus(*voltage_battery,'0', &displayClock);
   static SupplyMode mode;
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

/*	if((POWER_SUPPLY_CONNECT)&& (*voltage_battery > MINIMUM_VOLTAGE_VALID_BATTERY))
	{
		mode= NORMAL_POWER;
	}
	if ((POWER_SUPPLY_CONNECT) && (*voltage_battery <= MINIMUM_VOLTAGE_VALID_BATTERY))
	{
		mode=  BATTERY_ERROR;
	}
	else if ((POWER_SUPPLY_DISCONNECT) && (*voltage_battery <= VOLTAGE_LOW_BATTERY))
	{
		mode= LOW_BATTERY;
	}
	else if ((POWER_SUPPLY_DISCONNECT) && (*voltage_battery > VOLTAGE_LOW_BATTERY))
	{
		mode= SUPPLY_ERROR;
	}
	return mode;
	
}
*/

//void PowerSuplyManagemante( SupplyMode *SupplyStatus,int *displayClock){
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
