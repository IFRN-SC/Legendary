#include "SensoresDistancia.h"

#define DISTANCIA_OBSTACULO 4.20
#define DELAY_VERIFICACAO_OBSTACULO 1000

#define CORTE_PROXIMIDADE 3.0

#define DISTANCIA_RAMPA_ESQ 18.0
#define DISTANCIA_RAMPA_DIR 18.0


SensoresDistancia::SensoresDistancia(){}

void SensoresDistancia::ajustarDistanciaObstaculo(){
  motores.parar();  
  if(robo.lerSensorSonarFrontal() < CORTE_PROXIMIDADE){
    while(robo.lerSensorSonarFrontal() < CORTE_PROXIMIDADE){
      motores.alinhamentoVoltar();
    }
  }
  if(robo.lerSensorSonarFrontal() > CORTE_PROXIMIDADE){
    while(robo.lerSensorSonarFrontal() > CORTE_PROXIMIDADE){
      motores.alinhamentoFrente();
    }
  }
  motores.miniParada();
}

boolean SensoresDistancia::isOnObstaculo(){
  boolean resposta = false;
  if(robo.lerSensorSonarFrontal() <= DISTANCIA_OBSTACULO){
    motores.frear();
    delay(DELAY_VERIFICACAO_OBSTACULO);

    if(robo.lerSensorSonarFrontal() <= DISTANCIA_OBSTACULO){
      resposta = true;
    }
  }
  return resposta;
}

boolean SensoresDistancia::isTheRampa(){ return (robo.lerSensorSonarEsq() <= DISTANCIA_RAMPA_ESQ && robo.lerSensorSonarDir() <= DISTANCIA_RAMPA_DIR); }

double SensoresDistancia::getMediaSonarEsq(){
  double mediaSonar = robo.lerSensorSonarEsq();
  for(int i = 1; i <= 10; i++){ 
    mediaSonar += robo.lerSensorSonarEsq();
    mediaSonar /= 2;
    delay(10);
  }
  return mediaSonar;
}

double SensoresDistancia::getMediaSonarDir(){
  double mediaSonar = robo.lerSensorSonarDir();
  for(int i = 1; i <= 10; i++){ 
    mediaSonar += robo.lerSensorSonarDir();
    mediaSonar /= 2;
    delay(10);
  }
  return mediaSonar;
}

double SensoresDistancia::getValorMaximoSonarEsq(){
  motores.parar();
  double aux;
  double valorMaximo = robo.lerSensorSonarEsq();
  delay(10);
  for(int i = 1; i <= 10; i++){
    aux = robo.lerSensorSonarEsq();
    if(aux > valorMaximo){
      valorMaximo = aux;
    }
    delay(20);
  }
  return valorMaximo;
}

double SensoresDistancia::getValorMaximoSonarDir(){
  motores.parar();
  double valorMaximo = robo.lerSensorSonarDir();
  delay(10);
  for(int i = 1; i <= 10; i++){
    double aux = robo.lerSensorSonarDir();
    if(aux > valorMaximo){
      valorMaximo = aux;
    }
    delay(10);
  }
  return valorMaximo;
}

double SensoresDistancia::getValorMinimoSonarEsq(){
  motores.parar();
  double valorMinimo = robo.lerSensorSonarEsq();
  delay(10);
  for(int i = 1; i <= 10; i++){
    double aux = robo.lerSensorSonarEsq();
    if(aux < valorMinimo){
      valorMinimo = aux;
    }
    delay(10);
  }
  return valorMinimo;
}

double SensoresDistancia::getValorMinimoSonarDir(){
  motores.parar();
  double valorMinimo = robo.lerSensorSonarDir();
  delay(10);
  for(int i = 1; i <= 10; i++){
    double aux = robo.lerSensorSonarDir();
    if(aux < valorMinimo){
      valorMinimo = aux;
    }
    delay(10);
  }
  return valorMinimo;
}

void SensoresDistancia::printSensoresDeDistancia(){
  valorLido = robo.lerSensorSonarFrontal();
  Serial.print(F("Valor do sensor frontal: "));
  Serial.print(valorLido);

  valorLido = robo.lerSensorSonarEsq();
  Serial.print(F("  Esquerdo: "));
  Serial.print(valorLido);

  valorLido = robo.lerSensorSonarDir();
  Serial.print(F("  Direito: "));
  Serial.println(valorLido);
}