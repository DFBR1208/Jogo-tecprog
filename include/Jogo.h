#pragma once
#include "Gerenciador_Grafico.h"
#include "FasePrimeira.h"
#include "Jogador.h"
#include "Menu.h"

class Jogo {
private:
    Gerenciador_Grafico* GG;
	Jogador* pJog1;
	Jogador* pJog2;
    FasePrimeira* pFase;
    Menu* pMenu;
public:
    Jogo();
    ~Jogo();
    void executar();
	void iniciarFase1(int n_jogs);
};