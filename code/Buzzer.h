/* 
 *	Nama File 	:	Buzzer.h
 *	Deskripsi	:	Library untuk setting dan membunyikan buzzer.
 */

#ifndef _BUZZER_h
#define _BUZZER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Kedip.h"

class Buzzer
{
 public:
	Buzzer(const uint8_t pinBuzzer);
	void buzz();
};

#endif

