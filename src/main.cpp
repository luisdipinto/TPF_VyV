/*
 * Copyright (c) 2026 Luis Di Pinto
 * Este código está licenciado bajo la Licencia MIT.
 * Ver el archivo LICENSE en la raíz del proyecto para más detalles.
 */

#include <Arduino.h>

#include "ControladorRGB.h"

// Instanciamos nuestro objeto controlador con los pines del ESP32
ControladorRGB tiraLed(15, 2, 4);

void setup() {
    Serial.begin(115200);
    tiraLed.inicializar();
    Serial.println("Iniciando ESP32 RGB Web Server... (Librería validada)");
}

void loop() {
    // Lógica principal a implementar
}