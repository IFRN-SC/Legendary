#include "MenuIniciar.h"

MenuIniciar::MenuIniciar(){
  //  
}

void MenuIniciar::menuBotoes(){
  Serial.println("\n--------------------");
  Serial.println("Menu Botões Iniciado");
  Serial.println("--------------------\n");
  Serial.println("Você deve escolher o que deseja fazer com os botões");
  Serial.println("  Botão 1: Iniciar Competição");
  Serial.println("  Botão 2: Iniciar Calibrador");
  Serial.println("  Botão 3: Iniciar Menu Serial");
  Serial.println("Caso escolha Iniciar Competição, os dados da calibração serão pegados da EEPROM (Última Calibração Feita)");

  toy.allLedsOff();
  toy.ledsEscada(1, 75);
  
  boolean opcaoSelecionada = false;
  
  while(opcaoSelecionada == false){
    if(robo.botao1Pressionado()){
      Serial.println("  Botão 1 Selecionado: Iniciar Competição!");
      opcaoSelecionada = true;
      toy.allLedsOff();
      toy.led1On();
      delay(1000);

      Serial.println("\n----------------------------");
      Serial.println("Estrategia Executar Iniciado!");
      Serial.println("----------------------------\n");
      //Vai direto para o Loop
    }
  
    if(robo.botao2Pressionado()){
      Serial.println("  Botão 2 Selecionado: Iniciar Calibragem!");
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
  Serial.println("--------------------");

  boolean sairMenuSerial = false;
  boolean naoImprimir = false;
  
  while(sairMenuSerial == false){
    if(naoImprimir == false){
      Serial.println("\nO que deseja Fazer com o seu Robô? (Digite o número equivalente a opção)");
      Serial.println("  1- Ver sensores de Refletancia");
      Serial.println("  2- Ver sensores de Distancia");
      Serial.println("  3- Ver sensores de Cor");
      Serial.println("  4- Ver valores da Calibragem");
      Serial.println("  5- Modificar valocidade dos motores"); 
      Serial.println("Digite -1 para sair do Menu Serial"); 
    }

    while(!Serial.available()){}
    int i = Serial.parseInt();
    
    if(i != 0){
      Serial.print  ("Você digitou: ");
      Serial.println(i);
    }else{
      Serial.println("...");
    }
    
    switch(i){
      case -1:
        sairMenuSerial = true;
        break;
      case 0:
        naoImprimir = true;
        break;
        
      case 1:
        Serial.println("\nEntrando em Loop para ver os Sensores de Refletancia...");
        Serial.println("(Digite -1 para sair da Repetição)\n");
        while(Serial.parseInt() != -1){
          valorSensorMaisEsq = robo.lerSensorLinhaMaisEsq();
          valorSensorEsq = robo.lerSensorLinhaEsq();
          valorSensorDir = robo.lerSensorLinhaDir();
          valorSensorMaisDir = robo.lerSensorLinhaMaisDir();
            
          Serial.print("Sensores refletancia: +esq; esq; dir; +dir ");
          Serial.print(valorSensorMaisEsq);
          Serial.print("; ");
          Serial.print(valorSensorEsq);
          Serial.print("; ");
          Serial.print(valorSensorDir);
          Serial.print("; ");
          Serial.println(valorSensorMaisDir);
          delay(250);
        } 
        naoImprimir = false;
        break;
        
      case 2:
        Serial.println("\nEntrando em Loop para ver os Sensores de Distancia...");
        Serial.println("(Digite -1 para sair da Repetição)\n");
        while(Serial.parseInt() != -1){
          valorSensorLateralEsq = robo.lerSensorSonarDir();
          valorSensorLateralEsq = robo.lerSensorSonarEsq();
          valorSensorFrontal = robo.lerSensorSonarFrontal();

          Serial.print("Valor do sensor frontal: ");
          Serial.print(valorSensorFrontal);
          Serial.print("  esquerdo: ");
          Serial.print(valorSensorLateralEsq);
          Serial.print("  direito: ");
          Serial.println(valorSensorLateralDir);
          delay(500);
        } 
        naoImprimir = false;
        break;
      case 3:
        Serial.println("\nEntrando em Loop para ver os Sensores de Cor...");
        Serial.println("(Digite -1 para sair da Repetição)\n");
        robo.habilitaTCS34();
        
        while(Serial.parseInt() != -1){
          valorSensorCorEsq = robo.getRGBEsquerdo();
          valorSensorCorDir = robo.getRGBDireito(); 

          Serial.print("Valor do sensor de Cor Esquerdo: ");
          Serial.print(valorSensorCorEsq.vermelho);
          Serial.print(", ");
          Serial.print(valorSensorCorEsq.verde);
          Serial.print(", ");
          Serial.println(valorSensorCorEsq.azul);
          Serial.print("Valor do sensor de Cor Direito:  ");
          Serial.print(valorSensorCorDir.vermelho);
          Serial.print(", ");
          Serial.print(valorSensorCorDir.verde);
          Serial.print(", ");
          Serial.print(valorSensorCorDir.azul);
          Serial.println();
          delay(500);
        }
      
        naoImprimir = false;
        break;
      case 4:
        Serial.println("\nFunção ainda não construida");
        Serial.println("(Digite -1 para continuar)");
        while(Serial.parseInt() != -1){}
        naoImprimir = false;
        break;
      default:
        Serial.println("\nOpção Invalida, tente novamente!");
        naoImprimir = false;
    }
  }
  menuBotoes();
}

void MenuIniciar::dadosEEPROM(){
  robo.lerCalibracao(val);
  
  Serial.println("Dados da Última Calibração (EEPROM): ");
  Serial.println("  +esq    esq     dir     +dir");
  Serial.print  ("  ");
  Serial.print  (val.refletanciaMaisEsq);
  Serial.print  ("      ");
  Serial.print  (val.refletanciaEsq);
  Serial.print  ("      ");
  Serial.print  (val.refletanciaDir);
  Serial.print  ("      ");
  Serial.println(val.refletanciaMaisDir);
}

