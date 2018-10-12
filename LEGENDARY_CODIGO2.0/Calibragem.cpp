#include "Calibragem.h"
#define DELAY_INTERVALO_DE_CAPTURA 200

Calibragem::Calibragem (){
  //
}

void Calibragem::iniciarCalibragem(){
  Serial.println(F("\n-------------------"));
  Serial.println(F("Calibração Iniciada"));
  Serial.println(F("-------------------\n"));
  
  Serial.println(F("Parte 1: Coletar valores do Preto para os Sensores de Refletância"));
  Serial.println(F("Precione o Botão 1 para Começar!"));
  while(!robo.botao1Pressionado()){} //Espera Resposta do Botão 1
  toy.ligarApenasLed(1);
  calibracaoPretoRefletancia();
  
  Serial.println(F("\nParte 2: Coletar valores do Preto para os Sensores de Cor"));
  Serial.println(F("Pressione o Botão 1 para Continuar!"));
  while(!robo.botao1Pressionado()){} //Espera Resposta do Botão 1
  toy.desligaLigaLed(1);
  calibracaoPretoCor();
  
  Serial.println(F("\nParte 3: Coletar valores do Branco para os Sensores de Refletância e Cor"));
  Serial.println(F("Pressione o Botão 2 para Começar!"));
  while(!robo.botao2Pressionado()){} //Espera Resposta do Botão 2
  toy.ligarLed(2);
  calibracaoBrancoRefletanciaCor();

  Serial.println(F("\nParte 4: Coletar valores do Verde para o Sensor de Cor Esquerdo"));
  Serial.println(F("Pressione o Botão 3 para Começar!"));
  while(!robo.botao3Pressionado()){} //Espera Resposta do Botão 3
  toy.ligarLed(3);
  calibracaoVerdeEsq();

  Serial.println(F("\nParte 5: Coletar valores do Verde para o Sensor de Cor Direito"));
  Serial.println(F("Pressione o Botão 3 para Continuar!"));
  while(!robo.botao3Pressionado()){} //Espera Resposta do Botão 3
  toy.desligaLigaLed(3);
  calibracaoVerdeDir();

  Serial.println(F("\nRealizando Últimas Ações..."));
  delay(1000);
  calcularCinzaRefletancia();
  guardarDadosEEPROM();

  Serial.println(F("\nCALIBRAÇÃO FINALIZADA!!"));
  
  delay(200);
  toy.ledsAlerta(4);
  delay(200);
  voltarMenu = true;
}


void Calibragem::calibracaoPretoRefletancia(){
  int i;
  Serial.println(F("\n  | Coletando Dados |"));
  Serial.print  (F("  |-------"));
  for (i = 0; i < 10; i++) {
    mediaPretoRefletanciaMaisEsq = mediaPretoRefletanciaMaisEsq + robo.lerSensorLinhaMaisEsq();
    mediaPretoRefletanciaEsq = mediaPretoRefletanciaEsq + robo.lerSensorLinhaEsq();
    mediaPretoRefletanciaDir = mediaPretoRefletanciaDir + robo.lerSensorLinhaDir();
    mediaPretoRefletanciaMaisDir = mediaPretoRefletanciaMaisDir + robo.lerSensorLinhaMaisDir();
    delay(DELAY_INTERVALO_DE_CAPTURA);
    Serial.print(F("-"));
  }
  Serial.println(F("|"));
  Serial.println(F("  |    Concluido    |"));
  mediaPretoRefletanciaMaisEsq = mediaPretoRefletanciaMaisEsq / 10;
  mediaPretoRefletanciaEsq = mediaPretoRefletanciaEsq / 10;
  mediaPretoRefletanciaDir = mediaPretoRefletanciaDir / 10;
  mediaPretoRefletanciaMaisDir = mediaPretoRefletanciaMaisDir / 10;
  
  toy.ledAlerta(1, 10, 50);

  Serial.println(F("\n  Valores Pretos Capturados dos Sensores de Refletância: "));
  Serial.println(F("  +esq    esq     dir     +dir"));
  Serial.print  (F("  "));
  Serial.print  (mediaPretoRefletanciaMaisEsq);
  Serial.print  (F("   "));
  Serial.print  (mediaPretoRefletanciaEsq);
  Serial.print  (F("   "));
  Serial.print  (mediaPretoRefletanciaDir);
  Serial.print  (F("   "));
  Serial.println(mediaPretoRefletanciaMaisDir);
}


