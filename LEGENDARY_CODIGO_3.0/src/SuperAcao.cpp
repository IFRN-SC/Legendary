#include "SuperAcao.h"

SuperAcao::SuperAcao(){
    //
}

void SuperAcao::alinheComPPPP(){
    boolean alinhamentoFinalizado = false;
    while(alinhamentoFinalizado == false){
        if(refletancia.bbbb()){
            motores.alinhamentoVoltar();
        } else if(refletancia.bbbp()){
            motores.alinhamentoVoltarEsq();
        } else if(refletancia.pbbb()){
            motores.alinhamentoVoltarDir();
        } else if(refletancia.bppb() || refletancia.pppp()){
            motores.parar();
            alinhamentoFinalizado = true;
        }
    }
}

void SuperAcao::alinheComBBBB(){
    boolean alinhamentoFinalizado = false;
    while(alinhamentoFinalizado == false){
        if(refletancia.bpbb()){
            motores.alinhamentoVoltarEsq();
        } else if(refletancia.bbpb()){
            motores.alinhamentoVoltarDir();
        } else if(refletancia.bbbb()){
            motores.alinhamentoVoltarEsq();
            alinhamentoFinalizado = true;
        }
    }
}

void SuperAcao::alinharObstaculo(){
    alinheComBBBB();
    motores.girar90Dir();
    alinheComPPPP();
}
