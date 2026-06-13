#pragma once
#include "Obstaculo.h"


namespace Kawabanga::Entidades::Obstaculos {
	class Plataforma : public Obstaculo {
	private:
		int altura;
	public:
		Plataforma();
		Plataforma(float px, float py, float largura = 200.f);
		~Plataforma();
		void executar();
		void salvar();
		void obstaculizar(Personagens::Jogador* p);
	};
}