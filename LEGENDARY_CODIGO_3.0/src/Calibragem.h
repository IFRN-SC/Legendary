#ifndef CALIBRAGEM_H
#define CALIBRAGEM_H

#include <robo_hardware2.h>
#include "Toy.h"

class Calibragem{
  public:
    Calibragem();
    boolean voltarMenu;

    void printDadosEEPROM();
    void iniciarCalibragem();
    
  private:
    Toy toy;
    calibracao_dados val;
  
    //Variaveis para a Calibração dos Sensores de Refletancia
    int mediaBrancoRefletanciaMaisEsq;
    int mediaBrancoRefletanciaEsq;
    int mediaBrancoRefletanciaDir;
    int mediaBrancoRefletanciaMaisDir;

    double mediaSuperBrancoRefletanciaMaisEsq;
    double mediaSuperBrancoRefletanciaEsq;
    double mediaSuperBrancoRefletanciaDir;
    double mediaSuperBrancoRefletanciaMaisDir;
    
    int mediaPretoRefletanciaMaisEsq;
    int mediaPretoRefletanciaEsq;
    int mediaPretoRefletanciaDir;
    int mediaPretoRefletanciaMaisDir;

    //Variaveis para calibração dos Sensores de Cor
    HSV capturadorDeCorAuxEsqHSV;
    HSV capturadorDeCorAuxDirHSV;

    HSV mediaBrancoCorEsq;
    HSV mediaBrancoCorDir;
    HSV mediaPretoCorEsq;
    HSV mediaPretoCorDir;
    HSV mediaVerdeCorEsqHSV;
    HSV mediaVerdeCorDirHSV; 

    //Métodos para calibração de Sensores
    void calibracaoPretoRefletancia();
    void calibracaoPretoCor();
    void calibracaoBrancoRefletanciaCor();
    void calibracaoSuperBrancoRefletancia();
    void calibracaoVerdeEsq();
    void calibracaoVerdeDir();

    void calcularCinzaRefletancia();
    void guardarDadosEEPROM();
};

#endif
