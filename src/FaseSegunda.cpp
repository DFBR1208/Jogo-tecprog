#include "FaseSegunda.h"
#include <cstdlib>

FaseSegunda::FaseSegunda(Jogador* pJog1, Jogador* pJog2) : Fase(pJog1, pJog2) {
    criarInimigos();
    criarObstaculo();
    criarProjeteis();

    texturaBg.loadFromFile("assests/bg/Pink.png");
    texturaBg.setRepeated(true);
    spriteBg.setTexture(texturaBg);
    spriteBg.setTextureRect(sf::IntRect(0, 0, (int)MUNDO_LARGURA, (int)MUNDO_ALTURA));
    spriteBg.setColor(sf::Color(200, 160, 220));

    chao.setSize(sf::Vector2f(MUNDO_LARGURA, 750.f));
    chao.setFillColor(sf::Color(60, 20, 80));
    chao.setPosition(0.f, 750.f);
}

FaseSegunda::~FaseSegunda() {}

void FaseSegunda::criarInimigos() {
    criarChefoes();
}

void FaseSegunda::criarChefoes() {
    int criados = 0;
    for (int i = 1; i < NUM_PLATS && criados < maxChefoes; i += 2) {
        if (!plats[i]) continue;
        Chefao* ch = new Chefao(0.f, 0.f);
        (*ch) = plats[i];

        Projetil* proj = new Projetil();
        ch->setProjetil(proj);

        lista_enti.incluir(ch);
        lista_enti.incluir(proj);
        GC.incluirInimigo(ch);
        GC.incluirProjetil(proj);
        ++criados;
    }
}

void FaseSegunda::criarObstaculo() {
    criarObstMedios();
}

void FaseSegunda::criarObstMedios() {
    auto addOD = [&](float x, float y) {
        Obst_Dificil* od = new Obst_Dificil(x, y, 35.f);
        lista_enti.incluir(od);
        GC.incluirObstaculo(od);
    };
    addOD(410.f, 235.f);
    addOD(1300.f, 435.f);
    addOD(690.f, 335.f);
    if (rand()%10 == 1) {addOD(1700.f, 335.f);}
}

void FaseSegunda::criarProjeteis() {
    // Projeteis ja criados e atribuidos em criarChefoes()
}

void FaseSegunda::executar() {
    lista_enti.percorrer();
    GC.executar();
    pGG->atualizarCamera(pJog1->getPosicao(), MUNDO_LARGURA, MUNDO_ALTURA);
}

void FaseSegunda::desenhar() {
    pGG->desenhar(spriteBg);
    pGG->desenhar(chao);
    lista_enti.desenhar();
}
