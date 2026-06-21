#pragma once
#include "Fase.h"
#include "Pedrao.h"
#include "Espinhos.h"
#include "Bola_de_Espinhos.h"
#include "Projetil.h"
#include "Rosquinha.h"

namespace Kawabanga::Fases {
    class FaseSegunda : public Fase {
    public:
        static constexpr float MUNDO_LARGURA = 3600.f;
        static constexpr float MUNDO_ALTURA  = 2500.f;
    private:
        sf::Texture texturaBg;
        sf::Sprite  spriteBg;
        sf::RectangleShape chao;

        static const int maxChefoes = 4;

        void criarPedraos();
        void criarBolas();
        Kawabanga::Entidades::Projetil* criarProjetil();
        void criarInimigos()   override;
        void criarObstaculo()  override;
    public:
        FaseSegunda(Entidades::Personagens::Jogador* pJog1, Entidades::Personagens::Jogador* pJog2, bool fromSave = false);
        ~FaseSegunda();
        void executar() override;
        void desenhar();
    };
}
