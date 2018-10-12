#include "Motores.h"

#define POSITIVO 25
#define NEGATIVO -25

#define POSITIVO_DEVAGAR 25
#define NEGATIVO_DEVAGAR -25

#define POSITIVO_90_GRAUS 40
#define NEGATIVO_90_GRAUS -40

#define POSITIVO_DIFERENTE 45
#define NEGATIVO_DIFERENTE -40

#define DELAY_90_GRAUS 320

#define POSITIVO_FRENTE_CURVA 25
#define DELAY_FRENTE_CURVA 100

Motores::Motores(){
  //
}

//Movimentos com Valores Padrões
void Motores::frente(){robo.acionarMotores(POSITIVO, POSITIVO);}
void Motores::voltar(){robo.acionarMotores(NEGATIVO, NEGATIVO);}
void Motores::parar(){robo.acionarMotores(0, 0);}
void Motores::girarEsq(){robo.acionarMotores(NEGATIVO, POSITIVO);}
void Motores::girarDir(){robo.acionarMotores(POSITIVO, NEGATIVO);}
void Motores::virarEsq(){robo.acionarMotores(0, POSITIVO);}
void Motores::virarDir(){robo.acionarMotores(POSITIVO, 0);}
void Motores::voltarEsq(){robo.acionarMotores(NEGATIVO, 0);}
void Motores::voltarDir(){robo.acionarMotores(0, NEGATIVO);}

//Movimentos Devagar
void Motores::frenteDevagar(){robo.acionarMotores(POSITIVO_DEVAGAR, POSITIVO_DEVAGAR);}
void Motores::voltarDevagar(){robo.acionarMotores(NEGATIVO_DEVAGAR, NEGATIVO_DEVAGAR);}
void Motores::girarDevagarEsq(){robo.acionarMotores(NEGATIVO_DEVAGAR, POSITIVO_DEVAGAR);}
void Motores::girarDevagarDir(){robo.acionarMotores(POSITIVO_DEVAGAR, NEGATIVO_DEVAGAR);}
void Motores::virarDevagarEsq(){robo.acionarMotores(0, POSITIVO_DEVAGAR);}
void Motores::virarDevagarDir(){robo.acionarMotores(POSITIVO_DEVAGAR, 0);}
void Motores::voltarDevagarEsq(){robo.acionarMotores(NEGATIVO_DEVAGAR, 0);}
void Motores::voltarDevagarDir(){robo.acionarMotores(0, NEGATIVO_DEVAGAR);}

//Movimentos Diferentes
void Motores::giroDiferenteDir(){robo.acionarMotores(POSITIVO_DIFERENTE, NEGATIVO_DIFERENTE);}
void Motores::giroDiferenteEsq(){robo.acionarMotores(NEGATIVO_DIFERENTE, POSITIVO_DIFERENTE);}


//Movimentos de 90 Graus
void Motores::girar90Esq(){
  robo.acionarMotores(NEGATIVO_90_GRAUS, POSITIVO_90_GRAUS);
  delay(DELAY_90_GRAUS);
}
void Motores::girar90Dir(){
  robo.acionarMotores(POSITIVO_90_GRAUS, NEGATIVO_90_GRAUS);
  delay(DELAY_90_GRAUS);
}


//Movimentos Especificos
void Motores::frenteCurva(){
  robo.acionarMotores(POSITIVO_FRENTE_CURVA, POSITIVO_FRENTE_CURVA);
  delay(DELAY_FRENTE_CURVA);
}

void Motores::pararAteBotao1(){
  parar();
  while(!robo.botao1Pressionado()){}
  toy.ledsAlerta(3);
}

