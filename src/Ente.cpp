#include "Ente.h"

Gerenciador_Grafico* Ente::pGG = nullptr;

Ente::Ente() {
    id = 0;
}

Ente::~Ente() {}

void Ente::desenhar() {
    if (pGG != nullptr) {
        pGG->desenhar(forma);
    }
}

void Ente::setGerenciadorGrafico(Gerenciador_Grafico* pG) {
    pGG = pG;
}

Gerenciador_Grafico* Ente::getGerenciadorGrafico() {
    return pGG;
}

const sf::RectangleShape& Ente::getForma() const {
    return forma;
}