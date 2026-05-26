#pragma once
#include <SFML/Graphics.hpp>

class Gerenciador_Grafico {
private:
    sf::RenderWindow* window;
public:
    Gerenciador_Grafico();
    ~Gerenciador_Grafico();
    
    void limpar();
    void desenhar(sf::RectangleShape forma);
    void mostrar();
    bool verificaJanelaAberta(); 
};