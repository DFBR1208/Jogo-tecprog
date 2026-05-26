#pragma once
#include "Obstaculo.h"

class Plataforma : public Obstaculo {
private:
	int altura;
public:
	Plataforma();
	~Plataforma();
	void executar();
	void obstaculizar(Jogador* p);
};