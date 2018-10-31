#include "SensoresCor.h"

SensoresCor::SensoresCor(){
  robo.habilitaTCS34();
  pegarDadosEEPROM();
  calcularDivisores();
}

//Verde Verde
boolean SensoresCor::vv(){ 
  boolean resposta = true;
  int cont = 0;
  for(int i = 1; i <= 3; i++){
    if((sensorEsq('V')) && (sensorDir('V'))){
      cont++;
    }
    delay(10);
  }
  return (cont >= 2);
}

//Verde NãoVerde
boolean SensoresCor::vn(){ 
  boolean resposta = true;
  int cont = 0;
  for(int i = 1; i <= 3; i++){
    if((sensorEsq('V')) && (!sensorDir('V'))){
      cont++;
    }
    delay(10);
  }
  return (cont >= 2);
}
//NãoVerde Verde
boolean SensoresCor::nv(){ 
  boolean resposta = true;
  int cont = 0;
  for(int i = 1; i <= 3; i++){
    if((!sensorEsq('V')) && (sensorDir('V'))){
      cont++;
    }
    delay(10);
  }
  return (cont >= 2);
}

//NãoVerde NãoVerde
boolean SensoresCor::nn(){ 
  boolean resposta = true;
  int cont = 0;
  for(int i = 1; i <= 3; i++){
    if((!sensorEsq('V')) && (!sensorDir('V'))){
      cont++;
    }
    delay(10);
  }
  return (cont >= 2);
}


boolean SensoresCor::sensorEsq(char entrada){
  boolean resposta = false;
  
  valorSensorCorHSVEsq = robo.getHSVEsquerdo();
  switch(entrada){
    case 'V': 
      if((valorSensorCorHSVEsq.h < divisorBrancoVerdeEsq.h)){
        if((valorSensorCorHSVEsq.v > divisorPretoVerdeEsq.v) && (valorSensorCorHSVEsq.v < divisorBrancoVerdeEsq.v)){
          resposta = true;
        }
      }
      break;
    case 'B':
      break;
    case 'P':
      break;
  }

  delay(70);
  return resposta;
}

boolean SensoresCor::sensorDir(char entrada){
  boolean resposta = false;
  
  valorSensorCorHSVDir = robo.getHSVDireito();
  switch(entrada){
    case 'V': 
      if((valorSensorCorHSVDir.h < divisorBrancoVerdeDir.h)){
        if((valorSensorCorHSVDir.v > divisorPretoVerdeDir.v) && (valorSensorCorHSVDir.v < divisorBrancoVerdeDir.v)){
          resposta = true;
        }
      }
      break;
    case 'B':
      break;
    case 'P':
      break;
  }

  delay(70);
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

void SensoresCor::testarVerde(){
  int cont = 0;
  
  if(sensorEsq('V')){
    Serial.println(F("Esquerdo: É Verde"));
    cont++;
  } else {
    Serial.println(F("Esquerdo: Não é Verde"));
  }
  delay(80);
  if(sensorDir('V')){
    Serial.println(F("Direito: É Verde"));
    cont++;
  } else {
    Serial.println(F("Direito: Não é Verde"));
  }
  delay(80);
  if(cont >= 2){
    robo.ligarLed(3);
  } else {
    robo.desligarLed(3);
  }
  Serial.println(F("----------------------"));
}

void SensoresCor::testarVerdeMultiplo(){
  if(vv()){
    Serial.println(F("Condição VV"));
  } else if(vn()){
    Serial.println(F("Condição VN"));
  } else if(nv()){
    Serial.println(F("Condição NV"));
  } else if(nn()){
    Serial.println(F("Condição NN"));
  } else {
    Serial.println(F("Condição Não Encontrada"));
  }

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