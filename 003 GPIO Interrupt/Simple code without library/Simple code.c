Author: MD. Soyabbir Abu Hanif;
Institution: Tampere University, Finland;
Program name: MSc in Embedded Systems;
Email: hanifseceee535@gmail.com ;
*/

/*
Hardware setup:
								output = PC13
								Input = PA 0 as an external interrupt
Algorithm:
								Input button is pressed >>Interrupt will occured => LED will start blinking;
								Again, input button pressed>> interrupt will occured => LED will stoped blinking

*/

#include <stdint.h>

uint32_t volatile *pRCC_Apb2En = (uint32_t*) 0x40021018;
uint32_t volatile *pGPIOA = (uint32_t*) 0x40010800;
uint32_t volatile *pGPIOC = (uint32_t*) 0x40011004;
uint32_t volatile *pODR = (uint32_t*) 0x4001100C;
uint32_t volatile *pIDR = (uint32_t*) 0x40010808;
uint32_t volatile *pAFIO_EXTCR1 = (uint32_t*) 0x40010008;
uint32_t volatile *pEXTI_IMR = (uint32_t*) 0x40010400;
uint32_t volatile *pEXTI_RTSR = (uint32_t*) 0x40010408;
uint32_t volatile *pEXTI_PR = (uint32_t*) 0x40010414;
uint32_t volatile *pNVIC_ISERO = (uint32_t*) 0xE000E100;

volatile uint8_t interrupt_Occurred = 0;

void delay ( int volatile rep);
void EXTI0_IRQHandler (void) ;


void EXTI0_IRQHandler (void) {
	if (*pEXTI_PR & (1<<0))  // Checking if EXT line 0 interrupt flag is set or not
		{
			if (interrupt_Occurred == 0){ interrupt_Occurred = 1; }
			else { interrupt_Occurred = 0; }
		
			*pEXTI_PR |= (1<<0); // Clearing the interrupt flug
	  }
}

int main ()
{
	//Enabling the clock for GPIO A, GPIOCC and alternative function AFIO
	*pRCC_Apb2En |= (1<<2) | (1<<4) | (1<<0);

	//configuring PA0 for external interrupt

	*pGPIOA &= (unsigned) ~ (0xF <<0); //clearing the bits
	*pGPIOA |= 0x8 <<0 ;  //configuring as input pull up
	
	// configuring the GPIO C13 pin for output push pull
	*pGPIOC &= (unsigned) ~(0xF<<20); //clearing the data
	*pGPIOC |= 0x3<< 20; //setting the value
	
	//Enabling and configuring the External interrupt Controller (EXTI) for line 0
	
	*pAFIO_EXTCR1 &= (unsigned) ~ (0xF <<0); //clearing External interrupt configuration register EXTI0 bits
	*pEXTI_IMR |= 1<<0; //Enabling Interrupt Mask register (EXT_IMR) on line 0
	*pEXTI_RTSR |= 1<<0 ; //Enabling Rising Trigger Selection Register (EXT_RTSR) on line 0
	
	// Enable and set EXTI0 Interrupt to the lowest priority
	*pNVIC_ISERO |= (1 << 6);
	while (1) 
	{
		if (interrupt_Occurred){
			*pODR &= (unsigned) ~ 1<<13;
			
			delay (10);
			*pODR |= 1<<13;
			delay (10);
			
		}
	
	}
	
}

void delay (int volatile rep)
{
	int volatile i;
	for (rep; rep>0; rep--)
	{
		for (i= 100000; i>0; i--)
		{
		
		}
	}
}
