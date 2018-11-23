#include "Motores.h"

#define DIFERENCA 3 //Diferença de Nivel entre Motores Esquerdo e Direito

//Valores dos Motores Normais
#define DIR_POSITIVO 50
#define DIR_NEGATIVO -50
#define ESQ_POSITIVO (DIR_POSITIVO + DIFERENCA)
#define ESQ_NEGATIVO (DIR_NEGATIVO - DIFERENCA)

//Valores dos Motores mais Lentos
#define DIR_POSITIVO_DEVAGAR 23
#define DIR_NEGATIVO_DEVAGAR -23
#define ESQ_POSITIVO_DEVAGAR (DIR_POSITIVO_DEVAGAR + DIFERENCA)
#define ESQ_NEGATIVO_DEVAGAR (DIR_NEGATIVO_DEVAGAR - DIFERENCA)

//Valores dos Motores para as Curvas
#define DIR_POSITIVO_CURVA 40
#define DIR_NEGATIVO_CURVA -40
#define ESQ_POSITIVO_CURVA (DIR_POSITIVO_CURVA + DIFERENCA)
#define ESQ_NEGATIVO_CURVA (DIR_NEGATIVO_CURVA - DIFERENCA)
//Frente Curva
#define DIR_POSITIVO_MINI_FRENTE_CURVA 25
#define DIR_NEGATIVO_MINI_FRENTE_CURVA -25
#define ESQ_POSITIVO_MINI_FRENTE_CURVA (DIR_POSITIVO_MINI_FRENTE_CURVA + DIFERENCA)
#define ESQ_NEGATIVO_MINI_FRENTE_CURVA (DIR_NEGATIVO_MINI_FRENTE_CURVA - DIFERENCA)
//Retorno Curva
#define DIR_POSITIVO_VOLTAR_CURVA 15
#define DIR_NEGATIVO_VOLTAR_CURVA -15
#define ESQ_POSITIVO_VOLTAR_CURVA (DIR_POSITIVO_VOLTAR_CURVA + DIFERENCA)
#define ESQ_NEGATIVO_VOLTAR_CURVA (DIR_NEGATIVO_VOLTAR_CURVA - DIFERENCA)

//Valores dos Motores para Movimentos Leves para voltar a linha
#define DIR_POSITIVO_GIRO_LEVE 30
#define DIR_NEGATIVO_GIRO_LEVE -30
#define ESQ_POSITIVO_GIRO_LEVE (DIR_POSITIVO_GIRO_LEVE + DIFERENCA)
#define ESQ_NEGATIVO_GIRO_LEVE (DIR_NEGATIVO_GIRO_LEVE - DIFERENCA)

//Valores dos Motores para Alinhamento
#define DIR_POSITIVO_ALINHAMENTO 18
#define DIR_NEGATIVO_ALINHAMENTO -18
#define ESQ_POSITIVO_ALINHAMENTO (DIR_POSITIVO_ALINHAMENTO + DIFERENCA)
#define ESQ_NEGATIVO_ALINHAMENTO (DIR_NEGATIVO_ALINHAMENTO - DIFERENCA)

//Valores dos Motores para girar 90 Graus
#define DIR_POSITIVO_90_GRAUS 40
#define DIR_NEGATIVO_90_GRAUS -40
#define ESQ_POSITIVO_90_GRAUS (DIR_POSITIVO_90_GRAUS + DIFERENCA)
#define ESQ_NEGATIVO_90_GRAUS (DIR_NEGATIVO_90_GRAUS - DIFERENCA)

//Valores dos Motores para desviar os Obstaculo
#define DIR_POSITIVO_DESVIAR_OBSTACULO 30
#define DIR_NEGATIVO_DESVIAR_OBSTACULO -30
#define ESQ_POSITIVO_DESVIAR_OBSTACULO (DIR_POSITIVO_DESVIAR_OBSTACULO + (DIFERENCA - 2))
#define ESQ_NEGATIVO_DESVIAR_OBSTACULO (DIR_POSITIVO_NEGATIVO_OBSTACULO - (DIFERENCA + 2))

//Valores dos Motores para a rampa
#define DIR_POSITIVO_RAMPA 50
#define DIR_NEGATIVO_RAMPA 20
#define ESQ_POSITIVO_RAMPA (DIR_POSITIVO_RAMPA + DIFERENCA)
#define ESQ_NEGATIVO_RAMPA (DIR_NEGATIVO_RAMPA - DIFERENCA)

//frear
#define DIR_POSITIVO_FREIO 20
#define DIR_NEGATIVO_FREIO -20
#define ESQ_POSITIVO_FREIO (DIR_POSITIVO_FREIO + DIFERENCA)
#define ESQ_NEGATIVO_FREIO (DIR_NEGATIVO_FREIO - DIFERENCA)

