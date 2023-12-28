#include<stdio.h>
#include<stdlib.h>
#include <xc.h>

void main(void) {
    
    TRISBbits.RB0 = 0;
    OSCCON = 0x76;
    
    while(1)
    {
        LATBbits.LATB0 = ~ LATBbits.LATB0;
        
        for(int countDelay = 0; countDelay < 20; countDelay++)
        {};
        
    }
}
