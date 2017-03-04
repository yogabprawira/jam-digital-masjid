/*
 Name 			:	JamDigitalMasjid.ino
 Created		:	1/26/2016 9:41:18 PM
 Author			:	Yoga Budhi Prawira
 Description	:	Program jam digital masjid sederhana menggunakan arduino pro mini
*/

#include <Wire.h>
#include "AT24C64.h"
#include "Iqomah.h"
#include "Tombol.h"
#include "Kedip.h"
#include "DataJadwalSholat.h"
#include "SevenSegment.h"
#include "JamDigital.h"

/* (SER, RCLK, SRCLK) */
SevenSegment boardJam(3, 5, 4);
SevenSegment boardTanggal(9, 8, 7);
SevenSegment boardJadwal(12, 10, 11);

Kedip buzzer(2);
Kedip ledJam(6);
//Tombol tombolKal(A1);
Tombol tombolIq(A2);
//Tombol tombolGerak(A0);
//Tombol tombolOk(13);

static uint8_t detik, menit, jam, hari, tanggal, bulan, tahun;
static uint8_t menitIqomah, detikIqomah;
//static uint8_t menitKalib, detikKalib;
//static boolean stateInKal = HIGH;
//static boolean stateOutKal = LOW;
//static boolean stateOutKalPrev;
static boolean stateInIq = HIGH;
static boolean stateOutIq = LOW;
static boolean stateOutIqPrev;
//static boolean stateInGer = HIGH;
//static boolean stateOutGer = LOW;
//static boolean stateOutGerPrev = LOW;
//static boolean stateInOk = HIGH;
//static boolean stateOutOk = LOW;
static boolean buzzerNyala;

void setup() {
	//Serial.begin(9600);

	/* Kalibrasi waktu RTC : detik, menit, jam, hari, tanggal, bulan, tahun */
	//jamDigital.kalibrasiRealTime(__DATE__, __TIME__);

	/* Menulis data jadwal sholat ke EEPROM Ext */
	//int i, j;
	/*int bulanTest = DESEMBER;
	for (i = 0; i < 31; i++) {
		for (j = 0; j < 6; j++) {
			dataEepromJadwalSholat.tulisByte(ALAMAT_EEPROM_DS3231, ((bulanTest-1)*186)+(i*6)+j, jadwalSholat.desember[i][j]);
			delay(10);
		}
	}*/
	/* Read EEPROM Test */
	/*for (i = 1; i <= 31; i++) {
		Serial.print(jadwalSholat.jamImsyak(i, bulanTest));
		Serial.print(":");
		Serial.print(jadwalSholat.menitImsyak(i, bulanTest));
		Serial.print(" ");
		Serial.print(jadwalSholat.jamSubuh(i, bulanTest));
		Serial.print(":");
		Serial.print(jadwalSholat.menitSubuh(i, bulanTest));
		Serial.print(" ");
		Serial.print(jadwalSholat.jamDzuhur(i, bulanTest));
		Serial.print(":");
		Serial.print(jadwalSholat.menitDzuhur(i, bulanTest));
		Serial.print(" ");
		Serial.print(jadwalSholat.jamAsar(i, bulanTest));
		Serial.print(":");
		Serial.print(jadwalSholat.menitAsar(i, bulanTest));
		Serial.print(" ");
		Serial.print(jadwalSholat.jamMaghrib(i, bulanTest));
		Serial.print(":");
		Serial.print(jadwalSholat.menitMaghrib(i, bulanTest));
		Serial.print(" ");
		Serial.print(jadwalSholat.jamIsya(i, bulanTest));
		Serial.print(":");
		Serial.println(jadwalSholat.menitIsya(i, bulanTest));
		delay(10);
	}*/

}

