#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Teste");
    window.setFramerateLimit(60);


    sf::CircleShape jogador(75.f);
    jogador.setFillColor(sf::Color::Red);
    jogador.setPosition(275.f, 275.f); 

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        float velocidade = 5.0f; 

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            jogador.move(velocidade, 0.f); 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            jogador.move(-velocidade, 0.f); 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            jogador.move(0.f, -velocidade); 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            jogador.move(0.f, velocidade);
        }

        window.clear();
        window.draw(jogador);
        window.display();
    }
    return 0;
}