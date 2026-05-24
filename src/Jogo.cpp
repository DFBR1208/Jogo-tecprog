#include "Jogo.h"
#include "Gerenciador_Grafico.h"
#include<iostream>

Jogo::Jogo() {

}

Jogo::~Jogo() {
	std::cout << "Teste2" << std::endl;
}

void Jogo::executar() {
	Gerenciador_Grafico gerenciador;
	gerenciador.desenharEnte();
}