void Calibragem::calibracaoPretoCor(){
  robo.habilitaTCS34();
  int i;
  Serial.println(F("\n  | Coletando Dados |"));
  Serial.print  (F("  |-------"));
  
  capturadorDeCorAuxEsq = robo.getHSVEsquerdo();
  capturadorDeCorAuxDir = robo.getHSVDireito();
  mediaPretoCorEsq.h = capturadorDeCorAuxEsq.h;
  mediaPretoCorDir.h = capturadorDeCorAuxDir.h;
  mediaPretoCorEsq.s = capturadorDeCorAuxEsq.s;
  mediaPretoCorDir.s = capturadorDeCorAuxDir.s;
  mediaPretoCorEsq.v = capturadorDeCorAuxEsq.v;
  mediaPretoCorDir.v = capturadorDeCorAuxDir.v;
  for (i = 0; i < 10; i++) {
    capturadorDeCorAuxEsq = robo.getHSVEsquerdo();
    capturadorDeCorAuxDir = robo.getHSVDireito();
    mediaPretoCorEsq.h = (mediaPretoCorEsq.h + capturadorDeCorAuxEsq.h) / 2; 
    mediaPretoCorDir.h = (mediaPretoCorDir.h + capturadorDeCorAuxDir.h) / 2;  
    mediaPretoCorEsq.s = (mediaPretoCorEsq.s + capturadorDeCorAuxEsq.s) / 2;
    mediaPretoCorDir.s = (mediaPretoCorDir.s + capturadorDeCorAuxDir.s) / 2;   
    mediaPretoCorEsq.v = (mediaPretoCorEsq.v + capturadorDeCorAuxEsq.v) / 2; 
    mediaPretoCorDir.v = (mediaPretoCorDir.v + capturadorDeCorAuxDir.v) / 2;   
    delay(DELAY_INTERVALO_DE_CAPTURA);
    Serial.print(F("-"));
  } 
  Serial.println(F("|"));
  Serial.println(F("  |    Concluido    |"));

  toy.ledAlerta(1, 10, 50);

  Serial.println(F("\n  Valores Pretos Capturados dos Sensores de Cor: "));
  Serial.println(F("  esq            dir   "));
  Serial.print  (F("  H: "));
  Serial.print  (mediaPretoCorEsq.h);
  Serial.print  (F("      H: "));
  Serial.println(mediaPretoCorDir.h);
  Serial.print  (F("  S: "));
  Serial.print  (mediaPretoCorEsq.s);
  Serial.print  (F("        S: "));
  Serial.println(mediaPretoCorDir.s);
  Serial.print  (F("  V: "));
  Serial.print  (mediaPretoCorEsq.v);
  Serial.print  (F("      V: "));
  Serial.println(mediaPretoCorDir.v);
}


