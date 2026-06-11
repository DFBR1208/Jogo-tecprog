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

class Gerenciador_Colisoes {
private:
    Jogador* pJog1;
    Jogador* pJog2;
    std::vector<Inimigo*>   LIs;
    std::list<Obstaculo*>   LOs;
    std::set<Projetil*>     LPs;

    const bool verificarColisao(Entidade* pe1, Entidade* pe2);
    void tratarColisoesJogsObstacs();
    void tratarColisoesJogsInimgs();
    void tratarColisoesJogsProjeteis();

public:
    Gerenciador_Colisoes(Jogador* pJogo1, Jogador* pJogo2);
    ~Gerenciador_Colisoes();
    void incluirInimigo(Inimigo* pi);
    void incluirObstaculo(Obstaculo* po);
    void incluirProjetil(Projetil* pj);
    void executar();
};
