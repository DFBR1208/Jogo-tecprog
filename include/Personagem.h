#pragma once
#include "Entidade.h"

class Personagem : public Entidade {
protected:
	int num_vidas;
public:
	Personagem();
	virtual ~Personagem();
	virtual void executar() = 0;
	virtual void mover() = 0;
};