void Calibragem::calibracaoBrancoRefletanciaCor(){  
  int i;
  Serial.println(F("\n  | Coletando Dados |"));
  Serial.print  (F("  |-------"));
  
  capturadorDeCorAuxEsq = robo.getHSVEsquerdo();
  capturadorDeCorAuxDir = robo.getHSVDireito();
  mediaBrancoCorEsq.h = capturadorDeCorAuxEsq.h; 
  mediaBrancoCorDir.h = capturadorDeCorAuxDir.h;
  mediaBrancoCorEsq.s = capturadorDeCorAuxEsq.s; 
  mediaBrancoCorDir.s = capturadorDeCorAuxDir.s;
  mediaBrancoCorEsq.v = capturadorDeCorAuxEsq.v; 
  mediaBrancoCorDir.v = capturadorDeCorAuxDir.v;
  
  for (i = 0; i < 10; i++) {
    mediaBrancoRefletanciaMaisEsq = mediaBrancoRefletanciaMaisEsq + robo.lerSensorLinhaMaisEsq();
    mediaBrancoRefletanciaEsq = mediaBrancoRefletanciaEsq + robo.lerSensorLinhaEsq();
    mediaBrancoRefletanciaDir = mediaBrancoRefletanciaDir + robo.lerSensorLinhaDir();
    mediaBrancoRefletanciaMaisDir = mediaBrancoRefletanciaMaisDir + robo.lerSensorLinhaMaisDir();
    
    capturadorDeCorAuxEsq = robo.getHSVEsquerdo();
    capturadorDeCorAuxDir = robo.getHSVDireito();
    mediaBrancoCorEsq.h = (mediaBrancoCorEsq.h + capturadorDeCorAuxEsq.h) / 2; 
    mediaBrancoCorDir.h = (mediaBrancoCorDir.h + capturadorDeCorAuxDir.h) / 2;
    mediaBrancoCorEsq.s = (mediaBrancoCorEsq.s + capturadorDeCorAuxEsq.s) / 2; 
    mediaBrancoCorDir.s = (mediaBrancoCorDir.s + capturadorDeCorAuxDir.s) / 2;
    mediaBrancoCorEsq.v = (mediaBrancoCorEsq.v + capturadorDeCorAuxEsq.v) / 2; 
    mediaBrancoCorDir.v = (mediaBrancoCorDir.v + capturadorDeCorAuxDir.v) / 2;
    
    delay(DELAY_INTERVALO_DE_CAPTURA);
    Serial.print(F("-"));
  }
  Serial.println(F("|"));
  Serial.println(F("  |    Concluido    |"));
  
  mediaBrancoRefletanciaMaisEsq = mediaBrancoRefletanciaMaisEsq / 10;
  mediaBrancoRefletanciaEsq = mediaBrancoRefletanciaEsq / 10;
  mediaBrancoRefletanciaDir = mediaBrancoRefletanciaDir / 10;
  mediaBrancoRefletanciaMaisDir = mediaBrancoRefletanciaMaisDir / 10;

  toy.ledAlerta(2, 10, 50);

  Serial.println(F("\n  Valores Brancos Capturados dos Sensores de Refletância: "));
  Serial.println(F("  +esq    esq     dir     +dir"));
  Serial.print  (F("  "));
  Serial.print  (mediaBrancoRefletanciaMaisEsq);
  Serial.print  (F("   "));
  Serial.print  (mediaBrancoRefletanciaEsq);
  Serial.print  (F("   "));
  Serial.print  (mediaBrancoRefletanciaDir);
  Serial.print  (F("   "));
  Serial.println(mediaBrancoRefletanciaMaisDir);

  Serial.println(F("\n  Valores Brancos Capturados dos Sensores de Cor: "));
  Serial.println(F("  esq            dir   "));
  Serial.print  (F("  H: "));
  Serial.print  (mediaBrancoCorEsq.h);
  Serial.print  (F("      H: "));
  Serial.println(mediaBrancoCorDir.h);
  Serial.print  (F("  S: "));
  Serial.print  (mediaBrancoCorEsq.s);
  Serial.print  (F("        S: "));
  Serial.println(mediaBrancoCorDir.s);
  Serial.print  (F("  V: "));
  Serial.print  (mediaBrancoCorEsq.v);
  Serial.print  (F("      V: "));
  Serial.println(mediaBrancoCorDir.v);
}


