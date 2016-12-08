#include <iostream>
#include "lm35.h"

LM35::LM35() {
  pin = 23;
  digitalValue = 0;
}

LM35::LM35(int pin) {
  this pin = pin;
  digitalValue = 0;
}

LM35::LM35(int pin, int val) {
  this pin = pin;
  if (val >=0 && val < 1024) {
    digitalValue = val;
  } else {
   digitalValue = val % 1024; 
  }
}

LM35::~LM35() {

}

LM35::setPin(int pin) {
  if (pin > 22 && pin < 29) {
    this pin = pin;
  } else {
    pin = 23; 
  }
}

LM35::getPin() {
  return pin;
}

LM35::setAnalogValue(int val) {
  if (val >= 0 && val <= 5000) {
    digitalValue = (1024 * val) / 5000;
  } else {
   digitalValue = 0; 
  }
}

LM35::setDigitalValue(int val) {
  if (val >=0 && val <= 1023) {
   digitalValue = val; 
  } else {
   digitalValue = val % 1024; 
  }
}

LM35::getDigitalValue(int val) {
  return digitalValue;
}
