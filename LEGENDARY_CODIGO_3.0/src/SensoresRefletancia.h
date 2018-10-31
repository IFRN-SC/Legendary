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

    double corteRedutorMaisEsq = 101;
    double corteRedutorEsq = 101;
    double corteRedutorDir = 101;
    double corteRedutorMaisDir = 101;
};

#endif
