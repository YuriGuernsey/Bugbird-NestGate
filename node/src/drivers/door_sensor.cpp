#include "door_sensor.h"
#include <Arduino.h>
#include "config.h"

void DoorSensor::begin() {
  pinMode(DOOR_SENSOR_PIN, INPUT_PULLUP);
}

bool DoorSensor::isOpen() const {
  return digitalRead(DOOR_SENSOR_PIN) == LOW;
}
