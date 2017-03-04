/*
 *	Nama File 	:	AT24C64.cpp
 *	Deskripsi	: 	Implementasi dari library AT24C64.h
 */

#include <Wire.h>
#include "AT24C64.h"

void AT24C64::tulisByte(int alamatperangkat, unsigned int alamatregister, byte data)
{
	int rdata = data;
	Wire.beginTransmission(alamatperangkat);
	Wire.write((int)(alamatregister >> 8)); // MSB
	Wire.write((int)(alamatregister & 0xFF)); // LSB
	Wire.write(rdata);
	Wire.endTransmission();
}

/*
 *	WARNING: address is a page address, 6-bit end will wrap around
 *	also, data can be maximum of about 30 uint8_ts, because the Wire library has a buffer of 32 uint8_ts
 */
void AT24C64::tulis(int alamatperangkat, unsigned int alamatslotregister, byte* data, int panjangdata)
{
	Wire.beginTransmission(alamatperangkat);
	Wire.write((int)(alamatslotregister >> 8)); // MSB
	Wire.write((int)(alamatslotregister & 0xFF)); // LSB
	int c;
	for (c = 0; c < panjangdata; c++)
		Wire.write(data[c]);
	Wire.endTransmission();
}

byte AT24C64::bacaByte(int alamatperangkat, unsigned int alamatregister)
{
	byte rdata = 0xFF;
	Wire.beginTransmission(alamatperangkat);
	Wire.write((int)(alamatregister >> 8)); // MSB
	Wire.write((int)(alamatregister & 0xFF)); // LSB
	Wire.endTransmission();
	Wire.requestFrom(alamatperangkat, 0x01);
	if (Wire.available()) rdata = Wire.read();
	return rdata;
}

void AT24C64::baca(int alamatperangkat, unsigned int alamatregister, byte* buffer, int panjangdata)
{
	Wire.beginTransmission(alamatperangkat);
	Wire.write((int)(alamatregister >> 8)); // MSB
	Wire.write((int)(alamatregister & 0xFF)); // LSB
	Wire.endTransmission();
	Wire.requestFrom(alamatperangkat, panjangdata);
	int c;
	for (c = 0; c < panjangdata; c++)
		if (Wire.available()) buffer[c] = Wire.read();
}

AT24C64 dataEepromJadwalSholat = AT24C64();
