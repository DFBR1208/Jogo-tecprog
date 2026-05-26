#pragma once
#include "Entidade.h"
#include "Jogador.h"

class Obstaculo : public Entidade {
protected:
	bool danoso;
public:
	Obstaculo();
	~Obstaculo();
	virtual void executar()=0;
	virtual void obstaculizar(Jogador* p)=0;
};