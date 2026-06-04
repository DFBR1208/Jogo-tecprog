#pragma once
#include "Gerenciador_Grafico.h"
#include "FasePrimeira.h"

class Menu;

class Jogo {
private:
    Gerenciador_Grafico* pGrafico;
    FasePrimeira*        pFase;
    Menu*                pMenu;
public:
    Jogo();
    ~Jogo();
    void executar();
    int getVidas()  const;
    int getPontos() const;
};
