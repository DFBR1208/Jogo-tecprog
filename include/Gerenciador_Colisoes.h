#pragma once
#include "SFML/Graphics.hpp"
#include "Lista.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Projetil.h"
#include "Entidade.h"
#include <vector>
#include <list>
#include <set>

namespace Kawabanga::Gerenciadores {
    class Gerenciador_Colisoes {
    private:
        Entidades::Personagens::Jogador* pJog1;
        Entidades::Personagens::Jogador* pJog2;
        std::vector<Entidades::Personagens::Inimigo*>   LIs;
        std::list<Entidades::Obstaculos::Obstaculo*>   LOs;
        std::set<Entidades::Projetil*>     LPs;

        const bool verificarColisao(Entidades::Entidade* pe1, Entidades::Entidade* pe2);
        void tratarColisoesJogsObstacs();
        void tratarColisoesJogsInimgs();
        void tratarColisoesJogsProjeteis();

    public:
        Gerenciador_Colisoes(Entidades::Personagens::Jogador* pJogo1, Entidades::Personagens::Jogador* pJogo2);
        ~Gerenciador_Colisoes();
        void incluirInimigo(Entidades::Personagens::Inimigo* pi);
        void incluirObstaculo(Entidades::Obstaculos::Obstaculo* po);
        void incluirProjetil(Entidades::Projetil* pj);
        void executar();
        void removerInimigo(Entidades::Personagens::Inimigo* pIni);
    };
}
