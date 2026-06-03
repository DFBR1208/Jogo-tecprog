#pragma once
#include "Personagem.h"
#include "Jogador.h"

class Inimigo : public Personagem {
protected:
    int   nivel_maldade;
    float velocidadeX;

    sf::RectangleShape forma;
    int   frameAtual;
    int   temporizador;
    static const int FRAME_SIZE    = 42;
    static const int TOTAL_FRAMES  = 4;
    static const int DURACAO_FRAME = 10;

public:
    Inimigo();
    Inimigo(float px, float py);
    virtual ~Inimigo();

    void executar()               override;
    void mover()                  override;
    sf::FloatRect getBounds() const override;

    virtual void danificar(Jogador* p);
    virtual void salvarDataBuffer() = 0;
    virtual void salva()            = 0;
};