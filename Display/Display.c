#include "Display.h"

//void DisplayInit(void)
//{
//	// Set 7-segment configuration
//	COM0 = 1; // Set initial digit to display
//	COM1 = 1;
//	COM2 = 1;
//	COM3 = 1;
//	SEGA = 0;
//	SEGB = 0;
//	SEGC = 0;
//	SEGD = 0;
//	SEGE = 0;
//	SEGF = 0;
//	SEGG = 0;
//}

void segmentNumbers(unsigned char number)
{
  
	switch (number)
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
	
		
	}
}
void segmentCharacters(unsigned char character)
{

	switch (character)
	{
		case 'A':
			SEGA = 0;
			SEGB = 0;
			SEGC = 0;
			SEGD = 1;
			SEGE = 0;
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
			
		case 'L':
			SEGA = 1;
			SEGB = 1;
			SEGC = 1;
			SEGD = 0;
			SEGE = 0;
			SEGF = 0;
			SEGG = 1;
			break;
			
		case 'N':
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
			
		case 'E':
			SEGA = 0;
			SEGB = 1;
			SEGC = 1;
			SEGD = 0;
			SEGE = 0;
			SEGF = 0;
			SEGG = 0;
		break;
				
		case 'r':
			SEGA = 0;
			SEGB = 1;
			SEGC = 1;
			SEGD = 1;
			SEGE = 0;
			SEGF = 0;
			SEGG = 1;
		break;	
		case 'S':
			SEGA = 0;
			SEGB = 1;
			SEGC = 0;
			SEGD = 0;
			SEGE = 1;
			SEGF = 0;
			SEGG = 0;
		break;	
		
		case 'T':
       
			SEGA = 0;
			SEGB = 0;
			SEGC = 0;
			SEGD = 1;
			SEGE = 1;
			SEGF = 1;
			SEGG = 1;
		break;	
		

	}
}	
void Display(int number, unsigned char character,char *clock)
{	
	switch(*clock) 
	{		
		case 0:
		
			if(character!='0')
			{
			
				segmentCharacters(character);
	     	}
			else 
			{
			
				segmentNumbers((number/1000)%10);
			}
			
			COM0 = 1;
			COM1 = 0;
			COM2 = 0;
			COM3 = 0;
		
		break;	
			
		case 1:
	
		 /*segmentCharacters(character);*/
	        segmentNumbers((number/100)%10);
			COM0 = 0;
			COM1 = 1;
			COM2 = 0;
			COM3 = 0;
		
		break;
		
		case 2:
		    segmentNumbers((number/10)%10);
		  
			COM0 = 0;
			COM1 = 0;
			COM2 = 1;
			COM3 = 0;
		break;
			
		case 3:
		  
		    segmentNumbers((number)%10);
		 
			COM0 = 0;
			COM1 = 0;
			COM2 = 0;
			COM3 = 1;
	
		break;	
	};

}	
	
	
void DisplayLoading(char cunterDigit )
{
	
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
		
	
void DisplayBatteryLOW(char cunterDigit )
{
	switch(cunterDigit) 
	{			
		case 0:
		 segmentCharacters('L');
			COM0 = 1;
			COM1 = 0;
			COM2 = 0;
			COM3 = 0;
		
		break;		
		case 1:
	      segmentCharacters('b');
			COM0 = 0;
			COM1 = 1;
			COM2 = 0;
			COM3 = 0;
		
		break;
		case 2:
		 segmentCharacters('A');
			COM0 = 0;
			COM1 = 0;
			COM2 = 1;
			COM3 = 0;
		
		break;	
		case 3:
		 segmentCharacters('T');
			COM0 = 0;
			COM1 = 0;
			COM2 = 0;
			COM3 = 1;
		
		break;	
	}
}



void DisplayBatteryError(char cunterDigit )
{
	switch(cunterDigit) 
	{			
		case 0:
		 segmentCharacters('b');
			COM0 = 1;
			COM1 = 0;
			COM2 = 0;
			COM3 = 0;
		
		break;		
		case 1:
	      segmentCharacters('E');
			COM0 = 0;
			COM1 = 1;
			COM2 = 0;
			COM3 = 0;
		
		break;
		case 2:
		 segmentCharacters('r');
			COM0 = 0;
			COM1 = 0;
			COM2 = 1;
			COM3 = 0;
		
		break;	
		case 3:
		 segmentCharacters('r');
			COM0 = 0;
			COM1 = 0;
			COM2 = 0;
			COM3 = 1;
		
		break;	
	}
}



void DisplaySupplyError(char cunterDigit )
{
	switch(cunterDigit) 
	{			
		case 0:
		 segmentCharacters('p');
			COM0 = 1;
			COM1 = 0;
			COM2 = 0;
			COM3 = 0;
		
		break;		
		case 1:
	      segmentCharacters('E');
			COM0 = 0;
			COM1 = 1;
			COM2 = 0;
			COM3 = 0;
		
		break;
		case 2:
		 segmentCharacters('r');
			COM0 = 0;
			COM1 = 0;
			COM2 = 1;
			COM3 = 0;
		
		break;	
		case 3:
		 segmentCharacters('r');
			COM0 = 0;
			COM1 = 0;
			COM2 = 0;
			COM3 = 1;
		
		break;	
	}
}



void DisplaySensorError(char cunterDigit )
{
	switch(cunterDigit) 
	{			
		case 0:
		 segmentCharacters('S');
			COM0 = 1;
			COM1 = 0;
			COM2 = 0;
			COM3 = 0;
		
		break;		
		case 1:
	      segmentCharacters('E');
			COM0 = 0;
			COM1 = 1;
			COM2 = 0;
			COM3 = 0;
		
		break;
		case 2:
		 segmentCharacters('n');
			COM0 = 0;
			COM1 = 0;
			COM2 = 1;
			COM3 = 0;
		
		break;	
		case 3:
		 segmentCharacters('E');
			COM0 = 0;
			COM1 = 0;
			COM2 = 0;
			COM3 = 1;
		
		break;	
	}
}













/*
void DisplayCharecters( unsigned char *stringOfCharacter,char clock )
{

	switch(clock)
	{ 	
		case 0:
		 segmentCharacters( stringOfCharacter[0]);
			COM0 = 1;
			COM1 = 0;
			COM2 = 0;
			COM3 = 0;
		
		break;	
			
		case 1:
	      segmentCharacters(stringOfCharacter[1]);
			COM0 = 0;
			COM1 = 1;
			COM2 = 0;
			COM3 = 0;
		
		break;
		
		case 2:
		 segmentCharacters(stringOfCharacter[2]);
			COM0 = 0;
			COM1 = 0;
			COM2 = 1;
			COM3 = 0;
		
		break;	
		
		case 3:
		 segmentCharacters(stringOfCharacter[3]);
			COM0 = 0;
			COM1 = 0;
			COM2 = 0;
			COM3 = 1;
		
		break;	
	}	
}


*/
//
//void DisplaySupplyError(char cunterDigit )
//{
//		switch(cunterDigit) 
//	{			
//		case 0:
//		 segmentCharacters('E');
//			COM0 = 1;
//			COM1 = 0;
//			COM2 = 0;
//			COM3 = 0;
//		
//		break;		
//		case 1:
//	      segmentCharacters('S');
//			COM0 = 0;
//			COM1 = 1;
//			COM2 = 0;
//			COM3 = 0;
//		
//		break;
//		case 2:
//		 segmentCharacters('E');
//			COM0 = 0;
//			COM1 = 0;
//			COM2 = 1;
//			COM3 = 0;
//		
//		break;	
//		case 3:
//		 segmentCharacters('N');
//			COM0 = 0;
//			COM1 = 0;
//			COM2 = 0;
//			COM3 = 1;
//		
//		break;	
//	}
//}