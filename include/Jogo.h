#pragma once
#include "Gerenciador_Grafico.h"
#include "FasePrimeira.h"
#include "Jogador.h"

class Menu;

class Jogo {
private:
    Gerenciador_Grafico* GG;
    Jogador*             pJog1;
    FasePrimeira*        pFase;
    Menu*                pMenu;
public:
    Jogo();
    ~Jogo();
    void executar();
    int getVidas()  const;
    int getPontos() const;
};
