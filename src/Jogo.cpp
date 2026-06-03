#include "Jogo.h"
#include "Ente.h"

Jogo::Jogo() : GG(new Gerenciador_Grafico()), pJog1(new Jogador()), pFase(new FasePrimeira(pJog1))  {
    Ente::setGerenciadorGrafico(GG);
}

Jogo::~Jogo() {
    delete pFase;
    delete GG;
    delete pJog1;
}

void Jogo::executar() {
    while (GG->verificaJanelaAberta()) {

        GG->limpar();

        pFase->executar();

        pFase->desenhar(); 

        GG->mostrar();
    }
}