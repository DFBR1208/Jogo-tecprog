#pragma once
#include "Ente.h"

class Entidade : public Ente {
protected:
	int x;
	int y;
public:
	Entidade();
	virtual ~Entidade();
	virtual void executar() = 0;
};
