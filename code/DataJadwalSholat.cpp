/*
 *	Nama File 	:	DataJadwalSholat.cpp
 *	Deskripsi	: 	Implementasi dari library DataJadwalSholat.h
 */

#include "AT24C64.h"
#include "DataJadwalSholat.h"

uint8_t DataJadwalSholat::jamImsyak(uint8_t tanggal, uint8_t bulan) {
	int alamatregister = (bulan - 1) * 186 + (tanggal - 1) * 6;
	byte data = dataEepromJadwalSholat.bacaByte(ALAMAT_EEPROM_DS3231, alamatregister);
	if (data >> 7) return 4;
	else return 3;
}

uint8_t DataJadwalSholat::jamSubuh(uint8_t tanggal, uint8_t bulan) {
	int alamatregister = (bulan - 1) * 186 + (tanggal - 1) * 6 + 1;
	byte data = dataEepromJadwalSholat.bacaByte(ALAMAT_EEPROM_DS3231, alamatregister);
	if (data >> 7) return 4;
	else return 3;
}

uint8_t DataJadwalSholat::jamDzuhur(uint8_t tanggal, uint8_t bulan) {
	int alamatregister = (bulan - 1) * 186 + (tanggal - 1) * 6 + 2;
	byte data = dataEepromJadwalSholat.bacaByte(ALAMAT_EEPROM_DS3231, alamatregister);
	if (data >> 7) return 12;
	else return 11;
}

uint8_t DataJadwalSholat::jamAsar(uint8_t tanggal, uint8_t bulan) {
	int alamatregister = (bulan - 1) * 186 + (tanggal - 1) * 6 + 3;
	byte data = dataEepromJadwalSholat.bacaByte(ALAMAT_EEPROM_DS3231, alamatregister);
	if (data >> 7) return 15;
	else return 14;
}

uint8_t DataJadwalSholat::jamMaghrib(uint8_t tanggal, uint8_t bulan) {
	int alamatregister = (bulan - 1) * 186 + (tanggal - 1) * 6 + 4;
	byte data = dataEepromJadwalSholat.bacaByte(ALAMAT_EEPROM_DS3231, alamatregister);
	if (data >> 7) return 18;
	else return 17;
}

uint8_t DataJadwalSholat::jamIsya(uint8_t tanggal, uint8_t bulan) {
	int alamatregister = (bulan - 1) * 186 + (tanggal - 1) * 6 + 5;
	byte data = dataEepromJadwalSholat.bacaByte(ALAMAT_EEPROM_DS3231, alamatregister);
	if (data >> 7) return 19;
	else return 18;
}

uint8_t DataJadwalSholat::menitImsyak(uint8_t tanggal, uint8_t bulan) {
	int alamatregister = (bulan - 1) * 186 + (tanggal - 1) * 6;
	byte data = dataEepromJadwalSholat.bacaByte(ALAMAT_EEPROM_DS3231, alamatregister);
	return data & 0x7f;
}

uint8_t DataJadwalSholat::menitSubuh(uint8_t tanggal, uint8_t bulan) {
	int alamatregister = (bulan - 1) * 186 + (tanggal - 1) * 6 + 1;
	byte data = dataEepromJadwalSholat.bacaByte(ALAMAT_EEPROM_DS3231, alamatregister);
	return data & 0x7f;
}

uint8_t DataJadwalSholat::menitDzuhur(uint8_t tanggal, uint8_t bulan) {
	int alamatregister = (bulan - 1) * 186 + (tanggal - 1) * 6 + 2;
	byte data = dataEepromJadwalSholat.bacaByte(ALAMAT_EEPROM_DS3231, alamatregister);
	return data & 0x7f;
}

uint8_t DataJadwalSholat::menitAsar(uint8_t tanggal, uint8_t bulan) {
	int alamatregister = (bulan - 1) * 186 + (tanggal - 1) * 6 + 3;
	byte data = dataEepromJadwalSholat.bacaByte(ALAMAT_EEPROM_DS3231, alamatregister);
	return data & 0x7f;
}

uint8_t DataJadwalSholat::menitMaghrib(uint8_t tanggal, uint8_t bulan) {
	int alamatregister = (bulan - 1) * 186 + (tanggal - 1) * 6 + 4;
	byte data = dataEepromJadwalSholat.bacaByte(ALAMAT_EEPROM_DS3231, alamatregister);
	return data & 0x7f;
}

uint8_t DataJadwalSholat::menitIsya(uint8_t tanggal, uint8_t bulan) {
	int alamatregister = (bulan - 1) * 186 + (tanggal - 1) * 6 + 5;
	byte data = dataEepromJadwalSholat.bacaByte(ALAMAT_EEPROM_DS3231, alamatregister);
	return data & 0x7f;
}

DataJadwalSholat jadwalSholat = DataJadwalSholat();

