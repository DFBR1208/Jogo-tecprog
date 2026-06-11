#pragma once
#include "Fase.h"
#include "Chefao.h"
#include "Obst_Medio.h"
#include "Obst_Dificil.h"
#include "Projetil.h"
#include "Plataforma.h"

class FaseSegunda : public Fase {
public:
    static constexpr float MUNDO_LARGURA = 800.f;
    static constexpr float MUNDO_ALTURA  = 750.f;
private:
    sf::Texture        texturaBg;
    sf::Sprite         spriteBg;
    sf::RectangleShape chao;

    static const int maxChefoes = 2;

    void criarChefoes();
    void criarObstMedios();
    void criarProjeteis();
    void criarInimigos()   override;
    void criarObstaculo()  override;
public:
    FaseSegunda(Jogador* pJog1, Jogador* pJog2);
    ~FaseSegunda();
    void executar() override;
    void desenhar();
};
