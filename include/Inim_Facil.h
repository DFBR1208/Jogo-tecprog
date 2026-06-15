#pragma once
#include "Inimigo.h"

namespace Kawabanga::Entidades::Personagens {
    class Inim_Facil : public Inimigo {
    private:
        float       raio;
        sf::Texture texBlink;
    public:
        using Inimigo::operator=;
        Inim_Facil();
        Inim_Facil(float px, float py, int n_vid = 2);
        ~Inim_Facil();
        void executar();
        void danificar(Jogador* p);
        void salvar();
        void salvarDataBuffer() override;
        void salva()            override;
    };
}
