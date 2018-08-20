#include "Motores.h"

#define POSITIVO 30
#define NEGATIVO -30

Motores::Motores(){
  //
}

void Motores::frente(){robo.acionarMotores(POSITIVO, POSITIVO);}
void Motores::voltar(){robo.acionarMotores(NEGATIVO, NEGATIVO);}
void Motores::parar(){robo.acionarMotores(0, 0);}
void Motores::girarEsq(){robo.acionarMotores(NEGATIVO, POSITIVO);}
void Motores::girarDir(){robo.acionarMotores(POSITIVO, NEGATIVO);}
void Motores::virarEsq(){robo.acionarMotores(0, POSITIVO);}
void Motores::virarDir(){robo.acionarMotores(POSITIVO, 0);}
void Motores::voltarEsq(){robo.acionarMotores(NEGATIVO, 0);}
void Motores::voltarDir(){robo.acionarMotores(0, NEGATIVO);}

void Motores::girar90Esq(){
  robo.acionarMotores(NEGATIVO, POSITIVO);
  delay(630);
}
void Motores::girar90Dir(){
  robo.acionarMotores(POSITIVO, NEGATIVO);
  delay(630);
}


