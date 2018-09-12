#include "Estrategia.h"
#define DELAY_CURVA 500
#define DELAY_PONTA 150
#define DELAY_VERIFICACAO 275
#define DELAY_LADO 90
#define DELAY_FESTA 100
#define DELAY_EXPULSANDO_DA_FESTA 50 
#define DELAY_CONTINUE 90
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
    robo.ligarLed(2);
    motores.parar();
    delay(DELAY_VERIFICACAO);
    motores.frenteCurva();
    if(!sensores.bbpp()){
      while(!sensores.bpbb()){
        motores.girarDir();
      }
      while(sensores.bpbb()){
        motores.girarEsq();
      }
      motores.parar();
      delay(DELAY_VERIFICACAO);
    } else {
      while(sensores.bbpp()){
        motores.girarDir();
      }
      while(sensores.bbpb()){
        motores.girarDir();
      }
      while(sensores.bppb()){
        motores.girarDir();
      }
      while(sensores.bpbb()){
        motores.girarEsq();
      }
    }
    
    frente = false;
    direita = true;
    esquerda = false;
  }else if(sensores.ppbb()){
    robo.ligarLed(2);    
    motores.parar();
    delay(DELAY_VERIFICACAO);
    motores.frenteCurva();
    if(!sensores.ppbb()){
      while(!sensores.bbpb()){
        motores.girarEsq();
      }
      while(sensores.bbpb()){
        motores.girarDir();
      }
      motores.parar();
      delay(DELAY_VERIFICACAO);
    } else { 
      while(sensores.ppbb()){
        motores.giroDiferenteEsq();
      }
      while(sensores.bpbb()){
        motores.girarEsq();
      }
      while(sensores.bppb()){
        motores.girarEsq();
      }
      while(sensores.bbpb()){
        motores.girarDir();
      }
    }
    frente = false;
    direita = false;
    esquerda = true;

  }else if(sensores.bbbp()){
    motores.girarDir();
    delay(DELAY_PONTA);
    frente = false;
    direita = true;
    esquerda = false;
  }else if(sensores.pbbb()){
    motores.girarEsq();
    delay(DELAY_PONTA);
    frente = false;
    direita = false;
    esquerda = true;
  }else if(sensores.bppp()){
    motores.parar();
    delay(DELAY_VERIFICACAO);
    if(!sensores.bppp()){
      while(sensores.bppp()){
        motores.girarDir();
      }
      while(sensores.bbpb()){
        motores.girarDir();
      }
      while(sensores.bppb()){
        motores.girarDir();
      }
      while(sensores.bpbb()){
        motores.girarEsq();
      }
      motores.parar();
      delay(DELAY_VERIFICACAO);
    } else {
      while(sensores.bppp()){
        motores.giroDiferenteDir();
      }
      while(sensores.bpbb()){
        motores.giroDiferenteDir();
      }
      while(sensores.bppb()){
        motores.giroDiferenteDir();
      }
      while(sensores.bpbb()){
        motores.girarEsq();        
      }
    }
    
    frente = false;
    direita = true;
    esquerda = false;
  }else if(sensores.pppb()){
    motores.parar();
    delay(DELAY_VERIFICACAO);
    if(!sensores.pppb()){
      while(sensores.pppb()){
        motores.girarEsq();
      }
      while(sensores.bpbb()){
        motores.girarEsq();
      }
      while(sensores.bppb()){
        motores.girarEsq();
      }
      while(sensores.bbpb()){
        motores.girarDir();
      }
      motores.parar();
      delay(DELAY_VERIFICACAO);
    } else {
      while(sensores.pppb()){
        motores.giroDiferenteEsq();
      }
      while(sensores.bpbb()){
        motores.giroDiferenteEsq();
      }
      while(sensores.bppb()){
        motores.giroDiferenteEsq();
      }
      while(sensores.bbpb()){
        motores.girarDir();
      }
    }
    
    frente = false;
    direita = false;
    esquerda = true;
  }else if(sensores.pppp()){
    motores.parar();
    frente = false;
    direita = false;
    esquerda = false;
    
  }else if(sensores.bppb()){
    robo.ligarLed(3); 
    /*
    
    if(frente){
      motores.frente();
    }else if(direita){
      motores.virarDir();
    }else if(esquerda){
      motores.virarEsq();
    }
    delay(DELAY_CONTINUE);
    */
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

