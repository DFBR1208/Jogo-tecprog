#pragma once
#include "Ente.h"

class Jogo;

class Menu : public Ente {
private:
    Jogo*              pJogo;
    sf::Font           fonte;
    sf::Text           textoPontos;
    sf::RectangleShape coracoes[3];
    bool               fonteCarregada;

public:
    Menu(Jogo* pJ);
    ~Menu();
    void executar() override;
    void desenhar() override;
};
