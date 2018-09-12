#include "Estrategia.h"
#define DISTANCIA 4.60
#define DELAY_TAMANHO_OBSTACULO 1200

Estrategia::Estrategia(){
  //
}

void Estrategia::seguirLinha(){
  if(sensores.bbbb()){
    motores.frente();
    frente = true;
    direita = false;
    esquerda = false;
  }else if(sensores.bbpb()){
    motores.girarDir();
    frente = false;
    direita = true;
    esquerda = false;
  }else if(sensores.bpbb()){
    motores.girarEsq();
    frente = false;
    direita = false;
    esquerda = true;
  }else if(sensores.bbpp()){
    motores.girarDir();
    frente = false;
    direita = true;
    esquerda = false;
  }else if(sensores.ppbb()){
    motores.girarEsq();
    frente = false;
    direita = false;
    esquerda = true;
  }else if(sensores.bbbp()){
    motores.girarDir();
    frente = false;
    direita = true;
    esquerda = false;
  }else if(sensores.pbbb()){
    motores.girarEsq();
    frente = false;
    direita = false;
    esquerda = true;
  }else if(sensores.bppp()){
    motores.girarDir();
    frente = false;
    direita = true;
    esquerda = false;
  }else if(sensores.pppb()){
    motores.girarEsq();
    frente = false;
    direita = false;
    esquerda = true;
  }else if(sensores.pppp()){
    motores.parar();
    frente = false;
    direita = false;
    esquerda = false;
  }else if(sensores.bppb()){
    //Seja Criativo 
  }else{
    //Ação Anterior
  }
}

void Estrategia::desviarObstaculo(){
  if(sensores.sonar()){
    motores.parar();
    delay(1000);
    if(sensores.sonar()){
      motores.girar90Dir();
      motores.parar();
      delay(1000);
      motores.frente();
      delay(750);
      motores.parar();
      delay(1000);
      motores.girar90Esq();
      motores.parar();
      delay(1000);
      motores.frente();
      delay(DELAY_TAMANHO_OBSTACULO);
      motores.parar();
      delay(1000);
      motores.girar90Esq();
      motores.parar();
      delay(1000);
      while(!sensores.bbbb()){
        motores.frente(); 
      }
      motores.parar();
      delay(1000);
      motores.girar90Dir();
      motores.parar();
      delay(1000);
    } 
  }
}

void Estrategia::start(){
  if(dadosCapturados == false){
    sensores.start();
  }
  dadosCapturados = true;
}

void Estrategia::executar(){
  robo.desligarLed(1);
  robo.desligarLed(2);
  robo.desligarLed(3);
  start();
  //desviarObstaculo();
  seguirLinha();
}