//Delays para Movimentos
#define DELAY_90_GRAUS 356
#define DELAY_MINI_FRENTE_CURVA 317
#define DELAY_MINI_PARADA 300
#define DELAY_MINI_GIRO 300
#define DELAY_VERIFICACAO 350

Motores::Motores(){}

//Movimentos com Valores Padrões
void Motores::frente(){robo.acionarMotores(ESQ_POSITIVO, DIR_POSITIVO);}
void Motores::voltar(){robo.acionarMotores(ESQ_NEGATIVO, DIR_NEGATIVO);}
void Motores::parar(){robo.acionarMotores(0, 0);}
void Motores::girarEsq(){robo.acionarMotores(ESQ_NEGATIVO, DIR_POSITIVO);}
void Motores::girarDir(){robo.acionarMotores(ESQ_POSITIVO, DIR_NEGATIVO);}
void Motores::virarEsq(){robo.acionarMotores(0, DIR_POSITIVO);}
void Motores::virarDir(){robo.acionarMotores(ESQ_POSITIVO, 0);}
void Motores::voltarEsq(){robo.acionarMotores(ESQ_NEGATIVO, 0);}
void Motores::voltarDir(){robo.acionarMotores(0, DIR_NEGATIVO);}

//Movimentos Devagar
void Motores::frenteDevagar(){robo.acionarMotores(ESQ_POSITIVO_DEVAGAR, DIR_POSITIVO_DEVAGAR);}
void Motores::voltarDevagar(){robo.acionarMotores(ESQ_NEGATIVO_DEVAGAR, DIR_NEGATIVO_DEVAGAR);}
void Motores::girarDevagarEsq(){robo.acionarMotores(ESQ_NEGATIVO_DEVAGAR, DIR_POSITIVO_DEVAGAR);}
void Motores::girarDevagarDir(){robo.acionarMotores(ESQ_POSITIVO_DEVAGAR, DIR_NEGATIVO_DEVAGAR);}
void Motores::virarDevagarEsq(){robo.acionarMotores(0, DIR_POSITIVO_DEVAGAR);}
void Motores::virarDevagarDir(){robo.acionarMotores(ESQ_POSITIVO_DEVAGAR, 0);}
void Motores::voltarDevagarEsq(){robo.acionarMotores(ESQ_NEGATIVO_DEVAGAR, 0);}
void Motores::voltarDevagarDir(){robo.acionarMotores(0, DIR_NEGATIVO_DEVAGAR);}

//Movimentos Curva
void Motores::miniFrenteCurva(){
  robo.acionarMotores(ESQ_POSITIVO_MINI_FRENTE_CURVA, DIR_POSITIVO_MINI_FRENTE_CURVA);
  delay(DELAY_MINI_FRENTE_CURVA);
}
void Motores::voltarCurva(){robo.acionarMotores(ESQ_NEGATIVO_VOLTAR_CURVA, DIR_NEGATIVO_VOLTAR_CURVA);}
void Motores::giroCurvaEsq(){robo.acionarMotores(ESQ_NEGATIVO_CURVA, DIR_POSITIVO_CURVA);}
void Motores::giroCurvaDir(){robo.acionarMotores(ESQ_POSITIVO_CURVA, DIR_NEGATIVO_CURVA);}


//Movimentos Leves
void Motores::giroLeveEsq(){robo.acionarMotores(ESQ_NEGATIVO_GIRO_LEVE, DIR_POSITIVO_GIRO_LEVE);}
void Motores::giroLeveDir(){robo.acionarMotores(ESQ_POSITIVO_GIRO_LEVE, DIR_NEGATIVO_GIRO_LEVE);}

//Movimentos de Alinhamento
void Motores::alinhamentoFrente(){robo.acionarMotores(ESQ_POSITIVO_ALINHAMENTO, DIR_POSITIVO_ALINHAMENTO);}
void Motores::alinhamentoVoltar(){robo.acionarMotores(ESQ_NEGATIVO_ALINHAMENTO, DIR_NEGATIVO_ALINHAMENTO);}
void Motores::alinhamentoVirarEsq(){robo.acionarMotores(0, DIR_POSITIVO_ALINHAMENTO);}
void Motores::alinhamentoVirarDir(){robo.acionarMotores(ESQ_POSITIVO_ALINHAMENTO, 0);}
void Motores::alinhamentoVoltarEsq(){robo.acionarMotores(ESQ_NEGATIVO_ALINHAMENTO, 0);}
void Motores::alinhamentoVoltarDir(){robo.acionarMotores(0, DIR_NEGATIVO_ALINHAMENTO);}


