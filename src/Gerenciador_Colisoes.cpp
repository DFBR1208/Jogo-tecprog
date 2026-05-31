#include "Gerenciador_Colisoes.h"

Gerenciador_Colisoes::Gerenciador_Colisoes(Jogador* pJog) : pJogador(pJog) {}

Gerenciador_Colisoes::~Gerenciador_Colisoes() {}

void Gerenciador_Colisoes::incluirInimigo(Inimigo* pi) {
    LIs.push_back(pi);
}

void Gerenciador_Colisoes::incluirObstaculo(Obstaculo* po) {
    LOs.push_back(po);
}

const bool Gerenciador_Colisoes::verificarColisao(Entidade* pe1, Entidade* pe2) {
    return pe1->getBounds().intersects(pe2->getBounds());
}

void Gerenciador_Colisoes::tratarColisoesJogsInimgs() {
    for (Inimigo* ini : LIs) {
        if (ini && verificarColisao(pJogador, ini))
            ini->danificar(pJogador);
    }
}

void Gerenciador_Colisoes::tratarColisoesJogsObstacs() {
    for (Obstaculo* obs : LOs) {
        if (obs && verificarColisao(pJogador, obs))
            obs->obstaculizar(pJogador);
    }
}

void Gerenciador_Colisoes::executar() {
    if (!pJogador) return;
    tratarColisoesJogsInimgs();
    tratarColisoesJogsObstacs();
}
