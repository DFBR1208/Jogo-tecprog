#pragma once
#include "Fase.h"
#include "Pedroso.h"
#include "Pedrado.h"
#include "Espinhos.h"
#include "Rosquinha.h"

namespace Kawabanga::Fases {
    class FasePrimeira : public Fase {
    public:
        // constexpr permite definir o valor diretamente no .h
        static constexpr float MUNDO_LARGURA = 2500.f;
        static constexpr float MUNDO_ALTURA  = 3200.f;
    private:
        sf::Texture texturaBg;
        sf::Sprite  spriteBg;
        sf::RectangleShape chao;

        static const int maxInimMedios = 5;

        void criarPedrados();
        void criarEspinhos();
        void criarInimigos()  override;
        void criarObstaculo() override;
    public:
        FasePrimeira(Entidades::Personagens::Jogador* pJog1, Entidades::Personagens::Jogador* pJog2, bool fromSave = false);
        ~FasePrimeira();
        void executar() override;
        void desenhar();
    };
}