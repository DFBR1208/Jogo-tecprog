#include "HUD.h"
#include "Jogador.h"

namespace Kawabanga {
    using namespace Entidades::Personagens;
    HUD::HUD(Jogador* pJo1) : Ente(), pJog1(pJo1), fonteCarregada(false) {
        fonteCarregada = fonte.loadFromFile("fonts/arial.ttf");

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

    HUD::~HUD() {}

    void HUD::executar() {}

    void HUD::desenhar() {
        if (!pGG) return;
        pGG->resetarViewUI();

        int vidas = pJog1->getNumVidas();
        int pontos = pJog1->getPontos();

        for (int i = 0; i < 3; i++) {
            coracoes[i].setFillColor(i < vidas ? sf::Color::Red : sf::Color(60, 60, 60));
            pGG->desenhar(coracoes[i]);
        }

        if (fonteCarregada) {
            textoPontos.setString("Pontos: " + std::to_string(pontos));
            pGG->desenhar(textoPontos);
        }
    }
}