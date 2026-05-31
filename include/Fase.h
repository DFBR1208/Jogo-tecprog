#pragma once
#include "Ente.h"
#include "Jogador.h"
#include "Gerenciador_Colisoes.h"
#include "ListaEntidades.h"

class Fase : public Ente {
protected:
    Jogador*         pJogador;
    ListaEntidades   lista_enti;
    Gerenciador_Colisoes GC;

    void criarInimFaceis();
    void criarPlataformas();
    virtual void criarInimigos() = 0;
    virtual void criarObstaculo() = 0;
    void criarCenario();
    
public:
    Fase();
    virtual ~Fase();
    virtual void executar() = 0;

};