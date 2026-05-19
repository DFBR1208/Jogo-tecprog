#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Primeiro Teste");
    sf::RectangleShape jogador(sf::Vector2f(50.f, 50.f));
    jogador.setFillColor(sf::Color::Green);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear();
        window.draw(jogador);
        window.display();
    }
    return 0;
}