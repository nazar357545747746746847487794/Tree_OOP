#include <Arduino.h>



const int LED = 23;
unsigned long t;
int prew = 0;
int LED_STATE = LOW;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  t = millis();
  if(t - prew >= 10000){
    if(LED_STATE == LOW){
      LED_STATE = HIGH;
    }
    else{
      LED_STATE = LOW;
    }
    digitalWrite(LED, LED_STATE);
    prew = t;
  }

}
