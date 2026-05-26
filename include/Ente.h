#pragma once
#include "Gerenciador_Grafico.h"

class Ente {
protected:
	int id;
	static Gerenciador_Grafico* pGG;
	sf::RectangleShape forma;
public:
	Ente();
	virtual ~Ente();
	virtual void executar() = 0;
	virtual void desenhar();
	static void setGerenciadorGrafico(Gerenciador_Grafico* pG);
	static Gerenciador_Grafico* getGerenciadorGrafico();
	const sf::RectangleShape& getForma() const;
};