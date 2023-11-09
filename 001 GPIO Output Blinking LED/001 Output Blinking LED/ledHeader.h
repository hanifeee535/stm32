#include <stdint.h>

#define pRccAPB2  *(uint32_t*) 0x40021018
#define pGpioA *(uint32_t*) 0x40010800
#define pGpioB *(uint32_t*) 0x40010C00
#define  pGpioC  *(uint32_t*) 0x40011000 
#define	pPortCODR  *(uint32_t*) 0x4001100C 




//Define the ports
#define portA 1
#define portB 2
#define portC 3

// Define Mode of ports

#define input 0
#define output_10Mhz 1
#define output_2Mhz 2
#define output_50Mhz 3

//Define the port configuration for input mode

#define analog_in 0
#define floating_in 1
#define pp_in 2

//Define the port configuration for output mode

#define gp_output 0
#define open_drain_output 1
#define af_pp_output 2
#define af_od_output 3

//Define State
#define HIGH 1
#define LOW 0

void config_gp ( uint32_t port , uint32_t pin, uint32_t mode, uint32_t config);
void write_gp (uint32_t port, uint32_t pin, uint32_t state);





