#include "Fase.h"
#include "Plataforma.h"
#include "Inim_Facil.h"
#include <cstdlib>

Fase::Fase() : Ente(), pJogador(new Jogador()), GC(pJogador) {
    for (int i = 0; i < NUM_PLATS; i++) plats[i] = nullptr;
    criarPlataformas();
    criarCenario();
}

Fase::~Fase() {
    delete pJogador;
}

void Fase::criarInimFaceis() {
    int total = rand() % (maxInimFaceis - 3 + 1) + 3; // [3, maxInimFaceis]
    for (int i = 0; i < total; i++) {
        Inim_Facil* ini = new Inim_Facil(0.f, 0.f);
        (*ini) = plats[i % NUM_PLATS]; // posiciona na plataforma via operator=
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
