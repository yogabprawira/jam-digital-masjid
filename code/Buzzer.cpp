/*
 *	Nama File 	:	Buzzer.cpp
 *	Deskripsi	: 	Implementasi dari library Buzzer.h
 */

#include "Buzzer.h"

Buzzer::Buzzer(const uint8_t pinBuzzer)
{
	kedip.inisialisasi(pinBuzzer);
}

void Buzzer::buzz()
{
	kedip.berkedip(1000, 1000);
}


