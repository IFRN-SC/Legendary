#include "MenuIniciar.h"

#define DELAY_TEMPO_DE_TROCA_DOS_MOTORES 2000

MenuIniciar::MenuIniciar(){
  //  
}

void MenuIniciar::menuBotoes(){
  Serial.println(F("\n--------------------"));
  Serial.println(F("Menu Botões Iniciado"));
  Serial.println(F("--------------------\n"));
  Serial.println(F("Você deve escolher o que deseja fazer com os botões"));
  Serial.println(F("  Botão 1: Iniciar Competição"));
  Serial.println(F("  Botão 2: Iniciar Calibrador"));
  Serial.println(F("  Botão 3: Iniciar Menu Serial"));
  Serial.println(F("Caso escolha Iniciar Competição, os dados da calibração serão pegados da EEPROM (Última Calibração Feita)"));

  toy.desligarLeds();
  toy.ledsEscada(1, 75);
  
  boolean opcaoSelecionada = false;
  
  while(opcaoSelecionada == false){
    if(robo.botao1Pressionado()){
      toy.ligarApenasLed(1);
      Serial.println(F("  Botão 1 Selecionado: Iniciar Competição!"));
      opcaoSelecionada = true;
      delay(1000);

      Serial.println(F("\n----------------------------"));
      Serial.println(F("Estrategia Executar Iniciado!"));
      Serial.println(F("----------------------------\n"));
      //Vai direto para o Loop
    }
  
    if(robo.botao2Pressionado()){
      Serial.println(F("  Botão 2 Selecionado: Iniciar Calibragem!"));
      opcaoSelecionada = true;
      toy.ligarApenasLed(2);
      delay(1000);
      toy.ledsEscada(3, 100);
      calibragem.iniciarCalibragem();
      break;
    }
    
    if(robo.botao3Pressionado()){
      Serial.println(F("  Botão 3 Selecionado: Iniciar Menu Serial"));
      opcaoSelecionada = true;
      toy.ligarApenasLed(3);
      delay(1000);
      menuSerial(); 
    }
  }
}

void MenuIniciar::menuSerial(){
  toy.ledsAlerta(3);
  Serial.println(F("\n--------------------"));
  Serial.println(F("Menu Serial Iniciado"));
  Serial.println(F("--------------------"));

  boolean sairMenuSerial = false; //Usado para sair do Menu
  boolean naoImprimir = false; //Usado para Erros
  
  while(sairMenuSerial == false){
    if(naoImprimir == false){
      Serial.println(F("\nO que deseja Fazer com o seu Robô? (Digite o número equivalente a opção)"));
      Serial.println(F("  1- Ver sensores de Refletancia"));
      Serial.println(F("  2- Ver sensores de Distancia"));
      Serial.println(F("  3- Ver sensores de Cor RGB"));
      Serial.println(F("  4- Ver sensores de Cor HSV"));
      Serial.println(F("  5- Testar Julgamento do Verde"));
      Serial.println(F("  6- Ver valores das Calibragens"));
      Serial.println(F("  10- Limpar Roda"));
      Serial.println(F("Digite -1 para sair do Menu Serial")); 
    }

    while(!Serial.available()){}
    int i = Serial.parseInt();

    if(i != 0){
      Serial.print(F("Você digitou: "));
      Serial.println(i);
    }else{
      Serial.println(F("..."));
    }
    
    switch(i){
      case -1:
        sairMenuSerial = true;
        break;
      
      case 0:
        naoImprimir = true;
        break;
        
      case 1: //Ver Sensores de Refretância
        avisoLoop();

        while(Serial.parseInt() != -1){
          refletancia.printSensoresDeRefletancia();
          delay(250);
        } 
        
        naoImprimir = false;
        break;
        
      case 2: //Ver sensores de Distancia
        avisoLoop();

        while(Serial.parseInt() != -1){
          sonar.printSensoresDeDistancia();
          delay(500);
        } 
        naoImprimir = false;
        break;
      
      case 3: //Ver sensores de Cor na forma RGB
        avisoLoop();

        while(Serial.parseInt() != -1){
          cor.printSensoresDeCorRGB();
          delay(500);
        }
      
        naoImprimir = false;
        break;
        
      case 4: //Ver sensores de Cor na forma HSV
        avisoLoop();
        
        while(Serial.parseInt() != -1){
          cor.printSensoresDeCorHSV();
          delay(100);
        }
      
        naoImprimir = false;
        break;
        
      case 5: //Testar Julgamento do Verde nos sensores de cor
        avisoLoop();
        
        while(Serial.parseInt() != -1){
          cor.testarVerde();
        }
      
        naoImprimir = false;
        break;
        
      case 6: //Ver dados Calibração
        Serial.println(F(""));
        calibragem.printDadosEEPROM();
        Serial.println(F("\n(Digite -1 para voltar ao menu)"));
        while(Serial.parseInt() != -1){}
        
        naoImprimir = false;
        break;
      
      case 10:
        Serial.println(F("\nEntrando em Loop para girar o motor Esquerdo... Lembre-se de ligar o Switch"));
        Serial.println(F("(Digite 1 para limpar o motor Direito)\n"));
        delay(DELAY_TEMPO_DE_TROCA_DOS_MOTORES);
        
        while(Serial.parseInt() != 1){
          robo.acionarMotores(50,0);
        }  
        robo.acionarMotores(0,0);      
        Serial.println(F("\nEntrando em Loop para girar o motor Direito..."));
        Serial.println(F("(Digite -1 para terminar o Limpeza)\n"));
        delay(DELAY_TEMPO_DE_TROCA_DOS_MOTORES);
        
        while(Serial.parseInt() != -1){
          robo.acionarMotores(0,50);
        }
        robo.acionarMotores(0,0);
        
        naoImprimir = false;
        break;

      default:
        Serial.println(F("\nOpção Invalida, tente novamente!"));
        naoImprimir = false;
    }
  }
  menuBotoes();
}

void MenuIniciar::avisoLoop(){
  toy.desligarLeds();
  Serial.println(F("\nComeçando Loop..."));
  Serial.println(F("(Digite -1 para sair da Repetição)\n"));
}