void Calibragem::calibracaoVerdeEsq(){
  int i;
  Serial.println(F("\n  | Coletando Dados |"));
  Serial.print  (F("  |-------"));
  
  capturadorDeCorAuxEsq = robo.getHSVEsquerdo();
  mediaVerdeCorEsq.h = capturadorDeCorAuxEsq.h;
  mediaVerdeCorEsq.s = capturadorDeCorAuxEsq.s;
  mediaVerdeCorEsq.v = capturadorDeCorAuxEsq.v;
  
  for (i = 0; i < 10; i++) {
    capturadorDeCorAuxEsq = robo.getHSVEsquerdo();
    mediaVerdeCorEsq.h = (mediaVerdeCorEsq.h + capturadorDeCorAuxEsq.h) / 2; 
    mediaVerdeCorEsq.s = (mediaVerdeCorEsq.s + capturadorDeCorAuxEsq.s) / 2; 
    mediaVerdeCorEsq.v = (mediaVerdeCorEsq.v + capturadorDeCorAuxEsq.v) / 2;   
    delay(DELAY_INTERVALO_DE_CAPTURA);
    Serial.print(F("-"));
  } 
  Serial.println(F("|"));
  Serial.println(F("  |    Concluido    |"));

  toy.ledAlerta(3, 10, 50);

  Serial.println(F("\n  Valores do Verde Capturados do Sensor de Cor Esquerdo: "));
  Serial.print  (F("  H: "));
  Serial.println(mediaVerdeCorEsq.h);     
  Serial.print  (F("  S: "));
  Serial.println(mediaVerdeCorEsq.s);
  Serial.print  (F("  V: "));
  Serial.println(mediaVerdeCorEsq.v);  
}


void Calibragem::calibracaoVerdeDir(){
  int i;
  Serial.println(F("\n  | Coletando Dados |"));
  Serial.print  (F("  |-------"));
  
  capturadorDeCorAuxDir = robo.getHSVDireito();
  mediaVerdeCorDir.h = capturadorDeCorAuxDir.h;
  mediaVerdeCorDir.s = capturadorDeCorAuxDir.s;
  mediaVerdeCorDir.v = capturadorDeCorAuxDir.v;
  
  for (i = 0; i < 10; i++) {
    capturadorDeCorAuxDir = robo.getHSVDireito();
    mediaVerdeCorDir.h = (mediaVerdeCorDir.h + capturadorDeCorAuxDir.h) / 2;
    mediaVerdeCorDir.s = (mediaVerdeCorDir.s + capturadorDeCorAuxDir.s) / 2;      
    mediaVerdeCorDir.v = (mediaVerdeCorDir.v + capturadorDeCorAuxDir.v) / 2;   
    
    delay(DELAY_INTERVALO_DE_CAPTURA);
    Serial.print(F("-"));
  } 
  Serial.println(F("|"));
  Serial.println(F("  |    Concluido    |"));

  toy.ledAlerta(3, 10, 50);

  Serial.println(F("\n  Valores do Verde Capturados do Sensor de Cor Direito: "));
  Serial.print  (F("  H: "));
  Serial.println(mediaVerdeCorDir.h);     
  Serial.print  (F("  S: "));
  Serial.println(mediaVerdeCorDir.s);
  Serial.print  (F("  V: "));
  Serial.println(mediaVerdeCorDir.v);
}


