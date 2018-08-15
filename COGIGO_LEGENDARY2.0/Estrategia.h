#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H

#include <robo_hardware2.h>
#include <Servo.h>
#include "Toy.h"
#include "Calibragem.h"

class Estrategia{
  public:
    Estrategia();
    void executar();
  private:
    Calibragem calibragem;
    Toy toy;
    
    void seguirLinha();
    void desviarObstaculo();
};

#endif
