#include "Jogador.h"
#include "Inimigo.h"
#include <SFML/Window/Keyboard.hpp>

namespace Kawabanga::Entidades::Personagens {
    Jogador::Jogador(bool flag) : Personagem(5), j1(flag), isPoderoso(false), lento(false) {
        pontos = 0;
        if (j1) {
            forma.setSize(sf::Vector2f(30.f, 50.f));
            forma.setFillColor(sf::Color::Transparent); // hitbox invisivel
            forma.setPosition(50.f, 0.f);

            velocidadeX = 5.0f;
            pulo = -15.0f;

            frameAtual = 0;
            totalFrames = 11;
            temporizador = 0;
            duracaoFrame = 7;
            viradoEsquerda = false;
            estadoAnim = IDLE;

            texIdle.loadFromFile("assets/player/Idle (32x32).png");
            texRun.loadFromFile("assets/player/Run (32x32).png");
            texJump.loadFromFile("assets/player/Jump (32x32).png");
            texFall.loadFromFile("assets/player/Fall (32x32).png");

            spriteAnim.setTexture(texIdle);
            spriteAnim.setTextureRect(sf::IntRect(0, 0, FRAME_SIZE, FRAME_SIZE));
            pFig = new Figura(&spriteAnim);
        }
        else {
            forma.setSize(sf::Vector2f(30.f, 50.f));
            forma.setFillColor(sf::Color::Transparent);
            forma.setPosition(75.f, 0.f);

            velocidadeX = 5.0f;
            pulo = -15.0f;

            frameAtual = 0;
            totalFrames = 11;
            temporizador = 0;
            duracaoFrame = 7;
            viradoEsquerda = false;
            estadoAnim = IDLE;

            texIdle.loadFromFile("assets/player/Idle (32x32).png");
            texRun.loadFromFile("assets/player/Run (32x32).png");
            texJump.loadFromFile("assets/player/Jump (32x32).png");
            texFall.loadFromFile("assets/player/Fall (32x32).png");

            spriteAnim.setTexture(texIdle);
            spriteAnim.setTextureRect(sf::IntRect(0, 0, FRAME_SIZE, FRAME_SIZE));
            spriteAnim.setColor(sf::Color(100, 100, 255));
            pFig = new Figura(&spriteAnim);
        }
    }

    Jogador::~Jogador() {}

    void Jogador::executar() {
        if (!isPoderoso) {
            if ((j1 && sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) || 
                (!j1 && sf::Keyboard::isKeyPressed(sf::Keyboard::S))) {
                
                isPoderoso = true;
                timerPoderoso.restart();
                spriteAnim.setColor(sf::Color::Yellow); 
            }
        } else {
            if (timerPoderoso.getElapsedTime().asSeconds() >= duracaoPoderoso) {
                isPoderoso = false;
                spriteAnim.setColor(j1 ? sf::Color::White : sf::Color(100, 100, 255));
            }
        }

        if (lento && timerLento.getElapsedTime().asSeconds() >= duracaoLento) {
            lento = false;
            if (!isPoderoso)
                spriteAnim.setColor(j1 ? sf::Color::White : sf::Color(100, 100, 255));
        }

        mover();
        atualizarAnimacao();

        sf::Vector2f pos  = forma.getPosition();
        sf::Vector2f size = forma.getSize();
        float sx = size.x / FRAME_SIZE;
        float sy = size.y / FRAME_SIZE;
        if (viradoEsquerda) {
            spriteAnim.setScale(-sx, sy);
            spriteAnim.setPosition(pos.x + size.x, pos.y);
        } else {
            spriteAnim.setScale(sx, sy);
            spriteAnim.setPosition(pos.x, pos.y);
        }
    }

