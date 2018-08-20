#include "Estrategia.h"
#define DELAY_PONTA 150
#define DELAY_LADO 90
#define DELAY_FESTA 100
#define DELAY_EXPULSANDO_DA_FESTA 50 
#define DELAY_CONTINUE 90

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
    if(!sensores.bbpp()){
      while(sensores.bbpb()){
        motores.girarDir();
      }
    } else {
      while(sensores.bbpb()){
        motores.girarDir();
        delay(30);
      }
      while(sensores.bbbb()){
        motores.girarDir();
        delay(30);
      }
      
      while(sensores.bbpb()){
        motores.girarEsq();
      }
    }
    frente = false;
    direita = true;
    esquerda = false;
    
  }else if(sensores.ppbb()){    
    if(!sensores.ppbb()){
      while(sensores.bpbb()){
        motores.virarEsq();
      }
    } else {
      while(sensores.bpbb()){
        motores.girarEsq();
        delay(50);
      }
      while(sensores.bbbb()){
        motores.girarEsq();
        delay(50);
      }
      while(sensores.bpbb()){
        motores.girarDir();
      }
    }
    frente = false;
    direita = false;
    esquerda = true;

  }else if(sensores.bbbp()){
    motores.voltarDir();
    delay(90);   
    motores.girarDir();
    delay(DELAY_PONTA);
    frente = false;
    direita = true;
    esquerda = false;
  }else if(sensores.pbbb()){
    motores.voltarEsq();
    delay(90);
    motores.girarEsq();
    delay(DELAY_PONTA);
    frente = false;
    direita = false;
    esquerda = true;
  }else if(sensores.bppp()){
    motores.virarDir();
    delay(DELAY_EXPULSANDO_DA_FESTA);
    frente = false;
    direita = true;
    esquerda = false;
  }else if(sensores.pppb()){
    motores.virarEsq();
    delay(DELAY_EXPULSANDO_DA_FESTA);
    frente = false;
    direita = false;
    esquerda = true;
  }else if(sensores.pppp()){
    motores.parar();
    frente = false;
    direita = false;
    esquerda = false;
  }else if(sensores.bppb()){
    if(frente){
      motores.frente();
    }else if(direita){
      motores.girarDir();
    }else if(esquerda){
      motores.girarEsq();
    }
    delay(DELAY_CONTINUE);
  }else{
    //Ação Anterior
  }
}

void Estrategia::start(){
  if(dadosCapturados == false){
    sensores.start();
  }
  dadosCapturados = true;
}

void Estrategia::executar(){
  start();
  seguirLinha();
}

