#include "Fase.h"
#include "Plataforma.h"
#include "Inim_Facil.h"

Fase::Fase() : Ente(), pJogador(new Jogador()), GC(pJogador) {
    criarPlataformas();
    criarCenario();
}


Fase::~Fase() {
    delete pJogador;
}

void Fase::criarInimFaceis() {
    static const float xs[] = { 80.f};
    for (float x : xs) {
        Inim_Facil* ini = new Inim_Facil(x, 508.f);
        lista_enti.incluir(ini);
        GC.incluirInimigo(ini);
    }
}

void Fase::criarPlataformas() {
    auto addPlat = [&](float x, float y, float w) {
        Plataforma* p = new Plataforma(x, y, w);
        lista_enti.incluir(p);
        GC.incluirObstaculo(p);
    };
    
    addPlat(100.f, 350.f, 200.f);
    addPlat(300.f, 450.f, 200.f);
}

void Fase::criarCenario() {}