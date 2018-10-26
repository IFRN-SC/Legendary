#include "SensoresDistancia.h"

#define DISTANCIA_OBSTACULO 14.0
#define DELAY_VERIFICACAO_OBSTACULO 1000

#define DIFERENCA_PARA_CORTE 1

#define CORTE_MAXIMA_PROXIMIDADE (DISTANCIA_OBSTACULO + DIFERENCA_PARA_CORTE)
#define CORTE_MAXIMA_DISTANCIA (DISTANCIA_OBSTACULO - DIFERENCA_PARA_CORTE)

#define DISTANCIA_RAMPA_ESQ 18.0
#define DISTANCIA_RAMPA_DIR 15.0


SensoresDistancia::SensoresDistancia(){}

void SensoresDistancia::ajustarDistanciaObstaculo(){
  motores.parar();  if(robo.lerSensorSonarFrontal() < CORTE_MAXIMA_PROXIMIDADE){
    while(robo.lerSensorSonarFrontal() < CORTE_MAXIMA_PROXIMIDADE){
      motores.alinhamentoVoltar();
    }
  }
  if(robo.lerSensorSonarFrontal() > CORTE_MAXIMA_DISTANCIA){
    while(robo.lerSensorSonarFrontal() > CORTE_MAXIMA_DISTANCIA){
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

float SensoresDistancia::getMediaSonarEsq(){
  float mediaSonar = robo.lerSensorSonarEsq();
  for(int i = 1; i <= 10; i++){ 
    mediaSonar += robo.lerSensorSonarEsq();
    mediaSonar /= 2;
    delay(10);
  }
  return mediaSonar;
}

float SensoresDistancia::getMediaSonarDir(){
  float mediaSonar = robo.lerSensorSonarDir();
  for(int i = 1; i <= 10; i++){ 
    mediaSonar += robo.lerSensorSonarDir();
    mediaSonar /= 2;
    delay(10);
  }
  return mediaSonar;
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


