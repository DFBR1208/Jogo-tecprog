#pragma once
#include "Fase.h"
#include "Chefao.h"
#include "Obst_Medio.h"
#include "Obst_Dificil.h"
#include "Projetil.h"
#include "Plataforma.h"

namespace Kawabanga::Fases {
    class FaseSegunda : public Fase {
    public:
        static constexpr float MUNDO_LARGURA = 3600.f;
        static constexpr float MUNDO_ALTURA  = 2500.f;
    private:
        sf::Texture        texturaBg;
        sf::Sprite         spriteBg;
        sf::RectangleShape chao;

        static const int maxChefoes = 4;

        void criarChefoes();
        void criarObstMedios();
        void criarProjeteis();
        void criarInimigos()   override;
        void criarObstaculo()  override;
    public:
        FaseSegunda(Entidades::Personagens::Jogador* pJog1, Entidades::Personagens::Jogador* pJog2);
        ~FaseSegunda();
        void executar() override;
        void desenhar();
    };
}
