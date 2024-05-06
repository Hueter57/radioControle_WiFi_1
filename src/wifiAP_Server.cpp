#include <WiFiAP_Server.hpp>

namespace ph = std::placeholders;

WiFiAP_Server::WiFiAP_Server(char *ssid_, char *pass_) {
    ssid = ssid_;
    pass = pass_;
    sliderValue1 = 5;
    sliderValue2 = 5;
}

void WiFiAP_Server::notFound(AsyncWebServerRequest *request) {
    request->send(404);
}

void WiFiAP_Server::beginAP(IPAddress ip, IPAddress subnet) {
    // WiFiポート開始
    WiFi.softAP(ssid, pass);
    delay(100);
    WiFi.softAPConfig(ip, ip, subnet);
    IPAddress myIP = WiFi.softAPIP();
    Serial.print("SSID= ");
    Serial.println(ssid);
    Serial.print("Fixed IP addr= ");
    Serial.println(myIP);
    Serial.println("Server starting!");
}

void WiFiAP_Server::beginServer() {

    SPIFFS.begin(true);

    server.on(
        "/send", HTTP_POST, [](AsyncWebServerRequest *request) {}, NULL,
        std::bind(&WiFiAP_Server::body, this, ph::_1, ph::_2, ph::_3, ph::_4, ph::_5));

    server.serveStatic("/", SPIFFS, "/www/").setDefaultFile("index.html");
    server.onNotFound(WiFiAP_Server::notFound);

    // WebServerセットアップ
    DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*");
    DefaultHeaders::Instance().addHeader("Access-Control-Allow-Headers", "*");
    server.begin();
}

void WiFiAP_Server::body(AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total) {
    String resjson = "";

    for (size_t i = 0; i < len; i++) {
        //Serial.write(data[i]);
        resjson.concat(char(data[i]));
    }

    StaticJsonDocument<512> doc;
    Serial.println(resjson);
    DeserializationError error = deserializeJson(doc, resjson);

    if (error) {
        Serial.println("deserializeJson() faild");
        request->send(400);
    } else {
        sliderValue1 = doc["x"];  //zz Tilt Motor Default SPEED
        request->send(200);
    }
}
