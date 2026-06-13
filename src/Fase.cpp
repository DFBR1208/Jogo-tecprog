#include "Fase.h"
#include "Plataforma.h"
#include "Inim_Facil.h"
#include <cstdlib>

namespace Kawabanga::Fases {

    using namespace Entidades::Personagens;
    using namespace Entidades::Obstaculos;
    Fase::Fase(Jogador* pJo1, Jogador* pJo2) : Ente(), GC(pJo1, pJog2), pJog1(pJo1), pJog2(pJo2) {
        for (int i = 0; i < NUM_PLATS; i++) plats[i] = nullptr;
        criarPlataformas();
        criarCenario();
        if(pJog1)
            lista_enti.incluir(pJog1);
        if(pJog2)
            lista_enti.incluir(pJog2);
    }

    Fase::~Fase() {}

    void Fase::criarInimFaceis() {
        auto addIniF = [&](Plataforma* plat) {
            Inim_Facil* ini = new Inim_Facil(0.f, 0.f);
            (*ini) = plat;
            lista_enti.incluir(ini);
            GC.incluirInimigo(ini);
        };

        addIniF(plats[1]);
        addIniF(plats[3]);
        addIniF(plats[7]);
        if (rand()%10 == 1) {addIniF(plats[3]);}

    }


void Fase::criarPlataformas() {
    auto addPlat = [&](int idx, float x, float y, float w) {
        Plataforma* p = new Plataforma(x, y, w);
        plats[idx] = p;
        lista_enti.incluir(p);
        GC.incluirObstaculo(p);
    };
    addPlat(0, 100.f, 650.f, 200.f);
    addPlat(1, 350.f, 550.f, 450.f);
    addPlat(2, 880.f, 470.f, 500.f);
    addPlat(3, 410.f, 370.f, 600.f);
    addPlat(4, 410.f, 270.f, 100.f);
    addPlat(5, 660.f, 270.f, 100.f);
    addPlat(6, 509.f, 170.f, 100.f);
    addPlat(7, 1400.f, 530.f, 400.f);
    addPlat(8, 1600.f, 400.f, 250.f);
    addPlat(9, 1900.f, 330.f, 300.f);
    addPlat(10, 2200.f, 230.f, 300.f);
}

void Fase::criarCenario() {}
}

