#include "SensoresAlavanca.h"

#define PIN_ALAVANCA_ESQ 4
#define PIN_ALAVANCA_DIR 5

void testar();

SensoresAlavanca::SensoresAlavanca(){
  //
}

void SensoresAlavanca::start(){
  pinMode(PIN_ALAVANCA_ESQ, INPUT_PULLUP);
  pinMode(PIN_ALAVANCA_DIR, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIN_ALAVANCA_DIR), testar, CHANGE);
}

bool SensoresAlavanca::alavancaEsq() {
   #define tempoDebounce 50 //(tempo para eliminar o efeito Bounce EM MILISEGUNDOS)

   bool estadoBotao;
   static bool estadoBotaoAnt; 
   static bool estadoRet = true;
   static unsigned long delayBotao = 0;

   if ( (millis() - delayBotao) > tempoDebounce ) {
       estadoBotao = digitalRead(PIN_ALAVANCA_ESQ);
       if ( estadoBotao && (estadoBotao != estadoBotaoAnt) ) {
          estadoRet = !estadoRet;
          delayBotao = millis();
       }
       estadoBotaoAnt = estadoBotao;
   }

   return estadoRet;
}


bool SensoresAlavanca::alavancaDir() {
   #define tempoDebounce 50 //(tempo para eliminar o efeito Bounce EM MILISEGUNDOS)

   bool estadoBotao;
   static bool estadoBotaoAnt; 
   static bool estadoRet = true;
   static unsigned long delayBotao = 0;

   if ( (millis() - delayBotao) > tempoDebounce ) {
       estadoBotao = digitalRead(PIN_ALAVANCA_DIR);;
       if ( estadoBotao && (estadoBotao != estadoBotaoAnt) ) {
          estadoRet = !estadoRet;
          delayBotao = millis();
       }
       estadoBotaoAnt = estadoBotao;
   }

   return estadoRet;
}

void SensoresAlavanca::testarSensoresAlavanca(){
  if(alavancaEsq() && alavancaDir()){
    Serial.println("Alavanca Esquerda Pressionada");
    toy.desligarLeds();
    robo.ligarLed(1);
    robo.ligarLed(2);
  } else if(alavancaDir()){
    Serial.println("Alavanca Direita Pressionada");
    toy.ligarApenasLed(2);
  } else if(alavancaEsq()){
    Serial.println("Alavanca Esquerda e Direita Pressionada");
    toy.ligarApenasLed(1);
  } else {
    Serial.println("Nenhuma Alavanca Pressionada");
    toy.desligarLeds();
  }
}

void testar(){
  Serial.println("Dentro da Classe");
}

