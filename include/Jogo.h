#pragma once
#include "Gerenciador_Grafico.h"
#include "FasePrimeira.h"
#include "Jogador.h"
#include "Menu.h"
#include "HUD.h"

class Menu;

class Jogo {
private:
    Gerenciador_Grafico* GG;
	Jogador* pJog1;
	Jogador* pJog2;
    FasePrimeira* pFase;
    Menu* pMenu;
	HUD* pHUD;
public:
    Jogo();
    ~Jogo();
    void executar();
	void iniciarFase1(int n_jogs);
};
