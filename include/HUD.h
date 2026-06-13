#pragma once
#include "Ente.h"

namespace Kawabanga::Entidades::Personagens {
    class Jogador;
}
namespace Kawabanga {
class HUD : public Ente {
    private:
        sf::Text textoPontos;
        sf::RectangleShape coracoes[3];
        sf::Font fonte;
        bool fonteCarregada;
        Entidades::Personagens::Jogador* pJog1;
    public:
        HUD(Entidades::Personagens::Jogador* pJo1);
        ~HUD();
        void executar(); 
        void desenhar();
    };
}