#ifndef ESTRATEGIA_H
#define ESTRATEGIA_H

#include <robo_hardware2.h>
#include "Toy.h"
#include "SensoresRefletancia.h"
#include "SensoresCor.h"
#include "SensoresDistancia.h"
#include "Motores.h"

class Estrategia{
  public:
    Estrategia();
    int ultimoMovimentoRegistrado();
    void executar();
    void seguirLinhaVerde();

  private:
    Toy toy;
    SensoresRefletancia refletancia;
    SensoresCor cor;
    SensoresDistancia distancia;
    Motores motores;

    boolean caiu = false;

    boolean frente;
    boolean direita;
    boolean esquerda;
    
    boolean dadosCapturados;
    void start();
    void seguirLinha();
    void desviarObstaculo();
    void seguirLinhaRampa();

    boolean acaoVerde();
    void alinharObstaculo();

    void setFrente();
    void setEsquerda();
    void setDireita();
};

#endif
