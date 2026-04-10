#include <Arduino.h>
#include <WiFi.h>
#include "config.h"
#include "core/app.h"

App app;

void setup() {
  Serial.begin(115200);
  app.begin();
}

void loop() {
  app.loop();
}
