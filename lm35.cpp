#include <iostream>
#include "lm35.h"

LM35::LM35() {
  pin = 23;
}

LM35::LM35(int pin) {
  this pin = pin;
}

LM35::~LM35() {

}

LM35::setPin(int pin) {
  this pin = pin;
}

LM35::getPin() {
}

LM35::setAnalogValue(int) {

}

LM35::setDigitalValue(int) {

}

LM35::getDigitalValue(int) {

}
