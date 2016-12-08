/*
	 EEPROM szimuláció

	 Az arduino pro micro, mini lapka EEPROM elérését 
	 szimulálja.

*/

#ifndef EEPROM_H
#define EEPROM_H


class EEPROM {

	private:
        	const static int LEN = 512;
        	char mem[LEN];
        
	public:
	// EEPROM törlése
		bool clear();
	// 1 bájt olvasása adott címről.
		unsigned int read(unsigned int);
	// 1 bájt írása adott címre.
		bool write(unsigned int, unsigned char);
  // EEPROM méretének lekérdezése
		unsigned int length();
	// Kontrsuktor
		EEPROM();
	// Destruktor
		~EEPROM();


};

#endif
