#include "Jogador.h"
#include <SFML/Window/Keyboard.hpp>

Jogador::Jogador() : Personagem() {
    pontos = 0;

    forma.setSize(sf::Vector2f(30.f, 50.f));
    forma.setFillColor(sf::Color::Blue);
    forma.setPosition(375.f, 0.f);

    velocidadeX = 5.0f;
    velocidadeY = 0.0f;
    gravidade = 1.0f;
    pulo = -15.0f;
    noChao = false;
}

Jogador::~Jogador() {
}

void Jogador::executar() {
    mover();
}

void Jogador::mover() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        forma.move(velocidadeX, 0.f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        forma.move(-velocidadeX, 0.f);
    }
    float pos_x = forma.getPosition().x;
    float largura = forma.getSize().x; 
    if (pos_x < 0.f) {
        forma.setPosition(0.f, forma.getPosition().y);
    }
    else if (pos_x + largura > 800.f) {
        forma.setPosition(800.f - largura, forma.getPosition().y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && noChao) {
        velocidadeY = pulo;
        noChao = false;
    }

    velocidadeY += gravidade;
    forma.move(0.f, velocidadeY);


    if (forma.getPosition().y >= 500.f) {
        forma.setPosition(forma.getPosition().x, 500.f); 
        velocidadeY = 0.0f; 
        noChao = true;    
    }
}

void Jogador::pararNoChao(float y_chao) {
    forma.setPosition(forma.getPosition().x, y_chao - forma.getSize().y);
    velocidadeY = 0.0f; 
    noChao = true;     
}

void Jogador::tomarDano() {
    num_vidas--;
    

    if (num_vidas <= 0) {
        exit(0); 
    }
    else {
        forma.move(-50.f, -50.f);
    }
}

float Jogador::getVelocidadeY() const {
	return velocidadeY;
}

void Jogador::baterCabeca(float base_plataforma) {
	forma.setPosition(forma.getPosition().x, base_plataforma);
    velocidadeY = 0.0f;
}