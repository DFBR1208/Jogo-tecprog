#pragma once
#include "SFML/Graphics.hpp"
#include "Jogador.h"
#include "Inimigo.h"
#include "Plataforma.h"
#include "Entidade.h"

class Gerenciador_Colisoes {
private:
	Jogador* pJogador;
	Inimigo* pInimigo;
	Plataforma* pPlataforma;
public:
	Gerenciador_Colisoes(Jogador* jogador, Inimigo* inimigo, Plataforma* plataforma);
	~Gerenciador_Colisoes();
	const bool verificarColisao(Entidade* pe1, Entidade* pe2);
	void tratarColisoes();
};