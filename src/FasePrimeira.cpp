#include "FasePrimeira.h"

FasePrimeira::FasePrimeira() : Fase() {
    pJogador = new Jogador();
	pInimigo = new Inimigo();
	pPlataforma = new Plataforma();
	pGerenciadorColisoes = new Gerenciador_Colisoes(pJogador, pInimigo, pPlataforma);

    ceu.setSize(sf::Vector2f(800.f, 600.f));
    ceu.setFillColor(sf::Color::Cyan);
    ceu.setPosition(0.f, 0.f);

    chao.setSize(sf::Vector2f(800.f, 50.f));
    chao.setFillColor(sf::Color::Green);
    chao.setPosition(0.f, 550.f);
}

FasePrimeira::~FasePrimeira() {}

void FasePrimeira::executar() {
    pJogador->executar();
	pInimigo->executar();
	pGerenciadorColisoes->tratarColisoes();
}

void FasePrimeira::desenhar() {
    Ente::getGerenciadorGrafico()->desenhar(ceu);
    Ente::getGerenciadorGrafico()->desenhar(chao);

    pJogador->desenhar();
	pInimigo->desenhar();
	pPlataforma->desenhar();
}