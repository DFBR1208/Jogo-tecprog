#pragma once
#include "Ente.h"

class Jogo;

class MenuBase : public Ente {
protected:
	Jogo* pJogo;
	sf::Font fonte;
	bool fonteCarregada;
public:
	MenuBase(Jogo* pJ);
	virtual ~MenuBase();
	virtual void executar() = 0;
	virtual void desenhar() = 0;
};
