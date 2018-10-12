#ifndef SENSORESREFLETANCIA_H
#define SENSORESREFLETANCIA_H

#include <robo_hardware2.h>
#include <Servo.h>
#include <Wire.h>

class SensoresRefletancia{
  public:
    SensoresRefletancia();
    void start();
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
    
    boolean sonarObstaculo();
    
    float cinzaMaisEsq;
    float cinzaEsq;
    float cinzaDir;
    float cinzaMaisDir;

    void printSensoresDeRefletancia();
    
  private:
    calibracao_dados val;
    void pegarDadosEEPROM();

    float valorSensorMaisEsq;
    float valorSensorEsq;
    float valorSensorDir;
    float valorSensorMaisDir;
};

#endif
