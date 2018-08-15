#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H

#include <robo_hardware2.h>
#include <Servo.h>
#include "Toy.h"
#include "Calibragem.h"
#include "Sensores.h"
#include "Motores.h"

class Estrategia{
  public:
    Estrategia();
    void executar();
  private:
    Calibragem calibragem;
    Toy toy;
    Sensores sensores;
    Motores motores;
    
    void seguirLinha();
    void desviarObstaculo();
};

#endif
