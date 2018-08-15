#ifndef MENUINICIAR_H
#define MENUINICIAR_H

#include <Arduino.h>
#include <robo_hardware2.h>
#include "Toy.h"
#include "Calibragem.h"
#include "Estrategia.h"

class MenuIniciar{
  public:
    Calibragem calibragem;
    MenuIniciar();
    void menuBotoes();
  
  private:
    void menuSerial();
    Toy toy;
};

#endif
