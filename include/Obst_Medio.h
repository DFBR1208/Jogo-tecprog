#pragma once
#include "Obstaculo.h"

class Obst_Medio : public Obstaculo {
private:
    float largura;
public:
    Obst_Medio();
    Obst_Medio(float px, float py, float larg = 40.f);
    ~Obst_Medio();
    void obstaculizar(Jogador* p);
    void executar();
    void salvar();
};