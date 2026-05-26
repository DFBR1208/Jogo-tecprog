#include "Gerenciador_Colisoes.h"

Gerenciador_Colisoes::Gerenciador_Colisoes(Jogador* jogador, Inimigo* inimigo, Plataforma* plataforma) {
	pJogador = jogador;
	pInimigo = inimigo;
	pPlataforma = plataforma;
}

Gerenciador_Colisoes::~Gerenciador_Colisoes() {
}

const bool Gerenciador_Colisoes::verificarColisao(Entidade* pe1, Entidade* pe2) {
	return pe1->getForma().getGlobalBounds().intersects(pe2->getForma().getGlobalBounds());
}

void Gerenciador_Colisoes::tratarColisoes() {
	if (pJogador != nullptr && pInimigo != nullptr) {
		if (verificarColisao(pJogador, pInimigo)) {
			pInimigo->danificar(pJogador);
		}
	}

	if (pJogador != nullptr && pPlataforma != nullptr) {
		if (verificarColisao(pJogador, pPlataforma)) {
			pPlataforma->obstaculizar(pJogador);
		}
	}
}