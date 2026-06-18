#include "Pedrado.h"

namespace Kawabanga::Entidades::Personagens {
Pedrado::Pedrado() : Inimigo(3) {
    tamanho       = 52;
    nivel_maldade = 2;
    velocidadeX   = -3.5f;
    forma.setSize(sf::Vector2f((float)tamanho, (float)tamanho));
    texBlink.loadFromFile("assets/enemy/Blink (42x42).png");
    spriteAnim.setTexture(texBlink);
    spriteAnim.setTextureRect(sf::IntRect(0, 0, FRAME_SIZE, FRAME_SIZE));
    spriteAnim.setColor(sf::Color::Yellow);
    pFig = new Figura(&spriteAnim);
}

Pedrado::Pedrado(float px, float py, int n_vid) : Inimigo(px, py, n_vid) {
    tamanho       = 52;
    nivel_maldade = 2;
    velocidadeX   = -3.5f;
    forma.setSize(sf::Vector2f((float)tamanho, (float)tamanho));
    texBlink.loadFromFile("assets/enemy/Blink (42x42).png");
    spriteAnim.setTexture(texBlink);
    spriteAnim.setTextureRect(sf::IntRect(0, 0, FRAME_SIZE, FRAME_SIZE));
    spriteAnim.setColor(sf::Color::Yellow);
    pFig = new Figura(&spriteAnim);
}

Pedrado::~Pedrado() {}

void Pedrado::executar() {
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

void Pedrado::danificar(Jogador* p) {
    if (!p) return;
    bool dir = (p->getForma().getPosition().x > forma.getPosition().x);
    p->tomarDano(dir);
    p->aplicarSlow();
}

void Pedrado::salvar() {}
void Pedrado::salvarDataBuffer() {}
void Pedrado::salva() {}
}