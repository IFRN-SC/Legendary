#include "SensoresCor.h"

SensoresCor::SensoresCor(){
  robo.habilitaTCS34();
  pegarDadosEEPROM();
  calcularDivisores();
}

void SensoresCor::testarVerde(){
  if(sensorEsq('V')){
    Serial.println("Esquerdo: É Verde");
  } else {
    Serial.println("Esquerdo: Não é Verde");
  }
  if(sensorDir('V')){
    Serial.println("Direito: É Verde");
  } else {
    Serial.println("Direito: Não é Verde");
  }
  if(sensorEsq('V') && sensorDir('V')){
    robo.ligarLed(3);
  } else {
    robo.desligarLed(3);
  }
  Serial.println("----------------------");
}

//Verde Verde
boolean SensoresCor::vv(){
  int verdeEncontrado = 0;
  boolean resposta = false;
  
  for(int i = 0; i < 3; i++){
    if((sensorEsq('V')) && (sensorDir('V'))){
      verdeEncontrado++;
    }
  }
  
  if(verdeEncontrado > 1){
    resposta = true;
  } else {
    resposta = false;
  }

  return resposta;
}

//Verde NãoVerde
boolean SensoresCor::vn(){
  int verdeEncontrado = 0;
  boolean resposta = false;
  
  for(int i = 0; i < 3; i++){
    if((sensorEsq('V')) && (sensorDir('V') == false)){
      verdeEncontrado++;
    }
  }

  if(verdeEncontrado > 1){
    resposta = true;
  } else {
    resposta = false;
  }

  return resposta;
}

//NãoVerde Verde
boolean SensoresCor::nv(){
  int verdeEncontrado = 0;
  boolean resposta = false;
  
  for(int i = 0; i < 3; i++){
    if((sensorEsq('V') == false) && (sensorDir('V'))){
      verdeEncontrado++;
    }
  }

  if(verdeEncontrado > 1){
    resposta = true;
  } else {
    resposta = false;
  }

  return resposta;
}

boolean SensoresCor::nn(){
  int verdeEncontrado = 0;
  boolean resposta = false;
  
  for(int i = 0; i < 3; i++){
    if((sensorEsq('V') == false) && (sensorEsq('V') == false)){
      verdeEncontrado++;
    }
  }

  if(verdeEncontrado > 1){
    resposta = true;
  } else {
    resposta = false;
  }
  
  return resposta;
}

boolean SensoresCor::sensorEsq(char entrada){
  boolean resposta = false;

  switch(entrada){
    case 'V':
      valorSensorCorHSVEsq = robo.getHSVEsquerdo(); 

      if((valorSensorCorHSVEsq.h < divisorBrancoVerdeEsq.h)){
        if((valorSensorCorHSVEsq.v > divisorPretoVerdeEsq.v) && (valorSensorCorHSVEsq.v < divisorBrancoVerdeEsq.v)){
          resposta = true;
        }
      }else{
        resposta = false;
      }
      break;

    case 'B':
      resposta = false;
      break;

    case 'P':
      resposta = false;
      break;

  }

  delay(100);
  return resposta;
}

boolean SensoresCor::sensorDir(char entrada){
  boolean resposta = false;

  switch(entrada){
    case 'V':
      valorSensorCorHSVDir = robo.getHSVDireito(); 

      if((valorSensorCorHSVDir.h < divisorBrancoVerdeDir.h)){
        if((valorSensorCorHSVDir.v > divisorPretoVerdeDir.v) && (valorSensorCorHSVDir.v < divisorBrancoVerdeDir.v)){
          resposta = true;
        }
      }else{
        resposta = false;
      }
      break;

    case 'B':
      resposta = false;
      break;

    case 'P':
      resposta = false;
      break;

  }
  
  delay(100);
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

