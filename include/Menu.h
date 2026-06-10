#pragma once
#include "Ente.h"
#include <vector>
#include <string>

class Jogo;

class Menu : public Ente {
private:
    Jogo* pJogo;
	sf::Font fonte;
    sf::Text titulo;
    std::vector<sf::Text> opcoes;
    int opcaoSelecionada;
    bool pressed;
    int n_jogadores;

public:
    Menu(Jogo* pJ);
    ~Menu();
    void executar();
    void desenhar();
};