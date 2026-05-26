#pragma once
#include "Personagem.h"

class Jogador : public Personagem {
private:
    int pontos;
    float velocidadeX;
    float velocidadeY;
    float gravidade;
    float pulo;
    bool noChao;
public:
    Jogador();
    ~Jogador();
    void executar();
    void mover();
    void pararNoChao(float y_chao);
    void tomarDano();
    float getVelocidadeY() const;
    void baterCabeca(float base_plataforma);
};