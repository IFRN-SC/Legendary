#ifndef CALIBRAGEM_H
#define CALIBRAGEM_H

#include <robo_hardware2.h>
#include <Servo.h>
#include "Toy.h"

class Calibragem{
  public:
    Calibragem();
    boolean voltarMenu;

    float cinzaMaisDir;
    float cinzaDir;
    float cinzaEsq;
    float cinzaMaisEsq;

    void getDadosCalibragem();
    void iniciarCalibragem();
    
  private:
    Toy toy;
    calibracao_dados val;
    
    void calibracaoBranco();
    void calibracaoPreto();
    void guardarDadosEEPROM();
    float mediaBranco[4];
    float mediaPreto[4];
};

#endif
