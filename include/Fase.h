#pragma once
#include "Ente.h"
#include "Jogador.h"
#include "Gerenciador_Colisoes.h"
#include "ListaEntidades.h"

class Plataforma;

class Fase : public Ente {
protected:
    ListaEntidades   lista_enti;
    Gerenciador_Colisoes GC;

    static const int maxInimFaceis = 6;
    static const int NUM_PLATS     = 3;
    Plataforma*      plats[NUM_PLATS];

    void criarInimFaceis();
    void criarPlataformas();
    virtual void criarInimigos() = 0;
    virtual void criarObstaculo() = 0;
    void criarCenario();
    
public:
    Fase(Jogador* pJog);
    virtual ~Fase();
    virtual void executar() = 0;
    int getVidas()  const;
    int getPontos() const;

};