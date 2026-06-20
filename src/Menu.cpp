#include "Menu.h"
#include "Jogo.h"
#include <iostream>

namespace Kawabanga {
	Menu::Menu(Jogo* pJ) : Ente(), titulo(), opcoes(), opcaoSelecionada(0), pressed(false), n_jogadores(1), pJogo(pJ) {
		fonte.loadFromFile("fonts/arial.ttf");
		titulo.setFont(fonte);
		titulo.setCharacterSize(48);
		titulo.setFillColor(sf::Color::White);
		opcoes.clear();
		fundo.setSize(sf::Vector2f(800.f, 600.f));
		fundo.setFillColor(sf::Color(0,0,0,255));
		setEstado(MENU_INICIO);
	}

	Menu::~Menu() {}

	void Menu::executar() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed) {
			if (opcaoSelecionada < opcoes.size()-1) {
				opcaoSelecionada++;
				opcoes[opcaoSelecionada].setFillColor(sf::Color::Red);
				opcoes[opcaoSelecionada - 1].setFillColor(sf::Color::White);
			}
			else if (opcaoSelecionada==opcoes.size()-1) {
				opcaoSelecionada=0;
				opcoes[opcaoSelecionada].setFillColor(sf::Color::Red);
				opcoes[opcoes.size()-1].setFillColor(sf::Color::White);
			}
			pressed = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed) {
			if (opcaoSelecionada > 0) {
				opcaoSelecionada--;
				opcoes[opcaoSelecionada].setFillColor(sf::Color::Red);
				opcoes[opcaoSelecionada + 1].setFillColor(sf::Color::White);
			}
			else if (opcaoSelecionada==0) {
				opcaoSelecionada=opcoes.size()-1;
				opcoes[opcaoSelecionada].setFillColor(sf::Color::Red);
				opcoes[0].setFillColor(sf::Color::White);				
			}
			pressed = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !pressed) {
			pressed = true;
			if(estadoMenu==MENU_INICIO) {
				if (opcaoSelecionada==0) {
					pJogo->iniciarFase1(n_jogadores);
				}
				else if (opcaoSelecionada==1) {
					pJogo->iniciarFase2(n_jogadores);
				}
				else if (opcaoSelecionada==2) {
					n_jogadores = (n_jogadores % 2) + 1; // Alterna entre 1 e 2 jogadores
					opcoes[2].setString("Numero de Jogadores: " + std::to_string(n_jogadores));
				}
				else if (opcaoSelecionada==3) {}
				else if (opcaoSelecionada==4) {}
				else if (opcaoSelecionada==5) {exit(0);}
			}
			else if (estadoMenu==MENU_PAUSE) {
				if(opcaoSelecionada==0) {
					pJogo->setEstado(pJogo->getFaseAtual());
				}
				else if (opcaoSelecionada==1) {}
				else if (opcaoSelecionada==2) {
					setEstado(MENU_INICIO);
				}
			}
			else if (estadoMenu==MENU_GAMEOVER) {
				if(opcaoSelecionada==0) {}
				else if (opcaoSelecionada==1) {
					setEstado(MENU_INICIO);

				}
			}
			else if (estadoMenu==MENU_VITORIA) {
				if(opcaoSelecionada==0) {}
				else if (opcaoSelecionada==1) {
					setEstado(MENU_INICIO);

				}
			}
		}

		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			pressed = false;
		}
	}

	void Menu::desenhar() {
		sf::View viewdojogo = getGerenciadorGrafico()->getWindow()->getView();
		getGerenciadorGrafico()->resetarViewUI();
		getGerenciadorGrafico()->desenhar(fundo);
		getGerenciadorGrafico()->desenhar(titulo);
		for (int i = 0; i < opcoes.size(); ++i) {
			getGerenciadorGrafico()->desenhar(opcoes[i]);
		}
		getGerenciadorGrafico()->getWindow()->setView(viewdojogo);
	}

	void Menu::setEstado(EstadoMenu novoEstado) {
		estadoMenu = novoEstado;
		opcaoSelecionada = 0;

		switch(estadoMenu) {
			case MENU_INICIO:
				titulo.setPosition(250.f, 100.f);
				titulo.setString("Kawabanga");

				opcoes.resize(6);
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
				opcoes[4].setFont(fonte);
				opcoes[4].setString("Carregar Jogo");
				opcoes[4].setCharacterSize(24);
				opcoes[4].setFillColor(sf::Color::White);
				opcoes[4].setPosition(250.f, 400.f);
				opcoes[5].setFont(fonte);
				opcoes[5].setString("Sair");
				opcoes[5].setCharacterSize(24);
				opcoes[5].setFillColor(sf::Color::White);
				opcoes[5].setPosition(250.f, 450.f);
				fundo.setFillColor(sf::Color(0,0,0,255));
				break;
			case MENU_PAUSE:
				titulo.setString("JOGO PAUSADO");
				titulo.setPosition(250.f, 100.f);

				opcoes.resize(3);

				opcoes[0].setFont(fonte);
				opcoes[0].setString("Voltar ao Jogo");
				opcoes[0].setCharacterSize(24);
				opcoes[0].setFillColor(sf::Color::Red); 
				opcoes[0].setPosition(250.f, 200.f);

				opcoes[1].setFont(fonte);
				opcoes[1].setString("Salvar Jogo");
				opcoes[1].setCharacterSize(24);
				opcoes[1].setFillColor(sf::Color::White);
				opcoes[1].setPosition(250.f, 250.f);

				opcoes[2].setFont(fonte);
				opcoes[2].setString("Sair para o Menu");
				opcoes[2].setCharacterSize(24);
				opcoes[2].setFillColor(sf::Color::White);
				opcoes[2].setPosition(250.f, 300.f);
				fundo.setFillColor(sf::Color(0,0,0,150));
				break;
			case MENU_GAMEOVER:
				titulo.setString("MORREU!!");
				titulo.setPosition(250.f, 100.f);
				opcoes.resize(2);
				opcoes[0].setFont(fonte);
				opcoes[0].setString("Salvar e Sair");
				opcoes[0].setCharacterSize(24);
				opcoes[0].setFillColor(sf::Color::White);
				opcoes[0].setPosition(250.f, 200.f);
				opcoes[1].setFont(fonte);
				opcoes[1].setString("Sair sem Salvar");
				opcoes[1].setCharacterSize(24);
				opcoes[1].setFillColor(sf::Color::White);
				opcoes[1].setPosition(250.f, 250.f);
				fundo.setFillColor(sf::Color(0,0,0,150));
				break;
			case MENU_VITORIA:
				titulo.setString("VENCEU!!");
				titulo.setPosition(250.f, 100.f);
				opcoes.resize(2);
				opcoes[0].setFont(fonte);
				opcoes[0].setString("Salvar no Ledaerboard");
				opcoes[0].setCharacterSize(24);
				opcoes[0].setFillColor(sf::Color::White);
				opcoes[0].setPosition(250.f, 200.f);
				opcoes[1].setFont(fonte);
				opcoes[1].setString("Sair sem Salvar");
				opcoes[1].setCharacterSize(24);
				opcoes[1].setFillColor(sf::Color::White);
				opcoes[1].setPosition(250.f, 250.f);
				fundo.setFillColor(sf::Color(0,0,0,150));				
		}

		if(!opcoes.empty()){
			opcoes[0].setFillColor(sf::Color::Red);
		}
	}
}