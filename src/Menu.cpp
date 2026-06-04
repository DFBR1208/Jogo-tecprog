#include "Menu.h"
#include "Jogo.h"
#include <string>

Menu::Menu(Jogo* pJ) : Ente(), pJogo(pJ), fonteCarregada(false) {
    fonteCarregada = fonte.loadFromFile("C:/Windows/Fonts/arial.ttf");

    if (fonteCarregada) {
        textoPontos.setFont(fonte);
        textoPontos.setCharacterSize(22);
        textoPontos.setFillColor(sf::Color::White);
        textoPontos.setOutlineColor(sf::Color::Black);
        textoPontos.setOutlineThickness(1.5f);
        textoPontos.setPosition(10.f, 10.f);
    }

    for (int i = 0; i < 3; i++) {
        coracoes[i].setSize(sf::Vector2f(24.f, 24.f));
        coracoes[i].setOutlineColor(sf::Color::White);
        coracoes[i].setOutlineThickness(1.f);
        coracoes[i].setPosition(10.f + i * 34.f, 40.f);
    }
}

Menu::~Menu() {}

void Menu::executar() {}

void Menu::desenhar() {
    if (!pGG) return;
    pGG->resetarViewUI();

    int vidas  = pJogo->getVidas();
    int pontos = pJogo->getPontos();

    for (int i = 0; i < 3; i++) {
        coracoes[i].setFillColor(i < vidas ? sf::Color::Red : sf::Color(60, 60, 60));
        pGG->desenhar(coracoes[i]);
    }

    if (fonteCarregada) {
        textoPontos.setString("Pontos: " + std::to_string(pontos));
        pGG->desenhar(textoPontos);
    }
}
