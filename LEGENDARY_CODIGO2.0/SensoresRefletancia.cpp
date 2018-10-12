#include "SensoresRefletancia.h"
#include <Wire.h>

#define DISTANCIA_SONAR_FRONTAL_OBSTACULO 8.3


SensoresRefletancia::SensoresRefletancia(){
  pegarDadosEEPROM();
}

void SensoresRefletancia::start(){
  //
}

//Branco Branco Branco Branco (Andar para Frente)
boolean SensoresRefletancia::bbbb(){  
  boolean resposta;
  if((robo.lerSensorLinhaMaisEsq() >= cinzaMaisEsq) && (robo.lerSensorLinhaEsq() >= cinzaEsq) && (robo.lerSensorLinhaDir() >= cinzaDir) && (robo.lerSensorLinhaMaisDir() >= cinzaMaisDir)){
    resposta = true;
  }else{
    resposta = false;
  }
  return resposta;
}

//Branco Preto Branco Branco (Direita)
boolean SensoresRefletancia::bpbb(){
  boolean resposta;
  if((robo.lerSensorLinhaMaisEsq() > cinzaMaisEsq) && (robo.lerSensorLinhaEsq() < cinzaEsq) && (robo.lerSensorLinhaDir() > cinzaDir) && (robo.lerSensorLinhaMaisDir() > cinzaMaisDir)){
    resposta = true;
  }else{
    resposta = false;
  }
  return resposta;
}

//Branco Branco Preto Branco (Esquerda)
boolean SensoresRefletancia::bbpb(){
  boolean resposta;
  if((robo.lerSensorLinhaMaisEsq() > cinzaMaisEsq) && (robo.lerSensorLinhaEsq() > cinzaEsq) && (robo.lerSensorLinhaDir() < cinzaDir) && (robo.lerSensorLinhaMaisDir() > cinzaMaisDir)){
    resposta = true;
  }else{
    resposta = false;
  }
  return resposta;
}

//Branco Preto Preto Branco (Continuar ação anterior)
boolean SensoresRefletancia::bppb(){
  boolean resposta;
  if((robo.lerSensorLinhaMaisEsq() > cinzaMaisEsq) && (robo.lerSensorLinhaEsq() < cinzaEsq) && (robo.lerSensorLinhaDir() < cinzaDir) && (robo.lerSensorLinhaMaisDir() > cinzaMaisDir)){
    resposta = true;
  }else{
    resposta = false;
  }
  return resposta;
}

//Preto Branco Branco Branco
boolean SensoresRefletancia::pbbb(){
  boolean resposta;
  if((robo.lerSensorLinhaMaisEsq() < cinzaMaisEsq) && (robo.lerSensorLinhaEsq() > cinzaEsq) && (robo.lerSensorLinhaDir() > cinzaDir) && (robo.lerSensorLinhaMaisDir() > cinzaMaisDir)){
    resposta = true;
  }else{
    resposta = false;
  }
  return resposta;
}

//Branco Branco Branco Preto
boolean SensoresRefletancia::bbbp(){
  boolean resposta;
  if((robo.lerSensorLinhaMaisEsq() > cinzaMaisEsq) && (robo.lerSensorLinhaEsq() > cinzaEsq) && (robo.lerSensorLinhaDir() > cinzaDir) && (robo.lerSensorLinhaMaisDir() < cinzaMaisDir)){
    resposta = true;
  }else{
    resposta = false;
  }
  return resposta;  
}

//Branco Branco Preto Preto
boolean SensoresRefletancia::bbpp(){
  boolean resposta;
  if((robo.lerSensorLinhaMaisEsq() > cinzaMaisEsq) && (robo.lerSensorLinhaEsq() > cinzaEsq) && (robo.lerSensorLinhaDir() < cinzaDir) && (robo.lerSensorLinhaMaisDir() < cinzaMaisDir)){
    resposta = true;
  }else{
    resposta = false;
  }
  return resposta;   
}

//Preto Preto Branco Branco
boolean SensoresRefletancia::ppbb(){
  boolean resposta;
  if((robo.lerSensorLinhaMaisEsq() < cinzaMaisEsq) && (robo.lerSensorLinhaEsq() < cinzaEsq) && (robo.lerSensorLinhaDir() > cinzaDir) && (robo.lerSensorLinhaMaisDir() > cinzaMaisDir)){
    resposta = true;
  }else{
    resposta = false;
  }
  return resposta; 
}

//Branco Preto Preto Preto
boolean SensoresRefletancia::bppp(){
  boolean resposta;
  if((robo.lerSensorLinhaMaisEsq() > cinzaMaisEsq) && (robo.lerSensorLinhaEsq() < cinzaEsq) && (robo.lerSensorLinhaDir() < cinzaDir) && (robo.lerSensorLinhaMaisDir() < cinzaMaisDir)){
    resposta = true;
  }else{
    resposta = false;
  }
  return resposta; 
}

