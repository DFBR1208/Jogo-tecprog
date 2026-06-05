#pragma once
#include "Gerenciador_Grafico.h"
#include "FasePrimeira.h"
#include "Jogador.h"
#include "MenuInicial.h"
#include "HUD.h"

class Menu;

class Jogo {
private:
    Gerenciador_Grafico* GG;
	Jogador* pJog1;
	Jogador* pJog2;
    FasePrimeira* pFase;
    MenuInicial* pMenuIni;
	HUD* pHUD;
public:
    Jogo();
    ~Jogo();
    void executar();
	void iniciarFase1(int n_jogs);
    int getVidas()  const;
    int getPontos() const;
};
