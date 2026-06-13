#pragma once
#include "Obstaculo.h"

namespace Kawabanga::Entidades::Obstaculos {
    class Obst_Dificil : public Obstaculo {
    private:
        short int danosidade;
    public:
        Obst_Dificil();
        Obst_Dificil(float px, float py, float lado = 30.f);
        ~Obst_Dificil();
        void executar()           override;
        void obstaculizar(Personagens::Jogador* p);
        void salvar()             override;
        void salvarDataBuffer();
    };
}