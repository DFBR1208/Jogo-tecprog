#pragma once
#include <SFML/Graphics.hpp>

namespace Kawabanga {
    class Figura {
    private:
        sf::Drawable* pDrawable;
    public:
        Figura();
        Figura(sf::Drawable* pd);
        ~Figura();
        void setDrawable(sf::Drawable* pd);
        sf::Drawable* getDrawable() const;
    };
}