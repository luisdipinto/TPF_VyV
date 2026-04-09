#ifndef CONTROLADOR_RGB_H
#define CONTROLADOR_RGB_H

#include <Arduino.h>

/**
 * @class ControladorRGB
 * @brief Clase encargada de gestionar los pines y el estado de una tira LED RGB.
 */
class ControladorRGB {
   private:
    uint8_t pinRojo;
    uint8_t pinVerde;
    uint8_t pinAzul;

    uint8_t estadoRojo;
    uint8_t estadoVerde;
    uint8_t estadoAzul;

   public:
    /**
     * @brief Constructor del controlador RGB.
     * @param r Pin correspondiente al color rojo.
     * @param g Pin correspondiente al color verde.
     * @param b Pin correspondiente al color azul.
     */
    ControladorRGB(uint8_t r, uint8_t g, uint8_t b);

    /**
     * @brief Inicializa los pines como salidas y establece el estado inicial en LOW.
     */
    void inicializar();

    /**
     * @brief Obtiene el estado lógico actual del pin rojo.
     * @return Estado del pin (HIGH o LOW).
     */
    uint8_t getEstadoRojo() const;

    /**
     * @brief Obtiene el estado lógico actual del pin verde.
     * @return Estado del pin (HIGH o LOW).
     */
    uint8_t getEstadoVerde() const;

    /**
     * @brief Obtiene el estado lógico actual del pin azul.
     * @return Estado del pin (HIGH o LOW).
     */
    uint8_t getEstadoAzul() const;
};

#endif