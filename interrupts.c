/*
 * interrupts.c
 *
 * Created: 2022-10-25 10:46:10
 *
 *  Author: Jesper Falk Sv�rd
 */ 
/********************************************************************************
* interrupts.c: ISR = Interrupt Service Routine.
********************************************************************************/
#include "header.h"

ISR (INT0_vect) // Fallande flank p� pin 2, ska medf�ra reset.
{
	fsm_reset();
	return;
}

ISR (INT1_vect) // Stigande flank p� pin 3.
{
	fsm_update();
	return;
}

// Hit kommer vi vid logisk f�r�ndring p� pin 11 - 13, vi m�ste sj�lva 
// kolla flanken (att n�gon knapp har trycks ned).
ISR (PCINT0_vect)
{
	if (PREV1_BUTTON_PRESSED || FWD1_BUTTON_PRESSED || FWD2_BUTTON_PRESSED) // Kollar om n�gon har tryckts ned.
	{
		fsm_update();
	}
	
	// Annars om uppsl�ppning av en knapp orsakade avbrottet s� g�rs ingenting (oavsiktligt avbrott).
	return;
}