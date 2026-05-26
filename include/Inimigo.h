#pragma once
#include "Personagem.h"
#include "Jogador.h"

class Inimigo : public Personagem {
protected:
	int nivel_maldade;
	float velocidadeX;
public:
	Inimigo();
	~Inimigo();
	void executar();
	void mover();
	void danificar(Jogador* p);
};