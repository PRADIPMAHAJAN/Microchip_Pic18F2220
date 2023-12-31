#include<stdio.h>
#include<stdlib.h>
#include <xc.h>
#define _XTAL_FREQ 8000000

unsigned char const SEGMENT_MAP[10] = {0X3F, //Hex value to display the number 0

                    0X06, //Hex value to display the number 1
                    0X5B, //Hex value to display the number 2
                    0X4F, //Hex value to display the number 3
                    0X66, //Hex value to display the number 4
                    0X6D, //Hex value to display the number 5
                    0X7C, //Hex value to display the number 6
                    0X07, //Hex value to display the number 7
                    0X7F, //Hex value to display the number 8
                    0X6F  //Hex value to display the number 9
                 }; //End of Array for displaying numbers from 0 to 9

void main(void) {

    TRISCbits.RC1 = 0x01; // Input
    TRISB = 0x00; //Output
    OSCCON = 0x76;
    char digit = 0;

    while (1) {
        digit++;
        
        if(digit > 9)
        {
            digit = 0;
        }
        else
            
        {
            PORTB = SEGMENT_MAP[digit];
        }
        
        __delay_ms(1000);
    }
    
}
