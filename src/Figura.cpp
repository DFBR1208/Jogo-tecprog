#include "Figura.h"

Figura::Figura() : pDrawable(nullptr) {}

Figura::Figura(sf::Drawable* pd) : pDrawable(pd) {}

Figura::~Figura() {}

void Figura::setDrawable(sf::Drawable* pd) {
	pDrawable = pd;
}

sf::Drawable* Figura::getDrawable() const {
	return pDrawable;
}