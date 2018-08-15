#include "Toy.h"

Toy::Toy(){
  //
}

static void Toy::allLedsOn(){
  digitalWrite(pinLED1, HIGH);
  digitalWrite(pinLED2, HIGH);
  digitalWrite(pinLED3, HIGH);
}

static void Toy::allLedsOff(){
  digitalWrite(pinLED1, LOW);
  digitalWrite(pinLED2, LOW);
  digitalWrite(pinLED3, LOW);
}

void Toy::ledsEscada(int numeroDeRepeticoes, int tempo){
  int cont = 0;
  
  while(cont != numeroDeRepeticoes){
    allLedsOff();
    delay(tempo);
    
    digitalWrite(pinLED1, HIGH);
    delay(tempo);
    digitalWrite(pinLED2, HIGH);
    delay(tempo);
    digitalWrite(pinLED3, HIGH);
    delay(tempo);
    cont++;
  }
}

void Toy::ledsAlerta(int numeroDeRepeticoes){
    int cont = 0;
    boolean primeiroVez = true; 
      
    while(cont != numeroDeRepeticoes){
      allLedsOn();
      delay(150);
      allLedsOff();
      delay(150);
      cont++;
    }
}

void Toy::ledAlerta(int numeroLed, int numeroDeRepeticoes, int tempo){
  int cont = 0;
  
  if(numeroLed == 1){
    while(cont != numeroDeRepeticoes){
      led1Off();
      delay(tempo);
      led1On();
      delay(tempo);
      cont++;
    }
  }else if(numeroLed = 2){
    while(cont != numeroDeRepeticoes){
      led2Off();
      delay(tempo);
      led2On();
      delay(tempo);
      cont++;
    }
  }else if(numeroLed = 3){
    while(cont != numeroDeRepeticoes){
      led3Off();
      delay(tempo);
      led3On();
      delay(tempo);
      cont++;
    }
  }
}

void Toy::led1On(){
  digitalWrite(pinLED1, HIGH);
}

void Toy::led2On(){
  digitalWrite(pinLED2, HIGH);
}

void Toy::led3On(){
  digitalWrite(pinLED3, HIGH);
}

void Toy::led1Off(){
  digitalWrite(pinLED1, LOW);
}

void Toy::led2Off(){
  digitalWrite(pinLED2, LOW);
}

void Toy::led3Off(){
  digitalWrite(pinLED3, LOW);
}

void Toy::start(){
  pinMode(pinLED1, OUTPUT);
  pinMode(pinLED2, OUTPUT);
  pinMode(pinLED3, OUTPUT);

  Serial.println("Pinos para os Leds Configurados");
}

