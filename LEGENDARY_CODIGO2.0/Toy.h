#ifndef TOY_H
#define TOY_H

#include <Arduino.h>

#define pinLED1 49
#define pinLED2 51
#define pinLED3 53

class Toy{
  public:
    Toy();
    void start();
    void led1On();
    void led2On();
    void led3On();
    void led1Off();
    void led2Off();
    void led3Off();
    void ledAlerta(int, int, int);
    void piscarLeds();
    void allLedsOn();
    void allLedsOff();
    void ledsEscada(int, int); 
    void ledsAlerta(int);
};

#endif
