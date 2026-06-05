#include "ListaEntidades.h"
#include "Gerenciador_Grafico.h"

ListaEntidades::ListaEntidades() {}
ListaEntidades::~ListaEntidades() {}

void ListaEntidades::incluir(Entidade* pe) { LEs.incluir(pe); }

void ListaEntidades::percorrer() {
    Lista<Entidade>::Iterador it = LEs.getIterador();
    while (it.temProximo()) {
        Entidade* ent = it.proximo();
        if (ent) ent->executar();
    }
}

void ListaEntidades::desenhar() {
    Gerenciador_Grafico* pGG = Ente::getGerenciadorGrafico();
    Lista<Entidade>::Iterador it = LEs.getIterador();
    while (it.temProximo()) {
        Entidade* ent = it.proximo();
        if (ent && pGG) pGG->desenharEnte(ent);
    }
}
