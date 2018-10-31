#include "SensoresRefletancia.h"

SensoresRefletancia::SensoresRefletancia(){
  pegarDadosEEPROM();
}

void SensoresRefletancia::start(){
  //
}

void SensoresRefletancia::alinheComPPPP(){
  boolean alinhamentoFinalizado = false;
  while(alinhamentoFinalizado == false){
      if(bbbb()){
          motores.alinhamentoVoltar();
      } else if(bbbp()){
          motores.alinhamentoVoltarEsq();
      } else if(pbbb()){
          motores.alinhamentoVoltarDir();
      } else if(bppb() || pppp()){
          motores.parar();
          alinhamentoFinalizado = true;
          break;
      }
  }
}

void SensoresRefletancia::alinheComPPNN(){
  boolean alinhamentoFinalizado = false;
  boolean realizandoBPNN = false;
  boolean realizandoPBNN = false;
  
  while(alinhamentoFinalizado == false){
    if(bbbb()){
      motores.alinhamentoVoltar();

    } else if(sensorMaisEsq('P') && sensorEsq('B')){
      realizandoBPNN = false;
      realizandoPBNN = true;
      robo.acionarMotores(18,-22);

    } else if(sensorMaisEsq('B') && sensorEsq('P')){
        realizandoBPNN = true;
        realizandoPBNN = false;
        robo.acionarMotores(-26, 20);

    } else if(sensorMaisEsq('P') && sensorEsq('P')){
      if(realizandoBPNN == true){
        delay(130);
        robo.acionarMotores(26, -20);
        delay(80);
        motores.parar();
      } else if(realizandoPBNN == true){
        delay(60);
        robo.acionarMotores(-18,22);
        delay(80);
        motores.parar();
      }
      
      alinhamentoFinalizado = true;
      break;
    }
  }
}

void SensoresRefletancia::alinheComNNPP(){
  boolean alinhamentoFinalizado = false;
  while(alinhamentoFinalizado == false){
    if(bbbb()){
      motores.alinhamentoVoltar();
    } else if(sensorDir('B') && sensorMaisDir('P')){
      motores.alinhamentoVoltarDir();
    } else if(sensorDir('P') && sensorMaisDir('B')){
      motores.miniFrenteCurva();
    } else if(sensorDir('P') && sensorMaisDir('P')){
      alinhamentoFinalizado = true;
      break;
    }
  }
}

void SensoresRefletancia::alinheComBBBB(){
  boolean alinhamentoFinalizado = false;
  boolean realizandoBPBB = false;
  boolean realizandoBBPB = false;
  while(alinhamentoFinalizado == false){
      if(bpbb()){
        motores.girarDevagarDir();
      } else if(bbpb()){
        motores.girarDevagarEsq();
      } else if(bbbb()){
        if(realizandoBPBB){
          motores.frearGiroDir();
        } else if (realizandoBBPB){
          motores.frearGiroEsq();
        }  
        alinhamentoFinalizado = true;
        break;
      }
  }
}

//Branco Branco Branco Branco (Andar para Frente)
boolean SensoresRefletancia::bbbb(){ return (sensorMaisEsq('B') && sensorEsq('B') && sensorDir('B') && sensorMaisDir('B'));}

//Branco Preto Branco Branco (Direita)
boolean SensoresRefletancia::bpbb(){ return (sensorMaisEsq('B') && sensorEsq('P') && sensorDir('B') && sensorMaisDir('B'));}

//Branco Branco Preto Branco (Esquerda)
boolean SensoresRefletancia::bbpb(){ return (sensorMaisEsq('B') && sensorEsq('B') && sensorDir('P') && sensorMaisDir('B'));}

//Branco Preto Preto Branco (Continuar ação anterior)
boolean SensoresRefletancia::bppb(){ return (sensorMaisEsq('B') && sensorEsq('P') && sensorDir('P') && sensorMaisDir('B'));}

//Preto Branco Branco Branco
boolean SensoresRefletancia::pbbb(){ return (sensorMaisEsq('P') && sensorEsq('B') && sensorDir('B') && sensorMaisDir('B'));}

//Branco Branco Branco Preto
boolean SensoresRefletancia::bbbp(){ return (sensorMaisEsq('B') && sensorEsq('B') && sensorDir('B') && sensorMaisDir('P'));}

//Branco Branco Preto Preto
boolean SensoresRefletancia::bbpp(){ return (sensorMaisEsq('B') && sensorEsq('B') && sensorDir('P') && sensorMaisDir('P'));}

