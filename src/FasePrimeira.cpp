#include "FasePrimeira.h"

FasePrimeira::FasePrimeira(Jogador* pJog1, Jogador* pJog2) : Fase(pJog1, pJog2) {
    criarInimigos();
    criarObstaculo();

    texturaBg.loadFromFile("assests/bg/Pink.png");
    texturaBg.setRepeated(true);
    spriteBg.setTexture(texturaBg);
    spriteBg.setTextureRect(sf::IntRect(0, 0, 800, 600));

    chao.setSize(sf::Vector2f(800.f, 50.f));
    chao.setFillColor(sf::Color(101, 67, 33));
    chao.setPosition(0.f, 550.f);
}

FasePrimeira::~FasePrimeira() {}

void FasePrimeira::criarInimigos() {
    criarInimFaceis();
    criarInimMedios();
}

void FasePrimeira::criarInimMedios() {
    // Inim_Medio ainda nao implementado
}

void FasePrimeira::criarObstaculo() {
    criarObstMedios();
}

void FasePrimeira::criarObstMedios() {
    // Obst_Medio ainda nao implementado
}

void FasePrimeira::executar() {
    lista_enti.percorrer();
    GC.executar();
}

void FasePrimeira::desenhar() {
    pGG->desenhar(spriteBg);
    pGG->desenhar(chao);
    lista_enti.desenhar();
}
