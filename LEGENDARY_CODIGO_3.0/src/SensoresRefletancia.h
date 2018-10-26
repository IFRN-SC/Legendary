#ifndef SENSORESREFLETANCIA_H
#define SENSORESREFLETANCIA_H

#include <robo_hardware2.h>
#include <Servo.h>
#include <Wire.h>

#include "Calibragem.h"
#include "Motores.h"

class SensoresRefletancia{
  public:
    SensoresRefletancia();
    void start();
    
    void alinheComPPPP();
    void alinheComBBBB();
    void alinheComPPNN();
    void alinheComNNPP();

    boolean bbbb();
    boolean bbbp();
    boolean pbbb();
    boolean bbpp();
    boolean ppbb();
    boolean bppp();
    boolean pppb();
    boolean bbpb();
    boolean bpbb(); 
    boolean bppb();
    boolean pppp();

    boolean sensorMaisEsq(char);
    boolean sensorEsq(char);
    boolean sensorDir(char);
    boolean sensorMaisDir(char);

    boolean isOnRedutor();

    void printSensoresDeRefletancia();
    
  private:
    Calibragem calibragem;
    calibracao_dados val;
    Motores motores;

    void pegarDadosEEPROM();

    int cinzaMaisEsq;
    int cinzaEsq;
    int cinzaDir;
    int cinzaMaisDir;

    double valorCapturado;

    //double corteRedutorMaisEsq;
    //double corteRedutorEsq;
    //double corteRedutorDir;
    //double corteRedutorMaisDir;

    float corteRedutorMaisEsq = 100;
    float corteRedutorEsq = 100;
    float corteRedutorDir = 100;
    float corteRedutorMaisDir = 100;
};

#endif
