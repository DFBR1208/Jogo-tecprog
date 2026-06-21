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

    void Obstaculo::antiGravitar() {
        velocidadeY -= gravidade;
    }

    void Obstaculo::salvarDataBuffer() {
        Entidade::salvarDataBuffer();
        buffer<<(danoso?1:0)<<" ";
    }

    void Obstaculo::carregarDataBuffer(std::stringstream& ss) {
        Entidade::carregarDataBuffer(ss);
        int leuDanoso;
        ss>>leuDanoso;
        danoso=(bool)leuDanoso;
    }
}