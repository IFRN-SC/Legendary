#ifndef CALIBRAGEM_H
#define CALIBRAGEM_H

#include <robo_hardware2.h>
#include <Servo.h>
#include "Toy.h"
#include "Sensores.h"

#define TESTES true

class Calibragem{
  public:
    Calibragem();
    boolean voltarMenu;

    float cinzaMaisDir;
    float cinzaDir;
    float cinzaEsq;
    float cinzaMaisEsq;
    
    void iniciarCalibragem();
    
  private:
    Toy toy;
    Sensores sensores;
    calibracao_dados val;

    
    void calibracaoBranco();
    void calibracaoPreto();
    void guardarDadosEEPROM();
    float mediaBranco[4];
    float mediaPreto[4];
};

#endif