void Calibragem::calcularCinzaRefletancia(){
  //Calculando Cinza
  
  cinzaMaisEsq = (mediaPretoRefletanciaMaisEsq + mediaBrancoRefletanciaMaisEsq)/2; 
  cinzaEsq = (mediaPretoRefletanciaEsq + mediaBrancoRefletanciaEsq)/2;
  cinzaDir = (mediaPretoRefletanciaDir + mediaBrancoRefletanciaDir)/2;
  cinzaMaisDir = (mediaPretoRefletanciaMaisDir + mediaBrancoRefletanciaMaisDir)/2; 

  Serial.println(F("\n  Valores Calculados dos sensores de refletância: "));
  Serial.println(F("   +esq    esq     dir     +dir"));
  Serial.print  (F("   "));
  Serial.print  (cinzaMaisEsq);
  Serial.print  (F("   "));
  Serial.print  (cinzaEsq);
  Serial.print  (F("   "));
  Serial.print  (cinzaDir);
  Serial.print  (F("   "));
  Serial.println(cinzaMaisDir);

  Serial.println(F("\n  Valores Calculados dos sensores de Cor: "));
  Serial.println(F("  esq            dir   "));
  Serial.print  (F("  H: "));
  Serial.print  (mediaPretoCorEsq.h);
  Serial.print  (F("      H: "));
  Serial.println(mediaPretoCorDir.h);
  Serial.print  (F("  S: "));
  Serial.print  (mediaPretoCorEsq.s);
  Serial.print  (F("        S: "));
  Serial.println(mediaPretoCorDir.s);
  Serial.print  (F("  V: "));
  Serial.print  (mediaPretoCorEsq.v);
  Serial.print  (F("      V: "));
  Serial.println(mediaPretoCorDir.v);
}


void Calibragem::guardarDadosEEPROM(){
  //Dados Refletância
  val.refletanciaMaisEsq = cinzaMaisEsq;
  val.refletanciaEsq = cinzaEsq;
  val.refletanciaDir = cinzaDir;
  val.refletanciaMaisDir = cinzaMaisDir;

  //Dados Cor
  val.pretoEsq.h = mediaPretoCorEsq.h;
  val.pretoEsq.s = mediaPretoCorEsq.s;
  val.pretoEsq.v = mediaPretoCorEsq.v;
  
  val.pretoDir.h = mediaPretoCorDir.h;
  val.pretoDir.s = mediaPretoCorDir.s;
  val.pretoDir.v = mediaPretoCorDir.v;
  
  val.brancoEsq.h = mediaBrancoCorEsq.h;
  val.brancoEsq.s = mediaBrancoCorEsq.s;
  val.brancoEsq.v = mediaBrancoCorEsq.v;
  
  val.brancoDir.h = mediaBrancoCorDir.h;
  val.brancoDir.s = mediaBrancoCorDir.s;
  val.brancoDir.v = mediaBrancoCorDir.v;
  
  val.verdeEsq.h = mediaVerdeCorEsq.h;
  val.verdeEsq.s = mediaVerdeCorEsq.s;
  val.verdeEsq.v = mediaVerdeCorEsq.v;
  
  val.verdeDir.h = mediaVerdeCorDir.h;
  val.verdeDir.s = mediaVerdeCorDir.s;
  val.verdeDir.v = mediaVerdeCorDir.v;
 

  robo.salvarCalibracao(val);
  Serial.println(F("\n  Dados Guardados na EEPROM"));
  robo.lerCalibracao(val);
}

