#include "Jogo.h"
#include "Ente.h"

Jogo::Jogo() : GG(new Gerenciador_Grafico()), pJog1(new Jogador()), pFase(new FasePrimeira(pJog1)), pMenu(new Menu(this))  {
    Ente::setGerenciadorGrafico(GG);
}

Jogo::~Jogo() {
    delete pFase;
    delete GG;
    delete pJog1;
    delete pMenu;
}

void Jogo::executar() {
    while (GG->verificaJanelaAberta()) {

        GG->limpar();

        pMenu->executar();

        pMenu->desenhar(); 

        GG->mostrar();
    }
}

void Jogo::iniciarFase1() {
	while (GG->verificaJanelaAberta()) {
		GG->limpar();
		pFase->executar();
		pFase->desenhar();
		GG->mostrar();
	}
}