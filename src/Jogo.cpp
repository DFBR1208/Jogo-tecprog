#include "Jogo.h"
#include "Gerenciador_Grafico.h"
#include <iostream>

Jogo::Jogo() {}

Jogo::~Jogo() {}

void Jogo::executar() {
	Gerenciador_Grafico gerenciador;
	gerenciador.desenharEnte();
}