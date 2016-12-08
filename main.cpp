
#include <iostream>

#include "eeprom.h"

using namespace std;
char a;

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
    
    return 0;
}


