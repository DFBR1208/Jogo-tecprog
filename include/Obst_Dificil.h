#pragma once 
#include "Obstaculo.h"

class Obst_Dificil : public Obstaculo
{
    private:
    short int danosidade;

    public: 
    Obst_Dificil();
    ~Obst_Dificil();
    void salvarDataBuffer();
    void executar();
    void obstaculizar(Jogador* p);
};