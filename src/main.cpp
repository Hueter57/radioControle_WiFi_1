#include <Arduino.h>
#include <EncorderMotor.hpp>
#include <WiFiAP_Server.hpp>

char *ssid = "Hueter_WiFi";
char *pass = "unyooooonn";

WiFiAP_Server wifiAP_Server(ssid, pass);

EncorderMotor motorLeft(14, 27, 26, 25);
// EncorderMotor motorRight(14, 27, 26, 25);

void setup() {
    Serial.begin(9600);
    const IPAddress ip(192, 168, 32, 2);
    const IPAddress subnet(255, 255, 255, 0);
    wifiAP_Server.beginAP(ip, subnet);
    wifiAP_Server.beginServer();
    motorLeft.stop();
}

void loop() {
    if(wifiAP_Server.sliderValue1 > 3 && wifiAP_Server.sliderValue1 < 7){
        motorLeft.stop();
    }else if(wifiAP_Server.sliderValue1 > 6){
        motorLeft.changeSpeed(1);
    }else{
        motorLeft.changeSpeed(-1);
    }
    
}