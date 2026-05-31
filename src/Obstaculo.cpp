#include "Obstaculo.h"

Obstaculo::Obstaculo() : Entidade() {
	danoso = false;
}

Obstaculo::~Obstaculo() {}

void Obstaculo::desenhar() {
    if (pGG) pGG->desenhar(forma);
}

sf::FloatRect Obstaculo::getBounds() const {
    return forma.getGlobalBounds();
}