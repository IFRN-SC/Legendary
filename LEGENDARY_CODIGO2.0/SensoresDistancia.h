#ifndef SENSORESDISTANCIA_H
#define SENSORESDISTANCIA_H

#include <robo_hardware2.h>
#include <Servo.h>
#include <Wire.h>

class SensoresDistancia{
  public:
    SensoresDistancia();
    void printSensoresDeDistancia();

  private:
    float valorSensorFrontal;
    float valorSensorLateralEsq;
    float valorSensorLateralDir;
      
};

#endif


