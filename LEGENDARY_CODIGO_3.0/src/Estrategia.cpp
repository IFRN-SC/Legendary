#include "Estrategia.h"

//Delays para Desviar Obstaculo
#define DELAY_PAUSA_MOVIMENTO 500
#define DELAY_FRENTE1 750
#define DELAY_FRENTE2 1125
#define DELAY_FRENTE3 1000

//Delays que eu não sei para que serve pq esqueci
#define DELAY_PARADA_CURVA 150
#define DELAY_VOLTAR_CURVA 100 
#define DELAY_VERIFICACAO_PPPP 500

int i = 0;

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
  toy.desligarLeds();
  start();
  
  //desviarObstaculo();
  seguirLinha();
  //cor.testarVerde();
}

void Estrategia::seguirLinha(){
  if(refletancia.bbbb()){
    setFrente();
    motores.frente();
  
  } else if(refletancia.bbpb()) {
    setDireita();
    motores.girarDir();

  } else if(refletancia.bpbb()) {
    setEsquerda();
    motores.girarEsq();
  
  } else if(refletancia.bbpp()) {
    setDireita();
    motores.miniParada();

    //Alinhar
    if(refletancia.bbbb()){
      //Retornar a Linha
      i = 0;
      while(!(refletancia.sensorMaisDir('P'))){ 
        i++;
        if(i >= 1500){
          break;
        }
        motores.voltarDevagar();
      }  
    }
    //Andar um pouco
    motores.miniParada();
    motores.frenteCurva();
    motores.miniParada();
    
    //Girar
    i = 0;
    while(!refletancia.sensorDir('P')){
        i++;
        if(i >= 1500){
          break;
        }
        motores.giroCurvaDir();
    }
    i = 0;
    while(!refletancia.sensorEsq('P')){
        i++;
        if(i >= 1500){
          break;
        }
        motores.giroCurvaDir();
    }
    i = 0;
    while(!refletancia.bbbb()){
      i++;
      if(i >= 1500){
        break;
      }
      motores.giroCurvaEsq();
    }
    motores.voltarDevagar();
    delay(125);
    motores.miniParada();

    
  } else if(refletancia.ppbb()) {
    setEsquerda();
    motores.miniParada();

    //Alinhar
    if(refletancia.bbbb()){
      //Retornar A Linha
      i = 0;
      while(!(refletancia.sensorMaisDir('P'))){ 
        i++;
        if(i >= 1500){
          break;
        }
        motores.voltarDevagar();
      } 
    }
    //Andar um pouco
    motores.miniParada();
    motores.frenteCurva();
    motores.miniParada();

    //Girar
    i = 0;
    while(!refletancia.sensorEsq('P')){
        i++;
        if(i >= 1500){
          break;
        }
        motores.giroCurvaEsq();
    }
    i = 0;
    while(!refletancia.sensorDir('P')){
        i++;
        if(i >= 1500){
          break;
        }
        motores.giroCurvaEsq();
    }
    i = 0;
    while(!refletancia.bbbb()){
      i++;
      if(i >= 1500){
        break;
      }
      motores.giroCurvaDir();
    }

    motores.voltarDevagar();
    delay(125);
    motores.miniParada();

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
    robo.ligarLed(1);
    motores.parar();
    
  }else if(refletancia.bppb()){
    robo.ligarLed(3);

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
