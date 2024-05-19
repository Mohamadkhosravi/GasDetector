#include <ht67f2432.h>
#include <main.h>
void segmentNumbers(unsigned char n);




int length(int number);
void Display(int number, char letter);
int Numbr=0;

int i;



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

	// Set ADC configuration

	// 1
	_sacks2 = 0; // Set ADC clock to 1/8 of system clock
	_sacks1 = 1;
	_sacks0 = 1;

	// 2
	_adcen = 1; // A/D converter function enable control

	_adrfs = 1; // A/D converter data format selection

	// 4
	_sains0 = 0; //  A/D converter input signal selection  000: External input External analog channel input
	_sains1 = 0;
	_sains2 = 0;

	// 6
	_savrs0 = 1; // A/D converter reference voltage selection
	_savrs1 = 0;
	//_pas0=0b00001000;

	// 7
	_adcen = 1; // A/D converter function enable control

	// 8
	_sacs0 = 0; // A/D converter external analog channel input selection
	_sacs1 = 0;
	_sacs2 = 0;
	_sacs3 = 0;

	// Set 7-segment configuration
	COM0 = 1; // Set initial digit to display
	COM1 = 1;
	COM2 = 1;
	COM3 = 1;
	SEGA = 0;
	SEGB = 0;
	SEGC = 0;
	SEGD = 0;
	SEGE = 0;
	SEGF = 0;
	SEGG = 0;

	_sacs0 = 0; // A/D converter external analog channel 0 selection
	_sacs1 = 0;
	_sacs2 = 0;
	_sacs3 = 0;

	BUZZER_OFF; // buzz
    LED_GREEN_OFF; // LED_G
	LED_RED_OFF; // LED_R
	LED_YELLOW_OFF; // LED_Y
	RELAY_ON; // relay
