#include<stdio.h>
#include<stdlib.h>
#include <xc.h>

void main(void) {

    TRISBbits.RB0 = 0;
    TRISCbits.RC1 = 1;
    OSCCON = 0x76;

    while (1) {
        if (PORTCbits.RC1 == 0) {
            for (int countDelay = 0; countDelay < 20; countDelay++) {
            };
            if (PORTCbits.RC1 == 0) {
                PORTBbits.RB0 = 1;
            } 
        }
        else {
                PORTBbits.RB0 = 0;
            }
    }
    
}
