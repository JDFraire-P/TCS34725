# Librería JDFraire-P/TCS34725

Esta es una librería personalizada para controlar el sensor RGB TCS34725 con control del pin LED en el constructor, tipos de color y funciones de conversión agregadas.

## Autor
- **Creador:** JDFraire-P
- **Fecha:** 31 de agosto de 2023
- **Versión:** 1.0.0

## Dependencias
- [Adafruit_TCS34725.h](https://github.com/adafruit/Adafruit_TCS34725)

## Descripción
Esta librería te permite controlar el sensor RGB TCS34725 con facilidad y ofrece las siguientes características:

- Control del estado del LED en el constructor.
- Tipos de color personalizados (rgb565_t).
- Funciones de lectura de colores en formatos 8 bits y 5-6-5 bits.
- Funciones para obtener valores individuales de rojo, verde, azul, claro, lux y temperatura de color.
- Funciones para poner el sensor en modo de sueño o despertarlo.

## Uso
### Instalación
1. Asegúrate de tener las dependencias instaladas.
2. Descarga esta librería y colócala en la carpeta `libraries` de tu proyecto Arduino.
3. Incluye la librería en tu código:
   ```cpp
   #include <JDFraire_TCS34725.h>
   ```
4. Crea una instancia del objeto RGB_Sensor con los parámetros deseados en tu código:
   ```cpp
   RGB_Sensor Color_Sensor(TCS34725_INTEGRATIONTIME_24MS, TCS34725_GAIN_60X, 6);
   ```

### Funciones Principales
- `bool init()`: Inicializa el sensor y configura el pin LED.
- `rgb565_t read_color(bool led_state = false)`: Lee y devuelve el color en formato rgb565_t. Puede controlar el estado del LED al hacer la lectura.
- `void read_raw_color(bool led_state = false)`: Lee los valores brutos de color y realiza cálculos internos. Puede controlar el estado del LED al hacer la lectura.
- `rgb565_t get_last_color()`: Obtiene el último color leído en formato rgb565_t.
- `void set_led(bool led_state)`: Configura el estado del LED.
- `bool get_led()`: Obtiene el estado actual del LED.
- `uint16_t get_red()`, `uint16_t get_green()`, `uint16_t get_blue()`, `uint16_t get_clear()`, `uint16_t get_lux()`, `uint16_t get_colorTemp()`: Obtiene los valores individuales de los componentes de color, luz y temperatura.

**¡Esperamos que esta librería sea útil para tu proyecto!** Si tienes alguna pregunta o problema, no dudes en crear un [issue](https://github.com/JDFraire-P/TCS34725/issues) en el repositorio de GitHub o contactar al autor.
