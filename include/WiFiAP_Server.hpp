#pragma once

#include <Arduino.h>

#include <ArduinoJson.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <FS.h>
#include <SPIFFS.h>
#include <WiFi.h>

namespace ph = std::placeholders;

class WiFiAP_Server {
    const char *ssid;
    const char *pass;
    AsyncWebServer server = AsyncWebServer(80);

  public:
    int sliderValue1;
    int sliderValue2;

    WiFiAP_Server(char *ssid_, char *pass_) ;

    static void notFound(AsyncWebServerRequest *request);

    void beginAP(IPAddress ip, IPAddress subnet);

    void beginServer();

    void body(AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total);
};
