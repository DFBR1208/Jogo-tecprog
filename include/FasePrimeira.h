#pragma once
#include "Fase.h"
#include <SFML/Graphics.hpp>
#include "Inimigo.h"
#include "Plataforma.h"
#include "Gerenciador_Colisoes.h"

class FasePrimeira : public Fase {
private:
    sf::RectangleShape ceu;
    sf::RectangleShape chao;
	Inimigo* pInimigo;
	Plataforma* pPlataforma;
	Gerenciador_Colisoes* pGerenciadorColisoes;
public:
    FasePrimeira();
    ~FasePrimeira();
    void executar();
    void desenhar();
};