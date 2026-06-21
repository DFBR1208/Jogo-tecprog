#include "Personagem.h"

namespace Kawabanga::Entidades::Personagens {
    Personagem::Personagem(int n_vi) : Entidade(), num_vidas(n_vi) {}

    Personagem::~Personagem() {}

    void Personagem::salvarDataBuffer() {
        Entidade::salvarDataBuffer();
        buffer<<num_vidas<<" ";
    }

    void Personagem::carregarDataBuffer(std::stringstream& ss) {
        Entidade::carregarDataBuffer(ss);
        ss>>num_vidas;
    }
}