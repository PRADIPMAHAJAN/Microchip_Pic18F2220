#include <xc.h>  // Include xc.h for __delay_ms

#define _XTAL_FREQ 8000000  

// Register and bit definitions for TRISD and PORTD
volatile unsigned char *TRISD_REG = (volatile unsigned char *)0x88;
volatile unsigned char *PORTD_REG = (volatile unsigned char *)0x08;

// Control pins
#define RS_BIT 0
#define RW_BIT 1
#define E_BIT  2

// Bit manipulation macros
#define SET_BIT(reg, bit) (reg |= (1 << bit))
#define CLEAR_BIT(reg, bit) (reg &= ~(1 << bit))

// Function to send a command to the LCD
void lcd_command(unsigned char command) {
    CLEAR_BIT(*PORTD_REG, RS_BIT);  // Select command register
    CLEAR_BIT(*PORTD_REG, RW_BIT);  // Write operation
    *PORTD_REG = command;  // Send the command to data lines
    SET_BIT(*PORTD_REG, E_BIT);  // Enable pulse
    __delay_ms(2);   // Short delay
    CLEAR_BIT(*PORTD_REG, E_BIT);  // Disable pulse
    __delay_ms(2);   // Short delay
}

// Function to send data to the LCD
void lcd_data(unsigned char data) {
    SET_BIT(*PORTD_REG, RS_BIT);  // Select data register
    CLEAR_BIT(*PORTD_REG, RW_BIT);  // Write operation
    *PORTD_REG = data;  // Send the data to data lines
    SET_BIT(*PORTD_REG, E_BIT);  // Enable pulse
    __delay_ms(2);   // Short delay
    CLEAR_BIT(*PORTD_REG, E_BIT);  // Disable pulse
    __delay_ms(2);   // Short delay
}

// Function to initialize the LCD
void lcd_init() {
    lcd_command(0x38); // 8-bit data, 2-line display, 5x8 font
    lcd_command(0x0C); // Display on, cursor off
    lcd_command(0x06); // Increment cursor position
    lcd_command(0x01); // Clear display
    __delay_ms(2);     // Short delay
}

// Function to display a string on the LCD
void lcd_puts(const char *str) {
    while (*str != '\0') {
        lcd_data(*str);
        str++;
    }
}

void main(void) {
    CLEAR_BIT(*TRISD_REG, 0); // Set PORTD0 as output for RS
    CLEAR_BIT(*TRISD_REG, 1); // Set PORTD1 as output for RW
    CLEAR_BIT(*TRISD_REG, 2); // Set PORTD2 as output for E

    lcd_init(); // Initialize the LCD
    
    while (1) {
        lcd_command(0x80); // Set cursor to the beginning of the first line
        lcd_puts("Hello, World!"); // Display a message
        
        __delay_ms(2000); // Wait for 2 seconds
        
        lcd_command(0x01); // Clear the display
        
        __delay_ms(2000); // Wait for 2 seconds again
    }
}