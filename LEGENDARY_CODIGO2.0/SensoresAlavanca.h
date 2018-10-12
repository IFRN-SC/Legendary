#ifndef SENSORESALAVANCA_H
#define SENSORESALAVANCA_H

#include <robo_hardware2.h>
#include "Toy.h"

class SensoresAlavanca{
  public:
    SensoresAlavanca();
    void start();
    bool alavancaEsq();
    bool alavancaDir();
    
    void testarSensoresAlavanca();
  private:
    Toy toy;
};

#endif

