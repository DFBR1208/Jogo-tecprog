#include "Jogo.h"
#include "Ente.h"

Jogo::Jogo() {
    pGrafico = new Gerenciador_Grafico();
    Ente::setGerenciadorGrafico(pGrafico);
    pFase = new FasePrimeira();
}

Jogo::~Jogo() {
    delete pFase;
    delete pGrafico;
}

void Jogo::executar() {
    while (pGrafico->verificaJanelaAberta()) {

        pGrafico->limpar();

        pFase->executar();

        pFase->desenhar(); 

        pGrafico->mostrar();
    }
}