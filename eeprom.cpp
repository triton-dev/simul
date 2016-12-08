/*
	 EEPROM program

*/

#include "eeprom.h"

EEPROM::EEPROM() {
    
}

EEPROM::~EEPROM() {

}

bool EEPROM::clear() {
	for(int i = 0; i <= LEN; i++) {
		mem[i] = 0;
	}
	return true;
}

unsigned int EEPROM::length() {
	return LEN;
}

unsigned int EEPROM::read(unsigned int address) {
	if (address < 0 || address >= LEN) {
		return 0;
	}
	return (unsigned char)mem[address];
}

bool EEPROM::write(unsigned int address, unsigned char value) {
	if(address < 0 || address >= LEN) {
		return false;
	}
	mem[address] = (unsigned char)value;
	return true;
}


