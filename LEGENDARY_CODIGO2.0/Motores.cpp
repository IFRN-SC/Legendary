#include "Motores.h"

#define POSITIVO 50
#define NEGATIVO -50

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


