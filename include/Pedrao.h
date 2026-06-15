#pragma once
#include "Inimigo.h"
#include "Projetil.h"

namespace Kawabanga::Entidades::Personagens {
    class Pedrao : public Inimigo {
    protected:
        short int forca;
    private:
        Projetil*   pProj;
        int         cooldownTiro;
        static const int INTERVALO_TIRO = 180; // 3s a 60fps
    public:
        using Inimigo::operator=;
        Pedrao();
        Pedrao(float px, float py, int n_vid=4);
        ~Pedrao();
        void executar()            override;
        void danificar(Jogador* p) override;
        void salvarDataBuffer()    override;
        void salva()               override;
        void salvar()              override;
        void setProjetil(Projetil* p) { pProj = p; }
        void tomarDano()              override;
    };
}