//Preto Preto Branco Branco
boolean SensoresRefletancia::ppbb(){ return (sensorMaisEsq('P') && sensorEsq('P') && sensorDir('B') && sensorMaisDir('B'));}

//Branco Preto Preto Preto
boolean SensoresRefletancia::bppp(){ return (sensorMaisEsq('B') && sensorEsq('P') && sensorDir('P') && sensorMaisDir('P'));}

//Preto Preto Preto Branco
boolean SensoresRefletancia::pppb(){ return (sensorMaisEsq('P') && sensorEsq('P') && sensorDir('P') && sensorMaisDir('B'));}

//Preto Preto Preto Preto
boolean SensoresRefletancia::pppp(){ return (sensorMaisEsq('P') && sensorEsq('P') && sensorDir('P') && sensorMaisDir('P'));}

//Está vendo um Redutor?
boolean SensoresRefletancia::isOnRedutor(){ return (robo.lerSensorLinhaMaisDir() > corteRedutorMaisDir); }

//Verificador do Sensor Mais Esquerdo, 'P' para Preto e 'B' para Branco 
boolean SensoresRefletancia::sensorMaisEsq(char entrada){
  boolean resposta;
  switch(entrada){
    case 'P':
      if(robo.lerSensorLinhaMaisEsq() < cinzaMaisEsq){
        resposta = true;
      }else{
        resposta = false;
      }
      break;   
    case 'B':
      if((robo.lerSensorLinhaMaisEsq() > cinzaMaisEsq)){
        resposta = true;
      }else{
        resposta = false;
      }
      break;  
  }
  return resposta;
}

//Verificador do Sensor Esquerdo, 'P' para Preto e 'B' para Branco 
boolean SensoresRefletancia::sensorEsq(char entrada){
  boolean resposta;
  switch(entrada){
    case 'P':
      if(robo.lerSensorLinhaEsq() < cinzaEsq){
        resposta = true;
      }else{
        resposta = false;
      }
      break;   
    case 'B':
      if((robo.lerSensorLinhaEsq() > cinzaEsq) && (robo.lerSensorLinhaEsq() < corteRedutorEsq)){
        resposta = true;
      }else{
        resposta = false;
      }
      break;  
  }
  return resposta;
}

//Verificador do Sensor Direito, 'P' para Preto e 'B' para Branco 
boolean SensoresRefletancia::sensorDir(char entrada){
  boolean resposta;
  switch(entrada){
    case 'P':
      if(robo.lerSensorLinhaDir() < cinzaDir){
        resposta = true;
      }else{
        resposta = false;
      }
      break;   
    case 'B':
      if(robo.lerSensorLinhaDir() > cinzaDir){
        resposta = true;
      }else{
        resposta = false;
      }
      break;  
  }
  return resposta;
}

//Verificador do Sensor Mais Direito, 'P' para Preto e 'B' para Branco 
boolean SensoresRefletancia::sensorMaisDir(char entrada){
  boolean resposta;
  switch(entrada){
    case 'P':
      if(robo.lerSensorLinhaMaisDir() < cinzaMaisDir){
        resposta = true;
      }else{
        resposta = false;
      }
      break;   
    case 'B':
      if(robo.lerSensorLinhaMaisDir() > cinzaMaisDir){
        resposta = true;
      }else{
        resposta = false;
      }
      break;  
  }
  return resposta;
}

void SensoresRefletancia::printSensoresDeRefletancia(){
            
  Serial.print(F("Sensores refletancia: +esq; esq; dir; +dir "));
  valorCapturado = robo.lerSensorLinhaMaisEsq();
  Serial.print(valorCapturado);
  Serial.print(F("; "));
  
  valorCapturado = robo.lerSensorLinhaEsq();
  Serial.print(valorCapturado);
  
  Serial.print(F("; "));
  valorCapturado = robo.lerSensorLinhaDir();
  
  Serial.print(valorCapturado);
  Serial.print(F("; "));
  
  valorCapturado = robo.lerSensorLinhaMaisDir();
  Serial.println(valorCapturado);
}

void SensoresRefletancia::pegarDadosEEPROM(){
  robo.lerCalibracao(val);
  
  cinzaMaisEsq = val.refletanciaMaisEsq;
  cinzaEsq = val.refletanciaEsq;
  cinzaDir = val.refletanciaDir;
  cinzaMaisDir = val.refletanciaMaisDir;

/*
  corteRedutorMaisEsq = val.superBrancoMaisEsq;
  corteRedutorEsq = val.superBrancoEsq;
  corteRedutorDir = val.superBrancoDir;
  corteRedutorMaisDir = val.superBrancoMaisDir;
*/
}