CC = g++
CFLAGS = -std=c++11
OUT = -o thermo

thermo: main.o eeprom.o lm35.o ds3231.o
	$(CC) $(CFLAGS) *.o $(OUT)

main.o: main.cpp    
	$(CC) $(CFLAGS) -c main.cpp

eeprom.o: eeprom.h eeprom.cpp
	$(CC) $(CFLAGS) -c eeprom.cpp

lm35.o:	lm35.h lm35.cpp
	$(CC) $(CFLAGS) -c lm35.cpp

ds3231.o: ds3231.h ds3231.cpp
	$(CC) $(CFLAGS) -c ds3231.cpp


.PHONY: clean
clean:
	rm *.o
	rm thermo
	
	
