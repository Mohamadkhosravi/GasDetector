
#ifndef _DISPLAY_H_
#define _DISPLAY_H_
#include <ht67f2432.h>

#define COM0 _pb5	 // PB5
#define COM1 _pb6	 // PB6
#define COM2 _pb7	 // PB7
#define COM3 _pb4	 // PB4
#define SEGA _pc7	 // PC7
#define SEGB _pd0	 // PD0
#define SEGC _pc4	 // PC4
#define SEGD _pa7	 // PA7
#define SEGE _pc6	 // PC6
#define SEGF _pd1	 // PD1
#define SEGG _pc3	 // PC3
#define SEGH _pc5	 // PC5

void DisplayInit(void);
void Display(int number, char character);
void segmentNumbers(unsigned char n);
void segmentCharacters(unsigned char n);
void DisplayLooding(char cunterDigit );
#endif