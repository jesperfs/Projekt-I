/*
 * Projekt-II.c
 *
 * Created: 2022-10-25 08:54:27
 *
 * Author : Jesper Falk Sv�rd
 */ 
/********************************************************************************
* Projekt-II: Implementering av en tillst�ndsmaskin f�r tre lysdioder samt 5 
*             tryckknappar d�r lysdioderna kan anta 5 tillst�nd.
*             - OFF : Samtliga lysdioder h�lls sl�ckta kontinuerligt.
*             - SLOW: De tre lysdioderna blinkar i en slinga var 500e ms.
*             - MED : De tre lysdioderna blinkar i en slinga var 250e ms.
*             - FAST: De tre lysdioderna blinkar i en slinga var 50e ms.
*             - ON  : Samtliga lysdioder h�lls t�nda kontinuerligt.
*
*             N�r n�gon av tryckknapparna blir nedtryckta skall ett avbrott
*             genereras, d�r tillst�ndsmaskinens tillst�nd uppdateras, antingen
*             fram�t eller bak�t 1-2 steg (eller sl�ckning via reset), beroende
*             p� vilken tryckknapp som trycktes ned. N�r detta sker s� skall
*             lysdiodernas tillst�nd f�r�ndras.
********************************************************************************/
/********************************************************************************
* main.c: Vi anropar setup samt
********************************************************************************/
#include "header.h"

int main(void)
{
	setup();
	
    while (true) 
    {
		fsm_set_output(100);
    }
	
	return 0;
}