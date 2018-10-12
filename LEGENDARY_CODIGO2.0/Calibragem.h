#ifndef CALIBRAGEM_H
#define CALIBRAGEM_H

#include <robo_hardware2.h>
#include "Toy.h"

class Calibragem{
  public:
    Calibragem();
    boolean voltarMenu;
    
    float cinzaMaisDir;
    float cinzaDir;
    float cinzaEsq;
    float cinzaMaisEsq;

    void printDadosEEPROM();
    void iniciarCalibragem();
    void calibrarIMU();
  private:
    Toy toy;
    calibracao_dados val;
    
    float mediaBrancoRefletanciaMaisEsq;
    float mediaBrancoRefletanciaEsq;
    float mediaBrancoRefletanciaDir;
    float mediaBrancoRefletanciaMaisDir;
    
    float mediaPretoRefletanciaMaisEsq;
    float mediaPretoRefletanciaEsq;
    float mediaPretoRefletanciaDir;
    float mediaPretoRefletanciaMaisDir;


    //Métodos para calibração de Sensores
    void calibracaoPretoRefletancia();
    void calibracaoPretoCor();
    void calibracaoBrancoRefletanciaCor();
    void calibracaoVerdeEsq();
    void calibracaoVerdeDir();


    void calcularCinzaRefletancia();
    void guardarDadosEEPROM();

    HSV capturadorDeCorAuxEsq;
    HSV capturadorDeCorAuxDir;
    HSV mediaBrancoCorEsq;
    HSV mediaBrancoCorDir;
    HSV mediaPretoCorEsq;
    HSV mediaPretoCorDir;
    HSV mediaVerdeCorEsq;
    HSV mediaVerdeCorDir; 
    
    double mediaArena;
    double mediaRampa;
    double corteInclinacao;
};

#endif
