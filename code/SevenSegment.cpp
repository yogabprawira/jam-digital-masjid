/*
 *	Nama File 	:	SevenSegment.cpp
 *	Deskripsi	: 	Implementasi dari library SevenSegment.h
 */

#include "SevenSegment.h"

SevenSegment::SevenSegment(uint8_t _pinSER, uint8_t _pinRCLK, uint8_t _pinSRCLK)
{
	pinSER = _pinSER; pinRCLK = _pinRCLK; pinSRCLK = _pinSRCLK;
	pinMode(pinSER, OUTPUT);
	pinMode(pinRCLK, OUTPUT);
	pinMode(pinSRCLK, OUTPUT);
}

void SevenSegment::tampilJam(uint8_t angkaJam, uint8_t angkaMenit)
{
	digitalWrite(pinRCLK, LOW);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaJam / 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaJam % 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaMenit / 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaMenit % 10]);
	digitalWrite(pinRCLK, HIGH);
}

void SevenSegment::tampilTanggal(uint8_t angkaTanggal, uint8_t angkaBulan, uint8_t angkaTahun)
{
	digitalWrite(pinRCLK, LOW);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaTanggal / 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaTanggal % 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaBulan / 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaBulan % 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaTahun / 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaTahun % 10]);
	digitalWrite(pinRCLK, HIGH);
}

void SevenSegment::tampilJadwal(
	uint8_t angkaJamImsyak, uint8_t angkaMenitImsyak,
	uint8_t angkaJamSubuh, uint8_t angkaMenitSubuh,
	uint8_t angkaJamDzuhur, uint8_t angkaMenitDzuhur,
	uint8_t angkaJamAsar, uint8_t angkaMenitAsar,
	uint8_t angkaJamMaghrib, uint8_t angkaMenitMaghrib,
	uint8_t angkaJamIsya, uint8_t angkaMenitIsya
	)
{
	digitalWrite(pinRCLK, LOW);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaJamImsyak / 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaJamImsyak % 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaMenitImsyak / 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaMenitImsyak % 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaJamSubuh / 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaJamSubuh % 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaMenitSubuh / 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaMenitSubuh % 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaJamDzuhur / 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaJamDzuhur % 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaMenitDzuhur / 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaMenitDzuhur % 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaJamAsar / 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaJamAsar % 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaMenitAsar / 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaMenitAsar % 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaJamMaghrib / 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaJamMaghrib % 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaMenitMaghrib / 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaMenitMaghrib % 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaJamIsya / 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaJamIsya % 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaMenitIsya / 10]);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, digitSevenSegment[angkaMenitIsya % 10]);
	digitalWrite(pinRCLK, HIGH);
}

void SevenSegment::tampilHari(uint8_t angkaHari) {
	int i;
	if (angkaHari == 1) angkaHari = 0;	// Mode Ahad
	digitalWrite(pinRCLK, LOW);
	for (i = 0; i < 6; i++) {
		shiftOut(pinSER, pinSRCLK, MSBFIRST, digitTulisanHari[angkaHari][i]);
	}
	digitalWrite(pinRCLK, HIGH);
}

void SevenSegment::autoSwitchTanggalHari(uint8_t angkaHari, uint8_t angkaTanggal, uint8_t angkaBulan, uint8_t angkaTahun) {
	unsigned long currentMillis = millis();
	if ((stateAktif == HIGH) && (currentMillis - prevMillis >= 5000))
	{
		stateAktif = LOW;
		prevMillis = currentMillis;
		tampilHari(angkaHari);
	}
	else if ((stateAktif == LOW) && (currentMillis - prevMillis >= 5000))
	{
		stateAktif = HIGH;
		prevMillis = currentMillis;
		tampilTanggal(angkaTanggal, angkaBulan, angkaTahun);
	}
}

void SevenSegment::mati() {
	digitalWrite(pinRCLK, LOW);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, 0xff);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, 0xff);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, 0xff);
	shiftOut(pinSER, pinSRCLK, MSBFIRST, 0xff);
	digitalWrite(pinRCLK, HIGH);
}

//void SevenSegment::tampilModeKalibrasi(uint8_t angkaMenit, uint8_t angkaDetik) {
//	uint8_t dig[4] = {digitSevenSegment}
//	unsigned long currentMillis = millis();
//	if ((stateAktif == HIGH) && (currentMillis - prevMillis >= 200))
//	{
//		stateAktif = LOW;
//		prevMillis = currentMillis;
//		tampilJam(angkaMenit, angkaDetik);
//	}
//	else if ((stateAktif == LOW) && (currentMillis - prevMillis >= 800))
//	{
//		stateAktif = HIGH;
//		prevMillis = currentMillis;
//		mati();
//	}
//}
