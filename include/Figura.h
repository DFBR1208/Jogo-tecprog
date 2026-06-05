#pragma once
#include <SFML/Graphics.hpp>

class Figura {
private:
    sf::Drawable* pDrawable;
public:
    Figura() : pDrawable(nullptr) {}
    Figura(sf::Drawable* pd) : pDrawable(pd) {}
    void           setDrawable(sf::Drawable* pd) { pDrawable = pd; }
    sf::Drawable*  getDrawable() const           { return pDrawable; }
};
