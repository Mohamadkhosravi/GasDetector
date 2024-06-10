
#ifndef _MAIN_H_
#define _MAIN_H_
#include <ht67f2432.h>
#include "HT8_it.h"
#include <Display.h>






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

#define TRESHOLD_DETECT_GAS     250
#define MINIMUM_VOLTAGE_VALID   3300
#define VOLTAGE_LOWBATTERY      3400

#define TIMER_CUNTER_INTRUPT    _tb0f
#define PRESEED_PUSHBUTUN       _pb3==0
#define POWER_SUPLY_CONNECT     _pa6==1 
#define POWER_SUPLY_DISCONNECT  _pa6==0 



//
//#define SCALE_FACTOR_NUM 64 // 4 * (1.6 * 10) as an integer
//#define SCALE_FACTOR_DEN 1023
//#define COEFF_NUM 133 // 0.133 * 1000 as an integer
//#define COEFF_DEN 1000
//#define OFFSET -368481 // -368.481 * 1000 as an integer

unsigned long delay = 0;
unsigned int i=0;
float vdd=5000;
float voltage_battery=0;
int percent_of_battery=0; 
char displayClock=0;
char bufferVdd=0;

typedef union parameter{
 unsigned int VoltageBattery;
 unsigned int GasValue;
 unsigned int GasErroreValue;
 unsigned int PersentOfBattery;
 unsigned int VDD
 
} Parametrs;
Parametrs Parametr;



#define VDD(ADC_VDD)(4*(1.6*ADC_VDD/1023))
#define batteryPercentage(VoltageBattery)(0.105263*VoltageBattery-338.421)


typedef struct
{
 unsigned int test;
 unsigned int lowBattry;
 unsigned int checkBattery;
 
} Cunters;
Cunters Cunter;
 unsigned short buffer=0;

	
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
#endif