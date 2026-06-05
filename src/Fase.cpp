#include "Fase.h"
#include "Plataforma.h"
#include "Inim_Facil.h"
#include <cstdlib>

Fase::Fase(Jogador* pJog) : Ente(), pJogador(pJog), GC(pJog) {
    for (int i = 0; i < NUM_PLATS; i++) plats[i] = nullptr;
    criarPlataformas();
    criarCenario();
    lista_enti.incluir(pJog); 
}

Fase::~Fase() {}

void Fase::criarInimFaceis() {
    int total = rand() % (maxInimFaceis - 3 + 1) + 3;
    for (int i = 1; i < total + 1; i++) {
        Inim_Facil* ini = new Inim_Facil(0.f, 0.f);
        (*ini) = plats[1 + (i % (NUM_PLATS - 1))];
        lista_enti.incluir(ini);
        GC.incluirInimigo(ini);
    }
}

void Fase::criarPlataformas() {
    auto addPlat = [&](int idx, float x, float y, float w) {
        Plataforma* p = new Plataforma(x, y, w);
        plats[idx] = p;
        lista_enti.incluir(p);
        GC.incluirObstaculo(p);
    };
    addPlat(0, 100.f, 250.f, 400.f);
    addPlat(1, 300.f, 450.f, 200.f);
    addPlat(2, 520.f, 370.f, 200.f);
}

void Fase::criarCenario() {}

int Fase::getVidas()  const { return pJogador->getNumVidas(); }
int Fase::getPontos() const { return pJogador->getPontos(); }
