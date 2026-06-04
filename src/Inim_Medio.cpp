#include "Inim_Medio.h"

Inim_Medio::Inim_Medio() : Inimigo() {
    tamanho       = 52;
    nivel_maldade = 2;
    velocidadeX   = -3.5f;
    forma.setSize(sf::Vector2f((float)tamanho, (float)tamanho));
    forma.setFillColor(sf::Color(210, 80, 30));
}

Inim_Medio::Inim_Medio(float px, float py) : Inimigo(px, py) {
    tamanho       = 52;
    nivel_maldade = 2;
    velocidadeX   = -3.5f;
    forma.setSize(sf::Vector2f((float)tamanho, (float)tamanho));
    forma.setFillColor(sf::Color(210, 80, 30));
}

Inim_Medio::~Inim_Medio() {}

void Inim_Medio::desenhar() {
    if (!pGG) return;
    pGG->desenhar(forma);
}

void Inim_Medio::danificar(Jogador* p) {
    if (!p) return;
    p->tomarDano();
    p->tomarDano();
}

void Inim_Medio::salvarDataBuffer() {}
void Inim_Medio::salva() {}
