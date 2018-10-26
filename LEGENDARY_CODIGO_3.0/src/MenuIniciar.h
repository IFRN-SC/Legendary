#ifndef MENUINICIAR_H
#define MENUINICIAR_H

#include <Arduino.h>
#include <robo_hardware2.h>
#include "Toy.h"
#include "Calibragem.h"
#include "Estrategia.h"
#include "SensoresRefletancia.h"
#include "SensoresCor.h"
#include "SensoresDistancia.h"

class MenuIniciar{
  public:
    Calibragem calibragem;
    
    MenuIniciar();
    void menuBotoes();

  private:
    void menuSerial();
    void avisoLoop();

    Toy toy;
    SensoresRefletancia refletancia;
    SensoresCor cor;
    SensoresDistancia sonar;
    Estrategia estrategia;
};

#endif
