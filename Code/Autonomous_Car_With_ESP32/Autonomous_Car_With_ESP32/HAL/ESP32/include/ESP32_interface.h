/*
 * ESP32_interface.h
 *
 * Created: 03-Dec-23 1:07:06 PM
 *  Author: 2A_TEAM
 */ 


#ifndef ESP32_INTERFACE_H_
#define ESP32_INTERFACE_H_


ESP32_init               (void);
ESP32_ReceiveChar        (u8* ReceiveData);
ESP32_TransimitChar      (u8 TransimitData);
ESP32_TransimitString    (u8* TransimitData);

#endif /* ESP32_INTERFACE_H_ */