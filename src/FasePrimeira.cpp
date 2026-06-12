#include "FasePrimeira.h"
#include <cstdlib>

FasePrimeira::FasePrimeira(Jogador* pJog1, Jogador* pJog2) : Fase(pJog1, pJog2) {
    criarInimigos();
    criarObstaculo();

    texturaBg.loadFromFile("assests/bg/Pink.png");
    texturaBg.setRepeated(true);
    spriteBg.setTexture(texturaBg);
    spriteBg.setTextureRect(sf::IntRect(0, 0, (int)MUNDO_LARGURA, (int)MUNDO_ALTURA));

    chao.setSize(sf::Vector2f(MUNDO_LARGURA, 750.f));
    chao.setFillColor(sf::Color(101, 67, 33));
    chao.setPosition(0.f, 750.f);
}

FasePrimeira::~FasePrimeira() {}

void FasePrimeira::criarInimigos() {
    criarInimFaceis();
    criarInimMedios();
}

void FasePrimeira::criarInimMedios() {
    auto addIniM = [&](Plataforma* plat) {
        Inim_Medio* im = new Inim_Medio(0.f, 0.f);
        (*im) = plat;
        lista_enti.incluir(im);
        GC.incluirInimigo(im);
    };

    
    addIniM(plats[2]);
    addIniM(plats[7]);
    addIniM(plats[9]);
    if (rand()%10 == 1) {addIniM(plats[10]);}
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
    addObst(410.f, 250.f);
    addObst(1300.f, 450.f);
    addObst(690.f, 350.f);
    if (rand()%10 == 1) {addObst(1700.f, 350.f);}
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
