#include "HUD.h"
#include "Jogador.h"

namespace Kawabanga {
    using namespace Entidades::Personagens;
    HUD::HUD(Jogador* pJo1, Jogador* pJo2) : Ente(), pJog1(pJo1), pJog2(pJo2), fonteCarregada(false) {
        fonteCarregada = fonte.loadFromFile("fonts/arial.ttf");

        if (fonteCarregada) {
            textoPontos.setFont(fonte);
            textoPontos.setCharacterSize(22);
            textoPontos.setFillColor(sf::Color::White);
            textoPontos.setOutlineColor(sf::Color::Black);
            textoPontos.setOutlineThickness(1.5f);
            textoPontos.setPosition(10.f, 10.f);
        }

        for (int i = 0; i < 5; i++) {
            coracoes_p1[i].setSize(sf::Vector2f(24.f, 24.f));
            coracoes_p1[i].setOutlineColor(sf::Color::White);
            coracoes_p1[i].setOutlineThickness(1.f);
            coracoes_p1[i].setPosition(10.f + i * 34.f, 40.f);
        }

        if (pJog2) {
            for (int j = 0; j < 5; j++) {
                coracoes_p2[j].setSize(sf::Vector2f(24.f, 24.f));
                coracoes_p2[j].setOutlineColor(sf::Color::White);
                coracoes_p2[j].setOutlineThickness(1.f);
                coracoes_p2[j].setPosition(10.f + j * 34.f, 70.f);
            }
        }
    }

    HUD::~HUD() {}

    void HUD::executar() {}

    void HUD::desenhar() {
        if (!pGG) return;
        pGG->resetarViewUI();

        int vidas = pJog1->getNumVidas();
        int pontos = pJog1->getPontos();

        for (int i = 0; i < 5; i++) {
            coracoes_p1[i].setFillColor(i < vidas ? sf::Color::Red : sf::Color(60, 60, 60));
            pGG->desenharEnte(coracoes_p1[i]);
        }

        if (pJog2) {
            int vidas_2 = pJog2->getNumVidas();

        for (int j = 0; j < 5; j++) {
            coracoes_p2[j].setFillColor(j < vidas_2 ? sf::Color::Red : sf::Color(60, 60, 60));
            pGG->desenharEnte(coracoes_p2[j]);
        }
        }

        if (fonteCarregada) {
            textoPontos.setString("Pontos: " + std::to_string(pontos));
            pGG->desenharEnte(textoPontos);
        }
    }
}