void Calibragem::printDadosEEPROM(){
  robo.lerCalibracao(val);
  Serial.println(F("-----------------------------------"));
  Serial.println(F("Dados da Última Calibração (EEPROM)"));
  Serial.println(F("-----------------------------------"));
  Serial.println(F("  Sensores de Refletância:"));
  Serial.println(F("  +esq    esq     dir     +dir"));
  Serial.print  (F("  "));
  Serial.print  (val.refletanciaMaisEsq);
  Serial.print  (F("      "));
  Serial.print  (val.refletanciaEsq);
  Serial.print  (F("      "));
  Serial.print  (val.refletanciaDir);
  Serial.print  (F("      "));
  Serial.println(val.refletanciaMaisDir);

  Serial.println(F("\n  Sensores de Cor (Preto): "));
  Serial.println(F("  esq            dir   "));
  Serial.print  (F("  H: "));
  Serial.print  (val.pretoEsq.h);
  Serial.print  (F("      H: "));
  Serial.println(val.pretoDir.h);
  Serial.print  (F("  S: "));
  Serial.print  (val.pretoEsq.s);
  Serial.print  (F("        S: "));
  Serial.println(val.pretoDir.s);
  Serial.print  (F("  V: "));
  Serial.print  (val.pretoEsq.v);
  Serial.print  (F("      V: "));
  Serial.println(val.pretoDir.v);

  Serial.println(F("\n  Sensores de Cor (Verde): "));
  Serial.println(F("  esq            dir   "));
  Serial.print  (F("  H: "));
  Serial.print  (val.verdeEsq.h);
  Serial.print  (F("      H: "));
  Serial.println(val.verdeDir.h);
  Serial.print  (F("  S: "));
  Serial.print  (val.verdeEsq.s);
  Serial.print  (F("        S: "));
  Serial.println(val.verdeDir.s);
  Serial.print  (F("  V: "));
  Serial.print  (val.verdeEsq.v);
  Serial.print  (F("      V: "));
  Serial.println(val.verdeDir.v);

  Serial.println(F("\n  Sensores de Cor (Branco): "));
  Serial.println(F("  esq            dir   "));
  Serial.print  (F("  H: "));
  Serial.print  (val.brancoEsq.h);
  Serial.print  (F("      H: "));
  Serial.println(val.brancoDir.h);
  Serial.print  (F("  S: "));
  Serial.print  (val.brancoEsq.s);
  Serial.print  (F("        S: "));
  Serial.println(val.brancoDir.s);
  Serial.print  (F("  V: "));
  Serial.print  (val.brancoEsq.v);
  Serial.print  (F("      V: "));
  Serial.println(val.brancoDir.v);
}


void Calibragem::calibrarIMU(){
  /*
  toy.allLedsOn();
  Serial.println(F("\nIniciando Calibração do sensor IMU (Apenas utilização do eixo AcY)..."));
  Serial.println(F("Parte 1 Calibração IMU: Colocar robô na arena principal (Precione o Botão 1 para Capturar os dados)"));
  while(!robo.botao1Pressionado()){} //Espera Resposta do Botão 1
  toy.allLedsOff();
  toy.ligarLed(1);
        
  int i = 0;  
  for (i = 0; i < 10; i++) {
    Serial.print(F("  Capturando valor: "));
    Serial.println(sensores.valorAcY());
    mediaArena = mediaArena + sensores.valorAcY();
    delay(300);
  }

  toy.ledAlerta(1, 10, 50);

  mediaArena = mediaArena/10;
  Serial.println(F("  ------------------"));
  Serial.print  (F("  Média da Inclinação da Arena Principal: "));
  Serial.println(mediaArena);

  Serial.println(F("Parte 2 Calibração IMU: Colocar robô na rampa (Precione o Botão 2 para Capturar os dados)"));
  while(!robo.botao2Pressionado()){} //Espera Resposta do Botão 1
  toy.ligarLed(2);

  mediaRampa = sensorIMU.valorAcY();  
  for(i = 0; i < 9; i++) {
    Serial.print(F("  Capturando valor: "));
    Serial.println(sensores.valorAcY());
    mediaRampa = (mediaRampa + sensores.valorAcY())/2;
    delay(300);
  }

  toy.ledAlerta(1, 10, 50);
  Serial.println(F("  ------------------"));
  Serial.print  (F("  Média da Inclinação da Rampa: "));
  Serial.println(mediaRampa);
  delay(300);
  toy.ligarLed(1);
  corteInclinacao = ((mediaArena*1) + (mediaRampa*2.7))/3.7;

  Serial.print  (F("\nValor de corte da Inclinação calculado: "));
  Serial.println(corteInclinacao);
  Serial.println(F("CALIBRAÇÃO FINALIZADA: Calibração terminada (Precione o Botão 3 para voltar ao Menu Serial)"));
        
  while(!robo.botao3Pressionado()){} //Espera Resposta do Botão 3
  toy.ligarLed(3);
  */
}
