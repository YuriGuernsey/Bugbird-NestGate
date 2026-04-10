#include "wifi_manager.h"
#include <WiFi.h>
#include "config.h"

void WifiManager::begin() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
}

void WifiManager::loop() {
  if (WiFi.status() == WL_CONNECTED) {
    return;
  }

  static unsigned long lastAttempt = 0;
  if (millis() - lastAttempt > 5000) {
    lastAttempt = millis();
    WiFi.disconnect();
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  }
}
