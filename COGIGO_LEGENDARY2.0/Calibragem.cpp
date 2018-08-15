#include "Calibragem.h"

Calibragem::Calibragem (){
  //
}

void Calibragem::iniciarCalibragem(){
  Serial.println("\n-------------------");
  Serial.println("Calibração Iniciada");
  Serial.println("-------------------\n");
  Serial.println("Parte 1 Calibração: Colocar sensores na linha preta (Precione o Botão 1 para Continuar)");
  
  while(!robo.botao1Pressionado()){} //Espera Resposta do Botão 1
  toy.allLedsOff();
  toy.led1On();

  calibracaoPreto();
  
  Serial.println("Captura dos Valores Pretos Completo");
  Serial.println("Valores Pretos Capturados: ");
  Serial.println("  +esq    esq     dir     +dir");
  Serial.print  ("  ");
  Serial.print  (mediaPreto[0]);
  Serial.print  ("   ");
  Serial.print  (mediaPreto[1]);
  Serial.print  ("   ");
  Serial.print  (mediaPreto[2]);
  Serial.print  ("   ");
  Serial.println(mediaPreto[3]);
  
  Serial.println("Parte 2 Calibração: Colocar sensores na linha branca (Precione o Botão 2 para Continuar)");
  while(!robo.botao2Pressionado()){} //Espera Resposta do Botão 2
  toy.led2On();

  calibracaoBranco();
  
  Serial.println("Captura dos Valores Branco Completo");
  Serial.println("Valores Brancos Capturados: ");
  Serial.println("  +esq    esq     dir     +dir");
  Serial.print  ("  ");
  Serial.print  (mediaBranco[0]);
  Serial.print  ("   ");
  Serial.print  (mediaBranco[1]);
  Serial.print  ("   ");
  Serial.print  (mediaBranco[2]);
  Serial.print  ("   ");
  Serial.println(mediaBranco[3]);

  //Calculando Cinza
  cinzaMaisEsq = (mediaPreto[0] + mediaBranco[0])/2; 
  cinzaEsq = (mediaPreto[1] + mediaBranco[1])/2;
  cinzaDir = (mediaPreto[2] + mediaBranco[2])/2;
  cinzaMaisDir = (mediaPreto[3] + mediaBranco[3])/2; 

  Serial.println("Valores de Corte Calculados");
  Serial.println("Valores Calculados: ");
  Serial.println("  +esq    esq     dir     +dir");
  Serial.print  ("  ");
  Serial.print  (cinzaMaisEsq);
  Serial.print  ("   ");
  Serial.print  (cinzaEsq);
  Serial.print  ("   ");
  Serial.print  (cinzaDir);
  Serial.print  ("   ");
  Serial.println(cinzaMaisDir);

  guardarDadosEEPROM();
  getDadosCalibragem();
  
  Serial.println("CALIBRAÇÃO FINALIZADA: Calibração terminada (Precione o Botão 3 para voltar ao Menu Botão)");
  while(!robo.botao3Pressionado()){} //Espera Resposta do Botão 3
  toy.led3On();
  
  delay(200);
  toy.ledsAlerta(4);
  delay(200);
  voltarMenu = true;
}

void Calibragem::calibracaoPreto(){
  int i;
  for (i = 0; i < 10; i++) {
    mediaPreto[0] = mediaPreto[0] + robo.lerSensorLinhaMaisEsq();
    mediaPreto[1] = mediaPreto[1] + robo.lerSensorLinhaEsq();
    mediaPreto[2] = mediaPreto[2] + robo.lerSensorLinhaDir();
    mediaPreto[3] = mediaPreto[3] + robo.lerSensorLinhaMaisDir();
    
    delay(300);
  }

  mediaPreto[0] = mediaPreto[0] / 10;
  mediaPreto[1] = mediaPreto[1] / 10;
  mediaPreto[2] = mediaPreto[2] / 10;
  mediaPreto[3] = mediaPreto[3] / 10;

  toy.ledAlerta(1, 10, 50);
}

void Calibragem::calibracaoBranco(){  
  int i;
  for (i = 0; i < 10; i++) {
    mediaBranco[0] = mediaBranco[0] + robo.lerSensorLinhaMaisEsq();
    mediaBranco[1] = mediaBranco[1] + robo.lerSensorLinhaEsq();
    mediaBranco[2] = mediaBranco[2] + robo.lerSensorLinhaDir();
    mediaBranco[3] = mediaBranco[3] + robo.lerSensorLinhaMaisDir();
    
    delay(300);
  }

  mediaBranco[0] = mediaBranco[0] / 10;
  mediaBranco[1] = mediaBranco[1] / 10;
  mediaBranco[2] = mediaBranco[2] / 10;
  mediaBranco[3] = mediaBranco[3] / 10;

  toy.ledAlerta(2, 10, 50);
}

void Calibragem::guardarDadosEEPROM(){
  
  
  val.refletanciaMaisEsq = cinzaMaisEsq;
  val.refletanciaEsq = cinzaEsq;
  val.refletanciaDir = cinzaDir;
  val.refletanciaMaisDir = cinzaMaisDir;

  robo.salvarCalibracao(val);
  Serial.println("\nDados Guardados na EEPROM");
}

void Calibragem::getDadosCalibragem(){
  robo.lerCalibracao(val);
  
  cinzaMaisEsq = val.refletanciaMaisEsq;
  cinzaEsq = val.refletanciaEsq;
  cinzaDir = val.refletanciaDir;
  cinzaMaisDir = val.refletanciaMaisDir;
  
  Serial.println(cinzaMaisEsq);
  Serial.println(cinzaEsq);
  Serial.println(cinzaDir);
  Serial.println(cinzaMaisDir);
  
  Serial.println("\nDados Capturados da EEPROM");
}



