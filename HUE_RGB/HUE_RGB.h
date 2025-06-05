#ifndef testLib_h
#define testLib_h
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
    
    void write(byte color){
    _color = color;
    if(_color < 85){
      _Rclr = 85 - _color;
      _Gclr = _color;
      _Bclr = 0;
    }
    else if(_color < 170){
      _Rclr = 0;
      _Gclr = 170 - _color;
      _Bclr = _color - 85;
    }
    else{
      _Rclr = _color - 170;
      _Gclr = 0;
      _Bclr = 255 - _color;
    }
  analogWrite(_Rpin, _Rclr);
  analogWrite(_Gpin, _Gclr);
  analogWrite(_Bpin, _Bclr);
  }
  private:
    byte _Rpin;
    byte _Gpin;
    byte _Bpin;
    byte _color;
    bool _flag;
    byte _Rclr, _Gclr, _Bclr;
};

#endif