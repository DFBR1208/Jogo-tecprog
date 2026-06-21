#include "Espinhos.h"
#include <fstream>

namespace Kawabanga::Entidades::Obstaculos {
    
    using namespace Personagens;
    Espinhos::Espinhos() : Obstaculo() {
        largura = 60.f;
        danoso  = true;
        forma.setSize(sf::Vector2f(largura, 20.f));
        forma.setFillColor(sf::Color(220, 50, 50));
    }

    Espinhos::Espinhos(float px, float py, float larg) : Obstaculo() {
        largura = larg;
        danoso  = true;
        forma.setSize(sf::Vector2f(largura, 20.f));
        if(pGG)
            forma.setTexture(&pGG->getTexObstaculo());
        forma.setPosition(px, py);
    }

    Espinhos::~Espinhos() {}

    void Espinhos::executar() {
        gravitar();
        antiGravitar();
    }

    void Espinhos::carregarDataBuffer(std::stringstream& ss) {
        Obstaculo::carregarDataBuffer(ss);
        ss >> largura;
        forma.setSize(sf::Vector2f(largura, 20.f));
        forma.setPosition(x, y);
        if (pGG) forma.setTexture(&pGG->getTexObstaculo());
    }

    void Espinhos::obstaculizar(Jogador* p) {
        if (p && danoso)
            p->tomarDano();
    }

    void Espinhos::salvar() {
        x=forma.getPosition().x;
        y=forma.getPosition().y;
        Obstaculo::salvarDataBuffer();
        buffer<<largura<<" ";
        std::ofstream arquivo("saves/save_jogo.txt", std::ios::app);
        if(arquivo.is_open()){
            arquivo<<"ESPINHOS "<<buffer.str()<<std::endl;
        }
    }
}