//	S_ADC_Init();
	
	while (delay < 100000)
	{
		delay++;
	}

	delay = 0;

	_pc0 = 1; // LED_G

	while (1)
	{
		
		while(1)
		{
			LED_GREEN_ON;
			LED_RED_OFF;
			LED_YELLOW_OFF;

		//	Numbr=123;
		 Display(123,'o');
	
		}

		PB = !_pb3; // Detect PUSH THE TEST BUTTON

		if (fire_gas == 1 || PB == 1)
		{			  // Detect FIER
		
			BUZZER_ON; // buzz
			LED_RED_ON; // LED_R
			RELAY_ON; // relay
		}
		else
		{
			BUZZER_OFF; // buzz
			LED_RED_OFF; // LED_R
			RELAY_OFF; // relay
		}

		if (falt_BAT == 1 || falt_gas == 1 || PB == 1)
		{			  //	Detect FALT
			RELAY_ON; // LED_Y
		}
		else
		{
			 RELAY_OFF; // LED_Y
		}

		if (adc_GAS > 250)
		{ // GAS OVER THRESHOLD
			fire_gas = 1;
		}
		else
		{
			fire_gas = 0;
		}

		if (GAS_ERR < 10)
		{ // remove GAS SENSORE DetectSHEN
			falt_gas = 1;
		}
		else
		{
			falt_gas = 0;
		}

		if (598 > BAT_ADC || BAT_ADC > 953)
		{ // no battry ditected 2.7,4.3
			falt_BAT = 1;
			BAT = 101; // disply "no";
			BAT_ADC_D = 0;
		}
		else
		{
			falt_BAT = 0;
		}

		if (BAT_ADC < 614 && BAT_ADC > 570)
		{			 // <7% low battry 2.8-3
			BAT = 3; // disply "lo";
			falt_BAT = 1;
		}
		else if (BAT_ADC < 676)
		{ // 7-20% battry 3.300
			BAT = 1;
			BAT_ADC_D = 20;
		}
		else if (BAT_ADC < 737)
		{ // 20-40% battry 3.600
			BAT = 1;
			BAT_ADC_D = 40;
		}
		else if (BAT_ADC < 758)
		{ // 40-60% battry 3.700
			BAT = 1;
			BAT_ADC_D = 60;
		}
		else if (BAT_ADC < 809)
		{ // 60-80% battry 3.950
			BAT = 1;
			BAT_ADC_D = 80;
		}
		else if (BAT_ADC < 940)
		{ // 80-100% battry 4.250
			BAT = 1;
			BAT_ADC_D = 100;
		}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		if (_tb1f == 1) // Comparator B Match CTMAF Interrupt
		{

			_tb1f = 0;
		}

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        
         
         
         
         
		if (TIMER_CUNTER_INTRUPT == 1) // Comparator A Match CTMAF Interrupt
		{

			TIMER_CUNTER_INTRUPT = 0;

			switch (SEG)
			{

			case 0: // Select WHAT TO disply

				if (PB == 0)
				{
					disply = adc_GAS;
					disply_bat = 0;
				}
				else
				{
					disply = BAT_ADC_D;
					disply_bat = 1;
				}

				break;

				// Select digit to display

			case 1:
				if (disply_bat == 0)
				{
					Digit[3] = disply / 1000;
					segmentNumbers(Digit[3]);
				}
				else
				{
					Digit[3] = 'b';
					segmentNumbers(Digit[3]);
				}
				COM0 = 1;
				COM1 = 0;
				COM2 = 0;
				COM3 = 0;

				break;

			case 3:
				if ((BAT == 101 || BAT == 3) && disply_bat == 1)
				{
					Digit[2] = '-';
					segmentNumbers(Digit[2]);
				}
				else if (disply_bat == 0)
				{
					Digit[2] = disply / 100 - Digit[3] * 10;
					segmentNumbers(Digit[2]);
				}
				else
				{
					Digit[2] = disply / 100;
					segmentNumbers(Digit[2]);
				}

				COM0 = 0;
				COM1 = 1;
				COM2 = 0;
				COM3 = 0;
				break;

			case 5:
				if (BAT == 3 && disply_bat == 1)
				{
					Digit[1] = 'l';
					segmentNumbers(Digit[1]);
				}
				else if (BAT == 101 && disply_bat == 1)
				{
					Digit[1] = 'n';
					segmentNumbers(Digit[1]);
				}
				else if (disply_bat == 0)
				{
					Digit[1] = disply / 10 - Digit[3] * 100 - Digit[2] * 10;
					segmentNumbers(Digit[1]);
				}
				else
				{
					Digit[1] = disply / 10 - Digit[2] * 10;
					segmentNumbers(Digit[1]);
				}

				COM0 = 0;
				COM1 = 0;
				COM2 = 1;
				COM3 = 0;
				break;

			case 7:
				if ((BAT == 101 || BAT == 3) && disply_bat == 1)
				{
					Digit[0] = 'o';
					segmentNumbers(Digit[0]);
				}
				else
				{
					Digit[0] = disply % 10;
					segmentNumbers(Digit[0]);
				}

				COM0 = 0;
				COM1 = 0;
				COM2 = 0;
				COM3 = 1;
			}

			SEG++;

			if (SEG > 7)
				SEG = 0;

			t1++;
		}

		////////////////////////////////////////////////////////////////////////////

		// ADC

		if (t1 > 50)
		{

			switch (adc)
			{

				// Read ADC GAS value
			case 0:
				_sacs0 = 1; // A/D converter external analog channel 0 selection
				_sacs1 = 0;
				_sacs2 = 0;
				_sacs3 = 0;
				break;

			case 1:

				_sadoh = 0;
				_sadol = 0;

				_start = 0; // Start ADC conversion
				_start = 1;
				_start = 0;

				while (!_adbz)
					; // Wait for conversion to complete

				_adbz = 0; // Clear ADC interrupt flag

				adc_GAS = (adc_GAS + ((_sadoh << 8) | (_sadol))) / 2; // Get 10-bit ADC value (ADRFS=1)

				break;

				// Read GAS_ERR value
			case 2:
				_sacs0 = 0; // A/D converter external analog channel 0 selection
				_sacs1 = 1;
				_sacs2 = 0;
				_sacs3 = 0;
				break;

			case 3:
				_sadoh = 0;
				_sadol = 0;

				_start = 0; // Start ADC conversion
				_start = 1;
				_start = 0;

				while (!_adbz)
					; // Wait for conversion to complete

				_adbz = 0; // Clear ADC interrupt flag

				GAS_ERR = (GAS_ERR + ((_sadoh << 8) | (_sadol))) / 2; // Get 10-bit ADC value (ADRFS=1)
				break;

			case 4:
				_sacs0 = 0; // A/D converter external analog channel 2 selection
				_sacs1 = 0;
				_sacs2 = 0;
				_sacs3 = 0;
				break;

			case 5:
				_sadoh = 0;
				_sadol = 0;

				_start = 0; // Start ADC conversion
				_start = 1;
				_start = 0;

				while (!_adbz)
					;	   // Wait for conversion to complete
				_adbz = 0; // Clear ADC interrupt flag

				BAT_ADC = (BAT_ADC + ((_sadoh << 8) | (_sadol))) / 2;

				break;
			}

			adc++;
			if (adc > 5)
				adc = 0;

			t1 = 0;
		}
	}
}

