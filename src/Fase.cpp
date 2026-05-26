#include "Fase.h"

Fase::Fase() : Ente() {
    pJogador = nullptr;
}

Fase::~Fase() {
    if (pJogador != nullptr) {
        delete pJogador;
    }
}