/*
 * Copyright (c) 2026 Luis Di Pinto
 * Este código está licenciado bajo la Licencia MIT.
 * Ver el archivo LICENSE en la raíz del proyecto para más detalles.
 */

#include "ControladorRGB.h"

ControladorRGB::ControladorRGB(uint8_t r, uint8_t g, uint8_t b)
    : pinRojo(r), pinVerde(g), pinAzul(b), estadoRojo(LOW), estadoVerde(LOW), estadoAzul(LOW) {}

void ControladorRGB::inicializar() {
    // Establecer estado inicial seguro antes de configurar como salida
    digitalWrite(pinRojo, LOW);
    digitalWrite(pinVerde, LOW);
    digitalWrite(pinAzul, LOW);

    // Configurar pines
    pinMode(pinRojo, OUTPUT);
    pinMode(pinVerde, OUTPUT);
    pinMode(pinAzul, OUTPUT);

    // Guardar el estado interno
    estadoRojo = LOW;
    estadoVerde = LOW;
    estadoAzul = LOW;
}

uint8_t ControladorRGB::getEstadoRojo() const { return estadoRojo; }
uint8_t ControladorRGB::getEstadoVerde() const { return estadoVerde; }
uint8_t ControladorRGB::getEstadoAzul() const { return estadoAzul; }

void ControladorRGB::encenderRojo() {
    digitalWrite(pinRojo, HIGH);
    estadoRojo = HIGH;
}

void ControladorRGB::apagarRojo() {
    digitalWrite(pinRojo, LOW);
    estadoRojo = LOW;
}

void ControladorRGB::encenderVerde() {
    digitalWrite(pinVerde, HIGH);
    estadoVerde = HIGH;
}

void ControladorRGB::apagarVerde() {
    digitalWrite(pinVerde, LOW);
    estadoVerde = LOW;
}

void ControladorRGB::encenderAzul() {
    digitalWrite(pinAzul, HIGH);
    estadoAzul = HIGH;
}

void ControladorRGB::apagarAzul() {
    digitalWrite(pinAzul, LOW);
    estadoAzul = LOW;
}