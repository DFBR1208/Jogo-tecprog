#include "Bola_de_Espinhos.h"
#include <fstream>
float Kawabanga::Entidades::Obstaculos::Bola_de_Espinhos::FORCA_MOLA = 0.07f;
namespace Kawabanga::Entidades::Obstaculos {
    using namespace Personagens;
    Bola_de_Espinhos::Bola_de_Espinhos() : Obstaculo() {
        danosidade = 2;
        danoso = true;
        forma.setSize(sf::Vector2f(30.f, 30.f));
        forma.setFillColor(sf::Color(180, 0, 200));
    }

    Bola_de_Espinhos::Bola_de_Espinhos(float px, float py, float lado) : Obstaculo(), yOrigem(py), velOscilacao(-2.f) {
        danosidade = 2;
        danoso = true;
        forma.setSize(sf::Vector2f(lado, lado));
        forma.setFillColor(sf::Color(180, 0, 200));
        if (pGG)
            forma.setTexture(&pGG->getTexObstaculoD());
        forma.setPosition(px, py);
    }

    Bola_de_Espinhos::~Bola_de_Espinhos() {}

    void Bola_de_Espinhos::executar() {
        gravitar();
        antiGravitar();
        float dy = forma.getPosition().y - yOrigem;
        velOscilacao += -FORCA_MOLA * dy;
        forma.move(0.f, velOscilacao);
    }

    void Bola_de_Espinhos::carregarDataBuffer(std::stringstream& ss) {
        Obstaculo::carregarDataBuffer(ss);
        int leuDanosidade;
        ss >> leuDanosidade >> yOrigem >> velOscilacao;
        danosidade = (short int)leuDanosidade;
        forma.setPosition(x, y);
        if (pGG) forma.setTexture(&pGG->getTexObstaculoD());
    }

    void Bola_de_Espinhos::obstaculizar(Jogador* p) {
        if (!p || !danoso) return;
        for (short i = 0; i < danosidade; ++i)
            p->tomarDano();
    }

    void Bola_de_Espinhos::salvar() {
        x=forma.getPosition().x;
        y=forma.getPosition().y;
        Obstaculo::salvarDataBuffer();
        buffer<<danosidade<<" "<<yOrigem<<" "<<velOscilacao<<" ";
        std::ofstream arquivo("saves/save_jogo.txt", std::ios::app);
        if(arquivo.is_open()){
            arquivo<<"BOLA "<<buffer.str()<<std::endl;
            arquivo.close();
        }
    }
}