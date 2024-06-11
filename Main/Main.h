
#ifndef _MAIN_H_
#define _MAIN_H_

#include <ht67f2432.h>
#include <Display.h>
#include <ADC.h>





#define	BUZZER_ON       _pa4= 1
#define	BUZZER_OFF      _pa4= 0	
#define	LED_GREEN       _pc0
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
#define PERSENTEAGE_LOWBATTRY   19
#define TIMER_CUNTER_INTRUPT    _tb0f
#define PRESEED_PUSHBUTUN       _pb3==0
#define POWER_SUPLY_CONNECT     _pa6==1 
#define POWER_SUPLY_DISCONNECT  _pa6==0 
#define MINIMUM_CURRENT_SENSOR  5
#define START_DELAY             15000
#define START_BLINK_ON          1000
#define START_BLINK_OFF         2000
#define BATTRY_ERROR_BLINK_ON   1000
#define BATTRY_ERROR_BLINK_OFF  2000
#define SUPPLY_ERROR_BLINK_ON   1000
#define SUPPLY_ERROR_BLINK_OFF  2000
#define LOW_BATTERY_BLINK_ON    300
#define LOW_BATTERY_BLINK_OFF   600						
#define TEST_DISPLAY_VIWE       8888
#define DETECT_DISPLAY_VIWE     TRESHOLD_DETECT_GAS 
#define TEST_TIMEOUT            1000
#define CHECK_BATTERY_TIMEOUT   500
#define AVDD                    5000.0
#define COEFFICIENT             4.8875855327 //(AVDD/1023.0)
#define b                       338.421
#define a                       0.105263
#define VDD(ADC_VDD)(4*(1.6*ADC_VDD/1023))
#define batteryPercentage(VoltageBattery)(a*VoltageBattery-b)




float voltage_battery=0;
int percent_of_battery=0; 
char displayClock=0;
char bufferVdd=0;
unsigned int Cunter=0;
unsigned short buffer=0;
bit pushButtonState=0;
unsigned int pushButtonCunter=0;



typedef union parameter{
 //unsigned int VoltageBattery;
 unsigned int GasValue;
 //unsigned int GasErroreValue;
 //unsigned int PersentOfBattery;
 //unsigned int VDD
 
} Parametrs;
Parametrs Parametr;




typedef enum
{
	NORMAL,
	CHECK_BATTERY,
	TEST,
	DETECT,
	SENSOR_ERRORE
	
}mode;
	mode Mode;

typedef enum
{
    NORMAL_POWER, 
	BATTRY_ERROR,
	SUPPLY_ERROR,
	LOW_BATTERY
	
}Suplymode;
 Suplymode SuplyStatus;
#endif