/*
 * ESP32_progarm.c
 *
 * Created: 03-Dec-23 1:06:34 PM
 *  Author: 2A_TEAM
 */ 

#include "../../../UTILITES/STD_TYPE.h"
#include "../../../UTILITES/BIT_MATH.h"

#include "../../../MCAL/UART/include/UART_config.h"
#include "../../../MCAL/UART/include/UART_interface.h"
#include "../../../MCAL/UART/include/UART_private.h"

#include "../../../MCAL/DIO/include/DIO_config.h"
#include "../../../MCAL/DIO/include/DIO_interface.h"
#include "../../../MCAL/DIO/include/DIO_private.h"

#include "../include/ESP32_config.h"
#include "../include/ESP32_interface.h"
#include "../include/ESP32_private.h"


ESP32_init(void)
{
	UART_init();
}

ESP32_ReceiveChar(u8* ReceiveData)
{
	UART_ReceiveChar(ReceiveData);	
}

ESP32_TransimitChar(u8 TransimitData)
{
	UART_TransmiteChar(TransimitData);
}

ESP32_TransimitString(u8* TransimitData)
{	
	UART_TransmiteString(TransimitData);	
}