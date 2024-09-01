#ifndef PushButton_h
#define PushButton_h
#include "Arduino.h" 

/**
 * I tried to create common version of this push button functionality but I was not able to get it working.
 * Only working way I was able to come across was with templates and wrapping argument lists with tuples.
 * Sadly arduino does not support them, so that had to be scrapped.
 * To get ahead, I decided to manually create version of this function to every different function I use.
 */
class PushButton {
public:
  volatile bool reseted; // This attribute is meant to be used with interrupts.
  PushButton(const byte pin);
  
  template <typename ShortPressCallable, typename LongPressCallable> // Templates allow use of function with any signature.
  void PushButton::handlePress(ShortPressCallable function_short_press=[]() {}, 
                   LongPressCallable function_long_press=[]() {}, int longPressDetectTime_ms=2000){
  
    if (!digitalRead(this->buttonPin))this->reseted = false; // If button is not pressed, it is reseted.
    if (this->reseted){
      if(digitalRead(this->buttonPin) && millis() - this->timeAtButtonPress_ms > 100){ // Eliminating push back with later condition.
        this->timeAtButtonPress_ms = millis();
        while(digitalRead(this->buttonPin) || millis() - this->timeAtButtonPress_ms < 100){  // Loop to listen for long press.
          if (millis() - this->timeAtButtonPress_ms >= longPressDetectTime_ms) break;        // If long press time exceeds, break the loop.
        }
        if (millis() - this->timeAtButtonPress_ms >= longPressDetectTime_ms){
          function_long_press();
        }
        else{
          function_short_press();
        }
      }
      this->reseted = false;
    }
  }


  void handlePress(void(*function_short_press)(), 
                   void(*function_long_press)(char*, byte),
                   char* string, byte max_size,
                   int longPressDetectTime_ms=2000);

  unsigned long getTimeAtButtonPress_ms() const { return this->timeAtButtonPress_ms; }

private:
  byte buttonPin;
  unsigned long timeAtButtonPress_ms;
};
#endif
