CC = g++
CFLAGS = -std=c++11
OUT = -o thermo

thermo: main.o eeprom.o
	$(CC) $(CFLAGS) *.o $(OUT)

main.o: main.cpp    
	$(CC) $(CFLAGS) -c main.cpp

eeprom.o: eeprom.h eeprom.cpp
	$(CC) $(CFLAGS) -c eeprom.cpp

.PHONY: clean
clean:
	rm *.o
	
	
