#include "Entidade.h"

Entidade::Entidade() : Ente(), x(0), y(0), velocidadeY(0.f), gravidade(1.f), noChao(false) {}

Entidade::~Entidade() {}

void Entidade::gravitar() {
    velocidadeY += gravidade;
}

void Entidade::SalvarDataBuffer() {}