void loop() {
	// Baca waktu saat ini dari RTC
	jamDigital.bacaWaktuSekarang(&detik, &menit, &jam, &hari, &tanggal, &bulan, &tahun);

	// Baca state terakhir dan state yang baru
	stateOutIqPrev = stateOutIq;
	tombolIq.bacaState(stateInIq, stateOutIq);
	/*stateOutKalPrev = stateOutKal;
	tombolKal.bacaState(stateInKal, stateOutKal);
	tombolGerak.bacaState(stateInGer, stateOutGer);
	tombolOk.bacaState(stateInOk, stateOutOk);*/

	/*if (stateOutKal == HIGH) {
		if (stateOutKalPrev == LOW) {
			menitKalib = iqomah.getMenitDefault();
			detikKalib = iqomah.getDetikDefault();
		}
		if (stateOutGer != stateOutGerPrev) {
			++detikKalib;
			detikKalib %= 60;
			stateOutGerPrev = stateOutGer;
		}
		boardJam.tampilModeKalibrasi(menitKalib, detikKalib);
	}
	else {*/

	// Kondisi state mode Iqomah
	if (stateOutIq == HIGH) {
		if (stateOutIqPrev == LOW) {
			// Mulai menghitung iqomah
			//iqomah.mulai(iqomah.getMenitDefault(), iqomah.getDetikDefault());
			iqomah.mulai(10, 0);
		}
		// Decrement iqomah per detik
		--iqomah;
		// Mendapatkan nilai iqomah dan state buzzer
		menitIqomah = iqomah.getMenitIq();
		detikIqomah = iqomah.getDetikIq();
		buzzerNyala = iqomah.getStateBuzz();
		// Tampilkan iqomah
		boardJam.tampilJam(menitIqomah, detikIqomah);
		// Ketika mode iqomah, led pada board jam tidak berkedip
		ledJam.setState(HIGH);
	}
	else {
		if (stateOutIqPrev == HIGH) {
			// Matikan buzzer ketika berubah ke mode jam
			buzzerNyala = false;
		}
		// Tampilkan jam
		boardJam.tampilJam(jam, menit);

		// Lampu led pada board jam terus berkedip selama 1 detik hidup 1 detik mati
		ledJam.berkedip(1000, 1000);
	}
	
	/*}*/
	
	// Kondisi apabila buzzer aktif
	if (buzzerNyala) buzzer.berkedip(500, 1000);
	else buzzer.setState(LOW);

	// Tampilkan tanggal
	//boardTanggal.tampilTanggal(tanggal, bulan, tahun);
	boardTanggal.autoSwitchTanggalHari(hari, tanggal, bulan, tahun);
	
	// Tampilkan jadwal imsyak hingga isya
	boardJadwal.tampilJadwal(
		jadwalSholat.jamImsyak(tanggal, bulan), jadwalSholat.menitImsyak(tanggal, bulan),
		jadwalSholat.jamSubuh(tanggal, bulan), jadwalSholat.menitSubuh(tanggal, bulan),
		jadwalSholat.jamDzuhur(tanggal, bulan), jadwalSholat.menitDzuhur(tanggal, bulan),
		jadwalSholat.jamAsar(tanggal, bulan), jadwalSholat.menitAsar(tanggal, bulan),
		jadwalSholat.jamMaghrib(tanggal, bulan), jadwalSholat.menitMaghrib(tanggal, bulan),
		jadwalSholat.jamIsya(tanggal, bulan), jadwalSholat.menitIsya(tanggal, bulan)
		);
	
	// Kondisi ketika masuk waktu sholat : buzzer aktif
	// Buzzer nyala selama 15 detik, kecuali dimatikan dengan menekan tombol iqomah
	if (((jam == jadwalSholat.jamSubuh(tanggal, bulan)) && (menit == jadwalSholat.menitSubuh(tanggal, bulan))) ||
		((jam == jadwalSholat.jamDzuhur(tanggal, bulan)) && (menit == jadwalSholat.menitDzuhur(tanggal, bulan))) ||
		((jam == jadwalSholat.jamAsar(tanggal, bulan)) && (menit == jadwalSholat.menitAsar(tanggal, bulan))) ||
		((jam == jadwalSholat.jamMaghrib(tanggal, bulan)) && (menit == jadwalSholat.menitMaghrib(tanggal, bulan))) ||
		((jam == jadwalSholat.jamIsya(tanggal, bulan)) && (menit == jadwalSholat.menitIsya(tanggal, bulan)))
		)
	{	
		if (detik < 15) buzzerNyala = true;
		else buzzerNyala = false;
	} 
	
	/* Mencocokkan Jam via Serial */
	/*Serial.print(tanggal);
	Serial.print("-");
	Serial.print(bulan);
	Serial.print("-");
	Serial.print(tahun);
	Serial.print("  ");
	Serial.print(hari);
	Serial.print("  ");
	Serial.print(jam);
	Serial.print(":");
	Serial.print(menit);
	Serial.print(":");
	Serial.println(detik);*/
}

