#include "ListaEntidades.h"
#include "Gerenciador_Grafico.h"

namespace Kawabanga::Listas { 
    using namespace Entidades;
    using namespace Gerenciadores;
    ListaEntidades::ListaEntidades() {}
    ListaEntidades::~ListaEntidades() {}

    void ListaEntidades::incluir(Entidade* pe) { LEs.incluir(pe); }

    void ListaEntidades::percorrer() {
        Lista<Entidade>::Elemento<Entidade>* pAux = LEs.getPrimeiroElemento();
        
        while (pAux != nullptr) {
            Entidade* ent = pAux->getDado();
            if (ent) ent->executar();
            
            pAux = pAux->getProx();
        }
    }
    void ListaEntidades::desenhar() {
        Gerenciador_Grafico* pGG = Ente::getGerenciadorGrafico();
        Lista<Entidade>::Elemento<Entidade>* pAux = LEs.getPrimeiroElemento();
        
        while (pAux != nullptr) {
            Entidade* ent = pAux->getDado();
            if (ent && pGG) pGG->desenharEnte(ent);
            
            pAux = pAux->getProx();
        }
    }

    void ListaEntidades::remover(Entidade* pe) {
        LEs.limpar(pe);
    }
    Lista<Entidade>::Elemento<Entidade>* ListaEntidades::getPrimeiroElemento() const {
        return LEs.getPrimeiroElemento();
    }
}
