#pragma once
#include "Inimigo.h"

class Inim_Facil : public Inimigo {
private:
    float       raio;
    sf::Texture texBlink;
    sf::Sprite  spriteAnim;
public:
    using Inimigo::operator=;
    Inim_Facil();
    Inim_Facil(float px, float py);
    ~Inim_Facil();
    void executar();
    void danificar(Jogador* p);
    void salvar();
    void salvarDataBuffer() override;
    void salva()            override;
};
