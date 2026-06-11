#pragma once
#include "Gerenciador_Grafico.h"
#include "FasePrimeira.h"
#include "FaseSegunda.h"
#include "Jogador.h"
#include "Menu.h"
#include "HUD.h"

class Menu;

class Jogo {
private:
    Gerenciador_Grafico* GG;
    Jogador*      pJog1;
    Jogador*      pJog2;
    FasePrimeira* pFase1;
    FaseSegunda*  pFase2;
    Menu*         pMenu;
    HUD*          pHUD;
public:
    Jogo();
    ~Jogo();
    void executar();
    void iniciarFase1(int n_jogs);
    void iniciarFase2(int n_jogs);
};
