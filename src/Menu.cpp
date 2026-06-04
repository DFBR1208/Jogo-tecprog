#include "Menu.h"
#include "Jogo.h"
#include<iostream>

Menu::Menu(Jogo* pJog) : Ente(), titulo(), opcoes(), fonte(), pJogo(pJog), opcaoSelecionada(0), pressed(false) {
	opcoes.resize(3);
	fonte.loadFromFile("fonts/ARIAL.ttf");
	titulo.setFont(fonte);
	titulo.setString("Jogo");
	titulo.setCharacterSize(48);
	titulo.setFillColor(sf::Color::White);
	titulo.setPosition(200.f, 100.f);
	opcoes[0].setFont(fonte);
	opcoes[0].setString("Fase 1");
	opcoes[0].setCharacterSize(24);
	opcoes[0].setFillColor(sf::Color::White);
	opcoes[0].setPosition(250.f, 200.f);
	opcoes[1].setFont(fonte);
	opcoes[1].setString("Fase 2");
	opcoes[1].setCharacterSize(24);
	opcoes[1].setFillColor(sf::Color::White);
	opcoes[1].setPosition(250.f, 250.f);
	opcoes[2].setFont(fonte);
	opcoes[2].setString("Leaderboard");
	opcoes[2].setCharacterSize(24);
	opcoes[2].setFillColor(sf::Color::White);
	opcoes[2].setPosition(250.f, 300.f);
	opcoes[opcaoSelecionada].setFillColor(sf::Color::Red);
}

Menu::~Menu() {}

void Menu::executar() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&&!pressed) {
		if (opcaoSelecionada < 2) {
			opcaoSelecionada++;
			opcoes[opcaoSelecionada].setFillColor(sf::Color::Red);
			opcoes[opcaoSelecionada - 1].setFillColor(sf::Color::White);
		}
		pressed = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&!pressed) {
		if (opcaoSelecionada > 0) {
			opcaoSelecionada--;
			opcoes[opcaoSelecionada].setFillColor(sf::Color::Red);
			opcoes[opcaoSelecionada + 1].setFillColor(sf::Color::White);
		}
		pressed = true;
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		pressed = false;
	}

	if (opcaoSelecionada == 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		pJogo->iniciarFase1();
	}
	else if (opcaoSelecionada == 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		std::cout << "Fase 2 selecionada" << std::endl;
	}
	else if (opcaoSelecionada == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		std::cout << "Leaderboard selecionada" << std::endl;
	}
}

void Menu::desenhar() {
	getGerenciadorGrafico()->desenhar(titulo);
	for (int i = 0; i < 3; ++i) {
		getGerenciadorGrafico()->desenhar(opcoes[i]);
	}
}