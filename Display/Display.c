#include "Display.h"

void DisplayInit(void)
{
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
void segmentCharacters(unsigned char n)
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
	}
}	
void Display(int number, char character,char clock)
{
	static char indexDigit=0;
	indexDigit=clock;
	char displayBuffer[4]={0,0,0,0};
	static int pow =1;
	char startIndexDigit=3;
	char digitNumber=0;
	int i=0;
/*	if((character!='0')&&((number/1000)<0))*/
    if(character!='0')
	{
		startIndexDigit=2;
		displayBuffer[3]=character;	
	}
	/*while(number!=0)
	{
	      
		displayBuffer[indexDigit]=number%10;
		number=(number-displayBuffer[indexDigit])/10;
		indexDigit++;
		
	}*/
	

  /*	if((character!='0')&&((number/1000)<0))*/
 /*   if(character!='0')
	{
		startIndexDigit=2;
		displayBuffer[3]=character;	
	}
	
	int temp = number; // ??? ???? ?? ?? ????? ???? ????? ????
	displayBuffer[0] = temp / 1000;
	temp %= 1000; // ???? ?? ????? ?????? ??????? ????
	displayBuffer[1] = temp / 100;
	temp %= 100;
	displayBuffer[2] = temp / 10;
	displayBuffer[3] = temp % 10;
	
	
	while(number!=0)
	{
	      
	displayBuffer[(startIndexDigit-indexDigit)]=number%10;
		number=(number-displayBuffer[(startIndexDigit-indexDigit)])/10;
		indexDigit++;*/
//		displayBuffer[0]=number/1000;
//		displayBuffer[1]=(number-displayBuffer[0]*1000)/100;
//		displayBuffer[2]=(number-((displayBuffer[0]*1000)+(displayBuffer[1]*100)))/10;
//		displayBuffer[3]=(number-((displayBuffer[0]*1000)+(displayBuffer[1]*100)+(displayBuffer[2]*10)));
//		
//		
		/*for(indexDigit=0;indexDigit<=3;indexDigit++){*/
			displayBuffer[indexDigit]=(number/pow)%10;
			pow=pow*10;
			if(pow==10000)pow=1;
	/*	}*/
		
	/*	displayBuffer[3]=number/1%10;
		displayBuffer[2]=(number/10*)%10;
		displayBuffer[1]=(number/100)%10;
		displayBuffer[0]=(number/1000)%10;	*/
//	}

   /* if(character=!0)
    {
     lenght=1;
    }*/
	
	
//	for(digitNumber=0;digitNumber<=3;digitNumber++)
//	{

	  
		switch(clock) 
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

/*	}*/

}	
	
	
void DisplayLooding(char cunterDigit )
{
///*	static cunterDigit=0
//	cunterDigit++;
	
	switch(cunterDigit) 
	{			
		case 0:
		 segmentCharacters('o');
			COM0 = 1;
			COM1 = 0;
			COM2 = 0;
			COM3 = 0;
		
		break;		
		case 1:
	      
			COM0 = 0;
			COM1 = 1;
			COM2 = 0;
			COM3 = 0;
		
		break;
		case 2:
		 
			COM0 = 0;
			COM1 = 0;
			COM2 = 1;
			COM3 = 0;
		
		break;	
		case 3:
		  
		  
			COM0 = 0;
			COM1 = 0;
			COM2 = 0;
			COM3 = 1;
	
		break;	
	};	
}
		
	
