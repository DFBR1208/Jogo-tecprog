#pragma once
#include "Obstaculo.h"

namespace Kawabanga::Entidades::Obstaculos {
    class Bola_de_Espinhos : public Obstaculo {
    private:
        short int danosidade;
        float     yOrigem;
        float     velOscilacao;
        static float FORCA_MOLA;
    public:
        Bola_de_Espinhos();
        Bola_de_Espinhos(float px, float py, float lado = 30.f);
        ~Bola_de_Espinhos();
        void executar() override;
        void obstaculizar(Personagens::Jogador* p);
        void salvar() override;
        void salvarDataBuffer();
        void carregarDataBuffer(std::stringstream& ss) override;
    };
}