//Movimentos de 90 Graus
void Motores::girar90Esq(){
  robo.acionarMotores(ESQ_NEGATIVO_90_GRAUS, DIR_POSITIVO_90_GRAUS);
  delay(DELAY_90_GRAUS);
  frearGiroEsq();
}
void Motores::girar90Dir(){
  robo.acionarMotores(ESQ_POSITIVO_90_GRAUS, DIR_NEGATIVO_90_GRAUS);
  delay(DELAY_90_GRAUS);
  frearGiroDir();
}

//Movimentos para Desviar o Obstaculo
void Motores::frenteDesviarObstaculo(){ robo.acionarMotores(ESQ_POSITIVO_DESVIAR_OBSTACULO, DIR_POSITIVO_DESVIAR_OBSTACULO);}

//Movimentos Para a Rampa
void Motores::frenteRampa(){ robo.acionarMotores(ESQ_POSITIVO_RAMPA, DIR_POSITIVO_RAMPA);}
void Motores::superFrenteRampa(){ robo.acionarMotores((ESQ_POSITIVO_RAMPA + 15), (DIR_POSITIVO_RAMPA + 15));}
void Motores::girarEsqRampa(){ robo.acionarMotores(ESQ_NEGATIVO_RAMPA, DIR_POSITIVO_RAMPA);}
void Motores::girarDirRampa(){ robo.acionarMotores(ESQ_POSITIVO_RAMPA, DIR_NEGATIVO_RAMPA);}


//Movimentos de Freio
void Motores::frear(){
  robo.acionarMotores(ESQ_NEGATIVO_FREIO, DIR_NEGATIVO_FREIO);
  delay(90);
  robo.acionarMotores(0, 0);
}
void Motores::frearVoltar(){
  robo.acionarMotores(ESQ_POSITIVO_FREIO, DIR_POSITIVO_FREIO);
  delay(90);
  robo.acionarMotores(0, 0);
}
void Motores::frearGiroEsq(){
  robo.acionarMotores(ESQ_POSITIVO_FREIO, DIR_NEGATIVO_FREIO);
  delay(90);
  robo.acionarMotores(0, 0);
}
void Motores::frearGiroDir(){
  robo.acionarMotores(ESQ_NEGATIVO_FREIO, DIR_POSITIVO_FREIO);
  delay(90);
  robo.acionarMotores(0, 0);
}
void Motores::frearVirarEsq(){
  robo.acionarMotores(ESQ_NEGATIVO_FREIO, 0);
  delay(90);
  robo.acionarMotores(0, 0);
}
void Motores::frearVirarDir(){
  robo.acionarMotores(0, DIR_NEGATIVO_FREIO);
  delay(90);
  robo.acionarMotores(0, 0);
}
void Motores::frearVoltarEsq(){
  robo.acionarMotores(ESQ_POSITIVO_FREIO, 0);
  delay(90);
  robo.acionarMotores(0, 0);
}
void Motores::frearVoltarDir(){
  robo.acionarMotores(0, DIR_POSITIVO_FREIO);
  delay(90);
  robo.acionarMotores(0, 0);
}


//Movimentos Especificos
void Motores::miniParada(){
  robo.acionarMotores(0, 0);
  delay(DELAY_MINI_PARADA);
}
void Motores::miniGiroEsq(){
  robo.acionarMotores(ESQ_NEGATIVO, DIR_POSITIVO);
  delay(DELAY_MINI_GIRO);
  miniParada();
}
void Motores::miniGiroDir(){
  robo.acionarMotores(DIR_POSITIVO, ESQ_NEGATIVO);
  delay(DELAY_MINI_GIRO);
  miniParada();
}
void Motores::acaoRedutor(){
  frear();
  miniParada();
  voltarDevagar();
  delay(250);
  miniParada();
  robo.acionarMotores(70, 70);
  delay(430);
}
void Motores::pararAteBotao1(){
  parar();
  while(!robo.botao1Pressionado()){}
  toy.ledsAlerta(3);
}

void Motores::testarMovimentacao(){
  frente();
  delay(1000);
  parar();
  delay(1000);
  voltar();
  delay(1000);
  parar();
  delay(1000);
  girarEsq();
  delay(1000);
  parar();
  delay(1000);
  girarDir();
  delay(1000);
  parar();
  delay(1000);
  virarEsq();
  delay(1000);
  parar();
  delay(1000);
  virarDir();
  delay(1000);
  parar();
  delay(1000);
  voltarEsq();
  delay(1000);
  parar();
  delay(1000);
  voltarDir();
  delay(1000);
  parar();
  delay(1000);
}
void Motores::testar90Graus(){
  miniParada();
  girar90Esq();
}