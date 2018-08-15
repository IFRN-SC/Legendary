#include "Estrategia.h"

Estrategia::Estrategia(){
  //
}

void Estrategia::seguirLinha(){
  
}

void Estrategia::executar(){
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
}

