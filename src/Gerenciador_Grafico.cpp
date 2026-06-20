#include "Gerenciador_Grafico.h"
#include "Ente.h"

namespace Kawabanga::Gerenciadores {

void Gerenciador_Grafico::carregarTexturas() {
    texBg.loadFromFile("assets/bg/Pink.png");
    texTerrain.loadFromFile("assets/bg/Terrain (16x16).png");
    texPlataforma.loadFromFile("assets/plataforma/testePlataforma.png");
    texPlataforma.setRepeated(true);
    texPlataforma.setSmooth(false);
    texObstaculo.loadFromFile("assets/Obstaculo/Idle.png");
    texObstaculoD.loadFromFile("assets/Obstaculo/dificil.png");

    texPlayerIdle.loadFromFile("assets/player/Idle (32x32).png");
    texPlayerRun.loadFromFile("assets/player/Run (32x32).png");
    texPlayerJump.loadFromFile("assets/player/Jump (32x32).png");
    texPlayerFall.loadFromFile("assets/player/Fall (32x32).png");
    texPlayerHit.loadFromFile("assets/player/Hit (32x32).png");
    texPlayerDoubleJump.loadFromFile("assets/player/Double Jump (32x32).png");
    texPlayerWallJump.loadFromFile("assets/player/Wall Jump (32x32).png");

    texEnemyIdle.loadFromFile("assets/enemy/Idle.png");
    texEnemyBlink.loadFromFile("assets/enemy/Blink (42x42).png");
    texEnemyTopHit.loadFromFile("assets/enemy/Top Hit (42x42).png");
    texEnemyBottomHit.loadFromFile("assets/enemy/Bottom Hit (42x42).png");
    texEnemyLeftHit.loadFromFile("assets/enemy/Left Hit (42x42).png");
    texEnemyRightHit.loadFromFile("assets/enemy/Right Hit (42x42).png");

    texProjetil.loadFromFile("assets/projetil/projetil.png");
    texBoss.loadFromFile("assets/chefao/Idle.png");
}

Gerenciador_Grafico::Gerenciador_Grafico() {
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "Kawabanga");
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
        if (event.type == sf::Event::TextEntered) {
            if (event.text.unicode == 8) {
                if(!textoDigitado.empty())
                    textoDigitado.pop_back();
            }
            else if (event.text.unicode != 13 && event.text.unicode < 128) {
                if (textoDigitado.length() < 10) {
                    textoDigitado+=static_cast<char>(event.text.unicode);
                }
            }
        }
    }
    return window->isOpen();
}

void Gerenciador_Grafico::focarCameraJogo() {
    window->setView(camera);
}

const std::string& Gerenciador_Grafico::getTextoDigitado() {
    return textoDigitado;
}

void Gerenciador_Grafico::resetarTextoDigitado() {
    textoDigitado.clear();
}

const sf::Texture& Gerenciador_Grafico::getTexBg() const { return texBg; }
const sf::Texture& Gerenciador_Grafico::getTexTerrain() const { return texTerrain; }
const sf::Texture& Gerenciador_Grafico::getTexPlataforma() const { return texPlataforma; }
const sf::Texture& Gerenciador_Grafico::getTexObstaculo() const { return texObstaculo; }
const sf::Texture& Gerenciador_Grafico::getTexPlayerIdle() const { return texPlayerIdle; }
const sf::Texture& Gerenciador_Grafico::getTexPlayerRun() const { return texPlayerRun; }
const sf::Texture& Gerenciador_Grafico::getTexPlayerJump() const { return texPlayerJump; }
const sf::Texture& Gerenciador_Grafico::getTexPlayerFall() const { return texPlayerFall; }
const sf::Texture& Gerenciador_Grafico::getTexPlayerHit() const { return texPlayerHit; }
const sf::Texture& Gerenciador_Grafico::getTexPlayerDoubleJump() const { return texPlayerDoubleJump; }
const sf::Texture& Gerenciador_Grafico::getTexPlayerWallJump() const { return texPlayerWallJump; }
const sf::Texture& Gerenciador_Grafico::getTexEnemyIdle() const { return texEnemyIdle; }
const sf::Texture& Gerenciador_Grafico::getTexEnemyBlink() const { return texEnemyBlink; }
const sf::Texture& Gerenciador_Grafico::getTexEnemyTopHit() const { return texEnemyTopHit; }
const sf::Texture& Gerenciador_Grafico::getTexEnemyBottomHit() const { return texEnemyBottomHit; }
const sf::Texture& Gerenciador_Grafico::getTexEnemyLeftHit() const { return texEnemyLeftHit; }
const sf::Texture& Gerenciador_Grafico::getTexEnemyRightHit() const { return texEnemyRightHit; }
const sf::Texture& Gerenciador_Grafico::getTexBoss() const { return texBoss; }
const sf::Texture& Gerenciador_Grafico::getTexProjetil() const { return texProjetil; }
const sf::Texture& Gerenciador_Grafico::getTexObstaculoD() const { return texObstaculoD; }

}