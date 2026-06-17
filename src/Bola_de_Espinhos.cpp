#include "Bola_de_Espinhos.h"

namespace Kawabanga::Entidades::Obstaculos {
    using namespace Personagens;
    Bola_de_Espinhos::Bola_de_Espinhos() : Obstaculo() {
        danosidade = 2;
        danoso = true;
        forma.setSize(sf::Vector2f(30.f, 30.f));
        forma.setFillColor(sf::Color(180, 0, 200));
    }

    Bola_de_Espinhos::Bola_de_Espinhos(float px, float py, float lado) : Obstaculo() {
        danosidade = 2;
        danoso = true;
        forma.setSize(sf::Vector2f(lado, lado));
        forma.setFillColor(sf::Color(180, 0, 200));
        if (pGG)
            forma.setTexture(&pGG->getTexObstaculoD());
        forma.setPosition(px, py);
    }

    Bola_de_Espinhos::~Bola_de_Espinhos() {}

    void Bola_de_Espinhos::executar() {
        gravitar();
        antiGravitar();
    }

    void Bola_de_Espinhos::obstaculizar(Jogador* p) {
        if (!p || !danoso) return;
        for (short i = 0; i < danosidade; ++i)
            p->tomarDano();
    }

    void Bola_de_Espinhos::salvar() {}
    void Bola_de_Espinhos::salvarDataBuffer() {}
}