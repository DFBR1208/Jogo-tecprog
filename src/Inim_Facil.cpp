#include "Inim_Facil.h"

Inim_Facil::Inim_Facil() : Inimigo() {
    raio = 0.f;
    texBlink.loadFromFile("assests/enemy/Blink (42x42).png");
    spriteAnim.setTexture(texBlink);
    spriteAnim.setTextureRect(sf::IntRect(0, 0, FRAME_SIZE, FRAME_SIZE));
    pFig = new Figura(&spriteAnim);
}

Inim_Facil::Inim_Facil(float px, float py) : Inimigo(px, py) {
    raio = 0.f;
    texBlink.loadFromFile("assests/enemy/Blink (42x42).png");
    spriteAnim.setTexture(texBlink);
    spriteAnim.setTextureRect(sf::IntRect(0, 0, FRAME_SIZE, FRAME_SIZE));
    pFig = new Figura(&spriteAnim);
}

Inim_Facil::~Inim_Facil() {}

void Inim_Facil::executar() {
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

void Inim_Facil::salvar() {}
void Inim_Facil::salvarDataBuffer() {}
void Inim_Facil::salva() {}
