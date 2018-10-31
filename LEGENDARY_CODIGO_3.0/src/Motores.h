#ifndef MOTORES_H
#define MOTORES_H

#include <robo_hardware2.h>
#include "Toy.h"

class Motores{
  public:
    Motores();

    //Movimentos Padrões
    void frente();
    void voltar();
    void parar();
    void girarEsq();
    void girarDir();
    void virarEsq();
    void virarDir();
    void voltarEsq();
    void voltarDir();
    
    //Movimentos Devagar
    void frenteDevagar();
    void voltarDevagar();
    void girarDevagarEsq();
    void girarDevagarDir();
    void virarDevagarEsq();
    void virarDevagarDir();
    void voltarDevagarEsq();
    void voltarDevagarDir();

    //Movimentos Mais leves
    void giroLeveEsq();
    void giroLeveDir();

    //Movimentos Curva
    void miniFrenteCurva();
    void voltarCurva();
    void giroCurvaEsq();
    void giroCurvaDir();

    //Movimentos para Alinhamento
    void alinhamentoFrente();
    void alinhamentoVoltar();
    void alinhamentoVirarEsq();
    void alinhamentoVirarDir();
    void alinhamentoVoltarEsq();
    void alinhamentoVoltarDir();

    //Movimentos de 90 Graus
    void girar90Esq();
    void girar90Dir();

    //Movimentos para Desviar Obstaculo
    void frenteDesviarObstaculo();
    void voltarDesviarObstaculo();

    //Movimentos para a Rampa
    void frenteRampa();
    void superFrenteRampa();
    void girarEsqRampa();
    void girarDirRampa();
    void pararRampa();

    //Movimentos de Freio
    void frear();
    void frearVoltar();
    void frearGiroEsq();
    void frearGiroDir();
    void frearVirarEsq();
    void frearVirarDir();
    void frearVoltarEsq();
    void frearVoltarDir();

    //Movimentos Especificos
    void miniParada();
    void miniGiroEsq();
    void miniGiroDir();
    void acaoRedutor();
    void pararAteBotao1();
    void testarMovimentacao();
    void testar90Graus();

  private:
    Toy toy;
};

#endif

/*
COMANDOS PARA TESTES:
*/
