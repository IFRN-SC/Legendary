#include "Sensores.h"

Sensores::Sensores(){
  robo.lerCalibracao(val);
  
  cinzaMaisEsq = val.refletanciaMaisEsq;
  cinzaEsq = val.refletanciaEsq;
  cinzaDir = val.refletanciaDir;
  cinzaMaisDir = val.refletanciaMaisDir;
}

//Branco Branco Branco Branco (Andar para Frente)
boolean Sensores::bbbb(){
  boolean resposta;
  if((robo.lerSensorLinhaMaisEsq() >= cinzaMaisEsq) && (robo.lerSensorLinhaEsq() >= cinzaEsq) && (robo.lerSensorLinhaDir() >= cinzaDir) && (robo.lerSensorLinhaMaisDir() >= cinzaMaisDir)){
    resposta = true;
  }
  return resposta;
}

//Branco Preto Branco Branco (Direita)
boolean Sensores::bpbb(){
  boolean resposta;
  if((robo.lerSensorLinhaMaisEsq() > cinzaMaisEsq) && (robo.lerSensorLinhaEsq() < cinzaEsq) && (robo.lerSensorLinhaDir() > cinzaDir) && (robo.lerSensorLinhaMaisDir() > cinzaMaisDir)){
    resposta = true;
  }
  return resposta;
}

//Branco Branco Preto Branco (Esquerda)
boolean Sensores::bbpb(){
  boolean resposta;
  if((robo.lerSensorLinhaMaisEsq() > cinzaMaisEsq) && (robo.lerSensorLinhaEsq() > cinzaEsq) && (robo.lerSensorLinhaDir() < cinzaDir) && (robo.lerSensorLinhaMaisDir() > cinzaMaisDir)){
    resposta = true;
  }
  return resposta;
}

//Branco Preto Preto Branco (Continuar ação anterior)
boolean Sensores::bppb(){
  boolean resposta;
  if((robo.lerSensorLinhaMaisEsq() > cinzaMaisEsq) && (robo.lerSensorLinhaEsq() < cinzaEsq) && (robo.lerSensorLinhaDir() < cinzaDir) && (robo.lerSensorLinhaMaisDir() > cinzaMaisDir)){
    resposta = true;
  }
  return resposta;
}

//Preto Branco Branco Branco
boolean Sensores::pbbb(){
  boolean resposta;
  if((robo.lerSensorLinhaMaisEsq() < cinzaMaisEsq) && (robo.lerSensorLinhaEsq() > cinzaEsq) && (robo.lerSensorLinhaDir() > cinzaDir) && (robo.lerSensorLinhaMaisDir() > cinzaMaisDir)){
    resposta = true;
  }
  return resposta;
}

//Branco Branco Branco Preto
boolean Sensores::bbbp(){
  boolean resposta;
  if((robo.lerSensorLinhaMaisEsq() > cinzaMaisEsq) && (robo.lerSensorLinhaEsq() > cinzaEsq) && (robo.lerSensorLinhaDir() > cinzaDir) && (robo.lerSensorLinhaMaisDir() < cinzaMaisDir)){
    resposta = true;
  }
  return resposta;  
}

//Branco Branco Preto Preto
boolean Sensores::bbpp(){
  boolean resposta;
  if((robo.lerSensorLinhaMaisEsq() > cinzaMaisEsq) && (robo.lerSensorLinhaEsq() > cinzaEsq) && (robo.lerSensorLinhaDir() < cinzaDir) && (robo.lerSensorLinhaMaisDir() < cinzaMaisDir)){
    resposta = true;
  }
  return resposta;   
}

//Preto Preto Branco Branco
boolean Sensores::ppbb(){
  boolean resposta;
  if((robo.lerSensorLinhaMaisEsq() < cinzaMaisEsq) && (robo.lerSensorLinhaEsq() < cinzaEsq) && (robo.lerSensorLinhaDir() > cinzaDir) && (robo.lerSensorLinhaMaisDir() > cinzaMaisDir)){
    resposta = true;
  }
  return resposta; 
}

//Branco Preto Preto Preto
boolean Sensores::bppp(){
  boolean resposta;
  if((robo.lerSensorLinhaMaisEsq() > cinzaMaisEsq) && (robo.lerSensorLinhaEsq() < cinzaEsq) && (robo.lerSensorLinhaDir() < cinzaDir) && (robo.lerSensorLinhaMaisDir() < cinzaMaisDir)){
    resposta = true;
  }
  return resposta; 
}

//Preto Preto Preto Branco
boolean Sensores::pppb(){
  boolean resposta;
  if((robo.lerSensorLinhaMaisEsq() < cinzaMaisEsq) && (robo.lerSensorLinhaEsq() < cinzaEsq) && (robo.lerSensorLinhaDir() < cinzaDir) && (robo.lerSensorLinhaMaisDir() > cinzaMaisDir)){
    resposta = true;
  }
  return resposta; 
}

//Preto Preto Preto Preto
boolean Sensores::pppp(){
  boolean resposta;
  if((robo.lerSensorLinhaMaisEsq() < cinzaMaisEsq) && (robo.lerSensorLinhaEsq()< cinzaEsq) && (robo.lerSensorLinhaDir() < cinzaDir) && (robo.lerSensorLinhaMaisDir() < cinzaMaisDir)){
    resposta = true;
  }
  return resposta;
}

