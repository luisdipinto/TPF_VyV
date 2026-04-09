#include <Arduino.h>
#include <unity.h>

#include "ControladorRGB.h"  // Esta librería aún no existe, por lo que el test fallará.

// Instanciamos el controlador con pines ficticios para el test
ControladorRGB led(15, 2, 4);

void setUp(void) {
    // Se ejecuta antes de cada test
}

void tearDown(void) {
    // Se ejecuta después de cada test
}

// Prueba trazada al REQ-01
void test_req_01_estado_inicial_apagado(void) {
    led.inicializar();
    // Verificamos que el estado interno guardado sea LOW (apagado)
    TEST_ASSERT_EQUAL(LOW, led.getEstadoRojo());
    TEST_ASSERT_EQUAL(LOW, led.getEstadoVerde());
    TEST_ASSERT_EQUAL(LOW, led.getEstadoAzul());
}

void setup() {
    delay(2000);  // Dar tiempo al puerto serial para iniciar
    UNITY_BEGIN();
    RUN_TEST(test_req_01_estado_inicial_apagado);
    UNITY_END();
}

void loop() {
    // En las pruebas unitarias, el loop suele quedar vacío
}