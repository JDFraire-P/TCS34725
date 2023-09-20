// JDFraire_TCS34725.cpp

// Custom librarie to control the RGB sensor TCS34725 with led pin control in the constructor, color types and conversion functions added

// Creator: JDFraire

// Date: 2023-08-31

// Version: 1.0

// dependences: Adafruit_TCS34725.h, Wire.h

#ifndef JDFraire_TCS34725_cpp
#define JDFraire_TCS34725_cpp

#include <JDFraire_TCS34725.h>


// Constructor
RGB_Sensor::RGB_Sensor(uint8_t ic, tcs34725Gain_t gain, uint8_t ledPin) : Adafruit_TCS34725(ic, gain) {
  _led_pin = ledPin;
  _led_state = false;
  _red = 0;
  _green = 0;
  _blue = 0;
  _clear = 0;
  _lux = 0;

  _tcs34725IntegrationTime = ic;
  _tcs34725Gain = gain;
}


bool RGB_Sensor::init() {
  pinMode(_led_pin, OUTPUT);
  // digitalWrite(_led_pin, _led_state);
  // setInterrupt(false);
  bool sensor_ok = Adafruit_TCS34725::begin();
  read_raw_color(true);
  disable();
  return sensor_ok;
}

// Read the color
rgb565_t RGB_Sensor::read_color(bool led_state) {
  float red, green, blue;
  if(led_state) set_led(true);
  getRGB(&red, &green, &blue);
  if(led_state) set_led(false);


  // convert the float values (0-255) to 8 bit values
  uint8_t red_5bits = red / 255.0 * 31.0;
  uint8_t green_6bits = green / 255.0 * 63.0;
  uint8_t blue_5bits = blue / 255.0 * 31.0;

  _last_color = rgb565_t(red, green, blue);
  return _last_color;
}

// Read Raw Color
void RGB_Sensor::read_raw_color(bool led_state) {

  // read the raw data
  if(led_state) set_led(true);
  enable();
  _red =    read8(TCS34725_RDATAL) | ((uint16_t)(read8(TCS34725_RDATAH)) << 8);
  _green =  read8(TCS34725_GDATAL) | ((uint16_t)(read8(TCS34725_GDATAH)) << 8);
  _blue =   read8(TCS34725_BDATAL) | ((uint16_t)(read8(TCS34725_BDATAH)) << 8);
  _clear =  read8(TCS34725_CDATAL) | ((uint16_t)(read8(TCS34725_CDATAH)) << 8);
  disable();

  if(led_state) set_led(false);

  // calculate lux
  _lux = calculateLux(_red, _green, _blue);

  // calculate color temperature
  _colorTemp = calculateColorTemperature(_red, _green, _blue);

  // Avoid divide by zero errors ... if clear = 0 return black
  if (_clear == 0) {
    _red = _green = _blue = 0;
    return;
  }

  // convert the raw values to 5, 6 and 5 bits
  uint8_t red_5bits = int((float)_red / (float)_clear * 31.0) & 0x1F;
  uint8_t green_6bits = int((float)_green / (float)_clear * 63.0) & 0x3F;
  uint8_t blue_5bits = int((float)_blue / (float)_clear * 31.0) & 0x1F;

  _red = red_5bits;
  _green = green_6bits;
  _blue = blue_5bits;

  // save the last color read
  _last_color = rgb565_t(red_5bits, green_6bits, blue_5bits);
}

// get the last color read
rgb565_t RGB_Sensor::get_last_color() {
  return _last_color;
}

// Set the led state
void RGB_Sensor::set_led(bool led_state) {
  _led_state = led_state;
  digitalWrite(_led_pin, _led_state);
}

// Get the led state
bool RGB_Sensor::get_led() {
  return _led_state;
}

// Get the red value
uint16_t RGB_Sensor::get_red() {
  return _red;
}

// Get the green value
uint16_t RGB_Sensor::get_green() {
  return _green;
}

// Get the blue value
uint16_t RGB_Sensor::get_blue() {
  return _blue;
}

// Get the clear value
uint16_t RGB_Sensor::get_clear() {
  return _clear;
}

// Get the lux value
uint16_t RGB_Sensor::get_lux() {
  return _lux;
}

// Get the color temperature value
uint16_t RGB_Sensor::get_colorTemp() {
  return _colorTemp;
}

// RGB sensor object
extern RGB_Sensor Color_Sensor = RGB_Sensor(TCS34725_INTEGRATIONTIME_24MS, TCS34725_GAIN_60X, 6);

#endif