/*
 *	Nama File 	:	Tombol.cpp
 *	Deskripsi	: 	Implementasi dari library Tombol.h
 */

#include "Tombol.h"

Tombol::Tombol(const uint8_t _pinTombol)
{
	pinTombol = _pinTombol;
	pinMode(pinTombol, INPUT_PULLUP);
	debounceTerakhir = 0;
	stateTerakhir = HIGH;
}

void Tombol::bacaState(boolean &stateIn, boolean &stateOut)
{
	boolean stateTerbaca = digitalRead(pinTombol);
	if (stateTerbaca != stateTerakhir)
	{
		debounceTerakhir = millis();
	}
	if (millis() - debounceTerakhir >= DEBOUNCING_TIME)
	{
		if (stateTerbaca != stateIn)
		{
			stateIn = stateTerbaca;
			if (stateIn == LOW)
			{
				stateOut = !(stateOut);
			}
		}
	}
	stateTerakhir = stateTerbaca;
}

