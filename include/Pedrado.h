#pragma once
#include "Inimigo.h"

namespace Kawabanga::Entidades::Personagens {
    class Pedrado : public Inimigo {
    private:
        int tamanho;
        sf::Texture texBlink;
    public:
        using Inimigo::operator=;
        Pedrado();
        Pedrado(float px, float py, int n_vid = 3);
        ~Pedrado();
        void executar();
        void danificar(Jogador* p);
        void salvar();
    };
}
