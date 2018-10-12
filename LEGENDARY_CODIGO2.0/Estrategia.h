#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H

#include <robo_hardware2.h>
#include <Servo.h>
#include "Toy.h"
#include "Calibragem.h"
#include "SensoresRefletancia.h"
#include "SensoresCor.h"
#include "SensoresDistancia.h"
#include "Motores.h"

class Estrategia{
  public:
    Estrategia();
    void executar();
    void seguirLinhaRampa();
  private:
    Calibragem calibragem;
    Toy toy;
    SensoresRefletancia refletancia;
    SensoresCor cor;
    SensoresDistancia sonar;
    Motores motores;

    boolean frente;
    boolean direita;
    boolean esquerda;
    
    boolean dadosCapturados;
    void start();
    void seguirLinha();
    //void desviarObstaculo();

    void voltarAtePPPP();
};

#endif
