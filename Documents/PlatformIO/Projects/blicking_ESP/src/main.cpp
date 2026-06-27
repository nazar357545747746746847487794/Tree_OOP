#include <Arduino.h>

const int LED = 23;
unsigned long t;
unsigned long prew = 0; // ✅ виправлено тип
int LED_STATE = LOW;
unsigned long lastPrint = 0; // ✅ для Serial

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  t = millis();

  // Мигання кожні 10 секунд
  if (t - prew >= 10000) {
    LED_STATE = (LED_STATE == LOW) ? HIGH : LOW;
    digitalWrite(LED, LED_STATE);
    prew = t;
  }

  // Виводимо в термінал раз на секунду
  if (t - lastPrint >= 1000) {
    Serial.println(LED_STATE == LOW ? "0" : "1");
    lastPrint = t;
  }
}
