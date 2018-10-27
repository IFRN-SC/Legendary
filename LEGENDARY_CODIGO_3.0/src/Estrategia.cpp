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

void Estrategia::executar(){
  caiu = false;

  toy.desligarLeds();
  start();
  desviarObstaculo();
  if(distancia.isTheRampa()){
    seguirLinhaRampa();  
  } else {
    seguirLinha();
  }

}

void Estrategia::seguirLinha(){
  robo.ligarLed(1);
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
  } else if(refletancia.bbpp() || refletancia.bppp()) {
    motores.frear();
    motores.miniParada();
    
    boolean acaoNaoTerminada = false;
    
    if(!refletancia.bbpp() || !refletancia.bppp()){
      int i = 0;
      while(refletancia.sensorDir('B') || refletancia.sensorMaisDir('B')){
        i++;
        if(i >= 6000){
          acaoNaoTerminada = true;
          break;
        }
        motores.voltarCurva();
      }
    }
    motores.miniParada();
  
    motores.miniFrenteCurva();
    while(!refletancia.sensorEsq('P')){ motores.giroCurvaDir(); }
    while(refletancia.sensorEsq('P')){ motores.giroLeveEsq(); }

  //Tem em Cima
  } else if(refletancia.ppbb() || refletancia.pppb()) {
    motores.frear();
    motores.miniParada();
    
    boolean acaoNaoTerminada = false;
    
    if(!refletancia.ppbb() || !refletancia.pppb()){
      int i = 0;
      while(refletancia.sensorMaisEsq('B') || refletancia.sensorEsq('B')){
        i++;
        if(i >= 6000){
          acaoNaoTerminada = true;
          break;
        }
        motores.voltarCurva();
      }
    }
    motores.miniParada();
    
    motores.miniFrenteCurva();
    while(!refletancia.sensorDir('P')){ motores.giroCurvaEsq(); }
    while(refletancia.sensorDir('P')){ motores.giroLeveDir(); }

  }else if(refletancia.bbbp()){
    setDireita();
    motores.girarDir();

  }else if(refletancia.pbbb()){
    setEsquerda();
    motores.girarEsq();

  }else if(refletancia.pppp()){
    motores.miniParada();
    refletancia.alinheComPPPP();
    //if(acaoVerde()){
      //
    //} else {
      motores.miniFrenteCurva();
    //}
    
  }else if(refletancia.bppb()){
    if(ultimoMovimentoRegistrado() == -1){ //Esquerda
    
    } else if(ultimoMovimentoRegistrado() == 0){ //Frente

    } else if(ultimoMovimentoRegistrado() == 1){ //Direita

    }
  }
}

boolean Estrategia::acaoVerde(){
  boolean resposta = false;
  
  if(cor.nn()){
    resposta = false;
  
  } else if(cor.vn()){
    resposta = true;
    robo.ligarLed(3);
    motores.miniFrenteCurva();
    motores.girar90Esq();
  
  } else if(cor.nv()){
    resposta = true;
    motores.miniFrenteCurva();
    motores.girar90Dir();
  
  } else if(cor.vv()){
    resposta = true;
    robo.ligarLed(3);
    motores.miniFrenteCurva();
    motores.girar90Esq();
    motores.girar90Esq();
  }
  
  return resposta;
}

void Estrategia::desviarObstaculo(){
  if(distancia.isOnObstaculo()){
    delay(DELAY_PAUSA_MOVIMENTO);
    //distancia.ajustarDistanciaObstaculo();
    motores.voltar();
    delay(80);
    motores.miniParada();
    alinharObstaculo();        

    motores.miniParada();  
    motores.miniParada();
    motores.miniParada();
    motores.miniParada();
    motores.miniParada();

    while(robo.lerSensorSonarEsq() <= 6.0){
      robo.acionarMotores(-30, -33);
    }

    while(robo.lerSensorSonarEsq() >= 6.0){
      robo.acionarMotores(30, 33);
    }

    while(robo.lerSensorSonarEsq() <= 10.0){
      robo.acionarMotores(30, 33);
    }
    delay(70);

    motores.girar90Esq();

    motores.pararAteBotao1();



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

void Estrategia::alinharObstaculo(){
    motores.girar90Dir();
    robo.acionarMotores(40, -40);
    delay(70);
    motores.miniParada();
    motores.miniParada();
    //refletancia.alinheComPPNN();
}

void Estrategia::seguirLinhaRampa(){
  if(distancia.isTheRampa()){
    if(refletancia.bbbb()){
      motores.frenteRampa();

    } else if(refletancia.bpbb() || refletancia.pbbb()){
      motores.girarEsqRampa();

    } else if(refletancia.bbpb() || refletancia.bbbp()){
      motores.girarDirRampa();

    } else {
      motores.frenteRampa();
      delay(500);
    }
  }
}

void Estrategia::start(){
  if(dadosCapturados == false){
    refletancia.start();
  }
  dadosCapturados = true;
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
