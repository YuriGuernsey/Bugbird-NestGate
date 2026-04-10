#include "network/mqtt_client_wrapper.h"
#include <ArduinoJson.h>
#include <WiFi.h>
#include "config.h"
#include "security/signature.h"

MqttClientWrapper::MqttClientWrapper(RelayController& relayController, DoorSensor& doorSensor)
  : mqttClient(wifiClient), relayController(relayController), doorSensor(doorSensor) {}

void MqttClientWrapper::begin() {
  mqttClient.setServer(MQTT_HOST, MQTT_PORT);
  mqttClient.setCallback([this](char* topic, byte* payload, unsigned int length) {
    handleMessage(topic, payload, length);
  });
}

void MqttClientWrapper::loop() {
  relayController.loop();

  if (WiFi.status() != WL_CONNECTED) {
    return;
  }

  ensureConnected();
  mqttClient.loop();
}

void MqttClientWrapper::ensureConnected() {
  if (mqttClient.connected()) {
    return;
  }

  if (mqttClient.connect(CONTROLLER_ID)) {
    String commandTopic = String("nestgate/door/") + CONTROLLER_ID + "/command";
    mqttClient.subscribe(commandTopic.c_str());
    publishStatus();
  }
}

void MqttClientWrapper::handleMessage(char* topic, byte* payload, unsigned int length) {
  (void)topic;

  StaticJsonDocument<512> doc;
  DeserializationError error = deserializeJson(doc, payload, length);
  if (error) {
    return;
  }

  const String action = doc["action"] | "";
  const String commandId = doc["commandId"] | "";
  const String doorId = doc["doorId"] | "";
  const String controllerId = doc["controllerId"] | "";
  const long issuedAt = doc["issuedAt"] | 0;
  const long expiresAt = doc["expiresAt"] | 0;
  const String nonce = doc["nonce"] | "";
  const int version = doc["version"] | 1;
  const String signature = doc["signature"] | "";

  if (controllerId != CONTROLLER_ID || doorId != DOOR_ID) {
    return;
  }

  if (expiresAt < (long)(millis() / 1000)) {
    return;
  }

  String canonical = canonicaliseCommand(commandId, doorId, controllerId, action, issuedAt, expiresAt, nonce, version);
  if (!verifySignature(signature, canonical)) {
    return;
  }

  if (action == "unlock") {
    relayController.unlock();
    publishStatus();
  }
}

void MqttClientWrapper::publishStatus() {
  StaticJsonDocument<256> doc;
  doc["controllerId"] = CONTROLLER_ID;
  doc["doorId"] = DOOR_ID;
  doc["doorOpen"] = doorSensor.isOpen();

  char buffer[256];
  size_t written = serializeJson(doc, buffer);

  String topic = String("nestgate/door/") + CONTROLLER_ID + "/status";
  mqttClient.publish(topic.c_str(), buffer, written);
}
