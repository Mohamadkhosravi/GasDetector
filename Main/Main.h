
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
#define TRESHOLD_DETECT_GAS 2500
#define PRESEED_PUSHBUTUN _pb3==0
#define  MINIMUM_VOLTAGE_VALID 5
#define  VOLTAGE_LOWBATTERY  3
#define POWER_SUPLY_CONNECT _pa6==1 
#define POWER_SUPLY_DISCONNECT _pa6==0 


void DisplayLooding(char cunterDigit );
float ReadVDD(void);
int Numbr=0;
int digcunt=0;
unsigned int i=0;

typedef union parameter{
 unsigned int VoltageBattery;
 unsigned int GasValue;
 unsigned int GasErroreValue;
 
} Parametrs;
Parametrs Parametr;


//#define minVoltageBattery 590
//#define maxVoltageBattery 890

#define minVoltageBattery 3437//59
#define maxVoltageBattery 4100//89
#define percentageAccuracy 10
#define voltageRange maxVoltageBattery-minVoltageBattery//30
//#define batteryPercentage(voltageBattery)((voltageBattery - minVoltageBattery)*100)/(maxVoltageBattery-minVoltageBattery)

#define batteryPercentage(voltageBattery)(0.133*voltageBattery-368.481)

//float a = 66.67;
//float b = -183.33;
//
//  
//  float soc = 66.67 * voltage + -183.33;


typedef struct
{
 unsigned int test;
 unsigned int lowBattry;
 unsigned int checkBattery;
 
} Cunters;
Cunters Cunter;
 char buffer=0;
float AVDD=0.0;	
char displayClock=0;	
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



/*Parametrs Parametr;*/
#endif