#pragma once
#include "Obstaculo.h"

namespace Kawabanga::Entidades::Obstaculos {
    class Bola_de_Espinhos : public Obstaculo {
    private:
        short int danosidade;
        float     yOrigem;
        float     velOscilacao;
        static constexpr float FORCA_MOLA = 0.07f;
    public:
        Bola_de_Espinhos();
        Bola_de_Espinhos(float px, float py, float lado = 30.f);
        ~Bola_de_Espinhos();
        void executar()           override;
        void obstaculizar(Personagens::Jogador* p);
        void salvar()             override;
        void salvarDataBuffer();
    };
}