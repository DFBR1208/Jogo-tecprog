#include "Inimigo.h"


Inimigo::Inimigo() : Personagem() {
    nivel_maldade = 1;
    velocidadeX   = -2.0f;
    frameAtual    = 0;
    temporizador  = 0;
    forma.setSize(sf::Vector2f(42.f, 42.f));
    forma.setFillColor(sf::Color::Transparent);
    forma.setPosition(700.f, 508.f);
}

Inimigo::Inimigo(float px, float py) : Personagem() {
    nivel_maldade = 1;
    velocidadeX   = -2.0f;
    frameAtual    = 0;
    temporizador  = 0;
    forma.setSize(sf::Vector2f(42.f, 42.f));
    forma.setFillColor(sf::Color::Transparent);
    forma.setPosition(px, py);
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
    if (p != nullptr){
        float xJogador=p->getForma().getPosition().x;
        bool knockback_direita = (bool)(xJogador>forma.getPosition().x);
        p->tomarDano(knockback_direita);
    }
}

sf::FloatRect Inimigo::getBounds() const {
    return forma.getGlobalBounds();
}
