#pragma once
#include "Ente.h"

namespace Kawabanga::Entidades {
	class Entidade : public Ente {
	protected:
		int   x;
		int   y;
		float velocidadeY;
		float gravidade;
		bool  noChao;
		void SalvarDataBuffer();
	public:
		Entidade();
		virtual ~Entidade();
		virtual void executar() = 0;
		virtual void salvar() = 0;
		virtual sf::FloatRect getBounds() const = 0;
		void gravitar();
	};
}
