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
    void giroDiferenteEsq();
    void giroDiferenteDir();
    void girar90Esq();
    void girar90Dir();
    void frenteCurva();
};

#endif

/*
COMANDOS PARA TESTES:
  motores.frente();
  delay(1000);
  motores.parar();
  delay(1000);
  motores.voltar();
  delay(1000);
  motores.parar();
  delay(1000);
  motores.girarEsq();
  delay(1000);
  motores.parar();
  delay(1000);
  motores.girarDir();
  delay(1000);
  motores.parar();
  delay(1000);
  motores.virarEsq();
  delay(1000);
  motores.parar();
  delay(1000);
  motores.virarDir();
  delay(1000);
  motores.parar();
  delay(1000);
  motores.voltarEsq();
  delay(1000);
  motores.parar();
  delay(1000);
  motores.voltarDir();
  delay(1000);
  motores.parar();
  delay(1000);
*/
