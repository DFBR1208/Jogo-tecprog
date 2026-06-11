#include "Chefao.h"

Chefao::Chefao() : Inimigo(), forca(1), pProj(nullptr), cooldownTiro(INTERVALO_TIRO) {
    nivel_maldade = 3;
    velocidadeX   = -1.2f;
    forma.setSize(sf::Vector2f(84.f, 84.f));
    texBoss.loadFromFile("assests/enemy/Blink (42x42).png");
    spriteAnim.setTexture(texBoss);
    spriteAnim.setTextureRect(sf::IntRect(0, 0, FRAME_SIZE, FRAME_SIZE));
    spriteAnim.setColor(sf::Color::Red);
    spriteAnim.setScale(2.f, 2.f);
    pFig = new Figura(&spriteAnim);
}

Chefao::Chefao(float px, float py) : Inimigo(px, py), forca(1), pProj(nullptr), cooldownTiro(INTERVALO_TIRO) {
    nivel_maldade = 3;
    velocidadeX   = -1.2f;
    forma.setSize(sf::Vector2f(84.f, 84.f));
    texBoss.loadFromFile("assests/enemy/Blink (42x42).png");
    spriteAnim.setTexture(texBoss);
    spriteAnim.setTextureRect(sf::IntRect(0, 0, FRAME_SIZE, FRAME_SIZE));
    spriteAnim.setColor(sf::Color::Red);
    spriteAnim.setScale(2.f, 2.f);
    pFig = new Figura(&spriteAnim);
}

Chefao::~Chefao() {}

void Chefao::executar() {
    Inimigo::executar();

    // animacao
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

void Chefao::danificar(Jogador* p) {
    if (!p) return;
    float xJogador = p->getForma().getPosition().x;
    bool knockback_direita = (xJogador > forma.getPosition().x);
    for (short i = 0; i <= forca; ++i)
        p->tomarDano(knockback_direita);
}

void Chefao::salvarDataBuffer() {}
void Chefao::salva()            {}
void Chefao::salvar()           {}
