
#ifndef _MAIN_H_
#define _MAIN_H_
#include <ht67f2432.h>
#include <Display.h>
unsigned char SEG;
unsigned int GAS_ERR = 0;
unsigned int BAT_ADC = 0;
unsigned int BAT_ADC_D = 0;
unsigned int adc_GAS = 0;

unsigned char adc = 0;
unsigned int t1 = 0;
unsigned char BAT = 0;

unsigned int disply = 0;

unsigned long delay = 0;

unsigned char AN = 0;

unsigned int Digit[4];

bit disply_bat;
bit PB = 0;
bit fire_gas;
bit falt_BAT;

#define ADC_PIN _pa1 // A1/AN0

#define AN0 AN = 0;
#define AN1 AN = 1;
#define AN2 AN = 2;
#define AN3 AN = 3;




#define	BUZZER_ON       _pa4= 1
#define	BUZZER_OFF      _pa4= 0	

#define	LED_GREEN      _pc0

#define	LED_GREEN_ON    _pc0= 1	
#define	LED_GREEN_OFF   _pc0= 0	

#define	LED_RED_ON      _pc1= 1	
#define	LED_RED_OFF     _pc1= 0

#define	LED_YELLOW_ON   _pc2= 1	
#define	LED_YELLOW_OFF  _pc2= 0	

#define	RELAY_ON        _pb2= 1
#define RELAY_OFF   	_pb2= 0	

#define TIMER_CUNTER_INTRUPT _tb0f
#define TRESHOLD_DETECT_GAS 250
#define PRESEED_PUSHBUTUN _pb3==0
#define  MINIMUM_VOLTAGE_VALID 5
void DisplayLooding(char cunterDigit );
int Numbr=0;
int digcunt=0;
unsigned int i=0;

typedef union parameter{
 unsigned int VoltageBattery;
 unsigned int GasValue;
 unsigned int GasErroreValue;
 
} Parametrs;
Parametrs Parametr;


#define minVoltageBattery 1
#define maxVoltageBattery 33
#define percentageAccuracy 10
#define voltageRange maxVoltageBattery-minVoltageBattery
#define batteryPercentage(voltageBattery)(((voltageBattery - minVoltageBattery) / voltageRange) * 100)


typedef struct{
 unsigned int test;
 unsigned int lowBattry;
 unsigned int checkBattery;
 
} Cunters;
Cunters Cunter;
	
//	typedef enum
//	{
//		NORMAL,
//		BATTERY,
//		TEST,
//		DETECT,
//		LOW_BATTERY,
//		ERORE
//	}mode;
//	mode Mode

	bit pushButtonState=0;
	unsigned long pushButtonCunter=0;

//


/*Parametrs Parametr;*/
#endif