/*
*	LM35 hőmérő IC
*
*	Virtulálisan beköthető egy analog csatlakozóra,lekérdezhető Pin, 
*	konstruktorból beállítható Pin, alapértelmezett Pin A0 = 23,
*	konstruktorból beállítható Pin és digitális érték.
*
*/

#ifndef LM35_H
#define LM35_H

class LM35 {
	private:
		int pin;
		int digitalValue;

	public:
		bool setPin(int);
		int getPin();
		bool setAnalogValue(int);
		bool setDigitalValue(int);
		int getDigitalValue();
		int getAnalogValue();

		LM35();
		LM35(int);
		LM35(int,int);
		~LM35();
};

#endif
