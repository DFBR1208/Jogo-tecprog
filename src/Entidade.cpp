#include "Entidade.h"

namespace Kawabanga::Entidades {

    Entidade::Entidade() : Ente(), x(0), y(0), velocidadeY(0.f), gravidade(1.f), noChao(false) {}

    Entidade::~Entidade() {}

    void Entidade::gravitar() {
        velocidadeY += gravidade;
    }

    void Entidade::salvarDataBuffer() {
        buffer.str("");
        buffer.clear();

        buffer<<id<<" "<<x<<" "<<y<<" "<<velocidadeY<<" "<<(noChao?1:0)<<" ";
    }

    void Entidade::carregarDataBuffer(std::stringstream& ss) {
        int leunoChao;
        ss>>id>>x>>y>>velocidadeY>>leunoChao;
        noChao=(bool)leunoChao;
    }
}