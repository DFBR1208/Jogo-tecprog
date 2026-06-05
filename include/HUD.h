#pragma once
#include "MenuBase.h"

class HUD : public MenuBase {
private:
    sf::Text textoPontos;
    sf::RectangleShape coracoes[3];
public:
    HUD(Jogo* pJ);
    ~HUD();
    void executar() override; 
    void desenhar() override;
};