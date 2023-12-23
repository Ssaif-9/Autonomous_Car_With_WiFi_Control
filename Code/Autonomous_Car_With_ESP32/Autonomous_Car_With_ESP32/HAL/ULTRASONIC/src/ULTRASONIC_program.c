/*
 * ULTRASONIC_program.c
 *
 * Created: 05-Nov-23 2:52:15 PM
 *  Author: 2A_TEAM
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

#include "../../../UTILITES/STD_TYPE.h"
#include "../../../UTILITES/BIT_MATH.h"

#include "../../../MCAL/DIO/include/DIO_config.h"
#include "../../../MCAL/DIO/include/DIO_interface.h"
#include "../../../MCAL/DIO/include/DIO_private.h"

#include "../include/ULTRASONIC_config.h"
#include "../include/ULTRASONIC_interface.h"
#include "../include/ULTRASONIC_private.h"

#include <avr/io.h>




// ----- Ultrasonic Initialization Configuration ----- //
void Ultrasonic_init()
{
	DIO_SetPinDirection(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,DIO_PIN_OUTPUT);
}


// ----- Ultrasonic Distance Measurement ----- //
void Ultrasonic_ReadDistance(f64* distance)
{
	u8 Echo_Value;
	u64 count = 0;					// Time Counts Variable
	// Distance Between Ultrasonic & Obstacle
	//choose which Us who will receive  the trigger
	DIO_SetPinValue(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,DIO_PIN_HIGH);
	_delay_us(10);
	DIO_SetPinValue(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,DIO_PIN_LOW);
	
	//wait till the one of ECHO arrived
	while((PIND & (1<<3)) >>3 == 0);
	//calculate the ECHO time
	while((PIND & (1<<3)) >>3 == 1){
		// Converting The Counts To Microseconds Variable
		_delay_us(1);
		count++;
	}
	*distance = (f64)count/40.00;					// Distance Equation.
}