//Preto Preto Preto Branco
boolean SensoresRefletancia::pppb(){
  boolean resposta;
  if((robo.lerSensorLinhaMaisEsq() < cinzaMaisEsq) && (robo.lerSensorLinhaEsq() < cinzaEsq) && (robo.lerSensorLinhaDir() < cinzaDir) && (robo.lerSensorLinhaMaisDir() > cinzaMaisDir)){
    resposta = true;
  }else{
    resposta = false;
  }
  return resposta; 
}

//Preto Preto Preto Preto
boolean SensoresRefletancia::pppp(){
  boolean resposta;
  if((robo.lerSensorLinhaMaisEsq() < cinzaMaisEsq) && (robo.lerSensorLinhaEsq()< cinzaEsq) && (robo.lerSensorLinhaDir() < cinzaDir) && (robo.lerSensorLinhaMaisDir() < cinzaMaisDir)){
    resposta = true;
  }else{
    resposta = false;
  }
  return resposta;
}

//Verificador do Sensor Mais Esquerdo, 'P' para Preto e 'B' para Branco 
boolean SensoresRefletancia::sensorMaisEsq(char entrada){
  boolean resposta;
  switch(entrada){
    case 'P':
      if(robo.lerSensorLinhaMaisEsq() < cinzaMaisEsq){
        resposta = true;
      }else{
        resposta = false;
      }
      break;   
    case 'B':
      if(robo.lerSensorLinhaMaisEsq() > cinzaMaisEsq){
        resposta = true;
      }else{
        resposta = false;
      }
      break;  
  }
  return resposta;
}

//Verificador do Sensor Esquerdo, 'P' para Preto e 'B' para Branco 
boolean SensoresRefletancia::sensorEsq(char entrada){
  boolean resposta;
  switch(entrada){
    case 'P':
      if(robo.lerSensorLinhaEsq() < cinzaEsq){
        resposta = true;
      }else{
        resposta = false;
      }
      break;   
    case 'B':
      if(robo.lerSensorLinhaEsq() > cinzaEsq){
        resposta = true;
      }else{
        resposta = false;
      }
      break;  
  }
  return resposta;
}

//Verificador do Sensor Direito, 'P' para Preto e 'B' para Branco 
boolean SensoresRefletancia::sensorDir(char entrada){
  boolean resposta;
  switch(entrada){
    case 'P':
      if(robo.lerSensorLinhaDir() < cinzaDir){
        resposta = true;
      }else{
        resposta = false;
      }
      break;   
    case 'B':
      if(robo.lerSensorLinhaDir() > cinzaDir){
        resposta = true;
      }else{
        resposta = false;
      }
      break;  
  }
  return resposta;
}

//Verificador do Sensor Mais Direito, 'P' para Preto e 'B' para Branco 
boolean SensoresRefletancia::sensorMaisDir(char entrada){
  boolean resposta;
  switch(entrada){
    case 'P':
      if(robo.lerSensorLinhaMaisDir() < cinzaMaisDir){
        resposta = true;
      }else{
        resposta = false;
      }
      break;   
    case 'B':
      if(robo.lerSensorLinhaMaisDir() > cinzaMaisDir){
        resposta = true;
      }else{
        resposta = false;
      }
      break;  
  }
  return resposta;
}

void SensoresRefletancia::printSensoresDeRefletancia(){
  valorSensorMaisEsq = robo.lerSensorLinhaMaisEsq();
  valorSensorEsq = robo.lerSensorLinhaEsq();
  valorSensorDir = robo.lerSensorLinhaDir();
  valorSensorMaisDir = robo.lerSensorLinhaMaisDir();
            
  Serial.print(F("Sensores refletancia: +esq; esq; dir; +dir "));
  Serial.print(valorSensorMaisEsq);
  Serial.print(F("; "));
  Serial.print(valorSensorEsq);
  Serial.print(F("; "));
  Serial.print(valorSensorDir);
  Serial.print(F("; "));
  Serial.println(valorSensorMaisDir);
}

void SensoresRefletancia::pegarDadosEEPROM(){
  robo.lerCalibracao(val);
  
  cinzaMaisEsq = val.refletanciaMaisEsq;
  cinzaEsq = val.refletanciaEsq;
  cinzaDir = val.refletanciaDir;
  cinzaMaisDir = val.refletanciaMaisDir;
}

//Utilização do Sonar Frontal para Obstaculo
  boolean SensoresRefletancia::sonarObstaculo(){
  boolean resposta;
  if(robo.lerSensorSonarFrontal() <= DISTANCIA_SONAR_FRONTAL_OBSTACULO){
    resposta = true;
  } else {
    resposta = false;
  }
  return resposta;
}



