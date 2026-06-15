#pragma once
#include "Obstaculo.h"


namespace Kawabanga::Entidades::Obstaculos {
	class Rosquinha : public Obstaculo {
	private:
		int altura;
	public:
		Rosquinha();
		Rosquinha(float px, float py, float largura = 200.f);
		~Rosquinha();
		void executar();
		void salvar();
		void obstaculizar(Personagens::Jogador* p);
	};
}