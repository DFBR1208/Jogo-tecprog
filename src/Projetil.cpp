#include "Projetil.h"
#include "Pedrao.h"

namespace Kawabanga::Entidades {
    using namespace Personagens;
    Projetil::Projetil() : Entidade(), ativo(false), velocidadeX(0.f) {
        forma.setSize(sf::Vector2f(20.f, 15.f));
        forma.setPosition(-100.f, -100.f);
        if (pGG) {
            forma.setTexture(&pGG->getTexProjetil());
        }
        pFig = new Figura(&forma);
    }

    Projetil::Projetil(float px, float py, float vx)
        : Entidade(), ativo(true), velocidadeX(vx) {
        forma.setSize(sf::Vector2f(20.f, 15.f));
        forma.setPosition(px, py);
        if (pGG) {
            forma.setTexture(&pGG->getTexProjetil());
        }
        pFig = new Figura(&forma);
    }

    Projetil::~Projetil() {}

    void Projetil::executar() {
        if (!ativo) return;
        gravitar();
        forma.move(velocidadeX, velocidadeY);
        sf::Vector2f pos = forma.getPosition();
        if (pos.x < -50.f || pos.x > 3700.f || pos.y > 2600.f)
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

    bool Projetil::isAtivo() const {
        return ativo;
    }

    void Projetil::setChefao(Pedrao* ch) {
        pChefao = ch;
    }

    Pedrao* Projetil::getChefao() const {
        return pChefao;
    }
}