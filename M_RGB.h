#ifndef M_RGB_h
#define M_RGB_h
#include <Arduino.h>

class LED{ 
  public:
    LED(byte Rpin, byte Gpin, byte Bpin){
    _Rpin = Rpin;
    _Gpin = Gpin;
    _Bpin = Bpin;
    pinMode(_Rpin, OUTPUT);
    pinMode(_Rpin, OUTPUT);
    pinMode(_Rpin, OUTPUT);
        }  
    
    void HUE_write(byte color){ // пространство RGB
      _HUEcolor = color;
      if(_color < 85){  // если значение цвета меньше 85 то, установить такие цвета
        _Rclr = 85 - _color;
        _Gclr = _color;
        _Bclr = 0;
      }
      else if(_color < 170){  // если значение цвета меньше 170 то, установить такие цвета
        _Rclr = 0;
        _Gclr = 170 - _color;
        _Bclr = _color - 85;
      }
      else{
        _Rclr = _color - 170; // иначе, установить такие цвета
        _Gclr = 0;
        _Bclr = 255 - _color;
      }
      analogWrite(_Rpin, _Rclr);
      analogWrite(_Gpin, _Gclr);
      analogWrite(_Bpin, _Bclr);
  }

    void RGB_write(byte Rclr1, byte Gclr1, byte Bclr1){ // пространство RGB
      _Rclr1 = Rclr1; 
      _Gclr1 = Gclr1;
      _Bclr1 = Bclr1;
      analogWrite(_Rpin, _Rclr1); // уровень красново
      analogWrite(_Gpin, _Gclr1); // уровень зелёного
      analogWrite(_Bpin, _Bclr1); // уровень синего
    }

  private: 
    // приватные переменные:
    byte _Rpin, _Gpin, _Bpin; // пины светодиода 
    byte _HUEcolor; // переменная значения цвета на вход HUE (0 - 255)
    byte _Rclr1, _Gclr1, _Bclr1; // переменная цвета RGB
    byte _Rclr, _Gclr, _Bclr; // переменная значения цвета на выходе по цветам (HUE)
};

#endif

