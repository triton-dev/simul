
#include <iostream>
#include "eeprom.h"
#include "lm35.h"
#include "ds3231.h"

#include <ctime>

using namespace std;

int main(void) {
  
	EEPROM eprom;
	//~ cout << "clear() előtti memóriaszemét...\n";    
	//~ for(int i=0; i < eprom.length(); i++) {
		//~ cout << eprom.read(i) << "\t";
	//~ }
	//~ cout << "\n";
	//~ cout <<"clear() utáni állapot\n";
	//~ for(int i=0;i< eprom.length();i++) {eprom.write(i, i%256);}
	//~ for(int i=0; i < eprom.length(); i++) {
		//~ cout << eprom.read(i) << "\t";
	//~ }
//~ 
	//~ cout << "\n*****************************************\n";

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
	
	//DS3231 rtc(37,12,21,1,9,12,16);
  DS3231 rtc;
	
	for(int i=0; i<8; i++) {
		cout << i << ".nap: " << rtc.getDOW(i) << ",";
	}
	cout << "\n";
	//~ cout << "bcd2dec(72) = " << rtc.bcd2dec(72) << "\n";
	//~ cout << "dec2bcd(48) = " << rtc.dec2bcd(48) << "\n";
	//~ for(int i= 0; i<100; i++) {
		//~ cout <<i << "(dec) = " << rtc.dec2bcd(i) << "\n";
	//~ }
	//~ cout << "\n****************************************\n";
	//~ for(int i= 0; i<154; i++) {
		//~ cout <<i << "(bcd) = " << rtc.bcd2dec(i) << "\n";
	//~ }
	cout << "\nIdő és dátum:\t";
	for(int i=0;i<7;i++) {
		cout << rtc.getDatepart(i) << "\t";
	}
	cout << "\n";
  char* a;
  a = rtc.getLongDateTime();
  cout << a << "\n";
  cout << rtc.getDOW(rtc.getDatepart(4)) << "\n";
  
    char c;
  
  time_t rawtime;
  struct tm * timeinfo;
  char timebuffer[80];
  while(true) {
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  strftime(timebuffer,80,"%F %T %w",timeinfo);
  if((c = getchar()) == 27) {
      break;
  }
  cout << timebuffer << "\n";
}
return 0;
}


