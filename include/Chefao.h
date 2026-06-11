#pragma once
#include "Inimigo.h"
#include "Projetil.h"

class Chefao : public Inimigo {
protected:
    short int forca;
private:
    sf::Texture texBoss;
    sf::Sprite  spriteAnim;
    Projetil*   pProj;
    int         cooldownTiro;
    static const int INTERVALO_TIRO = 180; // 3s a 60fps
public:
    using Inimigo::operator=;
    Chefao();
    Chefao(float px, float py);
    ~Chefao();
    void executar()            override;
    void danificar(Jogador* p) override;
    void salvarDataBuffer()    override;
    void salva()               override;
    void salvar()              override;
    void setProjetil(Projetil* p) { pProj = p; }
};
