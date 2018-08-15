#ifndef MOTORES_H
#define MOTORES_H

#include <robo_hardware2.h>
#include <Servo.h>

class Motores{
  public:
    Motores();
    void frente();
    void voltar();
    void parar();
    void girarEsq();
    void girarDir();
    void virarEsq();
    void virarDir();
    void voltarEsq();
    void voltarDir();
};

#endif
