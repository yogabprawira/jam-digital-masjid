/*
 *	Nama File 	:	Iqomah.h
 *	Deskripsi	: 	Library untuk masuk ke mode countdown iqomah
 */

#ifndef _IQOMAH_h
#define _IQOMAH_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Iqomah
{
private:
	unsigned long pMillis, cMillis;
	boolean buzzNyala;
	uint32_t detikGlobal;

 public:
	void mulai(uint8_t _menitIq, uint8_t _detikIq);
	uint8_t getMenitIq();
	uint8_t getDetikIq();
	boolean getStateBuzz();
	void operator --();
	uint8_t getMenitDefault();
	uint8_t getDetikDefault();
	void setMenitDefault(uint8_t dataMenit);
	void setDetikDefault(uint8_t dataDetik);
};

extern Iqomah iqomah;

#endif

