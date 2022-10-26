/*
 * header.h
 *
 * Created: 2022-10-25 08:56:36
 *
 *  Author: Jesper Falk Sv�rd
 */ 
/********************************************************************************
* header.h: inkluderingsdirektiv, makron m.m.
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

// S�tter klockfrekvensen f�r implementering av delay.
#define F_CPU 16000000UL

// Inkluderingsdirektiv f�r funktionalitet etc.
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// Makrodefinitioner f�r begriplighet.
#define LED1 0 // Lysdiod 1 ansluten till pin 8  / PORTB0.
#define LED2 1 // Lysdiod 2 ansluten till pin 9 / PORTB1.
#define LED3 2 // Lysdiod 3 ansluten till pin 10 / PORTB2.

#define LED1_ON PORTB |= (1 << LED1) // T�nder lysdiod 1.
#define LED2_ON PORTB |= (1 << LED2) // T�nder lysdiod 2.
#define LED3_ON PORTB |= (1 << LED3) // T�nder lysdiod 3.
#define LEDS_ON PORTB |= (1 << LED1) | (1 << LED2) | (1 << LED3) // T�nder samtliga lysdioder.

#define LED1_OFF PORTB &= ~(1 << LED1) // Sl�cker lysdiod 1.
#define LED2_OFF PORTB &= ~(1 << LED2) // Sl�cker lysdiod 2.
#define LED3_OFF PORTB &= ~(1 << LED3) // Sl�cker lysdiod 3.
#define LEDS_OFF PORTB &= ~((1 << LED1) | (1 << LED2) | (1 << LED3)) // Sl�cker samtliga lysdioder.

#define PREV1_BUTTON 3 // Tryckknapp ansluten till pin 11 / PORTB3.
#define FWD1_BUTTON 4 // Tryckknapp asnluten till pin 12 / PORTB4.
#define FWD2_BUTTON 5 // Tryckknapp ansluten till pin 13 / PORTB5.
#define RESET_BUTTON 2 // Tryckknapp asnluten till pin 2 / PORTD2
#define PREV2_BUTTON 3 // Tryckknapp ansluten till pin 3 / PORTD3.

#define PREV1_BUTTON_PRESSED (PINB & (1 << PREV1_BUTTON)) // Indikerar byte till f�reg�nde tillst�nd.
#define FWD1_BUTTON_PRESSED (PINB & (1 << FWD1_BUTTON)) // Indikerar byte till n�sta tillst�nd.
#define FWD2_BUTTON_PRESSED (PINB & (1 << FWD2_BUTTON)) // Indikerar byte till tillst�nd 2 steg fram�t.
#define RESET_BUTTON_PRESSED (PIND & (1 << RESET_BUTTON)) // Indikerar nedtryckning av reset-knappen.
#define PREV2_BUTTON_PRESSED (PIND & (1 << PREV2_BUTTON)) // Indikerar byte till tillst�nd 2 steg bak�t.

/********************************************************************************
* bool: Datatyp som indikerar sant eller falskt.
********************************************************************************/
typedef enum { false, true } bool;

/********************************************************************************
* led_state: Datatyp f�r lagring av lysdiodernas tillst�nd.
********************************************************************************/
enum led_state
{ 
	LED_STATE_OFF,
	LED_STATE_SLOW,
	LED_STATE_MED,
	LED_STATE_FAST,
	LED_STATE_ON
};

/********************************************************************************
* setup: Initiering av programmet.
********************************************************************************/
void setup(void);

/********************************************************************************
* fsm_reset: �terst�ller tillst�ndsmaskinen till startl�get, vilket inneb�r
*            att lysdioderna sl�cks.
********************************************************************************/
void fsm_reset(void);

/********************************************************************************
* fsm_uppdate: Uppdaterar tillst�ndsmaskinen utefter nuvarande tillst�nd samt
*              vilken tryckknapp som trycks ned.
********************************************************************************/
void fsm_update(void);

/********************************************************************************
* fsm_set_output: Uppdaterar tillst�ndsmaskinens utsignaler utefter aktuellt
*                 tillst�nd.
*
*                 blink_speed_ms: Lysdiodernas blinkhastighet vid blinkning.
********************************************************************************/
void fsm_set_output(const uint16_t blink_speed_ms);

#endif /* HEADER_H_ */