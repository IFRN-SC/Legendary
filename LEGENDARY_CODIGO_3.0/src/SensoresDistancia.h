#ifndef SENSORESDISTANCIA_H
#define SENSORESDISTANCIA_H

#include <robo_hardware2.h>

#include "Motores.h"
#include "SensoresRefletancia.h"
#include "SensoresDistancia.h"

class SensoresDistancia{
  public:
    SensoresDistancia();
    boolean isOnObstaculo();
    boolean isTheRampa();
    void ajustarDistanciaObstaculo();

    double getMediaSonarEsq();
    double getMediaSonarDir();
    double getValorMaximoSonarEsq();
    double getValorMaximoSonarDir();
    double getValorMinimoSonarEsq();
    double getValorMinimoSonarDir();

    void printSensoresDeDistancia();

  private:
    Motores motores;
    SensoresRefletancia refletancia;

    float valorLido;
      
};

#endif


