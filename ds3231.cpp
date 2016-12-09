#include <iostream>
#include "ds3231.h"

DS3231::DS3231() {

}

DS3231::DS3231(int sec,int min,int hour,int dow,int day,int month,int year) {
	datetime[0] = dec2bcd(sec);
	datetime[1] = dec2bcd(min);
	datetime[2] = dec2bcd(hour);
	datetime[3] = dec2bcd(dow);
	datetime[4] = dec2bcd(day);
	datetime[5] = dec2bcd(month);
	datetime[6] = dec2bcd(year);
}

DS3231::~DS3231() {

}

int DS3231::bcd2dec(int val) {
	return ((val / 16 * 10) + (val % 16));
}

int DS3231::dec2bcd(int val) {
	return ((val / 10 * 16) + (val % 10));
}

int DS3231::getDatepart(int part) {
	return (bcd2dec(datetime[part]));
}

char* DS3231::getDOW(int dow) {
	char* dayOfWeek;
	switch (dow) {
		case 0:
			dayOfWeek = (char*)"Vas";
		break;
		case 1:
			dayOfWeek = (char*)"H  ";
		break;
		case 2:
			dayOfWeek = (char*)"K  ";
		break;
		case 3:
			dayOfWeek = (char*)"Sze";
		break;
		case 4:
			dayOfWeek = (char*)"Cs ";
		break;
		case 5:
			dayOfWeek = (char*)"P  ";
		break;
		case 6:
			dayOfWeek = (char*)"Szo";
		break;
		default:
			dayOfWeek = (char*)"-#-";		
	}
	return dayOfWeek;
}


