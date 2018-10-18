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
    int ultimoMovimentoRegistrado();
    void executar();
    void seguirLinhaRampa();
    
  private:
    Calibragem calibragem;
    Toy toy;
    SensoresRefletancia refletancia;
    SensoresCor cor;
    SensoresDistancia distancia;
    Motores motores;

    boolean frente;
    boolean direita;
    boolean esquerda;
    
    boolean dadosCapturados;
    void start();
    void seguirLinha();
    void desviarObstaculo();

    void setFrente();
    void setEsquerda();
    void setDireita();

    void voltarAtePPPP();
};

#endif
