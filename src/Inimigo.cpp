#include "Inimigo.h"

Inimigo::Inimigo() : Personagem() {
	nivel_maldade = 1;
	velocidadeX = -2.0f;

	forma.setSize(sf::Vector2f(30.f, 50.f));
	forma.setFillColor(sf::Color::Red);
	forma.setPosition(700.f, 500.f);
}

Inimigo::~Inimigo() {}

void Inimigo::executar() {
	mover();
}

void Inimigo::mover() {
	forma.move(velocidadeX, 0.f);
	if (forma.getPosition().x <= 0.f || forma.getPosition().x >= 760.f) {
		velocidadeX = -velocidadeX;
	}
}

void Inimigo::danificar(Jogador* p) {
	if (p != nullptr) {
		float xJogador=p->getForma().getPosition().x;
		bool knockback_direita = (xJogador>forma.getPosition().x);
		p->tomarDano(knockback_direita);
	}
}
