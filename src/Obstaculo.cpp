#include "Obstaculo.h"

namespace Kawabanga::Entidades::Obstaculos {
    Obstaculo::Obstaculo() : Entidade() {
        danoso = false;
        pFig = new Figura(&forma);
    }

    Obstaculo::~Obstaculo() {}

    sf::FloatRect Obstaculo::getBounds() const {
        return forma.getGlobalBounds();
    }
}