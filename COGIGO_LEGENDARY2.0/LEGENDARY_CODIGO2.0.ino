
#include <robo_hardware2.h>
#include <Servo.h>
#include "Toy.h"
#include "MenuIniciar.h"
#include "Estrategia.h"
#include "Calibragem.h"

Toy toy;
MenuIniciar menuIniciar;
Estrategia estrategia;
Calibragem calibragem;
calibracao_dados val;

void setup() {
  Serial.begin(9600);
  robo.configurar(false);
  robo.lerCalibracao(val);
  toy.start();
  menuIniciar.menuBotoes();
}

void loop() {
  if(menuIniciar.calibragem.voltarMenu){
    Serial.println("Voltando para Menu Botões...");
    menuIniciar.calibragem.voltarMenu = false;
    menuIniciar.menuBotoes();
  }
  estrategia.executar();
}
