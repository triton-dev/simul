/*
  LM35 hőmérő IC
  
  Virtulálisan beköthető egy analog csatlakozóra,
  lekérdezhető Pin, konstruktorból beállítható Pin, alapértlemezett Pin A0 = 23
  
*/

#ifndef LM35_H
#define LM35_H

class LM35 {
  private:
    int pin;
    
  public:
    setPin(int);
    getPin();
    setAnalogValue(int);
    setDigitalValue(int);
    getDigitalValue(int);
    
    LM35();
    LM35(int);
    ~LM35();
};


#endif
