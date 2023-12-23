/*
 * Helper.c
 *
 * Created: 22-Dec-23 11:18:52 PM
 *  Author: 2A_TEAM
 */ 

#include "../UTILITES/STD_TYPE.h"

u8* FloatToString(f64 Number) {
	u8 str[16];
	u8 *tmpsign = (Number < 0) ? "-" : "";
	f32 tmpval = (Number < 0) ? -Number : Number;
	u16 tmpint1 = (u16)tmpval;
	f32 tmpfrac = tmpval - (float)tmpint1;
	u16 tmpint2 = tmpfrac * 10000;
	sprintf(str, "%s%d.%04d", tmpsign, tmpint1, tmpint2);

	// Allocate memory for the string and copy it
	char * String = (char *)malloc(strlen(str) + 1);
	strcpy(String, str);
	return String;
}