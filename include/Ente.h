#pragma once
#include "Gerenciador_Grafico.h"
#include "Figura.h"

class Ente {
protected:
	int id;
	static Gerenciador_Grafico* pGG;
	Figura* pFig;
public:
	Ente();
	virtual ~Ente();
	virtual void executar() = 0;
	void desenhar();
	static void setGerenciadorGrafico(Gerenciador_Grafico* pG);
	static Gerenciador_Grafico* getGerenciadorGrafico();
};