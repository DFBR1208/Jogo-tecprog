#include "MenuInicial.h"
#include "Jogo.h"
#include <iostream>

MenuInicial::MenuInicial(Jogo* pJ) : MenuBase(pJ), titulo(), opcoes(), opcaoSelecionada(0), pressed(false), n_jogadores(1) {
	fonteCarregada = fonte.loadFromFile("fonts/arial.ttf");
	if (!fonteCarregada) {
		std::cout << "Erro ao carregar a fonte arial.ttf" << std::endl;
	}
	titulo.setFont(fonte);
	titulo.setString("Jogo");
	titulo.setCharacterSize(48);
	titulo.setFillColor(sf::Color::White);
	titulo.setPosition(200.f, 100.f);
	opcoes.resize(4);
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
	opcoes[2].setString("Numero de Jogadores: " + std::to_string(n_jogadores)); //método to_string para converter o número de jogadores em string
	opcoes[2].setCharacterSize(24);
	opcoes[2].setFillColor(sf::Color::White);
	opcoes[2].setPosition(250.f, 300.f);
	opcoes[3].setFont(fonte);
	opcoes[3].setString("Leaderboard");
	opcoes[3].setCharacterSize(24);
	opcoes[3].setFillColor(sf::Color::White);
	opcoes[3].setPosition(250.f, 350.f);
	opcoes[opcaoSelecionada].setFillColor(sf::Color::Red);
}

MenuInicial::~MenuInicial() {}

void MenuInicial::executar() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed) {
		if (opcaoSelecionada < 3) {
			opcaoSelecionada++;
			opcoes[opcaoSelecionada].setFillColor(sf::Color::Red);
			opcoes[opcaoSelecionada - 1].setFillColor(sf::Color::White);
		}
		pressed = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed) {
		if (opcaoSelecionada > 0) {
			opcaoSelecionada--;
			opcoes[opcaoSelecionada].setFillColor(sf::Color::Red);
			opcoes[opcaoSelecionada + 1].setFillColor(sf::Color::White);
		}
		pressed = true;
	}
	if (opcaoSelecionada == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !pressed) {
		n_jogadores = (n_jogadores % 2) + 1; // Alterna entre 1 e 2 jogadores
		opcoes[2].setString("Numero de Jogadores: " + std::to_string(n_jogadores));
		pressed = true;
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		pressed = false;
	}

	if (opcaoSelecionada == 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
		pJogo->iniciarFase1(n_jogadores);
	}
	else if (opcaoSelecionada == 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {

	}
	else if (opcaoSelecionada == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
	}
}

void MenuInicial::desenhar() {
	getGerenciadorGrafico()->desenhar(titulo);
	for (int i = 0; i < 4; ++i) {
		getGerenciadorGrafico()->desenhar(opcoes[i]);
	}
}