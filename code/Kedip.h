/*
 *	Nama File 	:	Kedip.h
 *	Deskripsi	: 	Library untuk melakukan on off dengan waktu tertentu.
 */

#ifndef _KEDIP_h
#define _KEDIP_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Kedip
{
private:
	uint8_t pinKedip;
	boolean kedipState;
	unsigned long previousMillis;

 public:
	Kedip(const uint8_t _pinKedip);
	void berkedip(const unsigned long waktuNyala, const unsigned long waktuMati);
	void setState(boolean stateKedip);
};

#endif

