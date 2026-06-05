#include "Jogo.h"
#include "Ente.h"

Jogo::Jogo() : GG(new Gerenciador_Grafico()), pJog1(nullptr), pJog2(nullptr), pFase(nullptr), pMenu(new Menu(this)) {
    Ente::setGerenciadorGrafico(GG);
}

Jogo::~Jogo() {
    delete pFase;
    delete GG;
    delete pJog1;
    delete pJog2;
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

void Jogo::iniciarFase1(int n_jogs) {
	if (n_jogs == 1) {
		pJog1 = new Jogador(true);
		pFase = new FasePrimeira(pJog1, nullptr);
	}
	else if (n_jogs == 2) {
		pJog1 = new Jogador(true);
		pJog2 = new Jogador(false);
		pFase = new FasePrimeira(pJog1, pJog2);
	}
	else {
		return;
	}
	while (GG->verificaJanelaAberta()) {
		GG->limpar();
		pFase->executar();
		pFase->desenhar();
		GG->mostrar();
	}
}