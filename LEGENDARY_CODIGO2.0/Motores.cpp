#include "Motores.h"

#define POSITIVO 50
#define NEGATIVO -50
#define POSITIVO_DIFERENTE 50
#define NEGATIVO_DIFERENTE -45

#define POSITIVO_FRENTE_CURVA 25
#define DELAY_FRENTE_CURVA 100

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
  delay(640);
}
void Motores::girar90Dir(){
  robo.acionarMotores(POSITIVO, NEGATIVO);
  delay(680);
}
  
void Motores::giroDiferenteDir(){robo.acionarMotores(POSITIVO_DIFERENTE, NEGATIVO_DIFERENTE);}
void Motores::giroDiferenteEsq(){robo.acionarMotores(NEGATIVO_DIFERENTE, POSITIVO_DIFERENTE);}

void Motores::frenteCurva(){
  robo.acionarMotores(POSITIVO_FRENTE_CURVA, POSITIVO_FRENTE_CURVA);
  delay(DELAY_FRENTE_CURVA);
}
