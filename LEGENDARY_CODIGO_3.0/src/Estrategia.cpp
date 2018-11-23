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
  
  if(distancia.isTheRampa()){
    robo.ligarLed(2);
    seguirLinhaRampa();  
  } else {
    desviarObstaculo();
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
    setDireita();
    motores.frear();
    motores.miniParada();
    int i = 0;
    
    if(!refletancia.bbpp() || !refletancia.bppp()){
      i = 0;
      while(refletancia.sensorDir('B') && refletancia.sensorMaisDir('B')){
        i++;
        if(i >= 6000){ break;}
        motores.voltarCurva();
      }
      motores.frearVoltar();
    }
    motores.miniParada();
  
    //acaoVerde();

    motores.miniFrenteCurva();
    i = 0;
    while(!refletancia.sensorEsq('P')){ 
      i++;
      if(i >= 10000){ break;}
      motores.giroCurvaDir(); 
    }
    i = 0;
    while(refletancia.sensorEsq('P')){ 
      i++;
      if(i >= 10000){ break;}
      motores.giroLeveEsq(); 
    }
    motores.frearGiroEsq();
  
  //Tem em Cima
  } else if(refletancia.ppbb() || refletancia.pppb()) {
    setEsquerda();
    motores.frear();
    motores.miniParada();
    int i = 0;
    
    if(!refletancia.ppbb() || !refletancia.pppb()){
      i = 0;
      while(refletancia.sensorMaisEsq('B') && refletancia.sensorEsq('B')){
        i++;
        if(i >= 6000){ break;}
        motores.voltarCurva();
      }
      motores.frearVoltar();
    }
    motores.miniParada();
    
    //acaoVerde();

    motores.miniFrenteCurva();
    i = 0;
    while(!refletancia.sensorDir('P')){ 
      i++;
      if(i >= 10000){ break;}
      motores.giroCurvaEsq(); 
    }

    i = 0;
    while(refletancia.sensorDir('P')){ 
      i++;
      if(i >= 10000){ break;}
      motores.giroLeveDir(); 
    }
    motores.frearGiroDir();

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


void Estrategia::seguirLinhaVerde(){
  int sla = 0;
  while(sla < 10){
    if(distancia.isTheRampa()){
      robo.ligarLed(2);
      seguirLinhaRampa();  
    } else {
      toy.desligarLeds();
      desviarObstaculo();
      robo.ligarLed(3);
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
          motores.miniParada();
          motores.miniFrenteCurva();
        } else if(ultimoMovimentoRegistrado() == 0){ //Frente
          motores.frente();
        } else if(ultimoMovimentoRegistrado() == 1){ //Direita
          motores.frearGiroDir();
          delay(300);
          motores.miniFrenteCurva();
          while(refletancia.sensorMaisDir('B')){
            motores.girarDevagarDir();
          }
          while(refletancia.sensorDir('B')){
            motores.girarDevagarDir();
          }
          motores.miniParada();
          motores.miniFrenteCurva();
        }


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
      
        //acaoVerde();

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
        
        //acaoVerde();

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
  }
}

boolean Estrategia::acaoVerde(){
  boolean resposta = false;
  int contadorDeVerdes = 0;
  motores.miniParada();


  for(int i = 0; i <= 4; i++){
    if(cor.nn()){
      resposta = false;
    } else if (cor.vn()){
      resposta = true;
      robo.ligarLed(2);
    } else if (cor.nv()){
      resposta = true;
      robo.ligarLed(2);
    } else if (cor.vv()){
      resposta = true;
      robo.ligarLed(2);
    }
  
    if(i == 0){
      robo.acionarMotores(0,25);
      delay(100);
      motores.frearVoltarDir();
    
    } else if (i == 1){
      robo.acionarMotores(28,0);
      delay(100);
      motores.frearVoltarDir();

    } else if (i == 2){
      robo.acionarMotores(0,-23);
      delay(200);
      motores.frearVoltarDir();
      robo.acionarMotores(-23,-20);
      delay(100);
      motores.frearVoltar();

    } else if( i == 3){
      robo.acionarMotores(23,20);
      delay(100);
      motores.frear();
      robo.acionarMotores(-23,0);
      delay(200);
      motores.frearVoltarEsq();
      robo.acionarMotores(-23,-20);
      delay(100);
      motores.frearVoltar();

    } else {
      robo.acionarMotores(23,0);
      delay(200);
      motores.frearGiroEsq();
      motores.pararAteBotao1();
    }
  }

  if(resposta == false){
    for(int i = 0; i <= 4; i++){
      if(cor.nn()){
        resposta = false;
      } else if (cor.vn()){
        resposta = true;
        robo.ligarLed(2);
      } else if (cor.nv()){
        resposta = true;
        robo.ligarLed(2);
      } else if (cor.vv()){
        resposta = true;
        robo.ligarLed(2);
      }

      if(( i % 2 ) == 0){
        robo.acionarMotores(23,0);
        delay(100);
        motores.frearVirarDir();
      } else {
        robo.acionarMotores(0,23);
        delay(100);
        motores.frearVirarEsq();
      }
    }
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
  if(distancia.isTheRampa()){
    int i = 0;
    if(refletancia.bbbb()){
      while(refletancia.bbbb()){
        i++;
        motores.frenteRampa();
        if(i >= 20000){
          robo.acionarMotores(20,20);
          delay(700);
          robo.acionarMotores(75,75);
          delay(1000);
          break;  
        }
      }
    } else if(refletancia.bpbb() || refletancia.pbbb()){
      motores.girarEsqRampa();

    } else if(refletancia.bbpb() || refletancia.bbbp()){
      motores.girarDirRampa();

    } else {
      motores.superFrenteRampa();
      delay(300);
      
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
