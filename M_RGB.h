#pragma once
#include <Arduino.h>

class LED {
public:

  LED(uint8_t Rpin, uint8_t Gpin, uint8_t Bpin)
    : _Rpin(Rpin), _Gpin(Gpin), _Bpin(Bpin) {}

  void setHUE(byte color) {                                    // пространство RGB
    if (color < 85) setRGB(85 - color, color, 0);              // если значение цвета меньше 85 то, установить такие цвета
    else if (color < 170) setRGB(0, 170 - color, color - 85);  // если значение цвета меньше 170 то, установить такие цвета
    else setRGB(color - 170, 0, 255 - color);                  // иначе такие цвета
  }

  void setRGB(uint8_t Rclr, uint8_t Gclr, uint8_t Bclr) {  // обновить цвет
    analogWrite(_Rpin, Rclr);                              // уровень красново
    analogWrite(_Gpin, Gclr);                              // уровень зелёного
    analogWrite(_Bpin, Bclr);                              // уровень синего
  }

private:
  // приватные переменные:
  uint8_t _Rpin, _Gpin, _Bpin;  // пины светодиода
};
