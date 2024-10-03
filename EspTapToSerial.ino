#include <WiFi.h>
#include <WebServer.h>
#include <esp_wifi.h>
#include "EspTapToSerial.hpp"

WebServer server(SERVER_PORT);

void setup() {
    Serial.begin(115200);
    initWiFi();
    server.onNotFound(handleLaunchRequest);
    server.begin();
}

void loop() {
  server.handleClient();
}

void initWiFi() {
  WiFi.setHostname(hostname);
  WiFi.mode(WIFI_STA);
  esp_wifi_set_mac(WIFI_IF_STA, macAddress);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  Serial.println(WiFi.getHostname());
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.macAddress());
}

void handleLaunchRequest() {
  String text = server.urlDecode(server.uri());
  text.replace("/api/v1/launch/", "/"); //Remove the /api part for backwards compatability
  text = text.substring(server.uri().indexOf("/") + 1);
  Serial.print("SCAN\t" + text + "\n");
  Serial.flush();
  server.send(200, "text/plain", "Launching " + text);
}
