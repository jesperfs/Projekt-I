/*
 * setup.c
 *
 * Created: 2022-10-25 09:19:54
 *
 *  Author: Jesper Falk Svärd
 */ 
/********************************************************************************
* setup.c: Innehåller initieringsrutiner.
*
*          Statiska funktioner är bara synliga och åtkomliga i aktuell fil.
********************************************************************************/
#include "header.h"

// Statiska funktioner:
static inline void init_ports(void);
static inline void init_interrupts(void);

/********************************************************************************
* setup: Initierar mikrodatorn vid start.
********************************************************************************/
void setup (void)
{
	init_ports();
	init_interrupts();
	fsm_reset();
	return;
}

/********************************************************************************
* init_ports: Sätter lysdiodernas pins till utportar och sätter tryckknapparnas
*             pins till aktiva inportar där signalen alltid blir 0 eller 1.
********************************************************************************/
static inline void init_ports (void)
{
	DDRB = (1 << LED1) | (1 << LED2) | (1 << LED3); // Sätter lysdioderna till utportar.
	PORTB = (1 << PREV1_BUTTON) | (1 << FWD1_BUTTON) | (1 << FWD2_BUTTON); // Sätter PORTB tryckknapparna till inportar.
	PORTD = (1 << RESET_BUTTON) | (1 << PREV2_BUTTON); // Sätter PORTD tryckknapparna till inportar.
	return;
}

/********************************************************************************
* init_interrupts: Aktiverar avbrott på pin 2 - 3 / PORTD2 - PORTD3 samt
*                  pin 11 - 13 / PORTB3 - PORTB5.
********************************************************************************/
static inline void init_interrupts (void)
{
	asm("SEI"); // Aktiverar avbrott globalt.
	
	EICRA = ((1 << ISC01) | (1 << ISC10) | (1 << ISC11)); // Ställer in avbrott INT0 på fallande flank och INT1 på stigande flank.
	EIMSK = (1 << INT0) | (1 << INT1); // Aktiverar avbrott på PIN 2 - 3 / PORTD2 - PORTD3.
	
	PCICR = (1 << PCIE0); // Aktiverar avbrott på I/O-port B (PIN 8 – 13) (möjliggör avbrott om de aktiveras).
	PCMSK0 = (1 << PCINT5) | (1 << PCINT4) | (1 << PCINT3); // Aktiverar specifikt avbrott på PORTB3 - PORTB5 (PIN 11 - 13).
	return;

}