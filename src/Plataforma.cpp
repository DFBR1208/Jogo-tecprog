#include "Plataforma.h"
#include <algorithm>

Plataforma::Plataforma() : Obstaculo() {
	danoso = false;

	forma.setSize(sf::Vector2f(200.f, 30.f));
	forma.setFillColor(sf::Color::White);
	forma.setPosition(300.f, 450.f);
}

Plataforma::Plataforma(float px, float py, float largura) : Obstaculo() {
    danoso = false;
    forma.setSize(sf::Vector2f(largura, 30.f));
    forma.setFillColor(sf::Color::White);
    forma.setPosition(px, py);
}

Plataforma::~Plataforma() {}

void Plataforma::executar() {}
void Plataforma::salvar() {}

void Plataforma::obstaculizar(Jogador* p) {
    if (p == nullptr) return;

    sf::FloatRect pBounds  = p->getBounds();
    sf::FloatRect plBounds = forma.getGlobalBounds();

    float overlapTop    = (pBounds.top + pBounds.height) - plBounds.top;
    float overlapBottom = (plBounds.top + plBounds.height) - pBounds.top;
    float overlapLeft   = (pBounds.left + pBounds.width) - plBounds.left;
    float overlapRight  = (plBounds.left + plBounds.width) - pBounds.left;

    float minOverlapV = std::min(overlapTop, overlapBottom);
    float minOverlapH = std::min(overlapLeft, overlapRight);

    if (minOverlapV < minOverlapH) {
        if (overlapTop < overlapBottom && p->getVelocidadeY() >= 0.f)
            p->pararNoChao(plBounds.top);
        else if (overlapBottom < overlapTop && p->getVelocidadeY() < 0.f)
            p->baterCabeca(plBounds.top + plBounds.height);
    }
}