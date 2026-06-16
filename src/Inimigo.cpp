#include "Inimigo.h"
#include <cstdlib>

namespace Kawabanga::Entidades::Personagens {
    using namespace Obstaculos;
    Inimigo::Inimigo(int n_vid) : Personagem(n_vid) {
        nivel_maldade = 1;
        velocidadeX   = -2.0f;
        pRosquinha   = nullptr;
        frameAtual    = 0;
        temporizador  = 0;
        forma.setSize(sf::Vector2f(42.f, 42.f));
        forma.setFillColor(sf::Color::Transparent);
        forma.setPosition(700.f, 508.f);
    }

    Inimigo::Inimigo(float px, float py, int n_vid) : Personagem(n_vid) {
        nivel_maldade = 1;
        velocidadeX   = -1.5f;
        pRosquinha   = nullptr;
        frameAtual    = 0;
        temporizador  = 0;
        forma.setSize(sf::Vector2f(42.f, 42.f));
        forma.setFillColor(sf::Color::Transparent);
        forma.setPosition(px, py);
    }

    Inimigo::~Inimigo() {}

    void Inimigo::executar() {
        if (tomandoDano) {
            if (timerDano.getElapsedTime().asSeconds() >= duracaoDano) {
                tomandoDano = false;
                if(nivel_maldade == 1)
                    spriteAnim.setColor(sf::Color::White);
                else if (nivel_maldade == 2)
                    spriteAnim.setColor(sf::Color::Yellow);
                else if (nivel_maldade == 3)
                forma.setFillColor(sf::Color::Red);
            }
        }
        else {
            if (pRosquinha)
                mover(pRosquinha);
            else
                mover();
        }
    }

    void Inimigo::mover() {
        forma.move(velocidadeX, 0.f);
        if (forma.getPosition().x <= 100.f || forma.getPosition().x >= 760.f)
            velocidadeX = -velocidadeX;

        gravitar();
        forma.move(0.f, velocidadeY);

        float chao_y = 700.f - forma.getSize().y;
        if (forma.getPosition().y > chao_y) {
            forma.setPosition(forma.getPosition().x, chao_y);
            velocidadeY = 0.f;
            noChao = true;
        }
    }

    void Inimigo::mover(Rosquinha* p) {
        sf::FloatRect b = p->getBounds();
        float limEsq = b.left;
        float limDir = b.left + b.width - forma.getSize().x;

        forma.move(velocidadeX, 0.f);

        float px = forma.getPosition().x;
        if (px <= limEsq || px >= limDir)
            velocidadeX = -velocidadeX;

        forma.setPosition(forma.getPosition().x, b.top - forma.getSize().y);
    }

    void Inimigo::setPlataforma(Obstaculos::Rosquinha* p) {
        pRosquinha = p;
        if (p) {
            sf::FloatRect b = p->getBounds();
            float rangeX  = b.width - forma.getSize().x;
            float offsetX = (rangeX > 1.f) ? static_cast<float>(rand() % static_cast<int>(rangeX)) : 0.f;
            forma.setPosition(b.left + offsetX, b.top - forma.getSize().y);
        }
    }

    Inimigo& Inimigo::operator=(Obstaculos::Rosquinha* p) {
        setPlataforma(p);
        return *this;
    }

    std::ostream& operator<<(std::ostream& os, const Inimigo& ini) {
        os << "Inimigo[nivel=" << ini.nivel_maldade
        << ", pos=(" << ini.forma.getPosition().x
        << "," << ini.forma.getPosition().y << ")]";
        return os;
    }

    void Inimigo::danificar(Jogador* p) {
        if (p != nullptr){
            float xJogador=p->getForma().getPosition().x;
            bool knockback_direita = (bool)(xJogador>forma.getPosition().x);
            p->tomarDano(knockback_direita);
        }
    }

    sf::FloatRect Inimigo::getBounds() const {
        return forma.getGlobalBounds();
    }

    void Inimigo::tomarDano() {
    if (!tomandoDano) { 
            num_vidas--;
            tomandoDano = true;
            timerDano.restart(); 
            
            spriteAnim.setColor(sf::Color::Red);
        }
    }

    bool Inimigo::getTomandoDano() const {return tomandoDano;}

    int Inimigo::getNumVidas() const { return num_vidas; }
}