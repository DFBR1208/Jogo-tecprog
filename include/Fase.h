#pragma once
#include "Ente.h"
#include "Jogador.h"
#include "Gerenciador_Colisoes.h"
#include "ListaEntidades.h"

namespace Kawabanga::Entidades::Obstaculos {
    class Rosquinha;
}

namespace Kawabanga::Fases {
    class Fase : public Ente {
    protected:
        Entidades::Personagens::Jogador* pJog1;
        Entidades::Personagens::Jogador* pJog2; 
        Listas::ListaEntidades lista_enti;
        Gerenciadores::Gerenciador_Colisoes GC;

        static const int maxInimFaceis = 5;
        static const int NUM_PLATS     = 11;
        Entidades::Obstaculos::Rosquinha* plats[NUM_PLATS];
        bool faseConcluida;
        int qualfase;

        void criarPedrosos();
        void criarRosquinhas();
        virtual void criarInimigos() = 0;
        virtual void criarObstaculo() = 0;
        void criarCenario();

    public:
        Fase(Entidades::Personagens::Jogador* pJo1, Entidades::Personagens::Jogador* pJo2, bool fromSave = false);
        virtual ~Fase();
        virtual void executar() = 0;
        bool isFaseConcluida() const;
        void salvarFase();
        void carregarFase();
    };
}