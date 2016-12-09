#include <iostream>
#include "ds3231.h"



DS3231::DS3231() {
	for(int i=0; i < 7; i++) {
		datetime[i] = 0;
	}
}

DS3231::DS3231(int sec,int min,int hour,int dow,int day,int month,int year) {
	sec %= 60;
	min %= 60;
	hour %= 24;
	dow %= 7;
	int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	if (isLeapYear(year)) {
		days[2] = 29;
	}
	month %= 12;
	if (month == 0) {
		month = 12;
	}
	day = day % days[month];
	if (day == 0) {
		day = days[month];
	}
	
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

bool DS3231::isLeapYear(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
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

char* DS3231::getDOW(int d) {
	char* dayOfWeek;
	switch (d) {
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

char* DS3231::getLongDateTime() {
    int p;
    p = getDatepart(hour);
    if (p < 10) {
		longDateTime[0] = (char)48;
		longDateTime[1] = (char)(p + 48);
	} else {
		longDateTime[0] = (char)(p/10 + 48);
		longDateTime[1] = (char)(p%10 + 48);
	}
	longDateTime[2] = ':';
	p = getDatepart(min);
    if (p < 10) {
		longDateTime[3] = (char)48;
		longDateTime[4] = (char)(p + 48);
	} else {
		longDateTime[3] = (char)(p/10 + 48);
		longDateTime[4] = (char)(p%10 + 48);
	}
	longDateTime[5] = ':';
	p = getDatepart(sec);
    if (p < 10) {
		longDateTime[6] = (char)48;
		longDateTime[7] = (char)(p + 48);
	} else {
		longDateTime[6] = (char)(p/10 + 48);
		longDateTime[7] = (char)(p%10 + 48);
	}
	longDateTime[8] = ' ';
	longDateTime[9] = '2';
	longDateTime[10] = '0';
	p = getDatepart(year);
    if (p < 10) {
		longDateTime[11] = (char)48;
		longDateTime[12] = (char)(p + 48);
	} else {
		longDateTime[11] = (char)(p/10 + 48);
		longDateTime[12] = (char)(p%10 + 48);
	}
	longDateTime[13] = '.';
	p = getDatepart(month);
    if (p < 10) {
		longDateTime[14] = (char)48;
		longDateTime[15] = (char)(p + 48);
	} else {
		longDateTime[14] = (char)(p/10 + 48);
		longDateTime[15] = (char)(p%10 + 48);
	}
	longDateTime[16] = '.';
	p = getDatepart(day);
    if (p < 10) {
		longDateTime[17] = (char)48;
		longDateTime[18] = (char)(p + 48);
	} else {
		longDateTime[17] = (char)(p/10 + 48);
		longDateTime[18] = (char)(p%10 + 48);
	}
	longDateTime[19] = '.';
	longDateTime[20] = ' ';
	int d = getDatepart(dow);
	longDateTime[21] = getDOW(d)[0];
	longDateTime[22] = getDOW(d)[1];
	longDateTime[23] = getDOW(d)[2];
	longDateTime[24] = '\0';
    return longDateTime;
    
}
