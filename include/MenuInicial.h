#pragma once
#include "MenuBase.h"
#include <vector>
#include <string>

class MenuInicial : public MenuBase {
private:
    sf::Text titulo;
    std::vector<sf::Text> opcoes;
    int opcaoSelecionada;
    bool pressed;
    int n_jogadores;

public:
    MenuInicial(Jogo* pJ);
    ~MenuInicial();
    void executar();
    void desenhar();
};