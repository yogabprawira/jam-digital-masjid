/*
 *	Nama File 	:	Tombol.h
 *	Deskripsi	: 	Library untuk setting tombol dan membaca state dari tombol.
 */

#ifndef _TOMBOL_h
#define _TOMBOL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define DEBOUNCING_TIME		50

class Tombol
{
private:
	uint8_t pinTombol;
	unsigned long debounceTerakhir;
	boolean stateTerakhir;
public:
	Tombol(const uint8_t _pinTombol);
	void bacaState(boolean &stateIn, boolean &stateOut);
};

#endif

