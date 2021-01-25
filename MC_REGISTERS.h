/*
 * File Name: MC_REGISTERS.h
 * Creation Date: 07/20/2020
 * Author: Rehab
 * Description: Header File for registers' addresses of ATMAGA32, bits' names....
 */ 

#ifndef MC_REGISTERS_H_
#define MC_REGISTERS_H_

//FILES INCLUDING
#define F_CPU 10000000ul
#include <util/delay.h>
#include "STD_TYPES.h"

//BITS
#define BIT0 0
#define BIT1 1
#define BIT2 2
#define BIT3 3
#define BIT4 4
#define BIT5 5
#define BIT6 6
#define BIT7 7
/************************************************************************/
/*                         GENERAL REGISTERS                            */
/************************************************************************/
//GENERAL REGISTERS
#define SFIOR *((volatile uint8*)(0X50))
#define SREG *((volatile uint8*)(0X5F))
#define MCUCSR *((volatile uint8*)(0X54))


#define SF_IOR SFIOR
#define S_REG SREG
#define MCUCS_R MCUCSR
//SF_IOR REGISTER BITS
#define ACME BIT3
#define ADTS0 BIT5
#define ADTS1 BIT6
#define ADTS2 BIT7
//S_REG REGISTER BITS
#define I BIT7
//MCUCS_R REGISTER BITS
#define PORF BIT0
#define EXTRF BIT1
#define BORF BIT2
#define WDRF BIT3
#define JTRF BIT4
/************************************************************************/
/*                         GPIO REGISTERS                               */
/************************************************************************/
//PORTA REGISTERS
#define PORTA_BASE 0X39
#define PINA *((volatile uint8*)(PORTA_BASE))
#define DDRA *((volatile uint8*)(PORTA_BASE+1))
#define PORTA *((volatile uint8*)(PORTA_BASE+2))


#define DDR_A DDRA 
#define VALR_A PORTA
#define INPUTR_A PINA
//PORTB REGISTERS 
#define PORTB_BASE 0X36
#define PINB *((volatile uint8*)(PORTB_BASE))
#define DDRB *((volatile uint8*)(PORTB_BASE+1))
#define PORTB *((volatile uint8*)(PORTB_BASE+2))


#define DDR_B DDRB
#define VALR_B PORTB
#define INPUTR_B PINB
//PORTC REGISTERS
#define PORTC_BASE 0X33
#define PINC *((volatile uint8*)(PORTC_BASE))
#define DDRC *((volatile uint8*)(PORTC_BASE+1))
#define PORTC *((volatile uint8*)(PORTC_BASE+2))


#define DDR_C DDRC
#define VALR_C PORTC
#define INPUTR_C PINC
//PORTD REGISTERS
#define PORTD_BASE 0X30
#define PIND *((volatile uint8*)(PORTD_BASE))
#define DDRD *((volatile uint8*)(PORTD_BASE+1))
#define PORTD *((volatile uint8*)(PORTD_BASE+2))


#define DDR_D DDRD
#define VALR_D PORTD
#define INPUTR_D PIND
/************************************************************************/
/*                          ADC REGISTERS                               */
/************************************************************************/
//ADC REGISTERS
#define ADCL *((volatile uint8*)(0X24))
#define ADCH *((volatile uint8*)(0X25))
#define ADC *((volatile uint16*)(0X24))
#define ADCSRA *((volatile uint8*)(0X26))
#define ADMUX *((volatile uint8*)(0X27))


#define ADC_L ADCL
#define ADC_H ADCH
#define ADC_CSRA ADCSRA 
#define ADC_MUX ADMUX
//ADC_MUX REGISTER BITS
#define MUX0 BIT0
#define MUX1 BIT1
#define MUX2 BIT2
#define MUX3 BIT3
#define MUX4 BIT4
#define ADLAR BIT5
#define REFS0 BIT6
#define REFS1 BIT7
//ADC_CSRA REGISTER BITS
#define ADPS0 BIT0
#define ADPS1 BIT1
#define ADPS2 BIT2
#define ADIE BIT3
#define ADIF BIT4
#define ADATE BIT5
#define ADSC BIT6
#define ADEN BIT7
/************************************************************************/
/*                        EXTERNAL INTERRUPT REGISTERS                  */
/************************************************************************/
//EXTERNAL INTERRUPT REGISTERS
#define GICR *((volatile uint8*)(0X5B))
#define GIFR *((volatile uint8*)(0X5A))
#define MCUCR *((volatile uint8*)(0X55))
#define MCUCSR *((volatile uint8*)(0X54))


