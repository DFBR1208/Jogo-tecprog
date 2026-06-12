#include "Obst_Dificil.h"

Obst_Dificil::Obst_Dificil() : Obstaculo() {
    danosidade = 2;
    danoso = true;
    forma.setSize(sf::Vector2f(30.f, 30.f));
    forma.setFillColor(sf::Color(180, 0, 200));
}

Obst_Dificil::Obst_Dificil(float px, float py, float lado) : Obstaculo() {
    danosidade = 2;
    danoso = true;
    forma.setSize(sf::Vector2f(lado, lado));
    forma.setFillColor(sf::Color(180, 0, 200));
    if (pGG)
        forma.setTexture(&pGG->getTexObstaculoD());
    forma.setPosition(px, py);
}

Obst_Dificil::~Obst_Dificil() {}

void Obst_Dificil::executar() {}

void Obst_Dificil::obstaculizar(Jogador* p) {
    if (!p || !danoso) return;
    for (short i = 0; i < danosidade; ++i)
        p->tomarDano();
}

void Obst_Dificil::salvar() {}
void Obst_Dificil::salvarDataBuffer() {}
