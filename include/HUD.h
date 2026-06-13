#pragma once
#include "Ente.h"

namespace Kawabanga::Entidades::Personagens {
    class Jogador;
}
namespace Kawabanga {
class HUD : public Ente {
    private:
        sf::Text textoPontos;
        sf::RectangleShape coracoes_p1[3];
        sf::RectangleShape coracoes_p2[3];
        sf::Font fonte;
        bool fonteCarregada;
        Entidades::Personagens::Jogador* pJog1;
        Entidades::Personagens::Jogador* pJog2;
    public:
        HUD(Entidades::Personagens::Jogador* pJo1, Entidades::Personagens::Jogador* pJo2);
        ~HUD();
        void executar(); 
        void desenhar();
    };
}