/*
 *	Nama File 	:	LedJam.h
 *	Deskripsi	: 	Library untuk mengedipkan led pada board jam.
 */

#ifndef _LEDJAM_h
#define _LEDJAM_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Kedip.h"

class LedJam
{
 public:
	LedJam(const uint8_t pinLedJam);
	void kedipLedJam();
};

#endif

