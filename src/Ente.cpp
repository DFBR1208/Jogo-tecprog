#include "Ente.h"

namespace Kawabanga {

    using namespace Gerenciadores;

    Gerenciador_Grafico* Ente::pGG = nullptr;

    Ente::Ente() : id(0), pFig(nullptr) {}

    Ente::~Ente() {
        delete pFig;
        pFig = nullptr;
    }

    void Ente::desenhar() {
        if (pGG && pFig && pFig->getDrawable())
            pGG->desenhar(*pFig->getDrawable());
    }

    void Ente::setGerenciadorGrafico(Gerenciador_Grafico* pG) {
        pGG = pG;
    }

    Gerenciador_Grafico* Ente::getGerenciadorGrafico() {
        return pGG;
    }
}
