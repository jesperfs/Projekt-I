/*
 * Projekt-II.c
 *
 * Created: 2022-10-25 08:54:27
 *
 * Author : Jesper Falk Svärd
 */ 
/********************************************************************************
* Projekt-II: Implementering av en tillståndsmaskin för tre lysdioder samt 5 
*             tryckknappar där lysdioderna kan anta 5 tillstånd.
*             - OFF : Samtliga lysdioder hålls släckta kontinuerligt.
*             - SLOW: De tre lysdioderna blinkar i en slinga var 500e ms.
*             - MED : De tre lysdioderna blinkar i en slinga var 250e ms.
*             - FAST: De tre lysdioderna blinkar i en slinga var 50e ms.
*             - ON  : Samtliga lysdioder hålls tända kontinuerligt.
*
*             När någon av tryckknapparna blir nedtryckta skall ett avbrott
*             genereras, där tillståndsmaskinens tillstånd uppdateras, antingen
*             framåt eller bakåt 1-2 steg (eller släckning via reset), beroende
*             på vilken tryckknapp som trycktes ned. När detta sker så skall
*             lysdiodernas tillstånd förändras.
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