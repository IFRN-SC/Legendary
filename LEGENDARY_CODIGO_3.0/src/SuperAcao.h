#ifndef SUPERACAO_H
#define SUPERACAO_H

#include <robo_hardware2.h>
#include <Servo.h>
#include "Toy.h"
#include "SensoresRefletancia.h"
#include "SensoresCor.h"
#include "SensoresDistancia.h"
#include "Motores.h"

class SuperAcao{
  public:
    SuperAcao();
    void alinheComPPPP();
    void alinharObstaculo();
  
  private:
    Calibragem calibragem;
    Toy toy;
    SensoresRefletancia refletancia;
    SensoresCor cor;
    SensoresDistancia distancia;
    Motores motores;
};

#endif
