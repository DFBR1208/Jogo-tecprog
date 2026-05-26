#include "Gerenciador_Grafico.h"

Gerenciador_Grafico::Gerenciador_Grafico() {
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "Jogo");
    window->setFramerateLimit(60);
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