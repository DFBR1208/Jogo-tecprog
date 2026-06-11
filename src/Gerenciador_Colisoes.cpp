#include "Gerenciador_Colisoes.h"

Gerenciador_Colisoes::Gerenciador_Colisoes(Jogador* pJogo1, Jogador* pJogo2) : pJog1(pJogo1), pJog2(pJogo2) {}

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
        if (ini && verificarColisao(pJog1, ini))
            ini->danificar(pJog1);
		if (ini && pJog2 && verificarColisao(pJog2, ini))
			ini->danificar(pJog2);
    }
}

void Gerenciador_Colisoes::tratarColisoesJogsObstacs() {
    for (Obstaculo* obs : LOs) {
        if (obs && verificarColisao(pJog1, obs))
            obs->obstaculizar(pJog1);
		if (obs && pJog2 && verificarColisao(pJog2, obs))
			obs->obstaculizar(pJog2);
    }
}

void Gerenciador_Colisoes::incluirProjetil(Projetil* pj) {
    LPs.insert(pj);
}

void Gerenciador_Colisoes::tratarColisoesJogsProjeteis() {
    for (Projetil* proj : LPs) {
        if (!proj || !proj->isAtivo()) continue;
        if (verificarColisao(pJog1, proj))
            pJog1->tomarDano();
        if (pJog2 && verificarColisao(pJog2, proj))
            pJog2->tomarDano();
    }
}

void Gerenciador_Colisoes::executar() {
    if (!pJog1) return;
    tratarColisoesJogsInimgs();
    tratarColisoesJogsObstacs();
    tratarColisoesJogsProjeteis();
}
