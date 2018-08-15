#include "MenuIniciar.h"

MenuIniciar::MenuIniciar(){
  //  
}

void MenuIniciar::menuBotoes(){
  robo.lerCalibracao(val);
  
  Serial.println("Dados na EEPROM: ");
  Serial.println("  +esq    esq     dir     +dir");
  Serial.print  ("  ");
  Serial.print  (val.refletanciaMaisEsq);
  Serial.print  ("      ");
  Serial.print  (val.refletanciaEsq);
  Serial.print  ("      ");
  Serial.print  (val.refletanciaDir);
  Serial.print  ("      ");
  Serial.println(val.refletanciaMaisDir);
     
  Serial.println("\n--------------------");
  Serial.println("Menu Botões Iniciado");
  Serial.println("--------------------\n");
  Serial.println("Você deve escolher o que deseja fazer com os botões");
  Serial.println("  Botão 1: Iniciar Competição");
  Serial.println("  Botão 2: Iniciar Calibrador");
  Serial.println("  Botão 3: Iniciar Menu Serial");
  Serial.println("Caso escolha Iniciar Competição, os dados da calibração serão pegados da EEPROM (Última Calibração Feita)");

  toy.allLedsOff();
  toy.ledsEscada(1, 250);
  
  boolean opcaoSelecionada = false;
  
  while(opcaoSelecionada == false){
    if(robo.botao1Pressionado()){
      Serial.println("  Botão 1 Selecionado: Iniciar Competição");
      opcaoSelecionada = true;
      toy.allLedsOff();
      toy.led1On();
      delay(1000);

      Serial.println("\n----------------------------");
      Serial.println("Estrategia Executar Iniciado");
      Serial.println("----------------------------\n");
      //Vai direto para o Loop
    }
  
    if(robo.botao2Pressionado()){
      Serial.println("  Botão 2 Selecionado: Iniciar Calibragem");
      opcaoSelecionada = true;
      toy.allLedsOff();
      toy.led2On();
      delay(1000);
      toy.ledsEscada(3, 100);
      calibragem.iniciarCalibragem();
      break;
    }
    
    if(robo.botao3Pressionado()){
      Serial.println("  Botão 3 Selecionado: Iniciar Menu Serial");
      opcaoSelecionada = true;
      toy.allLedsOff();
      toy.led3On();
      delay(1000);
      menuSerial();
    }
  }
}

void MenuIniciar::menuSerial(){
  toy.ledsAlerta(3);
  Serial.println("\n--------------------");
  Serial.println("Menu Serial Iniciado");
  Serial.println("--------------------\n");

  Serial.println("O que deseja Fazer com o seu Robô? (Digite o número equivalente a opção)");
  Serial.println("  01- Ver sensores de Refletancia");
  Serial.println("  02- Ver sensores de Distancia");
  Serial.println("  03- Ver valores da Calibragem");
  Serial.println("  04- Modificar valocidade dos motores");
}




