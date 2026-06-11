#pragma once
#include "Entidade.h"

class Projetil : public Entidade {
protected:
    bool  ativo;
    float velocidadeX;
private:
    sf::RectangleShape forma;
public:
    Projetil();
    Projetil(float px, float py, float vx);
    ~Projetil();
    void executar() override;
    void salvar()   override;
    sf::FloatRect getBounds() const override;
    void atirar(float px, float py, float vx);
    bool isAtivo() const { return ativo; }
};
