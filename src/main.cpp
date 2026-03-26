#include <Arduino.h>

// Pines de la tira LED RGB
constexpr uint8_t pinLedRojo = 15;
constexpr uint8_t pinLedVerde = 2;
constexpr uint8_t pinLedAzul = 4;

void configurarPines() {
    // Apagar LEDs por defecto (asumiendo lógica positiva)
    digitalWrite(pinLedRojo, LOW);
    digitalWrite(pinLedVerde, LOW);
    digitalWrite(pinLedAzul, LOW);

    // Configurar como salidas
    pinMode(pinLedRojo, OUTPUT);
    pinMode(pinLedVerde, OUTPUT);
    pinMode(pinLedAzul, OUTPUT);
}

void setup() {
    Serial.begin(115200);
    configurarPines();
    Serial.println("Iniciando ESP32 RGB Web Server...");
}

void loop() {
    // Lógica principal a implementar
}