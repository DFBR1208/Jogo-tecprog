#include "Projetil.h"
#include "Pedrao.h"
#include <fstream>

namespace Kawabanga::Entidades {
    using namespace Personagens;
    Projetil::Projetil() : Entidade(), ativo(false), velocidadeX(0.f), idChefaoCarregado(-1) {
        forma.setSize(sf::Vector2f(20.f, 15.f));
        forma.setPosition(-100.f, -100.f);
        if (pGG) {
            forma.setTexture(&pGG->getTexProjetil());
        }
        pFig = new Figura(&forma);
    }

    Projetil::Projetil(float px, float py, float vx)
        : Entidade(), ativo(true), velocidadeX(vx) {
        forma.setSize(sf::Vector2f(20.f, 15.f));
        forma.setPosition(px, py);
        if (pGG) {
            forma.setTexture(&pGG->getTexProjetil());
        }
        pFig = new Figura(&forma);
    }

    Projetil::~Projetil() {}

    void Projetil::executar() {
        if (!ativo) return;
        gravitar();
        forma.move(velocidadeX, velocidadeY);
        sf::Vector2f pos = forma.getPosition();
        if (pos.x < -50.f || pos.x > 3700.f || pos.y > 2600.f)
            ativo = false;
    }


    sf::FloatRect Projetil::getBounds() const {
        if (!ativo) return sf::FloatRect(-1000.f, -1000.f, 0.f, 0.f);
        return forma.getGlobalBounds();
    }

    void Projetil::atirar(float px, float py, float vx) {
        forma.setPosition(px, py);
        velocidadeX = vx;
        velocidadeY = 0.f;
        ativo = true;
    }

    bool Projetil::isAtivo() const {
        return ativo;
    }

    void Projetil::setChefao(Pedrao* ch) {
        pChefao = ch;
    }

    Pedrao* Projetil::getChefao() const {
        return pChefao;
    }

    void Projetil::carregarDataBuffer(std::stringstream& ss) {
        Entidade::carregarDataBuffer(ss);
        int leuAtivo;
        ss >> velocidadeX >> leuAtivo >> idChefaoCarregado;
        ativo = (bool)leuAtivo;
        forma.setPosition(x, y);
    }

    int Projetil::getIdChefaoCarregado() const { return idChefaoCarregado; }

    void Projetil::salvar() {
        x=forma.getPosition().x;
        y=forma.getPosition().y;
        Entidade::salvarDataBuffer();
        int idPedrao=(pChefao!=nullptr)?pChefao->getId():-1;
        buffer<<velocidadeX<<" "<<(ativo?1:0)<<" "<<idPedrao<<" ";
        std::ofstream arquivo("saves/save_jogo.txt", std::ios::app);
        if (arquivo.is_open()){
            arquivo << "PROJETIL " << buffer.str() << std::endl;
            arquivo.close();
        }
    }
}