
#ifndef _MAIN_H_
#define _MAIN_H_
#include <ht67f2432.h>
#include "HT8_it.h"
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
#define MINIMUM_VOLTAGE_VALID 5
#define VOLTAGE_LOWBATTERY  3
#define POWER_SUPLY_CONNECT _pa6==1 
#define POWER_SUPLY_DISCONNECT _pa6==0 


void DisplayLooding(char cunterDigit );
float ReadVDD(void);
int Numbr=0;
int digcunt=0;
unsigned int i=0;


#define SCALE_FACTOR_NUM 64 // 4 * (1.6 * 10) as an integer
#define SCALE_FACTOR_DEN 1023
#define COEFF_NUM 133 // 0.133 * 1000 as an integer
#define COEFF_DEN 1000
#define OFFSET -368481 // -368.481 * 1000 as an integer
int vdd=5000;
int vdd1=0;
float voltage_battery=0;
float voltage_battery1=0;
int percent_of_battery=0; 
int adc_value_7 =0;
int adc_value_2 = 0;


typedef union parameter{
 unsigned int VoltageBattery;
 unsigned int GasValue;
 unsigned int GasErroreValue;
 unsigned int PersentOfBattery;
 unsigned int VDD
 
} Parametrs;
Parametrs Parametr;

char bufferVdd=0;
//#define minVoltageBattery 590
//#define maxVoltageBattery 890

//#define minVoltageBattery 3437//59
//#define maxVoltageBattery 4100//89
//#define percentageAccuracy 10
//#define voltageRange maxVoltageBattery-minVoltageBattery//30
//#define batteryPercentage(voltageBattery)((voltageBattery - minVoltageBattery)*100)/(maxVoltageBattery-minVoltageBattery)

/*#define batteryPercentage(voltageBattery)(0.133*voltageBattery-368.481)*/

#define a

#define VDD(ADC_VDD)(4*(1.6*ADC_VDD/1023))
#define batteryPercentage(ADCVoltageBattery,VDD)(0.133 *((ADCVoltageBattery*VDD)/1023)*1000 -368.481)



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
 unsigned short buffer=0;

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
	unsigned int pushButtonCunter=0;

	typedef enum
	{
		NORMAL,
		CHECK_BATTERY,
		TEST,
		DETECT,
		ERORE
		
	}mode;
		mode Mode;

	
	typedef enum
	{
		LOW_BATTERY,
		BATTRY_ERROR,
		SUPPLY_ERROR
		
	}Suplymode;
     Suplymode Suply;
	char tick;
#endif