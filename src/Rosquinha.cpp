#include "Rosquinha.h"
#include <algorithm>
#include <fstream>

namespace Kawabanga::Entidades::Obstaculos {
    using namespace Personagens;
    Rosquinha::Rosquinha() : Obstaculo() {
        danoso = false;

        forma.setSize(sf::Vector2f(200.f, 30.f));
        forma.setFillColor(sf::Color::White);
        forma.setPosition(300.f, 450.f);
    }

    Rosquinha::Rosquinha(float px, float py, float largura) : Obstaculo() {
        danoso = false;
        forma.setSize(sf::Vector2f(largura, 30.f));
        forma.setPosition(px, py);
        if (pGG) {
            forma.setTexture(&pGG->getTexPlataforma());
            forma.setTextureRect(sf::IntRect(0, 0, (int)largura, 30));
        }
    }

    Rosquinha::~Rosquinha() {}

    void Rosquinha::executar() {
        gravitar();
        antiGravitar();
    }
    
    void Rosquinha::salvar() {
        x=forma.getPosition().x;
        y=forma.getPosition().y;
        Obstaculo::salvarDataBuffer();
        buffer<<forma.getSize().x<<" ";
        std::ofstream arquivo("saves/save_jogo.txt", std::ios::app);
        if(arquivo.is_open()){
            arquivo<<"ROSQUINHA "<<buffer.str()<<std::endl;
            arquivo.close();
        }
    }

    void Rosquinha::carregarDataBuffer(std::stringstream& ss) {
        Obstaculo::carregarDataBuffer(ss);
        float largura;
        ss >> largura;
        forma.setSize(sf::Vector2f(largura, 30.f));
        forma.setPosition(x, y);
        if (pGG) {
            forma.setTexture(&pGG->getTexPlataforma());
            forma.setTextureRect(sf::IntRect(0, 0, (int)largura, 30));
        }
    }

    void Rosquinha::obstaculizar(Jogador* p) {
        if (p == nullptr) return;

        sf::FloatRect pBounds  = p->getBounds();
        sf::FloatRect plBounds = forma.getGlobalBounds();

        float overlapTop    = (pBounds.top + pBounds.height) - plBounds.top;
        float overlapBottom = (plBounds.top + plBounds.height) - pBounds.top;
        float overlapLeft   = (pBounds.left + pBounds.width) - plBounds.left;
        float overlapRight  = (plBounds.left + plBounds.width) - pBounds.left;

        float minOverlapV = std::min(overlapTop, overlapBottom);
        float minOverlapH = std::min(overlapLeft, overlapRight);

        if (minOverlapV < minOverlapH) {
            if (overlapTop < overlapBottom && p->getVelocidadeY() >= 0.f)
                p->pararNoChao(plBounds.top);
            else if (overlapBottom < overlapTop && p->getVelocidadeY() < 0.f)
                p->baterCabeca(plBounds.top + plBounds.height);
        }
        else {
            if (overlapLeft < overlapRight)
                p->pararNaParede(plBounds.left - pBounds.width);
            else if (overlapRight < overlapLeft)
                p->pararNaParede(plBounds.left + plBounds.width);
        }
    }
}