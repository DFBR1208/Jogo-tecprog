#include "Gerenciador_Grafico.h"
#include "Ente.h"

void Gerenciador_Grafico::carregarTexturas() {
    texBg.loadFromFile("assests/bg/Pink.png");
    texTerrain.loadFromFile("assests/bg/Terrain (16x16).png");
    texPlataforma.loadFromFile("assests/plataforma/testePlataforma.png");
    texPlataforma.setRepeated(true);
    texPlataforma.setSmooth(false);
    texObstaculo.loadFromFile("assests/Obstaculo/Idle.png");
    texObstaculoD.loadFromFile("assests/Obstaculo/dificil.png");

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

    texProjetil.loadFromFile("assests/projetil/projetil.png");
    texBoss.loadFromFile("assests/chefao/Idle.png");
}

Gerenciador_Grafico::Gerenciador_Grafico() {
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "Jogo");
    window->setFramerateLimit(60);
    camera = sf::View(sf::FloatRect(0.f, 0.f, 800.f, 600.f));
    carregarTexturas();
}

void Gerenciador_Grafico::atualizarCamera(sf::Vector2f posJogador, float mundoLargura, float mundoAltura) {
    float halfW = camera.getSize().x / 2.f;
    float halfH = camera.getSize().y / 2.f;

    float cx = posJogador.x + 15.f;
    float cy = posJogador.y + 25.f;

    if (cx - halfW < 0.f)          cx = halfW;
    if (cx + halfW > mundoLargura) cx = mundoLargura - halfW;
    if (cy - halfH < 0.f)          cy = halfH;
    if (cy + halfH > mundoAltura)  cy = mundoAltura - halfH;

    camera.setCenter(cx, cy);
    window->setView(camera);
}

void Gerenciador_Grafico::resetarViewUI() {
    window->setView(window->getDefaultView());
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