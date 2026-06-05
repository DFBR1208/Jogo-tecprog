#pragma once
#include "Personagem.h"

class Jogador : public Personagem {
private:
    int pontos;
    float velocidadeX;
    float velocidadeY;
    float gravidade;
    float pulo;
    bool noChao;
	bool j1; // true para jogador 1, false para jogador 2

    sf::RectangleShape forma;

    // animacao
    sf::Texture texIdle, texRun, texJump, texFall;
    sf::Sprite  spriteAnim;
    int   frameAtual;
    int   totalFrames;
    float temporizador;
    float duracaoFrame;
    bool  viradoEsquerda;
    enum EstadoAnim { IDLE, RUN, JUMP, FALL } estadoAnim;
    static const int FRAME_SIZE = 32;

    void atualizarAnimacao();
public:
    Jogador(bool flag);
    ~Jogador();
    void executar();
    void mover();
    void desenhar() override;
    void pararNoChao(float y_chao);
    void tomarDano(bool knockback_direita);
    float getVelocidadeY() const;
    void baterCabeca(float base_plataforma);
    sf::FloatRect getBounds() const;
    sf::RectangleShape getForma();
};