#pragma once
#include "Gerenciador_Grafico.h"
#include "FasePrimeira.h"
#include "FaseSegunda.h"
#include "Jogador.h"
#include "Menu.h"
#include "HUD.h"

namespace Kawabanga {
    class Menu;
    class Jogo {
    private:
        Gerenciadores::Gerenciador_Grafico* GG;
        Entidades::Personagens::Jogador*      pJog1;
        Entidades::Personagens::Jogador*      pJog2;
        Fases::FasePrimeira* pFase1;
        Fases::FaseSegunda*  pFase2;
        Menu*         pMenu;
        HUD*          pHUD;
    public:
        Jogo();
        ~Jogo();
        void executar();
        void iniciarFase1(int n_jogs);
        void iniciarFase2(int n_jogs);
    };
}