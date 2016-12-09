/*
 * DS3231 i2c RTC szimulálás
 */
 
 #ifndef DS3231_H
 #define DS3231_h
 
  
 class DS3231 {
	private:
		unsigned int datetime[7];
		
	public:
    enum {sec,min,hour,dow,day,month,year};
  
		char longDateTime[25];
    
		int bcd2dec(int);
		int dec2bcd(int);
    
    bool isLeapYear(int);
		
		bool setDateTime(int,int,int,int,int,int,int); // Idő és dátum beállítása.
		bool setTime(int,int,int); // Idő beállítása
		bool setDate(int,int,int,int); // Dátum beállítása a hét napjával.
		bool setDOW(int); // Hét napjának beállítása
		int getDatepart(int);
    char* getLongDateTime();
		char* getDateTime();
		char* getTime();
		char* getDate();
		char* getDOW(int);
		
		DS3231();
		DS3231(int,int,int,int,int,int,int);
		~DS3231();
 };
 
 #endif
