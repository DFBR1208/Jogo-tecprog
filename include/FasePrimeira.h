#pragma once
#include "Fase.h"
#include "Inim_Facil.h"
#include "Inim_Medio.h"
#include "Obst_Medio.h"
#include "Plataforma.h"

namespace Kawabanga::Fases {
    class FasePrimeira : public Fase {
    public:
        static constexpr float MUNDO_LARGURA = 2500.f;
        static constexpr float MUNDO_ALTURA  = 3200.f;
    private:
        sf::Texture texturaBg;
        sf::Sprite  spriteBg;
        sf::RectangleShape chao;

        static const int maxInimMedios = 5;

        void criarInimMedios();
        void criarObstMedios();
        void criarInimigos()  override;
        void criarObstaculo() override;
    public:
        FasePrimeira(Entidades::Personagens::Jogador* pJog1, Entidades::Personagens::Jogador* pJog2);
        ~FasePrimeira();
        void executar() override;
        void desenhar();
    };
}