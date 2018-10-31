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
  
  //if(distancia.isTheRampa()){
    //robo.ligarLed(2);
    //seguirLinhaRampa();  
  //} else {
    //desviarObstaculo();
    seguirLinha();
  //}
  
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
  
  } else if(refletancia.sensorEsq('P') && refletancia.sensorDir('P')){
    robo.ligarLed(3);
    /*
    if(ultimoMovimentoRegistrado() == -1){ //Esquerda
      motores.frearGiroEsq();
      delay(300);
      motores.miniFrenteCurva();
      while(refletancia.sensorMaisEsq('B')){
        motores.girarDevagarEsq();
      }
      while(refletancia.sensorEsq('B')){
        motores.girarDevagarEsq();
      }
      motores.pararAteBotao1();
    } else if(ultimoMovimentoRegistrado() == 0){ //Frente
      motores.frente();
    } else if(ultimoMovimentoRegistrado() == 1){ //Direita
      motores.miniGiroDir();
    }
    */

  //Tem em Baixo
  } else if(refletancia.bbpp() || refletancia.bppp()) {
    setDireita();
    motores.frear();
    motores.miniParada();
    int i = 0;
    boolean acaoNaoTerminada = false;
    
    if(!refletancia.bbpp() || !refletancia.bppp()){
      i = 0;
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
  
    acaoVerde();

    motores.miniFrenteCurva();
    i = 0;
    while(!refletancia.sensorEsq('P')){ 
      i++;
      if(i >= 10000){
        acaoNaoTerminada = true;
        break;
      }
      motores.giroCurvaDir(); 
    }
    i = 0;
    while(refletancia.sensorEsq('P')){ 
      i++;
      if(i >= 10000){
        acaoNaoTerminada = true;
        break;
      }
      motores.giroLeveEsq(); 
    }

  //Tem em Cima
  } else if(refletancia.ppbb() || refletancia.pppb()) {
    setEsquerda();
    motores.frear();
    motores.miniParada();
    int i = 0;
    boolean acaoNaoTerminada = false;
    
    if(!refletancia.ppbb() || !refletancia.pppb()){
      i = 0;
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
    
    acaoVerde();

    motores.miniFrenteCurva();
    i = 0;
    while(!refletancia.sensorDir('P')){ 
      i++;
      if(i >= 10000){
        acaoNaoTerminada = true;
        break;
      }
      motores.giroCurvaEsq(); 
    }

    i = 0;
    while(refletancia.sensorDir('P')){ 
      i++;
      if(i >= 10000){
        acaoNaoTerminada = true;
        break;
      }
      motores.giroLeveDir(); 
    }

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
  }
}

boolean Estrategia::acaoVerde(){
  boolean resposta = false;
  int contadorDeVerdes = 0;
  for(int i = 0; i <= 4; i++){
    if(( i % 2 ) == 0){
      robo.acionarMotores(-23,0);
      for(int cont = 0; cont <= 1; cont++){
        if(cor.sensorEsq('V')){
          contadorDeVerdes++;
        }
      }
      motores.frearVoltarEsq();
      delay(200);

    } else {
      robo.acionarMotores(0,-23);
      for(int cont = 0; cont <= 1; cont++){
        if(cor.sensorEsq('V')){
          contadorDeVerdes++;
        }
      }
      motores.frearVoltarDir();
      delay(200);
    }
  }
  motores.parar();
  if(contadorDeVerdes > 1){
    robo.ligarLed(3);
  }

  return resposta;
}

void Estrategia::desviarObstaculo(){
  if(distancia.isOnObstaculo()){
    delay(DELAY_PAUSA_MOVIMENTO);
    
    if(robo.lerSensorSonarFrontal() <= 4.50){
      motores.voltar();
      delay(80);
      motores.miniParada();
      motores.miniParada();
    }

    motores.girar90Dir();
    delay(600);

    refletancia.alinheComPPNN();      
    delay(600);

    //Primeira Parte
    double distanciaMedia = distancia.getMediaSonarEsq();
    double distanciaDeCorte = distanciaMedia / 6;

    while(robo.lerSensorSonarEsq() >= distanciaDeCorte){
      robo.acionarMotores(36, 38);
    }
    delay(200);

    while(robo.lerSensorSonarEsq() <= distanciaDeCorte){
      robo.acionarMotores(36, 38);
    }
    delay(50);

    motores.frear();
    delay(600);

    motores.girar90Esq();
    delay(600);

    //Segunda Parte
    distanciaMedia = distancia.getMediaSonarEsq();
    distanciaDeCorte = distanciaMedia / 6;

    while(robo.lerSensorSonarEsq() >= distanciaDeCorte){
      robo.acionarMotores(37, 37);
    }
    delay(200);
    while(robo.lerSensorSonarEsq() <= distanciaDeCorte){
      robo.acionarMotores(37, 37);
    }
    //cdelay(50);

    motores.frear();
    delay(600);

    motores.girar90Esq();
    delay(600);
    

    //Última Parte
    while(refletancia.sensorEsq('B')){
      robo.acionarMotores(36, 37);
    }
      

    while(refletancia.sensorEsq('P')){
      robo.acionarMotores(36, 37);
    }

    motores.frear();
    delay(600);

    while(!refletancia.sensorEsq('P')){
      motores.girarDevagarDir();
    }
    while(!refletancia.sensorEsq('B')){
      motores.giroLeveEsq();
    }
    motores.frearGiroEsq();
    delay(600);
  }
}

void Estrategia::seguirLinhaRampa(){
  #define LIMITE_RAMPA_BBBB 10000
  int cont = 0;
  if(distancia.isTheRampa()){
    if(refletancia.bbbb()){
      while(refletancia.bbbb() && (cont <= LIMITE_RAMPA_BBBB)){
        cont++;
        motores.frenteRampa();
      }
      if(cont >= LIMITE_RAMPA_BBBB){
        motores.superFrenteRampa();
        delay(1000);
      }
      cont = 0;

    } else if(refletancia.bpbb() || refletancia.pbbb()){
      motores.girarEsqRampa();

    } else if(refletancia.bbpb() || refletancia.bbbp()){
      motores.girarDirRampa();

    } else {
      motores.superFrenteRampa();
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