#define GIC_R GICR
#define GIF_R GIFR
#define MCUC_R MCUCR
#define MCUCS_R MCUCSR
//GIC_R REGISTER BITS
#define INT2 BIT5
#define INT0 BIT6
#define INT1 BIT7
//GIF_R REGISTER BITS
#define INTF2 BIT5
#define INTF0 BIT6
#define INTF1 BIT7
//MCUC_R REGISTER BITS
#define ISC00 BIT0
#define ISC01 BIT1
#define ISC10 BIT2
#define ISC11 BIT3
//MCUCS_R REGISTER BITS
#define ISC2 BIT6
/************************************************************************/
/*                      WATCHDOG TIMER REGISTERS                        */
/************************************************************************/
//WATCHDOG TIMER REGISTERS  
#define WDTCR *((volatile uint8*)(0X41))


#define WDTC_R WDTCR
//WDTC_R REGISTER BITS
#define WDP0 BIT0
#define WDP1 BIT1
#define WDP2 BIT2
#define WDE BIT3
#define WDTOE BIT4
/************************************************************************/
/*                         GENERAL TIMERS REGISTERS                     */
/************************************************************************/
//GENERAL TIMERS REGISTERS
#define TIMSK *((volatile uint8*)(0X59))
#define TIFR *((volatile uint8*)(0X58))

#define TIMSK_R TIMSK
#define TIF_R TIFR
//TIMSK_R REGISTER BITS
#define TOIE0 BIT0
#define OCIE0 BIT1
#define TOIE1 BIT2
#define OCIE1B BIT3
#define OCIE1A BIT4
#define TICIE1 BIT5
#define TOIE2 BIT6
#define OCIE2 BIT7
//TIF_R REGISTER BITS
#define TOV0 BIT0
#define OCF0 BIT1
#define TOV1 BIT2
#define OCF1B BIT3
#define OCF1A BIT4
#define ICF1 BIT5
#define TOV2 BIT6
#define OCF2 BIT7
/************************************************************************/
/*                         TIMER0 REGISTERS                             */
/************************************************************************/
//TIMER0 REGISTERS 
#define TCCR0 *((volatile uint8*)(0X53))
#define TCNT0 *((volatile uint8*)(0X52))
#define OCR0 *((volatile uint8*)(0X5C))

#define TCCR_0 TCCR0 
#define TCNT_0 TCNT0
#define OCR_0 OCR0
//TCCR_0 REGISTER BITS
#define CS00 BIT0
#define CS01 BIT1
#define CS02 BIT2
#define WGM01 BIT3
#define COM00 BIT4
#define COM01 BIT5
#define WGM00 BIT6
#define FOC0 BIT7
/************************************************************************/
/*                         TIMER1 REGISTERS                             */
/************************************************************************/
//#define 

/************************************************************************/
/*                         TIMER2 REGISTERS                             */
/************************************************************************/
//#define 

/************************************************************************/
/*                         EEPROM REGISTERS                             */
/************************************************************************/
//EEPROM REGISTERS
#define EEARH *((volatile uint8*)(0X3F))
#define EEARL *((volatile uint8*)(0X3E))
#define EEAR *((volatile uint16*)(0X3E))
#define EEDR *((volatile uint8*)(0X3D))
#define EECR *((volatile uint8*)(0X3C))


#define EEAR_H EEARH
#define EEAR_L EEARL
#define EEA_R EEAR
#define EED_R EEDR
#define EEC_R EECR
//EEC_R REGISTER BITS
#define EERE BIT0
#define EEWE BIT1
#define EEMWE BIT2
#define EERIE BIT3
/************************************************************************/
/*                          USART REGISTERS                             */
/************************************************************************/
//USART REGISTERS
#define UCSRB *((volatile uint8*)(0X2A))


#define UCS_RB UCSRB
//UCS_RB REGISTER BITS
#define UDRIE BIT5
#define TXCIE BIT6
#define RXCIE BIT7
/************************************************************************/
/*                           SPI REGISTERS                              */
/************************************************************************/
//SPI REGISTERS
#define SPCR *((volatile uint8*)(0X2D))


#define SPC_R SPCR
//SPC_R REGISTER BITS
#define SPIE BIT7
/************************************************************************/
/*                           TWI REGISTERS                              */
/************************************************************************/
//TWI REGISTERS
#define TWCR *((volatile uint8*)(0X56))


#define TWC_R TWCR
//TWC_R REGISTER BITS
#define TWIE BIT0
/************************************************************************/
/*                   ANALOG COMPARATOR REGISTERS                        */
/************************************************************************/
//ANALOG COMPARATOR REGISTERS  
#define ACSR *((volatile uint8*)(0X28))


#define ACS_R ACSR
//ACS_R REGISTER BITS
#define ACIS0 BIT0
#define ACIS1 BIT1
#define ACIC BIT2
#define ACIE BIT3
#define ACI BIT4
#define ACO BIT5
#define ACBG BIT6
#define ACD BIT7
/************************************************************************/
#endif