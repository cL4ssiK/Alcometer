#include "Arduino.h"
#include "PushButton.h"

PushButton::PushButton(const byte pin){
  pinMode(pin, INPUT);
  this->buttonPin = pin;
}

void PushButton::handlePress(void(*function_short_press)(), 
                   void(*function_long_press)(char*, byte), 
                   char* string, byte max_size, 
                   int longPressDetectTime_ms=2000){
  
  if (!digitalRead(this->buttonPin))this->reseted = false;
  if (this->reseted){
    if(digitalRead(this->buttonPin) && millis() - this->timeAtButtonPress_ms > 100){
      this->timeAtButtonPress_ms = millis();
      while(digitalRead(this->buttonPin) || millis() - this->timeAtButtonPress_ms < 100){
        if (millis() - this->timeAtButtonPress_ms >= longPressDetectTime_ms) break;
      }
      if (millis() - this->timeAtButtonPress_ms >= longPressDetectTime_ms){
        function_long_press(string, max_size);
      }
      else{
        function_short_press();
      }
    }
    this->reseted = false;
  }
}
