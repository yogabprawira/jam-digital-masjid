/*
 *	Nama File 	:	SevenSegment.h
 *	Deskripsi	: 	Library untuk menampilkan seven segment.
 */

#ifndef _SEVENSEGMENT_h
#define _SEVENSEGMENT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class SevenSegment
{
 private:
	uint8_t pinSER, pinRCLK, pinSRCLK;
	const byte digitSevenSegment[10] = { 0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10 };
	const byte digitTulisanHari[8][6] = {
		{0xa0, 0x8b, 0xa0, 0xa1, 0xff, 0xff}, // Ahad
		{0xc8, 0xc8, 0xf9, 0xc8, 0x82, 0xc1}, // Minggu
		{0x92, 0x84, 0xc8, 0xf9, 0xc8, 0xff}, // Senin
		{0x92, 0x84, 0xc7, 0xa0, 0x92, 0xa0}, // Selasa
		{0xce, 0xa0, 0x83, 0xc1, 0xff, 0xff}, // Rabu
		{0x89, 0xa0, 0xc8, 0xc8, 0xf9, 0x92}, // Kamis
		{0xe1, 0xc1, 0xc8, 0xc8, 0xa0, 0x87}, // Jumat
		{0x92, 0xa0, 0x83, 0x87, 0xc1, 0xff}  // Sabtu
	};
	unsigned long prevMillis;
	boolean stateAktif;

 public:
	SevenSegment(const uint8_t _pinSER, const uint8_t _pinRCLK, const uint8_t _pinSRCLK);
	void tampilJam(uint8_t angkaJam, uint8_t angkaMenit);
	void tampilTanggal(uint8_t angkaTanggal, uint8_t angkaBulan, uint8_t angkaTahun);
	void tampilJadwal(
		uint8_t angkaJamImsyak, uint8_t angkaMenitImsyak,
		uint8_t angkaJamSubuh, uint8_t angkaMenitSubuh,
		uint8_t angkaJamDzuhur, uint8_t angkaMenitDzuhur,
		uint8_t angkaJamAsar, uint8_t angkaMenitAsar,
		uint8_t angkaJamMaghrib, uint8_t angkaMenitMaghrib,
		uint8_t angkaJamIsya, uint8_t angkaMenitIsya 			
	);
	void tampilHari(uint8_t angkaHari);
	void autoSwitchTanggalHari(uint8_t angkaHari, uint8_t angkaTanggal, uint8_t angkaBulan, uint8_t angkaTahun);
	void mati();
	//void tampilModeKalibrasi(uint8_t angkaMenit, uint8_t angkaDetik);
};

#endif

