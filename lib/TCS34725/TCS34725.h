// TCS34725.h

// Custom librarie to control the RGB sensor TCS34725 with led pin control in the constructor, color RGB565 format

// Creator: JDFraire-P

// Date: 2023-08-31

// Version: 1.0.0

// dependences: Adafruit_TCS34725.h

#ifndef TCS34725_H
#define TCS34725_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_TCS34725.h>


// RGB sensor class, Child class of Adafruit_TCS34725 class, add custom functions and color type (rgb565_t)
class RGB_Sensor : public Adafruit_TCS34725 {
  public:
    RGB_Sensor(uint8_t ic = TCS34725_INTEGRATIONTIME_2_4MS, tcs34725Gain_t gain = TCS34725_GAIN_1X, uint8_t ledPin = 6);
    bool init();
    // Read the color
    uint16_t read_color(bool led_state = false);
    // Read Raw Color
    void read_raw_color(bool led_state = false);
    // get the last color read
    uint16_t get_last_color();
    // Set the led state
    void set_led(bool led_state);
    // Get the led state
    bool get_led();

    // Get the red value
    uint16_t get_red();
    // Get the green value
    uint16_t get_green();
    // Get the blue value
    uint16_t get_blue();
    // Get the clear value
    uint16_t get_clear();
    // Get the lux value
    uint16_t get_lux();
    // Get the color temperature value
    uint16_t get_colorTemp();
    // Sleep the sensor
    void sleep();
    // Wakeup the sensor
    void wakeup();

  private:
    // led pin and state
    uint8_t _led_pin;
    bool _led_state;

    uint16_t _red;
    uint16_t _green;
    uint16_t _blue;
    uint16_t _clear;

    uint16_t _lux;
    uint16_t _colorTemp;

    // Last color read
    uint16_t _last_color;

    // integration time and gain
    uint8_t _tcs34725IntegrationTime;
    tcs34725Gain_t _tcs34725Gain;

};

// RGB sensor object
extern RGB_Sensor Color_Sensor;
#endif