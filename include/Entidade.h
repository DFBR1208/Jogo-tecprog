#pragma once
#include "Ente.h"
#include <sstream>

namespace Kawabanga::Entidades {
	class Entidade : public Ente {
	protected:
		int   x;
		int   y;
		float velocidadeY;
		float gravidade;
		bool  noChao;
		std::ostringstream buffer; //ostream é inacessível para criar um objeto diretamente
		void salvarDataBuffer();
	public:
		Entidade();
		virtual ~Entidade();
		virtual void executar() = 0;
		virtual void salvar() = 0;
		virtual sf::FloatRect getBounds() const = 0;
		void gravitar();
		virtual void carregarDataBuffer(std::stringstream& ss);
	};
}
