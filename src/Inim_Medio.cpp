#include "Inim_Medio.h"

Inim_Medio::Inim_Medio() : Inimigo() {
    tamanho       = 52;
    nivel_maldade = 2;
    velocidadeX   = -3.5f;
    forma.setSize(sf::Vector2f((float)tamanho, (float)tamanho));
    texBlink.loadFromFile("assests/enemy/Blink (42x42).png");
    spriteAnim.setTexture(texBlink);
    spriteAnim.setTextureRect(sf::IntRect(0, 0, FRAME_SIZE, FRAME_SIZE));
    spriteAnim.setColor(sf::Color::Yellow);
    pFig = new Figura(&spriteAnim);
}

Inim_Medio::Inim_Medio(float px, float py) : Inimigo(px, py) {
    tamanho       = 52;
    nivel_maldade = 2;
    velocidadeX   = -3.5f;
    forma.setSize(sf::Vector2f((float)tamanho, (float)tamanho));
    texBlink.loadFromFile("assests/enemy/Blink (42x42).png");
    spriteAnim.setTexture(texBlink);
    spriteAnim.setTextureRect(sf::IntRect(0, 0, FRAME_SIZE, FRAME_SIZE));
    spriteAnim.setColor(sf::Color::Yellow);
    pFig = new Figura(&spriteAnim);
}

Inim_Medio::~Inim_Medio() {}

void Inim_Medio::executar() {
    Inimigo::executar();

    temporizador++;
    if (temporizador >= DURACAO_FRAME) {
        temporizador = 0;
        frameAtual   = (frameAtual + 1) % TOTAL_FRAMES;
    }
    spriteAnim.setTextureRect(sf::IntRect(frameAtual * FRAME_SIZE, 0, FRAME_SIZE, FRAME_SIZE));

    sf::Vector2f pos  = forma.getPosition();
    sf::Vector2f size = forma.getSize();
    float sx = size.x / FRAME_SIZE;
    float sy = size.y / FRAME_SIZE;
    if (velocidadeX > 0) {
        spriteAnim.setScale(-sx, sy);
        spriteAnim.setPosition(pos.x + size.x, pos.y);
    } else {
        spriteAnim.setScale(sx, sy);
        spriteAnim.setPosition(pos.x, pos.y);
    }
}

void Inim_Medio::danificar(Jogador* p) {
    if (!p) return;
    p->tomarDano();
    p->tomarDano();
}

void Inim_Medio::salvar() {}
void Inim_Medio::salvarDataBuffer() {}
void Inim_Medio::salva() {}
