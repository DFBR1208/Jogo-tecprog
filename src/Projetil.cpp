#include "Projetil.h"

Projetil::Projetil() : Entidade(), ativo(false), velocidadeX(0.f) {
    forma.setSize(sf::Vector2f(10.f, 5.f));
    forma.setFillColor(sf::Color::Yellow);
    forma.setPosition(-100.f, -100.f);
    pFig = new Figura(&forma);
}

Projetil::Projetil(float px, float py, float vx)
    : Entidade(), ativo(true), velocidadeX(vx) {
    forma.setSize(sf::Vector2f(10.f, 5.f));
    forma.setFillColor(sf::Color::Yellow);
    forma.setPosition(px, py);
    pFig = new Figura(&forma);
}

Projetil::~Projetil() {}

void Projetil::executar() {
    if (!ativo) return;
    gravitar();
    forma.move(velocidadeX, velocidadeY);
    sf::Vector2f pos = forma.getPosition();
    if (pos.x < -50.f || pos.x > 2000.f || pos.y > 900.f)
        ativo = false;
}

void Projetil::salvar() {}

sf::FloatRect Projetil::getBounds() const {
    if (!ativo) return sf::FloatRect(-1000.f, -1000.f, 0.f, 0.f);
    return forma.getGlobalBounds();
}

void Projetil::atirar(float px, float py, float vx) {
    forma.setPosition(px, py);
    velocidadeX = vx;
    velocidadeY = 0.f;
    ativo = true;
}
