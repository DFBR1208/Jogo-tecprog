#include "Espinhos.h"

namespace Kawabanga::Entidades::Obstaculos {
    
    using namespace Personagens;
    Espinhos::Espinhos() : Obstaculo() {
        largura = 60.f;
        danoso  = true;
        forma.setSize(sf::Vector2f(largura, 20.f));
        forma.setFillColor(sf::Color(220, 50, 50));
    }

    Espinhos::Espinhos(float px, float py, float larg) : Obstaculo() {
        largura = larg;
        danoso  = true;
        forma.setSize(sf::Vector2f(largura, 20.f));
        if(pGG)
            forma.setTexture(&pGG->getTexObstaculo());
        forma.setPosition(px, py);
    }

    Espinhos::~Espinhos() {}

    void Espinhos::executar() {}

    void Espinhos::obstaculizar(Jogador* p) {
        if (p && danoso)
            p->tomarDano();
    }

    void Espinhos::salvar() {}
}