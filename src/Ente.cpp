#include "Ente.h"

namespace Kawabanga {

    using namespace Gerenciadores;

    Gerenciador_Grafico* Ente::pGG = nullptr;

    Ente::Ente() : id(contadorId++), pFig(nullptr) {}

    Ente::~Ente() {
        delete pFig;
        pFig = nullptr;
    }

    void Ente::desenhar() {}

    Figura* Ente::getFigura() const { return pFig; }

    void Ente::setGerenciadorGrafico(Gerenciador_Grafico* pG) {
        pGG = pG;
    }

    Gerenciador_Grafico* Ente::getGerenciadorGrafico() {
        return pGG;
    }

    int Ente::getId() {return id;}
}
int Kawabanga::Ente::contadorId=0;
