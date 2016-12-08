
#include <iostream>
#include "eeprom.h"
#include "lm35.h"

using namespace std;

int main(void) {
	EEPROM eprom;
	cout << "clear() előtti memóriaszemét...\n";    
	for(int i=0; i < eprom.length(); i++) {
		cout << eprom.read(i) << "\t";
	}
	cout << "\n";
	cout <<"clear() utáni állapot\n";
	for(int i=0;i< eprom.length();i++) {eprom.write(i, i%256);}
	for(int i=0; i < eprom.length(); i++) {
		cout << eprom.read(i) << "\t";
	}

	cout << "*****************************************\n";

	LM35 sensor(23,512);
	
	cout << sensor.getPin() << "\n";
	cout << sensor.getDigitalValue() << "\n";
	sensor.setAnalogValue(4500);
	cout << sensor.getDigitalValue() << "\n";
	sensor.setDigitalValue(1000);
	cout << sensor.getDigitalValue() << "\n";
	sensor.setDigitalValue(512);
	cout << sensor.getAnalogValue() << "\n";
	
	cout << "*****************************************\n";

return 0;
}


