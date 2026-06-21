#pragma once
#include "Inimigo.h"

namespace Kawabanga::Entidades::Personagens {
    class Pedroso : public Inimigo {
    private:
        float       raio;
        sf::Texture texBlink;
    public:
        using Inimigo::operator=;
        Pedroso();
        Pedroso(float px, float py, int n_vid = 2);
        ~Pedroso();
        void executar();
        void danificar(Jogador* p);
        void salvar();
    };
}
