#include "SensoresCor.h"

SensoresCor::SensoresCor(){
  robo.habilitaTCS34();
  pegarDadosEEPROM();
  calcularDivisores();
}

void SensoresCor::testarVerde(){
  if(verificarVerdeEsq()){
    Serial.println("Esquerdo: É Verde");
  } else {
    Serial.println("Esquerdo: Não é Verde");
  }
  delay(100);
  if(verificarVerdeDir()){
    Serial.println("Direito: É Verde");
  } else {
    Serial.println("Direito: Não é Verde");
  }
  if(verificarVerdeEsq() && verificarVerdeDir()){
    robo.ligarLed(3);
  } else {
    robo.desligarLed(3);
  }
  Serial.println("----------------------");
  delay(100);
}

boolean SensoresCor::vv(){
  //
}

//Verde NãoVerde
boolean SensoresCor::vn(){
  boolean resposta = false;
  return resposta;
}

boolean SensoresCor::nv(){
  //
}

boolean SensoresCor::nn(){
  //
}

boolean SensoresCor::verificarVerdeEsq(){
  boolean resposta = false;
  valorSensorCorHSVEsq = robo.getHSVEsquerdo(); 

  if((valorSensorCorHSVEsq.h < divisorBrancoVerdeEsq.h)){
    if((valorSensorCorHSVEsq.v > divisorPretoVerdeEsq.v) && (valorSensorCorHSVEsq.v < divisorBrancoVerdeEsq.v)){
      resposta = true;
    }
  }else{
    resposta = false;
  }
  return resposta;
}

boolean SensoresCor::verificarVerdeDir(){
  boolean resposta = false;
  valorSensorCorHSVDir = robo.getHSVDireito(); 

  if((valorSensorCorHSVDir.h < divisorBrancoVerdeDir.h)){
    if((valorSensorCorHSVDir.v > divisorPretoVerdeDir.v) && (valorSensorCorHSVDir.v < divisorBrancoVerdeDir.v)){
      resposta = true;
    }
  }else{
    resposta = false;
  }
  return resposta;
}

void SensoresCor::printSensoresDeCorRGB(){  
    valorSensorCorRGBEsq = robo.getRGBEsquerdo();
    valorSensorCorRGBDir = robo.getRGBDireito(); 

    Serial.print(F("Cor Esquerdo: "));
    Serial.print(valorSensorCorRGBEsq.vermelho);
    Serial.print(F(", "));
    Serial.print(valorSensorCorRGBEsq.verde);
    Serial.print(F(", "));
    Serial.print(valorSensorCorRGBEsq.azul);
    Serial.print(F("   Cor Direito:  "));
    Serial.print(valorSensorCorRGBDir.vermelho);
    Serial.print(F(", "));
    Serial.print(valorSensorCorRGBDir.verde);
    Serial.print(F(", "));
    Serial.print(valorSensorCorRGBDir.azul);
    Serial.println();
}

void SensoresCor::printSensoresDeCorHSV(){
  valorSensorCorHSVEsq = robo.getHSVEsquerdo();
  valorSensorCorHSVDir = robo.getHSVDireito(); 

  Serial.print(F("Cor Esquerdo: "));
  Serial.print(valorSensorCorHSVEsq.h);
  Serial.print(F(", "));
  Serial.print(valorSensorCorHSVEsq.s);
  Serial.print(F(", "));
  Serial.print(valorSensorCorHSVEsq.v);
  Serial.print(F("   Cor Direito:  "));
  Serial.print(valorSensorCorHSVDir.h);
  Serial.print(F(", "));
  Serial.print(valorSensorCorHSVDir.s);
  Serial.print(F(", "));
  Serial.print(valorSensorCorHSVDir.v);
  Serial.println();  
}

void SensoresCor::pegarDadosEEPROM(){
  robo.lerCalibracao(val);

  mediaPretoCorEsq.h = val.pretoEsq.h;
  mediaPretoCorEsq.s = val.pretoEsq.s;
  mediaPretoCorEsq.v = val.pretoEsq.v;
  
  mediaPretoCorDir.h = val.pretoDir.h;
  mediaPretoCorDir.s = val.pretoDir.s;
  mediaPretoCorDir.v = val.pretoDir.v;
  
  mediaBrancoCorEsq.h = val.brancoEsq.h;
  mediaBrancoCorEsq.s = val.brancoEsq.s;
  mediaBrancoCorEsq.v = val.brancoEsq.v;
  
  mediaBrancoCorDir.h = val.brancoDir.h;
  mediaBrancoCorDir.s = val.brancoDir.s;
  mediaBrancoCorDir.v = val.brancoDir.v;
  
  mediaVerdeCorEsq.h = val.verdeEsq.h;
  mediaVerdeCorEsq.s = val.verdeEsq.s;
  mediaVerdeCorEsq.v = val.verdeEsq.v;
  
  mediaVerdeCorDir.h = val.verdeDir.h;
  mediaVerdeCorDir.s = val.verdeDir.s;
  mediaVerdeCorDir.v = val.verdeDir.v;
}

void SensoresCor::calcularDivisores(){
  //Calculando Cortes para H
  divisorPretoVerdeEsq.h = (mediaPretoCorEsq.h + mediaVerdeCorEsq.h) / 2;
  divisorPretoVerdeDir.h = (mediaPretoCorDir.h + mediaVerdeCorDir.h) / 2;

  divisorBrancoVerdeEsq.h = (mediaBrancoCorEsq.h + mediaVerdeCorEsq.h) / 2;
  divisorBrancoVerdeDir.h = (mediaBrancoCorDir.h + mediaVerdeCorDir.h) / 2;

  divisorPretoBrancoEsq.h = (mediaPretoCorEsq.h + mediaBrancoCorEsq.h) / 2;
  divisorPretoBrancoDir.h = (mediaPretoCorDir.h + mediaBrancoCorDir.h) / 2;

  //Calculando Cortes para V
  divisorPretoVerdeEsq.v = (mediaPretoCorEsq.v + mediaVerdeCorEsq.v) / 2;
  divisorPretoVerdeDir.v = (mediaPretoCorDir.v + mediaVerdeCorDir.v) / 2;
  
  divisorBrancoVerdeEsq.v = (mediaBrancoCorEsq.v + mediaVerdeCorEsq.v) / 2;
  divisorBrancoVerdeDir.v = (mediaBrancoCorDir.v + mediaVerdeCorDir.v) / 2;

  divisorPretoBrancoEsq.v = (mediaPretoCorEsq.v + mediaBrancoCorEsq.v) / 2;
  divisorPretoBrancoDir.v = (mediaPretoCorDir.v + mediaBrancoCorDir.v) / 2; 
}

