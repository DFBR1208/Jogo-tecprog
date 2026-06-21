#include "Pedrao.h"
#include <fstream>

namespace Kawabanga::Entidades::Personagens {
    Pedrao::Pedrao() : Inimigo(4), forca(2), pProj(nullptr), cooldownTiro(INTERVALO_TIRO), curando(false) {
        nivel_maldade = 3;
        velocidadeX   = -1.2f;
        forma.setSize(sf::Vector2f(64.f, 64.f));
        forma.setFillColor(sf::Color::Red);
        if (pGG) {
            forma.setTexture(&pGG->getTexBoss());
        }
        pFig = new Figura(&forma);
    }

    Pedrao::Pedrao(float px, float py, int n_vid) : Inimigo(px, py, n_vid), forca(2), pProj(nullptr), cooldownTiro(INTERVALO_TIRO) {
        nivel_maldade = 3;
        velocidadeX   = -1.2f;
        forma.setSize(sf::Vector2f(64.f, 64.f));
        forma.setFillColor(sf::Color::Red);
        if (pGG) {
            forma.setTexture(&pGG->getTexBoss());
        }
        pFig = new Figura(&forma);
    }

    Pedrao::~Pedrao() {}

    void Pedrao::executar() {
        Inimigo::executar();
        sf::Vector2f pos  = forma.getPosition();
        sf::Vector2f size = forma.getSize();
        // tiro
        if (pProj) {
            cooldownTiro--;
            if (cooldownTiro <= 0) {
                cooldownTiro = INTERVALO_TIRO;
                float projX = (velocidadeX < 0) ? pos.x : pos.x + size.x;
                float projY = pos.y + size.y * 0.4f;
                float projVX = (velocidadeX < 0) ? -7.f : 7.f;
                pProj->atirar(projX, projY, projVX);
            }
        }
        if(curando) {
            if(timerCura.getElapsedTime().asSeconds() >= duracaoCura) {
                forma.setFillColor(sf::Color::Red);
                curando = false;
            }
        }
    }

    void Pedrao::danificar(Jogador* p) {
        if (!p) return;
        bool dir = (p->getForma().getPosition().x > forma.getPosition().x);
        for (short i = 0; i <= forca; ++i)
            p->tomarDano(dir);
        p->adicionarPontos(-100);
    }

    void Pedrao::salvar() {
        x=forma.getPosition().x;
        y=forma.getPosition().y;
        Inimigo::salvarDataBuffer();
        buffer<<forca<<" "<<(curando?1:0)<<" ";
        std::ofstream arquivo("saves/save_jogo.txt", std::ios::app);
        if(arquivo.is_open()){
            arquivo<<"PEDRAO "<<buffer.str()<<std::endl;
            arquivo.close();
        }
    }

    void Pedrao::carregarDataBuffer(std::stringstream& ss) {
        Inimigo::carregarDataBuffer(ss);
        int leuCurando;
        ss >> forca >> leuCurando;
        curando = (bool)leuCurando;
        if (curando) {
            timerCura.restart();
            forma.setFillColor(sf::Color::Green);
        }
        if(tomandoDano) {
            forma.setFillColor(sf::Color::Blue);
        }
    }

    void Pedrao::tomarDano() {
        if (!tomandoDano) {
            num_vidas--;
            tomandoDano = true;
            timerDano.restart();
            forma.setFillColor(sf::Color::Blue);
        }
    }

    void Pedrao::setProjetil(Projetil* p) {
        pProj = p;
    }

    void Pedrao::projetilAtingiu() {
        if (pProj) {
            num_vidas++;
            curando = true;
            timerCura.restart();
            forma.setFillColor(sf::Color::Green);
        }
    }
}