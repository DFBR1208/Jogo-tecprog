#include "Gerenciador_Grafico.h"
#include <SFML/Graphics.hpp>

Gerenciador_Grafico::Gerenciador_Grafico() {}
Gerenciador_Grafico::~Gerenciador_Grafico() {}
void Gerenciador_Grafico::desenharEnte() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Teste");
    window.setFramerateLimit(60);

    sf::RectangleShape ceu(sf::Vector2f(800.f, 600.f));
    ceu.setFillColor(sf::Color::Cyan);
    ceu.setPosition(0.f, 0.f);

    sf::RectangleShape chao(sf::Vector2f(800.f, 50.f));
    chao.setFillColor(sf::Color::Green);
    chao.setPosition(0.f, 550.f);

    sf::RectangleShape jogador(sf::Vector2f(30.f, 50.f));
    jogador.setFillColor(sf::Color::Red);
    jogador.setPosition(375.f, 0.f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        float velocidadeX = 5.0f;
        float velocidadeY = 3.0f;
        float gravidade = 1.5f;


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            jogador.move(velocidadeX, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            jogador.move(-velocidadeX, 0.f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            jogador.move(0.f, -velocidadeY);
        }
        jogador.move(0.f, gravidade);

        if (jogador.getGlobalBounds().intersects(chao.getGlobalBounds())) {
            jogador.setPosition(jogador.getPosition().x, chao.getPosition().y - jogador.getSize().y);
        }

        window.clear();
        window.draw(ceu);
        window.draw(jogador);
        window.draw(chao);
        window.display();
    }
}
