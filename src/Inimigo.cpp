#include "Inimigo.h"
#include <cstdlib>

Inimigo::Inimigo() : Personagem() {
    nivel_maldade = 1;
    velocidadeX   = -2.0f;
    velocidadeY   = 0.0f;
    gravidade     = 1.0f;
    noChao        = false;
    pPlataforma   = nullptr;
    frameAtual    = 0;
    temporizador  = 0;
    forma.setSize(sf::Vector2f(42.f, 42.f));
    forma.setFillColor(sf::Color::Transparent);
    forma.setPosition(700.f, 508.f);
}

Inimigo::Inimigo(float px, float py) : Personagem() {
    nivel_maldade = 1;
    velocidadeX   = -1.5f;
    velocidadeY   = 0.0f;
    gravidade     = 1.0f;
    noChao        = false;
    pPlataforma   = nullptr;
    frameAtual    = 0;
    temporizador  = 0;
    forma.setSize(sf::Vector2f(42.f, 42.f));
    forma.setFillColor(sf::Color::Transparent);
    forma.setPosition(px, py);
}

Inimigo::~Inimigo() {}

void Inimigo::executar() {
    if (pPlataforma)
        mover(pPlataforma);
    else
        mover();
}

// patrulha no chao com gravidade
void Inimigo::mover() {
    forma.move(velocidadeX, 0.f);
    if (forma.getPosition().x <= 100.f || forma.getPosition().x >= 760.f)
        velocidadeX = -velocidadeX;

    velocidadeY += gravidade;
    forma.move(0.f, velocidadeY);

    float chao_y = 500.f - forma.getSize().y;
    if (forma.getPosition().y >= chao_y) {
        forma.setPosition(forma.getPosition().x, chao_y);
        velocidadeY = 0.f;
        noChao = true;
    }
}

// sobrecarga: patrulha dentro dos limites da plataforma
void Inimigo::mover(Plataforma* p) {
    sf::FloatRect b = p->getBounds();
    float limEsq = b.left;
    float limDir = b.left + b.width - forma.getSize().x;

    forma.move(velocidadeX, 0.f);

    float px = forma.getPosition().x;
    if (px <= limEsq || px >= limDir)
        velocidadeX = -velocidadeX;

    // mantém colado ao topo da plataforma
    forma.setPosition(forma.getPosition().x, b.top - forma.getSize().y);
}

// posiciona o inimigo na plataforma e guarda a referencia
Inimigo& Inimigo::operator=(Plataforma* p) {
    pPlataforma = p;
    if (p) {
        sf::FloatRect b = p->getBounds();
        float rangeX  = b.width - forma.getSize().x;
        float offsetX = (rangeX > 1.f) ? static_cast<float>(rand() % static_cast<int>(rangeX)) : 0.f;
        forma.setPosition(b.left + offsetX, b.top - forma.getSize().y);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Inimigo& ini) {
    os << "Inimigo[nivel=" << ini.nivel_maldade
       << ", pos=(" << ini.forma.getPosition().x
       << "," << ini.forma.getPosition().y << ")]";
    return os;
}

void Inimigo::danificar(Jogador* p) {
    if (p != nullptr)
        p->tomarDano();
}

sf::FloatRect Inimigo::getBounds() const {
    return forma.getGlobalBounds();
}
