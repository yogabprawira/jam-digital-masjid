/*
 *	Nama File 	:	JamDigital.h
 *	Deskripsi	: 	Library untuk setting dan membaca data dari RTC (Real Time Clock) DS3231
 */

#ifndef _JAMDIGITAL_h
#define _JAMDIGITAL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class JamDigital
{
 private:
	 const uint8_t jumlahHariPerBulan[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	 uint8_t decToBcd(uint8_t val);
	 uint8_t bcdToDec(uint8_t val);
	 uint8_t konversiKe2DigitInt(const char* c);
	 uint8_t konversiTanggalKeHari(uint8_t tgl, uint8_t bln, uint8_t thn);
 
 public:
	 JamDigital();
	 void bacaWaktuSekarang(uint8_t *detik, uint8_t *menit, uint8_t *jam, uint8_t *hari, uint8_t *tanggal, uint8_t *bulan, uint8_t *tahun);
	 void kalibrasiWaktu(uint8_t detik, uint8_t menit, uint8_t jam, uint8_t hari, uint8_t tanggal, uint8_t bulan, uint8_t tahun);
	 void kalibrasiRealTime(const char* tanggalSekarang, const char* waktuSekarang);
};

extern JamDigital jamDigital;

#endif

