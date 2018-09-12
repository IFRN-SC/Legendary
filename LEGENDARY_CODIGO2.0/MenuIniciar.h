#ifndef MENUINICIAR_H
#define MENUINICIAR_H

#include <Arduino.h>
#include <robo_hardware2.h>
#include "Toy.h"
#include "Calibragem.h"
#include "Estrategia.h"

class MenuIniciar{
  public:
    Calibragem calibragem;
    MenuIniciar();
    void menuBotoes();
    void dadosEEPROM();
  
  private:
    void menuSerial();
    
    Toy toy;
    calibracao_dados val;

    float valorSensorMaisEsq;
    float valorSensorEsq;
    float valorSensorDir;
    float valorSensorMaisDir;

    float valorSensorFrontal;
    float valorSensorLateralEsq;
    float valorSensorLateralDir;

    RGB valorSensorCorEsq;
    RGB valorSensorCorDir; 
};

#endif
