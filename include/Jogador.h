#pragma once
#include "Personagem.h"

namespace Kawabanga::Entidades::Personagens {
    class Inimigo;
}

namespace Kawabanga::Entidades::Personagens {
    class Jogador : public Personagem {
    private:
        int pontos;
        float velocidadeX;
        float pulo;
        bool j1; /*Lógica booleana baseada no projeto de Deborah Feijó e Rafael 
                   Fernandes conforme está no reltório*/
        bool isPoderoso;
        sf::Clock timerPoderoso;
        const float duracaoPoderoso = 4.0f;

        bool lento;
        sf::Clock timerLento;
        const float duracaoLento = 3.0f;

        sf::RectangleShape forma;

        sf::Texture texIdle, texRun, texJump, texFall;
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
        void pararNoChao(float y_chao);
        void pararNaParede(float x_parede);
        void tomarDano(bool knockback_direita = false);
        float getVelocidadeY() const;
        void baterCabeca(float base_plataforma);
        void salvar();
        sf::FloatRect      getBounds()   const;
        sf::Vector2f       getPosicao()  const;
        sf::RectangleShape getForma();
        int  getNumVidas()       const;
        int  getPontos()         const;
        void adicionarPontos(int n);
        void atacar(Inimigo* pIni);
        bool getIsPoderoso() const;
        void aplicarSlow();
        void paraFase2();
    };
}