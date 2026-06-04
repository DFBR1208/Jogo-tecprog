#include "Jogo.h"
#include "Menu.h"
#include "Ente.h"

Jogo::Jogo() {
    pGrafico = new Gerenciador_Grafico();
    Ente::setGerenciadorGrafico(pGrafico);
    pFase = new FasePrimeira();
    pMenu = new Menu(this);
}

Jogo::~Jogo() {
    delete pMenu;
    delete pFase;
    delete pGrafico;
}

int Jogo::getVidas()  const { return pFase->getVidas(); }
int Jogo::getPontos() const { return pFase->getPontos(); }

void Jogo::executar() {
    while (pGrafico->verificaJanelaAberta()) {
        pGrafico->limpar();
        pFase->executar();
        pMenu->executar();
        pFase->desenhar();
        pMenu->desenhar();
        pGrafico->mostrar();
    }
}
