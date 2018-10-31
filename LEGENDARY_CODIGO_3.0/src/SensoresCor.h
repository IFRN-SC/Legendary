#ifndef SENSORESCOR_H
#define SENSORESCOR_H

#include <robo_hardware2.h>

class SensoresCor{
  public:
    SensoresCor();
    void start();

    boolean sensorEsq(char);
    boolean sensorDir(char);

    boolean vv();
    boolean vn();
    boolean nv();
    boolean nn();

    void testarVerde();
    void testarVerdeMultiplo();
    void printSensoresDeCorRGB();
    void printSensoresDeCorHSV(); 
  
  private:
    calibracao_dados val;
    void pegarDadosEEPROM();
    void calcularDivisores();

    HSV divisorPretoVerdeEsq;
    HSV divisorBrancoVerdeEsq;
    HSV divisorPretoVerdeDir;
    HSV divisorBrancoVerdeDir;
    HSV divisorPretoBrancoEsq;
    HSV divisorPretoBrancoDir;

    RGB valorSensorCorRGBEsq;
    RGB valorSensorCorRGBDir;
    
    HSV valorSensorCorHSVEsq;
    HSV valorSensorCorHSVDir;

    HSV mediaBrancoCorEsq;
    HSV mediaBrancoCorDir;
    HSV mediaPretoCorEsq;
    HSV mediaPretoCorDir;
    HSV mediaVerdeCorEsq;
    HSV mediaVerdeCorDir;
    
};

#endif


