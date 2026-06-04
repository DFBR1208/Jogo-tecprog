#pragma once
#include "Ente.h"
#include <SFML/Graphics.hpp>
#include<vector>

class Jogo;

class Menu : public Ente {
private:
	sf::Text titulo;
	std::vector<sf::Text> opcoes;
	sf::Font fonte;
	Jogo* pJogo;
	int opcaoSelecionada;
	bool pressed; // Para evitar múltiplas detecções de uma única tecla pressionada
public:
	Menu(Jogo* pJog);
	~Menu();
	void executar();
	void desenhar();
};