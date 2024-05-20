#include "ADC.h" // Include the header file that contains necessary definitions and declarations for the ADC module.

//===========================================================
//*@brief      : ADC Init
//*@param[in]  : None
//*@retval     : None
//===========================================================
void S_ADC_Init()
{
    // Initialize the ADC module with specific configurations.
    _sadc0 = 0b00000111; // Configure ADC0 control register with appropriate settings.
    _sadc1 = 0b01101011; // Configure ADC1 control register with appropriate settings.
    _ade = 0; // Disable the analog-digital converter module.
    
   
    
}


//===========================================================
//*@brief      : Read ADC
//*@param[in]  : ADC channel: AN0, AN1, AN2, AN3, VBGREF, OPA0O, OPA1O, LINEV
//*@retval     : AD Value
//===========================================================
unsigned int  S_READ_ADC(unsigned char CH)
{
    unsigned int temp=0;

    
    // Switch statement to set the appropriate ADC channel based on the input parameter CH.
    switch(CH)
    {
        case 0:
            _RD_ADC_SET_AN0 // Set ADC channel to AN0.
            break;
        case 1:
            _RD_ADC_SET_AN1 // Set ADC channel to AN1.
            break;
        case 2:
            _RD_ADC_SET_AN2 // Set ADC channel to AN2.
            break;
        case 3:
            _RD_ADC_SET_AN3 // Set ADC channel to AN3.
            break;
        case 4:
            _RD_ADC_SET_VBGREF // Set ADC channel to VBGREF.
            break;
        case 5:
            _RD_ADC_SET_OPA0O // Set ADC channel to OPA0O.
            break;
        case 6:
            _RD_ADC_SET_OPA1O // Set ADC channel to OPA1O.
            break;
        case 7:
            _RD_ADC_SET_LINEV // Set ADC channel to LINEV.
            break;
        default:
            break;
    }
    
    _adcen = 1; // Enable the ADC module.
    GCC_DELAY(12); // Delay for stabilization of the ADC.
    _start = 0; // Clear the start bit.
    _start = 1; // Start the ADC conversion.
    _start = 0; // Clear the start bit after starting the conversion.
    while(_adbz); // Wait until ADC conversion is complete.
    _adcen = 0; // Disable the ADC module after the conversion.
   
 //temp =((_sadol>>4))|((_sadoh<<4)); // Read the high byte of the ADC result.

 
 

   // Read the high byte of the ADC result.
   //   /*temp=(temp)&(0x0fff);

 //temp=(temp + ((_sadoh << 8) | (_sadol))) / 2;
 
    if(_adrfs == 1)
    {   
     temp =((_sadol))|((_sadoh<<8));
    }
    else
    {
     temp =((_sadol>>6)|(_sadoh<<2));
    }
   
  // Ptr=&temp;

    return temp; // Return the ADC conversion result.
}