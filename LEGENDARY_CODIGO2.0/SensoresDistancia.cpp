#include "SensoresDistancia.h"

SensoresDistancia::SensoresDistancia(){
  //
}

void SensoresDistancia::printSensoresDeDistancia(){
  valorSensorLateralDir = robo.lerSensorSonarDir();
  valorSensorLateralEsq = robo.lerSensorSonarEsq();
  valorSensorFrontal = robo.lerSensorSonarFrontal();

  Serial.print(F("Valor do sensor frontal: "));
  Serial.print(valorSensorFrontal);
  Serial.print(F("  Esquerdo: "));
  Serial.print(valorSensorLateralEsq);
  Serial.print(F("  Direito: "));
  Serial.println(valorSensorLateralDir);
}

