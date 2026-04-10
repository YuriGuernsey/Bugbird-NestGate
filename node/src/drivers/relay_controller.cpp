#include "relay_controller.h"
#include <Arduino.h>
#include "config.h"

void RelayController::begin() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
}

void RelayController::unlock() {
  unlocking = true;
  unlockStartedAt = millis();
  digitalWrite(RELAY_PIN, HIGH);
}

void RelayController::loop() {
  if (!unlocking) return;

  if (millis() - unlockStartedAt >= UNLOCK_PULSE_MS) {
    unlocking = false;
    digitalWrite(RELAY_PIN, LOW);
  }
}
