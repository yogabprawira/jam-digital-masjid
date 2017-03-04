/*
 *	Nama File 	:	JamDigital.cpp
 *	Deskripsi	: 	Implementasi dari library JamDigital.h
 */

#include <Wire.h>
#include "JamDigital.h"

#define ALAMAT_DS3231 0x68

uint8_t JamDigital::decToBcd(uint8_t val)
{
	return((val / 10 * 16) + (val % 10));
}

uint8_t JamDigital::bcdToDec(uint8_t val)
{
	return((val / 16 * 10) + (val % 16));
}

JamDigital::JamDigital()
{
	Wire.begin();
}

void JamDigital::
bacaWaktuSekarang(uint8_t *detik, uint8_t *menit, uint8_t *jam, uint8_t *hari, uint8_t *tanggal, uint8_t *bulan, uint8_t *tahun)
{
	Wire.beginTransmission(ALAMAT_DS3231);
	Wire.write(0); // set DS3231 register pointer to 00h
	Wire.endTransmission();
	Wire.requestFrom(ALAMAT_DS3231, 7);
	// request seven uint8_ts of data from DS3231 starting from register 00h
	*detik = bcdToDec(Wire.read() & 0x7f);
	*menit = bcdToDec(Wire.read());
	*jam = bcdToDec(Wire.read() & 0x3f);
	*hari = bcdToDec(Wire.read());
	*tanggal = bcdToDec(Wire.read());
	*bulan = bcdToDec(Wire.read());
	*tahun = bcdToDec(Wire.read());
}

void JamDigital::kalibrasiWaktu(uint8_t detik, uint8_t menit, uint8_t jam, uint8_t hari, uint8_t tanggal, uint8_t bulan, uint8_t tahun)
{
	Wire.beginTransmission(ALAMAT_DS3231);
	Wire.write(0); 
	Wire.write(decToBcd(detik)); 
	Wire.write(decToBcd(menit)); 
	Wire.write(decToBcd(jam)); 
	Wire.write(decToBcd(hari)); // (1=Minggu, 7=Sabtu)
	Wire.write(decToBcd(tanggal)); // (1 to 31)
	Wire.write(decToBcd(bulan)); 
	Wire.write(decToBcd(tahun)); // (0 to 99)
	Wire.endTransmission();
}

uint8_t JamDigital::konversiKe2DigitInt(const char* c) {
	uint8_t puluhan = 0;
	if ('0' <= *c && *c <= '9')
		puluhan = *c - '0';
	return 10 * puluhan + *++c - '0';
}

void JamDigital::kalibrasiRealTime(const char* tanggalSekarang, const char* waktuSekarang) {
	uint8_t detikK, menitK, jamK, hariK, tanggalK, bulanK, tahunK;
	uint8_t offsetK = 13;	// offset dalam satuan detik
	
	switch (tanggalSekarang[0])
	{
		case 'J' :
		{
			if (!memcmp(&tanggalSekarang[1], "a", sizeof(char))) {
				bulanK = 1;
				break;
			} 
			else if(!memcmp(&tanggalSekarang[2], "n", sizeof(char))){
				bulanK = 6;
				break;
			}
			else {
				bulanK = 7;
			}
			break;
		}
		case 'F': bulanK = 2; break;
		case 'A': 
		{
			if (!memcmp(&tanggalSekarang[2], "r", sizeof(char))) {
				bulanK = 4;
			} 
			else {
				bulanK = 8;
			}
			break;
		}
		case 'M':
		{
			if (!memcmp(&tanggalSekarang[2], "r", sizeof(char))) {
				bulanK = 3;
			} 
			else {
				bulanK = 5;
			}
			break;
		}
		case 'S': bulanK = 9; break;
		case 'O': bulanK = 10; break;
		case 'N': bulanK = 11; break;
		case 'D': bulanK = 12; break;
		default: break;
	}
	tahunK = konversiKe2DigitInt(tanggalSekarang + 9);
	tanggalK = konversiKe2DigitInt(tanggalSekarang + 4);
	jamK = konversiKe2DigitInt(waktuSekarang);
	menitK = konversiKe2DigitInt(waktuSekarang + 3);
	detikK = konversiKe2DigitInt(waktuSekarang + 6);
	hariK = konversiTanggalKeHari(tanggalK, bulanK, tahunK);

	detikK += offsetK;
	if (detikK > 59) {
		if (menitK < 59) {
			++menitK;
			detikK %= 60;
		} 
		else {
			menitK = 0;
			if (jamK < 23) {
				++jamK;
			}
			else {
				jamK = 0;
				if (hariK < 7) {
					++hariK;
				} 
				else {
					hariK = 1;
				}
			}
		}
	}

	jamDigital.kalibrasiWaktu(detikK, menitK, jamK, hariK, tanggalK, bulanK, tahunK);
}

uint8_t JamDigital::konversiTanggalKeHari(uint8_t tgl, uint8_t bln, uint8_t thn) {
	if (thn > 2000) thn -= 2000;
	uint16_t totalHari = tgl;
	uint8_t i;
	for (i = 1; i < bln; i++) {
		totalHari += jumlahHariPerBulan[i - 1];
	}
	if ((bln > 2) && (thn % 4 == 0)) {
		++totalHari;
	}
	totalHari += 365 * thn + ((thn + 3) / 4) - 1;
	return (uint8_t)((totalHari + 6) % 7 + 1);
}

JamDigital jamDigital = JamDigital();