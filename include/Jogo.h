#pragma once
#include "Gerenciador_Grafico.h"
#include "FasePrimeira.h"
#include "Jogador.h"

class Jogo {
private:
    Gerenciador_Grafico* GG;
	Jogador* pJog1;
    FasePrimeira* pFase;
public:
    Jogo();
    ~Jogo();
    void executar();
};