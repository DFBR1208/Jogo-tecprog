#pragma once
#include "Gerenciador_Grafico.h"
#include "Figura.h"

namespace Kawabanga {
	class Ente {
	protected:
		int id;
		static Gerenciadores::Gerenciador_Grafico* pGG;
		static int contadorId;
		Figura* pFig;
	public:
		Ente();
		virtual ~Ente();
		virtual void executar() = 0;
		void desenhar();
		static void setGerenciadorGrafico(Gerenciadores::Gerenciador_Grafico* pG);
		static Gerenciadores::Gerenciador_Grafico* getGerenciadorGrafico();
		int getId();
	};
}