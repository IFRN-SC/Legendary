#include <robo_hardware2.h>
#include <Servo.h>
#include "Toy.h"
#include "MenuIniciar.h"
#include "Estrategia.h"
#include "Calibragem.h"
#include "SensoresAlavanca.h"

#define PIN_ALAVANCA_ESQ 15
#define PIN_ALAVANCA_DIR 14

Toy toy;
MenuIniciar menuIniciar;
Estrategia estrategia;
Calibragem calibragem;
SensoresAlavanca alavanca;

void start();
void acaoAlavanca();

void setup() {
  Serial.begin(9600);
  robo.configurar(false);
  robo.habilitaTCS34();
  alavanca.start();
  pinMode(PIN_ALAVANCA_ESQ, INPUT_PULLUP);
  pinMode(PIN_ALAVANCA_DIR, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(15), acaoAlavanca, CHANGE);
  start();
  
  calibragem.printDadosEEPROM();
  menuIniciar.menuBotoes();
}

void loop() {
  if(menuIniciar.calibragem.voltarMenu){
    Serial.println(F("Voltando para Menu Botões..."));
    menuIniciar.calibragem.voltarMenu = false;
    menuIniciar.menuBotoes();
  }
  estrategia.executar();
}

void start(){
  //
}

void acaoAlavanca(){
  toy.desligarLeds();
}

