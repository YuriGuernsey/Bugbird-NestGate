#include "app.h"
#include <Arduino.h>
#include "network/wifi_manager.h"
#include "network/mqtt_client_wrapper.h"
#include "drivers/relay_controller.h"
#include "drivers/door_sensor.h"

static WifiManager wifiManager;
static RelayController relayController;
static DoorSensor doorSensor;
static MqttClientWrapper mqttClient(relayController, doorSensor);

void App::begin() {
  pinMode(STATUS_LED_PIN, OUTPUT);
  digitalWrite(STATUS_LED_PIN, LOW);

  relayController.begin();
  doorSensor.begin();
  wifiManager.begin();
  mqttClient.begin();
}

void App::loop() {
  wifiManager.loop();
  mqttClient.loop();

  digitalWrite(STATUS_LED_PIN, WiFi.status() == WL_CONNECTED ? HIGH : LOW);
  delay(25);
}
