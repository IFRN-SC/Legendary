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

    float getMediaSonarEsq();
    float getMediaSonarDir();

    void printSensoresDeDistancia();

  private:
    Motores motores;
    SensoresRefletancia refletancia;

    float valorLido;
      
};

#endif


