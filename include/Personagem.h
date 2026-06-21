#pragma once
#include "Entidade.h"

namespace Kawabanga::Entidades::Personagens {
class Personagem : public Entidade {
	protected:
		int num_vidas;
		sf::Sprite  spriteAnim;
	public:
		Personagem(int n_vi);
		virtual ~Personagem();
		virtual void executar() = 0;
		virtual void mover() = 0;
		virtual void salvar() = 0;
		void salvarDataBuffer();
		virtual void carregarDataBuffer(std::stringstream& ss);
	};
}