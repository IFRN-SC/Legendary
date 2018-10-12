#include "Estrategia.h"
#define DELAY_PARADA_CURVA 150
#define DELAY_VOLTAR_CURVA 100
#define DELAY_VERIFICACAO_ONDE_ESTOU 300 
#define DELAY_VERIFICACAO_PPPP 500

#define DELAY_TAMANHO_OBSTACULO 1200

Estrategia::Estrategia(){
  //
}

void Estrategia::seguirLinha(){
  if(refletancia.bbbb()){
    motores.frente();
    frente = true;
    direita = false;
    esquerda = false;
  }else if(refletancia.bbpb()){
    motores.girarDir();
    frente = false;
    direita = true;
    esquerda = false;
  }else if(refletancia.bpbb()){
    motores.girarEsq();
    frente = false;
    direita = false;
    esquerda = true;
  
  //TEM EM BAIXO
  }else if(refletancia.bbpp()){
    robo.ligarLed(1);
    motores.parar();
    delay(DELAY_VERIFICACAO_ONDE_ESTOU);
    if(!refletancia.bbbb()){
      while(!refletancia.bbbb()){
        if(refletancia.bppb()){
          robo.ligarLed(2); 
        }
        motores.frente();
      }
      /*
    motores.parar();
      delay(DELAY_PARADA_CURVA);
      motores.voltar();
      delay(DELAY_VOLTAR_CURVA);
      */
      motores.parar();
      delay(DELAY_PARADA_CURVA);
      while(!refletancia.bpbb()){
        if(refletancia.bppb()){
          robo.ligarLed(2); 
        }
        motores.girarDir();
      }
      while(!refletancia.bbbb()){
        if(refletancia.bppb()){
          robo.ligarLed(2); 
        }
        motores.girarDevagarEsq();
      }  
    }else{
      while(!refletancia.bpbb()){
        if(refletancia.bppb()){
          robo.ligarLed(2); 
        }
        motores.girarDir();
      }
      while(!refletancia.bbbb()){
        if(refletancia.bppb()){
          robo.ligarLed(2); 
        }
        motores.girarDevagarEsq();
      }
    }
    
    frente = false;
    direita = true;
    esquerda = false;

  //TEM EM CIMA
  }else if(refletancia.ppbb()){
    robo.ligarLed(1);
    motores.parar();
    delay(DELAY_VERIFICACAO_ONDE_ESTOU);
    if(!refletancia.bbbb()){
      while(!refletancia.bbbb()){
        motores.frente();
      }
      /*
      motores.parar();
      delay(DELAY_PARADA_CURVA);
      motores.voltar();
      delay(DELAY_VOLTAR_CURVA);
      */
      motores.parar();
      delay(DELAY_PARADA_CURVA);
      while(!refletancia.bbpb()){
        if(refletancia.bppb()){
          robo.ligarLed(2); 
        }
        motores.girarEsq();
      }
      
      while(!refletancia.bbbb()){
        if(refletancia.bppb()){
          robo.ligarLed(2); 
        }
        motores.girarDevagarDir();
      }  
    }else{
      while(!refletancia.bbpb()){
        if(refletancia.bppb()){
          robo.ligarLed(2); 
        }
        motores.girarEsq();
      }
      while(!refletancia.bbbb()){
        if(refletancia.bppb()){
          robo.ligarLed(2); 
        }
        motores.girarDevagarDir();
      }
    }
    
    frente = false;
    direita = false;
    esquerda = true;

  }else if(refletancia.bbbp()){
    motores.girarDir();
    frente = false;
    direita = true;
    esquerda = false;
  }else if(refletancia.pbbb()){
    motores.girarEsq();
    frente = false;
    direita = false;
    esquerda = true;
  }else if(refletancia.bppp()){
    motores.girarDir();
    frente = false;
    direita = true;
    esquerda = false;
  }else if(refletancia.pppb()){
    motores.girarEsq();
    frente = false;
    direita = false;
    esquerda = true;
  }else if(refletancia.pppp()){
    robo.ligarLed(1);
    motores.frente();
    delay(1500);
    motores.girarDir();
    delay(500); 
    motores.parar();
    delay(DELAY_VERIFICACAO_PPPP);
    
    /*
    if(!refletancia.pppp()){
      voltarAtePPPP();
    }
    */
    frente = false;
    direita = false;
    esquerda = false;
    
  }else if(refletancia.bppb()){
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

void Estrategia::voltarAtePPPP(){
  if(refletancia.bbbb()){
    while(refletancia.pppp()){
      motores.voltarDevagar(); 
    }
  }
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
  /*
  while(!robo.botao1Pressionado()){
    cor.testarVerde();
  }
  */
}

