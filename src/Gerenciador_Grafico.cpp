#include "Gerenciador_Grafico.h"
#include "Ente.h"

void Gerenciador_Grafico::carregarTexturas() {
    texBg.loadFromFile("assests/bg/Pink.png");
    texTerrain.loadFromFile("assests/bg/Terrain (16x16).png");

    texPlayerIdle.loadFromFile("assests/player/Idle (32x32).png");
    texPlayerRun.loadFromFile("assests/player/Run (32x32).png");
    texPlayerJump.loadFromFile("assests/player/Jump (32x32).png");
    texPlayerFall.loadFromFile("assests/player/Fall (32x32).png");
    texPlayerHit.loadFromFile("assests/player/Hit (32x32).png");
    texPlayerDoubleJump.loadFromFile("assests/player/Double Jump (32x32).png");
    texPlayerWallJump.loadFromFile("assests/player/Wall Jump (32x32).png");

    texEnemyIdle.loadFromFile("assests/enemy/Idle.png");
    texEnemyBlink.loadFromFile("assests/enemy/Blink (42x42).png");
    texEnemyTopHit.loadFromFile("assests/enemy/Top Hit (42x42).png");
    texEnemyBottomHit.loadFromFile("assests/enemy/Bottom Hit (42x42).png");
    texEnemyLeftHit.loadFromFile("assests/enemy/Left Hit (42x42).png");
    texEnemyRightHit.loadFromFile("assests/enemy/Right Hit (42x42).png");
}

Gerenciador_Grafico::Gerenciador_Grafico() {
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "Jogo");
    window->setFramerateLimit(60);
    carregarTexturas();
}

Gerenciador_Grafico::~Gerenciador_Grafico() {
    delete window;
}

void Gerenciador_Grafico::limpar() {
    window->clear();
}

void Gerenciador_Grafico::desenhar(sf::RectangleShape forma) {
    window->draw(forma);
}

void Gerenciador_Grafico::desenhar(const sf::Sprite& sprite) {
    window->draw(sprite);
}

void Gerenciador_Grafico::desenhar(const sf::Drawable& drawable) {
    window->draw(drawable);
}

sf::RenderWindow* Gerenciador_Grafico::getWindow() {
    return window;
}

void Gerenciador_Grafico::desenharEnte(Ente* pe) {
    if (pe) pe->desenhar();
}

void Gerenciador_Grafico::mostrar() {
    window->display();
}

bool Gerenciador_Grafico::verificaJanelaAberta() {
    if (!window->isOpen()) return false;

    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
    }
    return window->isOpen();
}