void segmentNumbers(unsigned char n)
{

	switch (n)
	{
	case 0:
		SEGA = 0;
		SEGB = 0;
		SEGC = 0;
		SEGD = 0;
		SEGE = 0;
		SEGF = 0;
		SEGG = 1;
		break;
	case 1:
		SEGA = 1;
		SEGB = 0;
		SEGC = 0;
		SEGD = 1;
		SEGE = 1;
		SEGF = 1;
		SEGG = 1;
		break;
	case 2:
		SEGA = 0;
		SEGB = 0;
		SEGC = 1;
		SEGD = 0;
		SEGE = 0;
		SEGF = 1;
		SEGG = 0;
		break;
	case 3:
		SEGA = 0;
		SEGB = 0;
		SEGC = 0;
		SEGD = 0;
		SEGE = 1;
		SEGF = 1;
		SEGG = 0;
		break;
	case 4:
		SEGA = 1;
		SEGB = 0;
		SEGC = 0;
		SEGD = 1;
		SEGE = 1;
		SEGF = 0;
		SEGG = 0;
		break;
	case 5:
		SEGA = 0;
		SEGB = 1;
		SEGC = 0;
		SEGD = 0;
		SEGE = 1;
		SEGF = 0;
		SEGG = 0;
		break;
	case 6:
		SEGA = 0;
		SEGB = 1;
		SEGC = 0;
		SEGD = 0;
		SEGE = 0;
		SEGF = 0;
		SEGG = 0;
		break;
	case 7:
		SEGA = 0;
		SEGB = 0;
		SEGC = 0;
		SEGD = 1;
		SEGE = 1;
		SEGF = 1;
		SEGG = 1;
		break;
	case 8:
		SEGA = 0;
		SEGB = 0;
		SEGC = 0;
		SEGD = 0;
		SEGE = 0;
		SEGF = 0;
		SEGG = 0;
		break;
	case 9:
		SEGA = 0;
		SEGB = 0;
		SEGC = 0;
		SEGD = 0;
		SEGE = 1;
		SEGF = 0;
		SEGG = 0;
		break;

	case 'b':
		SEGA = 1;
		SEGB = 1;
		SEGC = 0;
		SEGD = 0;
		SEGE = 0;
		SEGF = 0;
		SEGG = 0;
		break;
	case 'l':
		SEGA = 1;
		SEGB = 1;
		SEGC = 1;
		SEGD = 0;
		SEGE = 0;
		SEGF = 0;
		SEGG = 1;
		break;
	case 'n':
		SEGA = 1;
		SEGB = 1;
		SEGC = 0;
		SEGD = 1;
		SEGE = 0;
		SEGF = 1;
		SEGG = 0;
		break;
	case 'o':
		SEGA = 1;
		SEGB = 1;
		SEGC = 0;
		SEGD = 0;
		SEGE = 0;
		SEGF = 1;
		SEGG = 0;
		break;
	case '-':
		SEGA = 1;
		SEGB = 1;
		SEGC = 1;
		SEGD = 1;
		SEGE = 1;
		SEGF = 1;
		SEGG = 0;
		break;
	}
}
void segmentCharters(unsigned char n)
{

	switch (n)
	{

		case 'b':
			SEGA = 1;
			SEGB = 1;
			SEGC = 0;
			SEGD = 0;
			SEGE = 0;
			SEGF = 0;
			SEGG = 0;
			break;
		case 'l':
			SEGA = 1;
			SEGB = 1;
			SEGC = 1;
			SEGD = 0;
			SEGE = 0;
			SEGF = 0;
			SEGG = 1;
			break;
		case 'n':
			SEGA = 1;
			SEGB = 1;
			SEGC = 0;
			SEGD = 1;
			SEGE = 0;
			SEGF = 1;
			SEGG = 0;
			break;
		case 'o':
			SEGA = 1;
			SEGB = 1;
			SEGC = 0;
			SEGD = 0;
			SEGE = 0;
			SEGF = 1;
			SEGG = 0;
			break;
		case '-':
			SEGA = 1;
			SEGB = 1;
			SEGC = 1;
			SEGD = 1;
			SEGE = 1;
			SEGF = 1;
			SEGG = 0;
			break;
	}
}
int length(int number){
	int cunter=0;
	while(number!=0){
		
		number = number/10;
		cunter++;
	}
	return cunter;

}


void Display(int number, char letter)
{
	char indexDigit=0;
	char displayBuffer[4]={0,0,0,0};
	char cunterCome=0;
	char startIndexDigit=3;
	
/*	if((letter!='0')&&((number/1000)<0))*/
    if(letter!='0')
	{
		startIndexDigit=2;
		displayBuffer[3]=letter;	
	}
	while(number!=0)
	{
	      
		displayBuffer[(startIndexDigit-indexDigit)]=number%10;
		number=(number-displayBuffer[(startIndexDigit-indexDigit)])/10;
		indexDigit++;
		
	}
  

   /* if(letter=!0)
    {
     lenght=1;
    }*/
	
	
	for(i=0;i<=3;i++)
	{

	  
		switch(i) 
		{			
			case 0:
			    segmentNumbers(displayBuffer[0]);
				COM0 = 1;
				COM1 = 0;
				COM2 = 0;
				COM3 = 0;
			
			break;		
			case 1:
		        segmentNumbers(displayBuffer[1]);
				COM0 = 0;
				COM1 = 1;
				COM2 = 0;
				COM3 = 0;
			
			break;
			case 2:
			     segmentNumbers(displayBuffer[2]);
				COM0 = 0;
				COM1 = 0;
				COM2 = 1;
				COM3 = 0;
			
			break;	
			case 3:
			  
			    segmentNumbers(displayBuffer[3]);
				COM0 = 0;
				COM1 = 0;
				COM2 = 0;
				COM3 = 1;
		
			break;	
		};	
	  GCC_DELAY(1000);
	}

}	
	
	

		
	
