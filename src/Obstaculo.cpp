#include "Obstaculo.h"

Obstaculo::Obstaculo() : Entidade() {
    danoso = false;
    pFig = new Figura(&forma);
}

Obstaculo::~Obstaculo() {}

sf::FloatRect Obstaculo::getBounds() const {
    return forma.getGlobalBounds();
}
