#include <JDFraire_TCS34725.h>

void setup() {
  Serial.begin(9600);

  // Inicializa el sensor
  if (Color_Sensor.init()) {
    Serial.println("Sensor RGB TCS34725 inicializado con éxito!");
  } else {
    Serial.println("Error al inicializar el sensor RGB TCS34725.");
    while (1);
  }
}

void loop() {
  // Lee el color actual
  rgb565_t color = Color_Sensor.read_color();

  // Muestra los valores
  Serial.print("Color (RGB565): 0x");
  Serial.println(color, HEX);
  Serial.print("Rojo: ");
  Serial.println(Color_Sensor.get_red());
  Serial.print("Verde: ");
  Serial.println(Color_Sensor.get_green());
  Serial.print("Azul: ");
  Serial.println(Color_Sensor.get_blue());
  Serial.print("Luz: ");
  Serial.println(Color_Sensor.get_lux());
  Serial.print("Temperatura de Color: ");
  Serial.println(Color_Sensor.get_colorTemp());

  delay(1000);
}
