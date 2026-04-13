/*
 * Copyright (c) 2026 Luis Di Pinto
 * Este código está licenciado bajo la Licencia MIT.
 * Ver el archivo LICENSE en la raíz del proyecto para más detalles.
 */

#include <Arduino.h>
#include <WebServer.h>
#include <WiFi.h>

#include "ControladorRGB.h"

// Credenciales WiFi (Asegurate de poner las tuyas)
const char* ssid = "UNT";
const char* password = "wifi.unt";

WebServer server(80);
ControladorRGB tiraLed(15, 2, 4);

// Función para generar el HTML con los nuevos botones
void handleRoot() {
    String html = "<!DOCTYPE html><html><head><meta charset=\"UTF-8\">";
    // Agregamos el viewport para que se vea bien en celulares
    html += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
    html +=
        "<title>ESP32 RGB</title></head><body style=\"font-family: Arial, sans-serif; text-align: "
        "center;\">";
    html += "<h1>Control de Tira LED RGB</h1>";

    html += "<h3>Control Maestro</h3>";
    html +=
        "<p><a href=\"/encender\"><button style=\"padding: 10px; font-size: 16px;\">Encender Todo "
        "(Blanco)</button></a> ";
    html +=
        "<a href=\"/apagar\"><button style=\"padding: 10px; font-size: 16px;\">Apagar "
        "Todo</button></a></p>";

    html += "<hr><h3>Control Individual</h3>";
    html +=
        "<p><a href=\"/rojo/on\"><button style=\"padding: 10px; font-size: 16px; color: "
        "red;\">Rojo ON</button></a> ";
    html +=
        "<a href=\"/rojo/off\"><button style=\"padding: 10px; font-size: 16px;\">Rojo "
        "OFF</button></a></p>";

    html +=
        "<p><a href=\"/verde/on\"><button style=\"padding: 10px; font-size: 16px; color: "
        "green;\">Verde ON</button></a> ";
    html +=
        "<a href=\"/verde/off\"><button style=\"padding: 10px; font-size: 16px;\">Verde "
        "OFF</button></a></p>";

    html +=
        "<p><a href=\"/azul/on\"><button style=\"padding: 10px; font-size: 16px; color: "
        "blue;\">Azul ON</button></a> ";
    html +=
        "<a href=\"/azul/off\"><button style=\"padding: 10px; font-size: 16px;\">Azul "
        "OFF</button></a></p>";

    html += "</body></html>";
    server.send(200, "text/html", html);
}

void handleNotFound() {
    server.send(404, "text/plain", "Error 404: Ruta no encontrada en el ESP32.");
}

void setup() {
    Serial.begin(115200);
    tiraLed.inicializar();

    Serial.print("Conectando a WiFi: ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);

    int intentos = 0;
    while (WiFi.status() != WL_CONNECTED && intentos < 20) {
        delay(500);
        Serial.print(".");
        intentos++;
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\nWiFi conectado.");
        Serial.print("Direccion IP: ");
        Serial.println(WiFi.localIP());

        // Rutas del servidor web
        server.on("/", handleRoot);

        // Control Maestro (ahora usando la librería)
        server.on("/encender", []() {
            tiraLed.encenderRojo();
            tiraLed.encenderVerde();
            tiraLed.encenderAzul();
            server.sendHeader("Location", "/");
            server.send(303);
        });
        server.on("/apagar", []() {
            tiraLed.inicializar();  // Apaga todo
            server.sendHeader("Location", "/");
            server.send(303);
        });

        // Rutas Control Individual
        server.on("/rojo/on", []() {
            tiraLed.encenderRojo();
            server.sendHeader("Location", "/");
            server.send(303);
        });
        server.on("/rojo/off", []() {
            tiraLed.apagarRojo();
            server.sendHeader("Location", "/");
            server.send(303);
        });

        server.on("/verde/on", []() {
            tiraLed.encenderVerde();
            server.sendHeader("Location", "/");
            server.send(303);
        });
        server.on("/verde/off", []() {
            tiraLed.apagarVerde();
            server.sendHeader("Location", "/");
            server.send(303);
        });

        server.on("/azul/on", []() {
            tiraLed.encenderAzul();
            server.sendHeader("Location", "/");
            server.send(303);
        });
        server.on("/azul/off", []() {
            tiraLed.apagarAzul();
            server.sendHeader("Location", "/");
            server.send(303);
        });

        server.onNotFound(handleNotFound);

        server.begin();
        Serial.println("Servidor HTTP iniciado.");
    } else {
        Serial.println("\nFallo la conexion WiFi. Modo seguro.");
    }
}

void loop() { server.handleClient(); }