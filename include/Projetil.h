#pragma once
#include "Entidade.h"

namespace Kawabanga::Entidades::Personagens {
    class Pedrao;
}

namespace Kawabanga::Entidades {
    class Projetil : public Entidade {
    protected:
        bool  ativo;
        float velocidadeX;
        Kawabanga::Entidades::Personagens::Pedrao* pChefao;
    private:
        sf::RectangleShape forma;
    public:
        Projetil();
        Projetil(float px, float py, float vx);
        ~Projetil();
        void executar() override;
        void salvar();
        sf::FloatRect getBounds() const override;
        void atirar(float px, float py, float vx);
        bool isAtivo() const;
        void setChefao(Kawabanga::Entidades::Personagens::Pedrao* ch);
        Kawabanga::Entidades::Personagens::Pedrao* getChefao() const;
    };
}
