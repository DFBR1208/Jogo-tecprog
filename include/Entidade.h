#pragma once
#include "Ente.h"

class Entidade : public Ente {
protected:
	int x;
	int y;
	void SalvarDataBuffer();
public:
	Entidade();
	virtual ~Entidade();
	virtual void executar() = 0;
	virtual void salvar() = 0;
	virtual sf::FloatRect getBounds() const = 0;
};
