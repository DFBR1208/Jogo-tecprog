#pragma once
#include "Fase.h"
#include "Inim_Facil.h"
#include "Plataforma.h"

class Jogador;

class FasePrimeira : public Fase {
private:
    sf::Texture texturaBg;
    sf::Sprite  spriteBg;
    sf::RectangleShape chao;

    static const int maxInimMedios = 0;

    void criarInimMedios();
    void criarObstMedios();
    void criarInimigos()  override;
    void criarObstaculo() override;
public:
    FasePrimeira(Jogador* pJog1, Jogador* pJog2);
    ~FasePrimeira();
    void executar() override;
    void desenhar() override;
};
