/*
 * header.h
 *
 * Created: 2022-10-25 08:56:36
 *
 *  Author: Jesper Falk Svärd
 */ 
/********************************************************************************
* header.h: inkluderingsdirektiv, makron m.m.
********************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

// Sätter klockfrekvensen för implementering av delay.
#define F_CPU 16000000UL

// Inkluderingsdirektiv för funktionalitet etc.
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// Makrodefinitioner för begriplighet.
#define LED1 0 // Lysdiod 1 ansluten till pin 8  / PORTB0.
#define LED2 1 // Lysdiod 2 ansluten till pin 9 / PORTB1.
#define LED3 2 // Lysdiod 3 ansluten till pin 10 / PORTB2.

#define LED1_ON PORTB |= (1 << LED1) // Tänder lysdiod 1.
#define LED2_ON PORTB |= (1 << LED2) // Tänder lysdiod 2.
#define LED3_ON PORTB |= (1 << LED3) // Tänder lysdiod 3.
#define LEDS_ON PORTB |= (1 << LED1) | (1 << LED2) | (1 << LED3) // Tänder samtliga lysdioder.

#define LED1_OFF PORTB &= ~(1 << LED1) // Släcker lysdiod 1.
#define LED2_OFF PORTB &= ~(1 << LED2) // Släcker lysdiod 2.
#define LED3_OFF PORTB &= ~(1 << LED3) // Släcker lysdiod 3.
#define LEDS_OFF PORTB &= ~((1 << LED1) | (1 << LED2) | (1 << LED3)) // Släcker samtliga lysdioder.

#define PREV1_BUTTON 3 // Tryckknapp ansluten till pin 11 / PORTB3.
#define FWD1_BUTTON 4 // Tryckknapp asnluten till pin 12 / PORTB4.
#define FWD2_BUTTON 5 // Tryckknapp ansluten till pin 13 / PORTB5.
#define RESET_BUTTON 2 // Tryckknapp asnluten till pin 2 / PORTD2
#define PREV2_BUTTON 3 // Tryckknapp ansluten till pin 3 / PORTD3.

#define PREV1_BUTTON_PRESSED (PINB & (1 << PREV1_BUTTON)) // Indikerar byte till föregånde tillstånd.
#define FWD1_BUTTON_PRESSED (PINB & (1 << FWD1_BUTTON)) // Indikerar byte till nästa tillstånd.
#define FWD2_BUTTON_PRESSED (PINB & (1 << FWD2_BUTTON)) // Indikerar byte till tillstånd 2 steg framåt.
#define RESET_BUTTON_PRESSED (PIND & (1 << RESET_BUTTON)) // Indikerar nedtryckning av reset-knappen.
#define PREV2_BUTTON_PRESSED (PIND & (1 << PREV2_BUTTON)) // Indikerar byte till tillstånd 2 steg bakåt.

/********************************************************************************
* bool: Datatyp som indikerar sant eller falskt.
********************************************************************************/
typedef enum { false, true } bool;

/********************************************************************************
* led_state: Datatyp för lagring av lysdiodernas tillstånd.
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
* fsm_reset: Återställer tillståndsmaskinen till startläget, vilket innebär
*            att lysdioderna släcks.
********************************************************************************/
void fsm_reset(void);

/********************************************************************************
* fsm_uppdate: Uppdaterar tillståndsmaskinen utefter nuvarande tillstånd samt
*              vilken tryckknapp som trycks ned.
********************************************************************************/
void fsm_update(void);

/********************************************************************************
* fsm_set_output: Uppdaterar tillståndsmaskinens utsignaler utefter aktuellt
*                 tillstånd.
*
*                 blink_speed_ms: Lysdiodernas blinkhastighet vid blinkning.
********************************************************************************/
void fsm_set_output(const uint16_t blink_speed_ms);

#endif /* HEADER_H_ */