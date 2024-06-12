#include <Main.h>

void buzzerDull(int *Counter);
void initializeSystem();
void initializePorts();
void initializeTimers();
void handleTestMode() ;
void main()
{

	initializeSystem();
	initializePorts();
	initializeTimers();
	S_ADC_Init();

	BUZZER_OFF;
	LED_GREEN_OFF;
	LED_RED_OFF;
	LED_YELLOW_OFF;
	RELAY_ON;

	while (pushButtonCounter < START_DELAY)
	{
		pushButtonCounter++;
		Counter++;
		if (Counter < START_BLINK_ON)
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
		if (Counter > START_BLINK_OFF)
		{

			Counter = 0;
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
			Counter = 0;
			displayClock = 0;
		}
	}
	pushButtonCounter = 0;
	Counter = 0;
	displayClock = 0;
	Mode = NORMAL;

	//		if (TIMER_Counter_INTRUPT == 1) // Comparator A Match CTMAF Interrupt
	//		{
	//			TIMER_Counter_INTRUPT = 0;
	//			delay++;
	//
	//		}

	while (1)
	{

#if READ_VDD
		vdd = VDD(S_READ_ADC(7) * 1000);
#endif

		voltage_battery = COEFFICIENT * S_READ_ADC(2);
		displayClock++;
		if (displayClock >= 4)
			displayClock = 0;

		Parameter.GasValue = S_READ_ADC(0);

		if (S_READ_ADC(1) < MINIMUM_CURRENT_SENSOR)
		{
			Mode = SENSOR_ERROR;
		}
		else if (Parameter.GasValue > THRESHOLD_DETECT_GAS)
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
					percent_of_battery = batteryPercentage(voltage_battery);

					if (percent_of_battery > 95)
					{
						percent_of_battery = 100;
					}
					else if (percent_of_battery <= 19)
					{
						percent_of_battery = 0;
					}
					bufferVdd = percent_of_battery;
					if (abs(percent_of_battery - bufferVdd) >= 3)
					{
						bufferVdd = percent_of_battery;
					}

					Mode = CHECK_BATTERY;
				}
			}
		}

		/*
		Supply |battery | Mode
		-----------------------------
		 1    |   1    | normal
		-----------------------------
		 1    |   0    | Battery Error
		-----------------------------
		 0    |   1    | Supply Error
		-----------------------------
		 0    | <limit | Low Battery
		-----------------------------
		*/
		// if voltage Battery <1 v batt rorre

		if ((POWER_SUPPLY_CONNECT) && (voltage_battery <= MINIMUM_VOLTAGE_VALID))
		{
			SupplyStatus = BATTERY_ERROR;
		}
		else if ((POWER_SUPPLY_DISCONNECT) && (voltage_battery > VOLTAGE_LOW_BATTERY))
		{
			SupplyStatus = SUPPLY_ERROR;
		}
		else if ((POWER_SUPPLY_DISCONNECT) && (voltage_battery < VOLTAGE_LOW_BATTERY))
		{
			SupplyStatus = LOW_BATTERY;
		}

		/*	SupplyStatus=LOW_BATTERY;
		 */

		SupplyStatus = NORMAL_POWER;
		switch (Mode)
		{
		case NORMAL:
			RELAY_OFF;

			if (abs((S_READ_ADC(0) - buffer)) >= 2)
			{
				buffer = S_READ_ADC(0);
			}

			//	Display( S_READ_ADC(1),'0',&displayClock);

			switch (SupplyStatus)
			{

			case NORMAL_POWER:

				LED_GREEN_ON;
				LED_RED_OFF;
				LED_YELLOW_OFF;
				Display(buffer, '0', &displayClock);

				break;

			case BATTERY_ERROR:

				LED_GREEN_OFF;
				LED_RED_OFF;
				LED_YELLOW_ON;
				Counter++;
				              
				if (Counter < BATTERY_ERROR_BLINK_ON)
				{
					Display(buffer, '0', &displayClock);
				}
				else
				{
					DisplayBatteryLOW(displayClock);
				}
				buzzerDull(&Counter);
				if (Counter > BATTERY_ERROR_BLINK_OFF)
					Counter = 0;

				break;

			case SUPPLY_ERROR:

				LED_GREEN_OFF;
				LED_RED_OFF;
				LED_YELLOW_ON;
				Counter++;

				if (Counter < SUPPLY_ERROR_BLINK_ON)
				{
					Display(buffer, '0', &displayClock);
				}
				else
				{
					DisplaySupplyError(displayClock);
				}

				buzzerDull(&Counter);
				if (Counter > SUPPLY_ERROR_BLINK_OFF)
					Counter = 0;
				break;

			case LOW_BATTERY:

				LED_GREEN_OFF;
				LED_YELLOW_ON;

				Counter++;

				if (Counter >= LOW_BATTERY_BLINK_ON)
				{
					BUZZER_ON;
					LED_RED_ON;
					Display(buffer, '0', &displayClock);
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

				break;
			}

			// Display(voltage_battery,'0',&displayClock);
			/*	LED_RED_OFF;*/

			break;

		case TEST:
		
		// handleTestMode(); 
		
		
		Counter++;
			BUZZER_ON;
			RELAY_ON;
			LED_RED_ON;
			LED_GREEN_ON;
			LED_YELLOW_ON;

			Display(TEST_DISPLAY_VIEW, '0', &displayClock);
			pushButtonState = 0;
			pushButtonCounter = 0;

			if (Counter > TEST_TIMEOUT)
			{
				BUZZER_OFF;
				RELAY_OFF;
				LED_RED_OFF;
				LED_YELLOW_OFF;
				LED_GREEN_OFF;

				Counter = 0;
				Mode = NORMAL;
			}
		 break;

		case CHECK_BATTERY:

			Counter++;

			if (bufferVdd <= PERCENTAGE_LOW_BATTERY)
			{
				DisplayBatteryLOW(displayClock);
			}
			else
			{
				Display(bufferVdd, 'b', &displayClock);
			}

			pushButtonState = 0;
			pushButtonCounter = 0;

			if (Counter > CHECK_BATTERY_TIMEOUT)
			{
				Mode = NORMAL;
				Counter = 0;
			}

			break;

		case DETECT:

			BUZZER_ON;
			RELAY_ON;
			LED_RED_ON;
			LED_GREEN_ON;
			LED_YELLOW_ON;
			Display(DETECT_DISPLAY_VIEW, '0', &displayClock);

			break;

		case SENSOR_ERROR:

			BUZZER_ON;
			RELAY_ON;
			LED_RED_ON;
			LED_GREEN_ON;
			LED_YELLOW_ON;
			Display(DETECT_DISPLAY_VIEW, '0', &displayClock);
			break;
		}
	}
}


//
//void handleTestMode() {
//    static int counter = 0;
//    counter++;
//    BUZZER_ON;
//    RELAY_ON;
//    LED_RED_ON;
//    LED_GREEN_ON;
//    LED_YELLOW_ON;
//    Display(TEST_DISPLAY_VIEW, '0', &displayClock);
//    pushButtonState = 0;
//    pushButtonCounter = 0;
//
//    if (counter > TEST_TIMEOUT) {
//        counter = 0;
//		BUZZER_ON;
//		RELAY_ON;
//		LED_RED_ON;
//		LED_GREEN_ON;
//		LED_YELLOW_ON;
//        Mode = NORMAL;
//    }
//}







void buzzerDull(int *Counter)
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

void initializeTimers()
{
	_tb0on = 1;
	_clksel0 = 1;
	_clksel1 = 1;
	_tb00 = 1;
	_tb01 = 0;
	_tb02 = 0;
	_tb0e = 1;
	_tb1on = 1;
	_tb10 = 1;
	_tb11 = 1;
	_tb12 = 1;
	_tb1e = 1;
	_vbgen = 1;
}
