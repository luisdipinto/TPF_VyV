## Estilo de Código y Nomenclatura
- **Formato base:** Google (mediante clang-format).
- **Variables:** `camelCase` (ej. `pinLedRojo`).
- **Funciones/Métodos:** `camelCase` (ej. `encenderLed()`).
- **Tipos/Clases/Structs:** `PascalCase` (ej. `ColorRgb`).

## Verificación Estática de Código
- **Compilador:** Se utilizan las banderas `-Wall` y `-Wextra` en el entorno de PlatformIO. El código compila sin advertencias.
- **Analizador Estático:** Se utiliza `cppcheck` integrado en PlatformIO. Al ejecutar `pio check`, no se reportan problemas de memoria, alcance o estilo en el código propio. No hay falsos positivos que requieran justificación en esta instancia.

## Revisión de Código por IA
Se utilizó el modelo Gemini (IA) para analizar el código base inicial (`src/main.cpp`).

**Sugerencias recibidas y evaluadas:**
1. Cambiar el tipo de dato de los pines de `const int` a `constexpr uint8_t` para optimizar el uso de memoria RAM y forzar la evaluación en tiempo de compilación.
2. Definir un estado inicial explícito (`LOW`) al configurar los pines como `OUTPUT` para evitar estados transitorios indeterminados en los LEDs durante el arranque.

**Acciones implementadas:**
Ambas sugerencias fueron evaluadas como positivas desde el punto de vista del hardware y del uso eficiente de recursos en C++, por lo que fueron implementadas en el commit correspondiente.