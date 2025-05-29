#ifndef ADC_H
#define	ADC_H

#include <xc.h>
#define _XTAL_FREQ 16000000UL

void setupADC(void);
unsigned int readADC(void);

#endif
