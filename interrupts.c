/*
 * interrupts.c
 *
 * Created: 2022-10-25 10:46:10
 *
 *  Author: Jesper Falk Svärd
 */ 
/********************************************************************************
* interrupts.c: ISR = Interrupt Service Routine.
********************************************************************************/
#include "header.h"

ISR (INT0_vect) // Fallande flank på pin 2, ska medföra reset.
{
	fsm_reset();
	return;
}

ISR (INT1_vect) // Stigande flank på pin 3.
{
	fsm_update();
	return;
}

// Hit kommer vi vid logisk förändring på pin 11 - 13, vi måste själva 
// kolla flanken (att någon knapp har trycks ned).
ISR (PCINT0_vect)
{
	if (PREV1_BUTTON_PRESSED || FWD1_BUTTON_PRESSED || FWD2_BUTTON_PRESSED) // Kollar om någon har tryckts ned.
	{
		fsm_update();
	}
	
	// Annars om uppsläppning av en knapp orsakade avbrottet så görs ingenting (oavsiktligt avbrott).
	return;
}