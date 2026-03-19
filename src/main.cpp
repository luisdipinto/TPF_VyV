#include <Arduino.h>

// put function declarations here:
// Pines de la tira LED RGB (ejemplo)
const int pinLedRojo = 15;
const int pinLedVerde = 2;
const int pinLedAzul = 4;

void configurarPines() {
    pinMode(pinLedRojo, OUTPUT);
    pinMode(pinLedVerde, OUTPUT);
    pinMode(pinLedAzul, OUTPUT);
}

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    configurarPines();
    Serial.println("Iniciando ESP32 RGB Web Server...");
}

void loop() {
    // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) { return x + y; }