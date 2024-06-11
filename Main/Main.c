#include<Main.h>


void buzzerDoull(int *Cunter);	
		
void main()
{
	
	// Oscillators

	_cks0 = 0; //: System clock selection (fH)
	_cks1 = 0;
	_cks2 = 0;
	_fss = 0; //: Low frequency clock selection internal RC
	_fsiden = 1; //: Low frequency oscillator control when CPU is switched of Enable

	_wdtc = 0b10101111; // WDT function software control: Disable

	_lvrc = 0b10100101; // LVR voltage select control: Disable

	// Input/Output Ports

	_lvpu = 0; // Pull-high resistor select when low voltage power supply: All pin pull high resistor is 60k @ 3V

	_pac &= 0b01101001; //: Port type selection I/O
	_pac |= 0b00000110;

	_pbc &= 0b00000000;
	_pbc |= 0b00001011;

	_pcc &= 0b00000000;
	_pcc |= 0b00000000;

	_pdc &= 0b00000000;
	_pdc |= 0b00000000;

	_pas1 = 0b00000000; // Pin-shared Function Selection Registers
	_pas0 = 0b00001000;

	_pbs1 = 0b00000000;
	_pbs0 = 0b00001010;

	_pcs1 = 0b00000000;
	_pcs0 = 0b00000000;

	_pds0 = 0b00000000;

	_pbpu3 = 1; // pin pull-high function control (pb3:test)

	// Time Base Interrupts

	_tb0on = 1; // Time Base 0 control Enable

	_clksel0 = 1; // Prescaler clock source selection
	_clksel1 = 1;

	_tb00 = 1; // Select Time Base 0 Time-out Period = 1000Hz
	_tb01 = 0;
	_tb02 = 0;

	_tb0e = 1;

	_tb1on = 1; // Time Base 1 control Enable

	_tb10 = 1; // Select Time Base 0 Time-out Period = 125Hz
	_tb11 = 1;
	_tb12 = 1;

	_tb1e = 1;

	 _vbgen=1;

	BUZZER_OFF; // buzz
    LED_GREEN_OFF; // LED_G
	LED_RED_OFF; // LED_R
	LED_YELLOW_OFF; // LED_Y
	RELAY_ON; // relay
	S_ADC_Init();

	while (pushButtonCunter < START_DELAY)
	{
		
		
	
		pushButtonCunter++;
		Cunter++;
		if(Cunter<START_BLINK_ON)
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
		if(Cunter>START_BLINK_OFF)
		{
		
		 Cunter=0;
		 displayClock++;
		}
		DisplayLooding(displayClock-8);
		DisplayLooding(displayClock-7);
		DisplayLooding(displayClock-6);
		DisplayLooding(displayClock-5);
		DisplayLooding(displayClock-4);
		DisplayLooding(displayClock-3);
		DisplayLooding(displayClock-2);
		DisplayLooding(displayClock-1);
		DisplayLooding(displayClock);
		if(displayClock>7){Cunter=0;displayClock=0;}
		

	}
	pushButtonCunter = 0;
	Cunter=0;
    displayClock=0;
    Mode=NORMAL;

  
     
     		
//		if (TIMER_CUNTER_INTRUPT == 1) // Comparator A Match CTMAF Interrupt
//		{
//			TIMER_CUNTER_INTRUPT = 0;
//			delay++;
//		
//		}
    
     
     
     
	while (1)
	{
   

     #if READ_VDD
     	vdd=VDD(S_READ_ADC(7)*1000);
     #endif	

     
        voltage_battery = COEFFICIENT*S_READ_ADC(2);
        displayClock++;
	    if(displayClock>=4)displayClock=0;
	    
        Parametr.GasValue=S_READ_ADC(0);
        
        
        if(S_READ_ADC(1)< MINIMUM_CURRENT_SENSOR)
        {
          Mode=SENSOR_ERRORE;	
        }
		else if(Parametr.GasValue>TRESHOLD_DETECT_GAS)
		{
			Mode=DETECT;
		}
        else
        {
    
            if(PRESEED_PUSHBUTUN)
            {
           
             pushButtonState=1;
             pushButtonCunter++;
      	
            }
            else
            {
            
            	if((pushButtonState==1)&&(pushButtonCunter>500))
            	{ 
            		Mode=TEST;
            	}
            	else if((pushButtonState==1)&&(pushButtonCunter<500)&&(pushButtonCunter>10))
            	{
				    	percent_of_battery=batteryPercentage(voltage_battery);
				    	
						if( percent_of_battery > 95)
						{
							percent_of_battery = 100;
						}
						else if( percent_of_battery <= 19)
						{
							percent_of_battery = 0;
						}  
							bufferVdd=percent_of_battery;
						if(abs(percent_of_battery-bufferVdd)>=3)
						{
					    	bufferVdd=percent_of_battery;	
						}
							
						
						 
            		Mode=CHECK_BATTERY;	
            		
	
            	}
            
            	
            }
      
            
			
	
        }
        
        
        
        
        /*
        Suply |battery | Mode
        -----------------------------
         1    |   1    | normal
        -----------------------------
         1    |   0    | Battry Error
        -----------------------------
         0    |   1    | Suply Error 
        -----------------------------
         0    | <limit | Low Battry 
        ----------------------------- 
        */
        // if voltage battry <1 v batt rorre
       
     
       if((POWER_SUPLY_CONNECT)&&(voltage_battery <= MINIMUM_VOLTAGE_VALID))
       {
        	SuplyStatus=BATTRY_ERROR;
       }
       else if((POWER_SUPLY_DISCONNECT)&&(voltage_battery> VOLTAGE_LOWBATTERY))
       {
       	    SuplyStatus=SUPPLY_ERROR;
   
       }
       else if((POWER_SUPLY_DISCONNECT)&&(voltage_battery < VOLTAGE_LOWBATTERY))
       {
       	   SuplyStatus=LOW_BATTERY;
       }
		
	  
	/*	SuplyStatus=LOW_BATTERY;
		*/

       SuplyStatus=NORMAL_POWER;
		switch(Mode)
		{
			case NORMAL:
			   RELAY_OFF;
			
				 if(abs((S_READ_ADC(0)-buffer))>=2)
				{
			    	buffer=S_READ_ADC(0);	
				}
			
		
			//	Display( S_READ_ADC(1),'0',&displayClock);
		
				switch(SuplyStatus)
				{
					
					case NORMAL_POWER:
					
					    LED_GREEN_ON;
					    LED_RED_OFF;
					    LED_YELLOW_OFF;
						Display( buffer,'0',&displayClock);
						
					break;
				
					
					case BATTRY_ERROR:
					
						LED_GREEN_OFF;
						LED_RED_OFF;
						LED_YELLOW_ON;
						Cunter++;	
						if(Cunter<BATTRY_ERROR_BLINK_ON)
						{
							Display( buffer,'0',&displayClock);
						}
						else
						{  
							DisplayBatteryLOW(displayClock);
						}
						buzzerDoull(&Cunter);
		                if(Cunter>BATTRY_ERROR_BLINK_OFF)Cunter=0;
		                
					break;
					
					case SUPPLY_ERROR:
					
						LED_GREEN_OFF;
						LED_RED_OFF;
						LED_YELLOW_ON;
						Cunter++;
						
						if(Cunter<SUPPLY_ERROR_BLINK_ON)
						{
						  Display( buffer,'0',&displayClock);
						}
						else
						{  
					      DisplaySuplyError(displayClock);
						}
						
						buzzerDoull(&Cunter);
					   if(Cunter>SUPPLY_ERROR_BLINK_OFF)Cunter=0;
					break;
					
					case LOW_BATTERY:
					
						LED_GREEN_OFF;
						LED_YELLOW_ON;
						
						Cunter++;
						
						if(Cunter>=LOW_BATTERY_BLINK_ON)
						{
						  BUZZER_ON;
						  LED_RED_ON;
						  Display( buffer,'0',&displayClock);	
						}
						else
						{
						   LED_RED_OFF;	
						   BUZZER_OFF;	
						   DisplayBatteryLOW(displayClock);
						}
						if(Cunter>=LOW_BATTERY_BLINK_OFF)
						{
				     	 Cunter=0;
						}
					
					break;
				
				}
			       
			
		  	   
			//Display(voltage_battery,'0',&displayClock);
			/*	LED_RED_OFF;*/
			
			break;
			
			case TEST:
				Cunter++;
				BUZZER_ON;
				RELAY_ON;
				LED_RED_ON;
				LED_GREEN_ON;
				LED_YELLOW_ON;

				Display(TEST_DISPLAY_VIWE,'0',&displayClock);
				pushButtonState=0;
				pushButtonCunter=0;
		
				if(Cunter>TEST_TIMEOUT)
				{
					Cunter=0;
					Mode=NORMAL;
				}
			break;
			
			case CHECK_BATTERY:
				
			   	Cunter++;
			   
			   	 
				if(bufferVdd<=PERSENTEAGE_LOWBATTRY)
				{
				   DisplayBatteryLOW(displayClock);
				}
				else
				{
		    	   Display(bufferVdd,'b',&displayClock);
				}
				
				pushButtonState=0;
				pushButtonCunter=0;
			
			    if(Cunter> CHECK_BATTERY_TIMEOUT)
				{
					Mode=NORMAL;
					Cunter=0;

				}
					
			break;
			
			
			case DETECT:
			
		        BUZZER_ON;
				RELAY_ON;
				LED_RED_ON;
				LED_GREEN_ON;
				LED_YELLOW_ON;
				Display(DETECT_DISPLAY_VIWE,'0',&displayClock);
		
			break;
			
		
			case SENSOR_ERRORE:
			
				BUZZER_ON;
				RELAY_ON;
				LED_RED_ON;
				LED_GREEN_ON;
				LED_YELLOW_ON;
				
			break;
	
			
		}
		
	
       

            
            
            
            
	
	}
}

void buzzerDoull(int *Cunter)
{
	if((*Cunter>1920)&&(*Cunter<1950))
	{
		BUZZER_ON;	
	}
	else if((*Cunter>1950)&&(*Cunter<1970))	
	{
		BUZZER_OFF;		
	}
	else if(*Cunter>1970)
	{
		BUZZER_ON;
	}
	else
	{
		BUZZER_OFF;		
	}

		
}