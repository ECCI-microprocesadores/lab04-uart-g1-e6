#include <xc.h>
#include "uart.h"
#include "ADC.h"

#pragma config FOSC = INTIO67  // Oscilador interno
#pragma config WDTEN = OFF     // Watchdog Timer apagado
#pragma config LVP = OFF       // Low Voltage Programming off

#define _XTAL_FREQ 16000000UL  // Frecuencia del oscilador 16MHz

void main(void) {
    
    OSCCON = 0b01110000;  // Oscilador interno a 16MHz
    
    UART_Init();          // Inicializa UART
    setupADC();
    
    while(1) {
         unsigned int valorADC = readADC();
        float voltaje = (valorADC * 5.0) / 1023.0;

        UART_WriteString("Voltaje: ");
        UART_WriteVoltage(voltaje);  // Mostrar valor en voltios
        UART_WriteString(" V\r\n");

        __delay_ms(1000);
    }
}
