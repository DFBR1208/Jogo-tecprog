#include "Obst_Medio.h"

Obst_Medio::Obst_Medio() : Obstaculo() {
    largura = 60.f;
    danoso  = true;
    forma.setSize(sf::Vector2f(largura, 20.f));
    forma.setFillColor(sf::Color(220, 50, 50));
}

Obst_Medio::Obst_Medio(float px, float py, float larg) : Obstaculo() {
    largura = larg;
    danoso  = true;
    forma.setSize(sf::Vector2f(largura, 20.f));
    if(pGG)
        forma.setTexture(&pGG->getTexObstaculo());
    forma.setPosition(px, py);
}

Obst_Medio::~Obst_Medio() {}

void Obst_Medio::executar() {}

void Obst_Medio::obstaculizar(Jogador* p) {
    if (p && danoso)
        p->tomarDano();
}

void Obst_Medio::salvar() {}