    void Jogador::mover() {
        float vx = lento ? velocidadeX * 0.4f : velocidadeX;
        if (j1) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                forma.move(vx, 0.f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                forma.move(-vx, 0.f);
            }
            float pos_x = forma.getPosition().x;
            if (pos_x < 0.f) {
                forma.setPosition(0.f, forma.getPosition().y);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && noChao) {
                velocidadeY = pulo;
                noChao = false;
            }
        }
        else {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                forma.move(vx, 0.f);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                forma.move(-vx, 0.f);
            }
            float pos_x = forma.getPosition().x;
            if (pos_x < 0.f) {
                forma.setPosition(0.f, forma.getPosition().y);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && noChao) {
                velocidadeY = pulo;
                noChao = false;
            }
        }

        gravitar();
        forma.move(0.f, velocidadeY);

        if (forma.getPosition().y >= 700.f) {
            forma.setPosition(forma.getPosition().x, 700.f);
            velocidadeY = 0.0f;
            noChao = true;
        }
    }

    void Jogador::pararNoChao(float y_chao) {
        forma.setPosition(forma.getPosition().x, y_chao - forma.getSize().y);
        velocidadeY = 0.0f;
        noChao = true;
    }

    void Jogador::pararNaParede(float x_parede) {
        forma.setPosition(x_parede, forma.getPosition().y);
    }

    void Jogador::tomarDano(bool knockback_direita) {
        num_vidas--;

        if (num_vidas <= 0) {
            exit(0);
        }
        else {
            if (knockback_direita)
                forma.move(50.f, -50.f);
            else
                forma.move(-50.f, -50.f);
        }
    }

    float Jogador::getVelocidadeY() const {
        return velocidadeY;
    }

    void Jogador::baterCabeca(float base_plataforma) {
        forma.setPosition(forma.getPosition().x, base_plataforma);
        velocidadeY = 0.0f;
    }

    void Jogador::atualizarAnimacao() {
        bool movendo = false;
        if (j1) {
            movendo = sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
            viradoEsquerda = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
        }
        else {
            movendo = sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::A);
            viradoEsquerda = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
        }

        EstadoAnim novoEstado;
        if (!noChao)
            novoEstado = (velocidadeY < 0) ? JUMP : FALL;
        else if (movendo)
            novoEstado = RUN;
        else
            novoEstado = IDLE;

        if (novoEstado != estadoAnim) {
            estadoAnim = novoEstado;
            frameAtual = 0;
            temporizador = 0;
            switch (estadoAnim) {
                case IDLE: spriteAnim.setTexture(texIdle); totalFrames = 11; duracaoFrame = 7; break;
                case RUN:  spriteAnim.setTexture(texRun);  totalFrames = 12; duracaoFrame = 5; break;
                case JUMP: spriteAnim.setTexture(texJump); totalFrames = 1;  duracaoFrame = 1; break;
                case FALL: spriteAnim.setTexture(texFall); totalFrames = 1;  duracaoFrame = 1; break;
            }
        }

        temporizador++;
        if (temporizador >= duracaoFrame) {
            temporizador = 0;
            frameAtual = (frameAtual + 1) % totalFrames;
        }
        spriteAnim.setTextureRect(sf::IntRect(frameAtual * FRAME_SIZE, 0, FRAME_SIZE, FRAME_SIZE));

        if (j1) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) viradoEsquerda = false;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  viradoEsquerda = true;
        }
        else {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) viradoEsquerda = false;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))  viradoEsquerda = true;
        }
    }

    void Jogador::salvar() {}

    sf::FloatRect Jogador::getBounds() const {
        return spriteAnim.getGlobalBounds();
    }

    sf::Vector2f Jogador::getPosicao() const {
        return forma.getPosition();
    }

    sf::RectangleShape Jogador::getForma() {
        return forma;
    }

    int Jogador::getNumVidas() const {
        return num_vidas;
    }

    int Jogador::getPontos() const {
        return pontos;
    }

    void Jogador::adicionarPontos(int n) {
        pontos += n;
    }

    void Jogador::atacar(Inimigo* pIni) {
        if (pIni) {
            pIni->tomarDano();
        }
    }

    bool Jogador::getIsPoderoso() const {return isPoderoso;}

    void Jogador::paraFase2() {
        forma.setPosition(50.f, 0.f);
        velocidadeY = 0.f;
    }

    void Jogador::aplicarSlow() {
        lento = true;
        timerLento.restart();
        spriteAnim.setColor(sf::Color::Cyan);
    }
}