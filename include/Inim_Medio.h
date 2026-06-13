#pragma once
#include "Inimigo.h"

namespace Kawabanga::Entidades::Personagens {
    class Inim_Medio : public Inimigo {
    private:
        int tamanho;
        sf::Texture texBlink;
        sf::Sprite  spriteAnim;
    public:
        using Inimigo::operator=;
        Inim_Medio();
        Inim_Medio(float px, float py);
        ~Inim_Medio();
        void executar();
        void danificar(Jogador* p);
        void salvar();
        void salvarDataBuffer() override;
        void salva()            override;
    };
}
