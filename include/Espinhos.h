#pragma once
#include "Obstaculo.h"

namespace Kawabanga::Entidades::Obstaculos {
    class Espinhos : public Obstaculo {
    private:
        float largura;
    public:
        Espinhos();
        Espinhos(float px, float py, float larg = 40.f);
        ~Espinhos();
        void obstaculizar(Personagens::Jogador* p);
        void executar();
        void salvar();
    };
}