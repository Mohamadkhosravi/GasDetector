#include<Main.h>
#include <ADC.h>

//	void __attribute((interrupt(0x0))) ISR_tmr0 (void)
//	{
//		tick=2;
//	};
//	
__attribute__((interrupt(0x1c)))
void isr_timer (void)
{

}

	
	
	
	
	
	
	
	
	
	
	
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

	while (delay < 15000)
	{
		delay++;
		i++;
		if(i<1000)
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
		if(i>2000)
		{
		
		i=0;
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
		if(displayClock>7){i=0;displayClock=0;}
		

	}
	delay = 0;
	i=0;
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

       
       
    	voltage_battery =(vdd/1023.0)*S_READ_ADC(2);

		
        displayClock++;
	    if(displayClock>=4)displayClock=0;
	    
        Parametr.GasValue=S_READ_ADC(0);	
        if(Parametr.GasValue>TRESHOLD_DETECT_GAS)
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
            //Parametr.VoltageBattery=S_READ_ADC(1);
            
			
	
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
        
     
       if((POWER_SUPLY_CONNECT)&&(voltage_battery <= MINIMUM_VOLTAGE_VALID))
       {
        	Suply=BATTRY_ERROR;
       }
       else if((POWER_SUPLY_DISCONNECT)&&(voltage_battery> VOLTAGE_LOWBATTERY))
       {
       	    Suply=SUPPLY_ERROR;
   
       }
       else if((POWER_SUPLY_DISCONNECT)&&(voltage_battery < VOLTAGE_LOWBATTERY))
       {
       	   Suply=LOW_BATTERY;
       }
		
	  
		
		switch(Mode)
		{
			case NORMAL:
			    BUZZER_OFF;
				/*LED_RED_OFF;*/
				LED_YELLOW_OFF;
		    	LED_GREEN_ON;
		    	RELAY_ON;
		    
		       if(POWER_SUPLY_CONNECT)
		       {
		       		LED_RED_OFF;
		       }
		       else
		       {
		       		LED_RED_ON;
		          
		       }
		    
		    
				/*Display( voltage_battery,'0',&displayClock);*/
		  	    if(abs((S_READ_ADC(0)-buffer))>=2)
				{
			    	buffer=S_READ_ADC(0);	
				}
			
				Display(voltage_battery,'0',&displayClock);
			/*	LED_RED_OFF;*/
			
			break;
			
			case TEST:
				Cunter.test++;
				BUZZER_ON;
				RELAY_ON;
				LED_RED_ON;
				LED_GREEN_ON;
				LED_YELLOW_ON;
				Display(8888,'0',&displayClock);
				pushButtonState=0;
				pushButtonCunter=0;
				if(Cunter.test>1000)
				{
					Cunter.test=0;
					Mode=NORMAL;
				}
			break;
			
			case CHECK_BATTERY:
				
			   	Cunter.checkBattery++;
			    BUZZER_OFF;
				LED_RED_OFF;
				LED_YELLOW_OFF;
				LED_GREEN_ON;
				if(bufferVdd<=19)
				{
				  DisplayBatteryLOW(displayClock);
				}
				else
				{
		    	   Display(bufferVdd,'b',&displayClock);
				}
				
				pushButtonState=0;
				pushButtonCunter=0;
			    if(Cunter.checkBattery>500)
				{
					Mode=NORMAL;
					Cunter.checkBattery=0;

				}
					
			break;
			
			
			case DETECT:
		        BUZZER_ON;
				RELAY_ON;
				LED_RED_ON;
				LED_GREEN_ON;
				LED_YELLOW_ON;
				Display(250,'0',&displayClock);
		
			break;
			
			
				
		 /* case LOW_BATTERY:
			
			    Cunter.lowBattry++;
			    if(Cunter.lowBattry<30)
			    {
			      BUZZER_ON;
			    }
			    else if((Cunter.lowBattry>30)&&(Cunter.lowBattry<50))
			    {
			      BUZZER_OFF;
			    }
			    else if((Cunter.lowBattry>50)&&(Cunter.lowBattry<80))
			    {
			     BUZZER_ON;	
			    }
			    else
			    {
			     BUZZER_OFF;	
			    }
			    if(Cunter.lowBattry<1000)
			    {
					Parametr.GasValue=S_READ_ADC(0);
					Display(Parametr.GasValue,'o');
			    }
			    else
			    {
			    	Parametr.VoltageBattery=S_READ_ADC(1);
			    	Parametr.VoltageBattery=(char)batteryPercentage(10);
					Display(Parametr.VoltageBattery,'0');
					
			    }
			    
			   if(Cunter.lowBattry>2000)Cunter.lowBattry=0;
				LED_RED_OFF;
				LED_YELLOW_ON;
				LED_GREEN_OFF;
				
				
			
			break;
			*/
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		/*	default :
			Mode=NORMAL;
			break;*/
			
		}
		
	


        /*   unsigned int Avarage( unsigned int value,char numberOfSample,char sampleClock)
           {
           	if(sampleClock==numberOfSample)
           	{
           	  value=+value;
           	}
            
             
           }*/
		
//		unsigned char BatteryPercentage(unsigned char voltageBattery) {
//
//
//		    unsigned char voltageRange = 0;
//		    voltageRange=maxVoltageBattery - minVoltageBattery;
//		    
//		    float batteryPercentage = 0;
//		    batteryPercentage=((voltageBattery - minVoltageBattery) / voltageRange) * 100;
//		/*
//		    int roundedPercentage = ((int)(batteryPercentage / percentageAccuracy + 0.5)) * percentageAccuracy;
//		
//		    if (roundedPercentage > 100) {
//		        roundedPercentage = 100;
//		    } else if (roundedPercentage < 0) {
//		        roundedPercentage = 0;
//		    }*/
//
//    		return batteryPercentage;
//		}
//		
//	
	
            
	/*	unsigned char BatteryPercentage(void) {
		
			 VDD=4*(1.6*S_READ_ADC(7)/1023);
			 VoltageBattery=(S_READ_ADC(2)*VDD/1023);
		    PersentOfBattery=(0.133 * oltageBattery*1000 -368.481);
			if(PersentOfBattery>95)
			{
			  PersentOfBattery=100;
			}
			if(PersentOfBattery<=20)
			{
		       PersentOfBattery=0;
			
			}
			return PersentOfBattery;
		
		}*/
	
    /*
    	Parametr.VDD=4*(1.6*S_READ_ADC(7)/1023);
			Parametr.VoltageBattery=(S_READ_ADC(2)*Parametr.VDD/1023);
			Parametr.PersentOfBattery=(0.133 * Parametr.VoltageBattery*1000 -368.481);
			if(Parametr.PersentOfBattery>95)
			{
			Parametr.PersentOfBattery=100;
			}
			if(Parametr.PersentOfBattery<=20)
			{
			Parametr.PersentOfBattery=0;
			
			}
    */
    
    
      /*  if((i>1)&&(i<=1000)){*/
			
	/*		Parametr.GasValue=S_READ_ADC(0);
			Display(Parametr.GasValue,'o');
		*/
	/*	
		}
		if
		
        if((i>1000)&&(i<=2000))
        {
		   Parametr.VoltageBattery=S_READ_ADC(1);
	 		Display(Parametr.VoltageBattery,'b');
	 	
        }
		if((i>2000)&&(i<=3000)){
		Parametr.GasErroreValue=S_READ_ADC(2);
		Display( Parametr.GasErroreValue,'0');
		
		}
        if(i>3000)i=0;*/
        
            
            
            
            
            
	
	}
}
