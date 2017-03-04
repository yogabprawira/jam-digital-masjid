/*
 *	Nama File 	:	Iqomah.cpp
 *	Deskripsi	: 	Implementasi dari library Iqomah.h
 */

#include "Iqomah.h"
#include "AT24C64.h"

#define MAX_ALAMAT_MEMORI_JADWAL	2232

void Iqomah::mulai(uint8_t _menitIq, uint8_t _detikIq) {
	detikGlobal = _menitIq * 60 + _detikIq;
	buzzNyala = false;
	pMillis = millis();
}

uint8_t Iqomah::getMenitIq() {
	return (uint8_t)(detikGlobal / 60);
}

uint8_t Iqomah::getDetikIq() {
	return (uint8_t)(detikGlobal % 60);
}

boolean Iqomah::getStateBuzz() {
	return buzzNyala;
}

void Iqomah::operator --()
{
	cMillis = millis();
	if (cMillis - pMillis >= 1000)
	{
		if (detikGlobal > 0) {
			--detikGlobal;
			buzzNyala = false;
		} 
		else {
			buzzNyala = true;
		}
		pMillis = millis();
	}
}

uint8_t Iqomah::getMenitDefault() {
	return dataEepromJadwalSholat.bacaByte(ALAMAT_EEPROM_DS3231,  MAX_ALAMAT_MEMORI_JADWAL + 1);
}

uint8_t Iqomah::getDetikDefault() {
	return dataEepromJadwalSholat.bacaByte(ALAMAT_EEPROM_DS3231, MAX_ALAMAT_MEMORI_JADWAL + 2);
}

void Iqomah::setMenitDefault(uint8_t dataMenit) {
	dataEepromJadwalSholat.tulisByte(ALAMAT_EEPROM_DS3231, MAX_ALAMAT_MEMORI_JADWAL + 1, dataMenit);
}

void Iqomah::setDetikDefault(uint8_t dataDetik) {
	dataEepromJadwalSholat.tulisByte(ALAMAT_EEPROM_DS3231, MAX_ALAMAT_MEMORI_JADWAL + 2, dataDetik);
}

Iqomah iqomah = Iqomah();
