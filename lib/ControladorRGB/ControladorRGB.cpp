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