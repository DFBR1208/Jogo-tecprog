#include "Pedrao.h"

namespace Kawabanga::Entidades::Personagens {
    Pedrao::Pedrao() : Inimigo(4), forca(1), pProj(nullptr), cooldownTiro(INTERVALO_TIRO) {
        nivel_maldade = 3;
        velocidadeX   = -1.2f;
        forma.setSize(sf::Vector2f(64.f, 64.f));
        forma.setFillColor(sf::Color::Red);
        if (pGG) {
            forma.setTexture(&pGG->getTexBoss());
        }
        pFig = new Figura(&forma);
    }

    Pedrao::Pedrao(float px, float py, int n_vid) : Inimigo(px, py, n_vid), forca(1), pProj(nullptr), cooldownTiro(INTERVALO_TIRO) {
        nivel_maldade = 3;
        velocidadeX   = -1.2f;
        forma.setSize(sf::Vector2f(64.f, 64.f));
        forma.setFillColor(sf::Color::Red);
        if (pGG) {
            forma.setTexture(&pGG->getTexBoss());
        }
        pFig = new Figura(&forma);
    }

    Pedrao::~Pedrao() {}

    void Pedrao::executar() {
        Inimigo::executar();
        sf::Vector2f pos  = forma.getPosition();
        sf::Vector2f size = forma.getSize();
        // tiro
        if (pProj) {
            cooldownTiro--;
            if (cooldownTiro <= 0) {
                cooldownTiro = INTERVALO_TIRO;
                float projX = (velocidadeX < 0) ? pos.x : pos.x + size.x;
                float projY = pos.y + size.y * 0.4f;
                float projVX = (velocidadeX < 0) ? -7.f : 7.f;
                pProj->atirar(projX, projY, projVX);
            }
        }
    }

    void Pedrao::danificar(Jogador* p) {
        if (!p) return;
        float xJogador = p->getForma().getPosition().x;
        bool knockback_direita = (xJogador > forma.getPosition().x);
        for (short i = 0; i <= forca; ++i)
            p->tomarDano(knockback_direita);
    }

    void Pedrao::salvarDataBuffer() {}
    void Pedrao::salva()            {}
    void Pedrao::salvar()           {}

    void Pedrao::tomarDano() {
        if (!tomandoDano) {
            num_vidas--;
            tomandoDano = true;
            timerDano.restart();
            forma.setFillColor(sf::Color::Blue);
        }
    }

    void Pedrao::setProjetil(Projetil* p) {
        pProj = p;
    }
}