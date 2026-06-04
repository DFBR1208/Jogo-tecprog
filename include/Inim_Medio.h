#pragma once
#include "Inimigo.h"

class Inim_Medio : public Inimigo {
private:
    int tamanho;
public:
    using Inimigo::operator=;
    Inim_Medio();
    Inim_Medio(float px, float py);
    ~Inim_Medio();
    void desenhar()         override;
    void danificar(Jogador* p) override;
    void salvarDataBuffer() override;
    void salva()            override;
};
