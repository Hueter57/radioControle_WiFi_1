#include <EncorderMotor.hpp>

EncorderMotor::EncorderMotor(int pin1, int pin2, int pin3, int pin4) {
    inputPin1  = pin1;
    inputPin2  = pin2;
    outputPin1 = pin3;
    outputPin2 = pin4;
    pinMode(inputPin1, INPUT);
    pinMode(inputPin2, INPUT);
    pinMode(outputPin1, OUTPUT);
    pinMode(outputPin2, OUTPUT);

    ledcSetup(pwmch1, 12800, 8);
    ledcSetup(pwmch2, 12800, 8);
    ledcAttachPin(outputPin1, pwmch1);
    ledcAttachPin(outputPin2, pwmch2);
}

void EncorderMotor::stop() {
    ledcWrite(pwmch1, LOW);
    ledcWrite(pwmch2, LOW);
}

void EncorderMotor::changeSpeed(int value) {
    if (value > 0) {
        ledcWrite(pwmch1, value);
        ledcWrite(pwmch2, LOW);
    } else {
        ledcWrite(pwmch1, LOW);
        ledcWrite(pwmch2, -value);
    }
}
