#pragma once
#include "SFML/Graphics.hpp"
#include "Lista.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Obstaculo.h"
#include "Entidade.h"
#include <vector>
#include <list>
#include <set>

class Gerenciador_Colisoes {
private:
    Jogador*          pJogador;
    std::vector<Inimigo*>   LIs;
    std::list<Obstaculo*> LOs;
    //std::set<Projetil*> LPs;

    const bool verificarColisao(Entidade* pe1, Entidade* pe2);
    void tratarColisoesJogsObstacs();
    void tratarColisoesJogsInimgs();
    //void tratarColicoesJogsProjeteis();
public:
    Gerenciador_Colisoes(Jogador* pJog);
    ~Gerenciador_Colisoes();
    void incluirInimigo(Inimigo* pi);
    void incluirObstaculo(Obstaculo* po);
    //void incluirProjetil(Projetil* pj);
    void executar();
};
