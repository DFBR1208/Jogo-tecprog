#include "Pedroso.h"

namespace Kawabanga::Entidades::Personagens {
    Pedroso::Pedroso() : Inimigo(2) {
        raio = 0.f;
        texBlink.loadFromFile("assets/enemy/Blink (42x42).png");
        spriteAnim.setTexture(texBlink);
        spriteAnim.setTextureRect(sf::IntRect(0, 0, FRAME_SIZE, FRAME_SIZE));
        pFig = new Figura(&spriteAnim);
    }

    Pedroso::Pedroso(float px, float py, int n_vid) : Inimigo(px, py, n_vid) {
        raio = 0.f;
        texBlink.loadFromFile("assets/enemy/Blink (42x42).png");
        spriteAnim.setTexture(texBlink);
        spriteAnim.setTextureRect(sf::IntRect(0, 0, FRAME_SIZE, FRAME_SIZE));
        pFig = new Figura(&spriteAnim);
    }

    Pedroso::~Pedroso() {}

    void Pedroso::executar() {
        Inimigo::executar();

        temporizador++;
        if (temporizador >= DURACAO_FRAME) {
            temporizador = 0;
            frameAtual   = (frameAtual + 1) % TOTAL_FRAMES;
        }
        spriteAnim.setTextureRect(sf::IntRect(frameAtual * FRAME_SIZE, 0, FRAME_SIZE, FRAME_SIZE));

        sf::Vector2f pos  = forma.getPosition();
        sf::Vector2f size = forma.getSize();
        if (velocidadeX > 0) {
            spriteAnim.setScale(-1.f, 1.f);
            spriteAnim.setPosition(pos.x + size.x, pos.y);
        } else {
            spriteAnim.setScale(1.f, 1.f);
            spriteAnim.setPosition(pos.x, pos.y);
        }
    }

    void Pedroso::danificar(Jogador* p) {
        if (p) {
            float xJogador = p->getForma().getPosition().x;
            bool knockback_direita = (xJogador > forma.getPosition().x);
            p->tomarDano(knockback_direita);
        }
    }

    void Pedroso::salvar() {}
    void Pedroso::salvarDataBuffer() {}
    void Pedroso::salva() {}
}