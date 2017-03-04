/*
 *	Nama File 	:	LedJam.cpp
 *	Deskripsi	: 	Implementasi dari library LedJam.h
 */

#include "LedJam.h"

LedJam::LedJam(const uint8_t pinLedJam)
{
	kedip.inisialisasi(pinLedJam);
}

void LedJam::kedipLedJam()
{
	kedip.berkedip(500, 500); // nyala setiap setengah detik
}


