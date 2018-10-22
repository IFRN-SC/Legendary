#include "Estrategia.h"

//Delays para Desviar Obstaculo
#define DELAY_PAUSA_MOVIMENTO 500
#define DELAY_FRENTE1 750
#define DELAY_FRENTE2 1125
#define DELAY_FRENTE3 1000

//Delays que eu não sei para que serve pq esqueci
#define DELAY_PARADA_CURVA 150
#define DELAY_VOLTAR_CURVA 100
#define DELAY_VERIFICACAO_ONDE_ESTOU 300 
#define DELAY_VERIFICACAO_PPPP 500

Estrategia::Estrategia(){
  //
}

void Estrategia::start(){
  if(dadosCapturados == false){
    refletancia.start();
  }
  dadosCapturados = true;
}

void Estrategia::executar(){
  caiu = false;

  toy.desligarLeds();
  start();
  //desviarObstaculo();
  seguirLinha();
}

void Estrategia::seguirLinha(){
  if(refletancia.bbbb()){
    setFrente();
    motores.frente();
  
  } else if(refletancia.bbpb()) {
    setDireita();
    motores.giroLeveDir();

  } else if(refletancia.bpbb()) {
    setEsquerda();
    motores.giroLeveEsq();
  
  //Tem em Baixo
  } else if(refletancia.bbpp()) {
    motores.miniParada();
    if(!refletancia.bbpp()){
      int i = 0;
      while(refletancia.sensorMaisDir('B')){
        i++;
        if(i >= 5000){
          break;
        }
      }
    }
    motores.parar();
    if(cor.nn()){
      if(cor.nv()){
        robo.ligarLed(3);
        motores.girar90Dir();
      }
    }
    motores.miniFrenteCurva();
    

    while(!refletancia.sensorEsq('P')){
      motores.giroCurvaDir();
    }
    while(refletancia.sensorEsq('P')){
      motores.giroLeveEsq();
    }

  //Tem em Cima
  } else if(refletancia.ppbb()) {
    motores.miniParada();
    if(!refletancia.ppbb()){
      int i = 0;
      while(refletancia.sensorMaisEsq('B')){
        i++;
        if(i >= 5000){
          break;
        }
        motores.voltarCurva();
      }
    }
    motores.parar();
    if(cor.nn()){
      if(cor.vn()){
        robo.ligarLed(3);
        motores.girar90Esq();
      }
    }
    motores.miniFrenteCurva();

    while(!refletancia.sensorDir('P')){
      motores.giroCurvaEsq();
    }
    while(refletancia.sensorDir('P')){
      motores.giroLeveDir();
    }

  }else if(refletancia.bbbp()){
    setDireita();
    motores.girarDir();

  }else if(refletancia.pbbb()){
    setEsquerda();
    motores.girarEsq();

  }else if(refletancia.bppp()){
    setDireita();
    motores.girarDir();

  }else if(refletancia.pppb()){
    setEsquerda();
    motores.girarEsq();

  }else if(refletancia.pppp()){
    //
    
  }else if(refletancia.bppb()){
    motores.miniParada();
    if(!refletancia.bppb()){
      while(refletancia.sensorMaisDir('B') && refletancia.sensorMaisEsq('B')){
        motores.voltarCurva();
      }
    }
    motores.pararAteBotao1();
  }else{
    //Ação Anterior
  }
}

void Estrategia::voltarAtePPPP(){
  if(refletancia.bbbb()){
    while(refletancia.pppp()){
      motores.voltarDevagar(); 
    }
  }
}

void Estrategia::desviarObstaculo(){
  if(distancia.verificarObstaculo()){
    delay(DELAY_PAUSA_MOVIMENTO);
      motores.girar90Dir();
      motores.parar();
      delay(DELAY_PAUSA_MOVIMENTO);

      motores.frenteDevagar();
      delay(DELAY_FRENTE1);
      motores.parar();
      delay(DELAY_PAUSA_MOVIMENTO);
      
      motores.girar90Esq();
      motores.parar();
      delay(DELAY_PAUSA_MOVIMENTO);
      
      motores.frenteDevagar();
      delay(DELAY_FRENTE2);
      motores.parar();
      delay(DELAY_PAUSA_MOVIMENTO);
      
      motores.girar90Esq();
      motores.parar();
      delay(DELAY_PAUSA_MOVIMENTO);
      
      while(refletancia.bbbb()){
        motores.frenteDevagar();
      }
      
      while(!refletancia.bbbb()){
        motores.frenteDevagar();
      }

      while(!refletancia.sensorDir('P')){
        motores.girarDevagarDir();
      }
  }
}

//Métodos de Registro de Movimentos
void Estrategia::setFrente(){
  frente = true;
  esquerda = false;
  direita = false;
}
void Estrategia::setDireita(){
  frente = false;
  esquerda = false;
  direita = true;
}
void Estrategia::setEsquerda(){
  frente = false;
  esquerda = true;
  direita = false;
}
int Estrategia::ultimoMovimentoRegistrado(){
  int resposta = 0;
  if(frente){
    resposta = 0;
  } else if (esquerda) {
    resposta = -1;
  } else if (direita) {
    resposta = 1;
  }
  return resposta;
}
