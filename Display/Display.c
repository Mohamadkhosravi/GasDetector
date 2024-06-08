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
		case 'O':
			SEGA = 0;
			SEGB = 0;
			SEGC = 1;
			SEGD = 1;
			SEGE = 1;
			SEGF = 0;
			SEGG = 0;
		break;	
			
			
		case '-':
			SEGA = 1;
			SEGB = 1;
			SEGC = 1;
	}
}	
void Display(int number, char character,char *clock)
{
	static char first=0;
	static char indexDigit=0;
    static char displayBuffer[4]={0,0,0,0};
	static int pow =1;
 
    if(character=='C'){
    	*clock=0;
    	 displayBuffer[0]=0;
    	 displayBuffer[1]=0;
    	 displayBuffer[2]=0;
    	 displayBuffer[3]=0;
    	 indexDigit=0;
    	 pow =1;
    }
   
    first=1;
 /*   if(character!='0')
	{
		indexDigit=*clock-1;
		displayBuffer[3]=character;	
	}
	else
	{*/
	  indexDigit=*clock;	
/*	}*/
	
	displayBuffer[*clock]=(number/pow)%10;
	pow=pow*10;
	if(pow==10000)pow=1;
	switch(*clock) 
	{			
		case 0:
		    segmentNumbers(displayBuffer[3]);
			COM0 = 1;
			COM1 = 0;
			COM2 = 0;
			COM3 = 0;
		
		break;		
		case 1:
	        segmentNumbers(displayBuffer[2]);
			COM0 = 0;
			COM1 = 1;
			COM2 = 0;
			COM3 = 0;
		
		break;
		case 2:
		     segmentNumbers(displayBuffer[1]);
			COM0 = 0;
			COM1 = 0;
			COM2 = 1;
			COM3 = 0;
		
		break;	
		case 3:
		  
		    segmentNumbers(displayBuffer[0]);
			COM0 = 0;
			COM1 = 0;
			COM2 = 0;
			COM3 = 1;
	
		break;	
	};	

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
		
		case 4:
		  
		   segmentCharacters('O');
			COM0 = 0;
			COM1 = 0;
			COM2 = 0;
			COM3 = 1;
	
		break;
		case 5:
		  
		  
			COM0 = 0;
			COM1 = 0;
			COM2 = 1;
			COM3 = 0;
	
		break;	
		case 6:
		  
		  
			COM0 = 0;
			COM1 = 1;
			COM2 = 0;
			COM3 = 0;
	
		break;	
			
		case 7:
		  
		  
			COM0 = 1;
			COM1 = 0;
			COM2 = 0;
			COM3 = 0;
	
		break;	
			
			
		
		
	};	
}
		
	
