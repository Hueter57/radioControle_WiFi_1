#pragma once

#include <Arduino.h>

// EncoderMotor{エンコーダー入力1, エンコーダー入力2, モーター出力指定正, モーター出力指定負}

class EncorderMotor {
    public:
    int inputPin1;   //H1pin
    int inputPin2;   //H2pin
    int outputPin1;  //M+
    int outputPin2;  //M-

    const int pwmch1 = 0;
    const int pwmch2 = 1;

    EncorderMotor(int pin1, int pin2, int pin3, int pin4);

    void stop();

    void changeSpeed(int value);

    void getEncordValues();

};