#ifndef SENSORES_H
#define SENSORES_H

#include <robo_hardware2.h>
#include <Servo.h>

class Sensores{
  public:
    Sensores();
    void start();
    boolean bbbb();
    boolean bbbp();
    boolean pbbb();
    boolean bbpp();
    boolean ppbb();
    boolean bppp();
    boolean pppb();
    boolean bbpb();
    boolean bpbb(); 
    boolean bppb();
    boolean pppp();
    
    float cinzaMaisEsq;
    float cinzaEsq;
    float cinzaDir;
    float cinzaMaisDir;
    
  private:
    calibracao_dados val;
};

#endif
