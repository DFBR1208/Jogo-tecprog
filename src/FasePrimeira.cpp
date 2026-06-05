#include "FasePrimeira.h"
#include <cstdlib>

FasePrimeira::FasePrimeira(Jogador* pJog1, Jogador* pJog2) : Fase(pJog1, pJog2) {
    criarInimigos();
    criarObstaculo();

    texturaBg.loadFromFile("assests/bg/Pink.png");
    texturaBg.setRepeated(true);
    spriteBg.setTexture(texturaBg);
    spriteBg.setTextureRect(sf::IntRect(0, 0, (int)MUNDO_LARGURA, (int)MUNDO_ALTURA));

    chao.setSize(sf::Vector2f(MUNDO_LARGURA, 700.f));
    chao.setFillColor(sf::Color(101, 67, 33));
    chao.setPosition(0.f, 700.f);
}

FasePrimeira::~FasePrimeira() {}

void FasePrimeira::criarInimigos() {
    criarInimFaceis();
    criarInimMedios();
}

void FasePrimeira::criarInimMedios() {
    int total = rand() % (maxInimMedios - 3 + 1) + 3;
    for (int i = 0; i < total; i++) {
        Inim_Medio* im = new Inim_Medio(0.f, 0.f);
        (*im) = plats[1 + (i % (NUM_PLATS - 1))];
        lista_enti.incluir(im);
        GC.incluirInimigo(im);
    }
}

void FasePrimeira::criarObstaculo() {
    criarObstMedios();
}

void FasePrimeira::criarObstMedios() {
    auto addObst = [&](float x, float y) {
        Obst_Medio* ob = new Obst_Medio(x, y, 40.f);
        lista_enti.incluir(ob);
        GC.incluirObstaculo(ob);
    };
    addObst(120.f, 350.f);
    addObst(600.f, 530.f);
    addObst(590.f, 370.f);
    if (rand() % 2) { addObst(790.f, 370.f); }
}

void FasePrimeira::executar() {
    lista_enti.percorrer();
    GC.executar();
    pGG->atualizarCamera(pJog1->getPosicao(), MUNDO_LARGURA, MUNDO_ALTURA);
}

void FasePrimeira::desenhar() {
    pGG->desenhar(spriteBg);
    pGG->desenhar(chao);
    lista_enti.desenhar();
}
