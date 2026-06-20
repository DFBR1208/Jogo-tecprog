#pragma once
#include "Gerenciador_Grafico.h"
#include "FasePrimeira.h"
#include "FaseSegunda.h"
#include "Jogador.h"
#include "Menu.h"
#include "HUD.h"

namespace Kawabanga {
    class Menu;
    enum EstadoJogo { JOGO_INICIO, JOGO_FASE1, JOGO_FASE2, JOGO_MENUGERAL};
    //Uso de enum para controle de estado do jogo baseado no vídeo de "The Cherno" e "SIMPLECODE", conforme dito no relatório 
    class Jogo {
    private:
        Gerenciadores::Gerenciador_Grafico* GG;
        Entidades::Personagens::Jogador*      pJog1;
        Entidades::Personagens::Jogador*      pJog2;
        Fases::FasePrimeira* pFase1;
        Fases::FaseSegunda*  pFase2;
        Menu*         pMenu;
        HUD*          pHUD;
        EstadoJogo     estadoAtual;
        EstadoJogo faseAtual;
    public:
        Jogo();
        ~Jogo();
        void executar();
        void iniciarFase1(int n_jogs);
        void iniciarFase2(int n_jogs);
        void setEstado(EstadoJogo novoEstado);
        EstadoJogo getFaseAtual();
        Entidades::Personagens::Jogador* getpJog1();
        Entidades::Personagens::Jogador* getpJog2();
    };
}