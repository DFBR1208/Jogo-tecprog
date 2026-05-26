#pragma once
#include "Ente.h"
#include "Jogador.h"

class Fase : public Ente {
protected:
    Jogador* pJogador;
public:
    Fase();
    virtual ~Fase();
    virtual void executar() = 0;
};