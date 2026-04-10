#pragma once

#include <PubSubClient.h>
#include <WiFiClient.h>
#include "drivers/relay_controller.h"
#include "drivers/door_sensor.h"

class MqttClientWrapper {
public:
  MqttClientWrapper(RelayController& relayController, DoorSensor& doorSensor);
  void begin();
  void loop();

private:
  WiFiClient wifiClient;
  PubSubClient mqttClient;
  RelayController& relayController;
  DoorSensor& doorSensor;

  void ensureConnected();
  void handleMessage(char* topic, byte* payload, unsigned int length);
  void publishStatus();
};
