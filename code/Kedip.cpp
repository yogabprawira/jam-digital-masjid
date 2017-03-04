/*
 *	Nama File 	:	Kedip.cpp
 *	Deskripsi	: 	Implementasi dari library Kedip.h
 */

#include "Kedip.h"

Kedip::Kedip(const uint8_t _pinKedip)
{
	pinKedip = _pinKedip;
	pinMode(pinKedip, OUTPUT);
	kedipState = LOW;
	previousMillis = 0;
}

void Kedip::berkedip(const unsigned long waktuNyala, const unsigned long waktuMati)
{
	unsigned long currentMillis = millis();
	if ((kedipState == HIGH) && (currentMillis - previousMillis >= waktuNyala))
	{
		kedipState = LOW;
		previousMillis = currentMillis;
		digitalWrite(pinKedip, kedipState);
	}
	else if ((kedipState == LOW) && (currentMillis - previousMillis >= waktuMati))
	{
		kedipState = HIGH;
		previousMillis = currentMillis;
		digitalWrite(pinKedip, kedipState);
	}
}

void Kedip::setState(boolean stateKedip) 
{
	kedipState = stateKedip;
}