#include "Jogo.h"
#include "Menu.h"
#include "Ente.h"

Jogo::Jogo() : GG(new Gerenciador_Grafico()), pJog1(new Jogador()), pFase(new FasePrimeira(pJog1)) {
    Ente::setGerenciadorGrafico(GG);
    pMenu = new Menu(this);
}

Jogo::~Jogo() {
    delete pMenu;
    delete pFase;
    delete GG;
    delete pJog1;
}

int Jogo::getVidas()  const { return pFase->getVidas(); }
int Jogo::getPontos() const { return pFase->getPontos(); }

void Jogo::executar() {
    while (GG->verificaJanelaAberta()) {
        GG->limpar();
        pFase->executar();
        pMenu->executar();
        pFase->desenhar();
        pMenu->desenhar();
        GG->mostrar();
    }
}
