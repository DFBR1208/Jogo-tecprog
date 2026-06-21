#pragma once
#include "Entidade.h"
#include "Jogador.h"

namespace Kawabanga::Entidades::Obstaculos {
	class Obstaculo : public Entidade {
	protected:
		bool danoso;
		sf::RectangleShape forma;
	public:
		Obstaculo();
		~Obstaculo();
		virtual void executar() = 0;
		virtual void obstaculizar(Personagens::Jogador* p) = 0;
		sf::FloatRect getBounds() const;
		virtual void salvar() = 0;
		void antiGravitar();
		void salvarDataBuffer();
		virtual void carregarDataBuffer(std::stringstream& ss);
	};
}