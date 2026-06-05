#pragma once
#include "Personagem.h"
#include "Jogador.h"
#include "Plataforma.h"
#include <ostream>

class Inimigo : public Personagem {
protected:
    int   nivel_maldade;
    float velocidadeX;
    float velocidadeY;
    float gravidade;
    bool  noChao;

    Plataforma* pPlataforma;

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

    void executar()                override;
    void mover()                   override;
    void mover(Plataforma* p);
    sf::FloatRect getBounds() const override;

    Inimigo& operator=(Plataforma* p);
    friend std::ostream& operator<<(std::ostream& os, const Inimigo& ini);

    virtual void danificar(Jogador* p);
    virtual void salvarDataBuffer() = 0;
    virtual void salva()            = 0;
};
