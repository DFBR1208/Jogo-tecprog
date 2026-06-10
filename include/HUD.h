#pragma once
#include "Ente.h"

class Jogador;

class HUD : public Ente {
private:
    sf::Text textoPontos;
    sf::RectangleShape coracoes[3];
	sf::Font fonte;
	bool fonteCarregada;
	Jogador* pJog1;
public:
    HUD(Jogador* pJo1);
    ~HUD();
    void executar(); 
    void desenhar();
};