/*
 *	Nama File 	:	AT24C64.h
 *	Deskripsi	:	Library untuk membaca dan menulis data dari EEPROM AT24C64 yang berisi
 *					data jadwal sholat.
 */
#ifndef _AT24C64_h
#define _AT24C64_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define ALAMAT_EEPROM_EXT 		0x50
#define ALAMAT_EEPROM_DS3231	0x57

class AT24C64
{
 public:
	void tulisByte(int alamatperangkat, unsigned int alamatregister, byte data);
	void tulis(int alamatperangkat, unsigned int alamatslotregister, byte* data, int panjangdata);
	byte bacaByte(int alamatperangkat, unsigned int alamatregister);
	void baca(int alamatperangkat, unsigned int alamatregister, byte* buffer, int panjangdata);
};

extern AT24C64 dataEepromJadwalSholat;

#endif
