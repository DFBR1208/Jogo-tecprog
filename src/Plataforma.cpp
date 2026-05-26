#include "Plataforma.h"

Plataforma::Plataforma() : Obstaculo() {
	danoso = false;

	forma.setSize(sf::Vector2f(200.f, 30.f));
	forma.setFillColor(sf::Color::White);
	forma.setPosition(300.f, 450.f);
}

Plataforma::~Plataforma() {}

void Plataforma::executar() {

}

void Plataforma::obstaculizar(Jogador* p) {
	if (p != nullptr) {
		if (p->getVelocidadeY() > 0.0f) {
			p->pararNoChao(forma.getPosition().y);
		}
		else if (p->getVelocidadeY() < 0.0f) {
			float base_plataforma = forma.getPosition().y + forma.getSize().y;
			p->baterCabeca(base_plataforma);
		}
	}
}