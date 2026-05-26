#pragma once
#include "Gerenciador_Grafico.h"
#include "FasePrimeira.h"

class Jogo {
private:
    Gerenciador_Grafico* pGrafico;
    FasePrimeira* pFase;
public:
    Jogo();
    ~Jogo();
    void executar();
};