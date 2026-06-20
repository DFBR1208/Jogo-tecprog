#pragma once
#include "Ente.h"
#include <vector>
#include <string>
#include <fstream>

namespace Kawabanga {
    class Jogo;
    enum EstadoMenu { MENU_INICIO, MENU_LEADERBOARD, MENU_PAUSE, MENU_GAMEOVER, MENU_VITORIA, MENU_DIGITAR };
    class Menu : public Ente {
    private:
        Jogo* pJogo;
        sf::Font fonte;
        sf::Text titulo;
        sf::RectangleShape fundo;
        std::vector<sf::Text> opcoes;
        sf::Text conteudo;
        int opcaoSelecionada;
        bool pressed;
        int n_jogadores;
        EstadoMenu estadoMenu;
    public:
        Menu(Jogo* pJ);
        ~Menu();
        void executar();
        void desenhar();
        void setEstado(EstadoMenu novoEstado);
    };
}