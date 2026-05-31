#pragma once
#include <SFML/Graphics.hpp>

class Ente;

class Gerenciador_Grafico {
private:
    sf::RenderWindow* window;

    // Texturas do background
    sf::Texture texBg;
    sf::Texture texTerrain;

    // Texturas do player
    sf::Texture texPlayerIdle;
    sf::Texture texPlayerRun;
    sf::Texture texPlayerJump;
    sf::Texture texPlayerFall;
    sf::Texture texPlayerHit;
    sf::Texture texPlayerDoubleJump;
    sf::Texture texPlayerWallJump;

    // Texturas do inimigo
    sf::Texture texEnemyIdle;
    sf::Texture texEnemyBlink;
    sf::Texture texEnemyTopHit;
    sf::Texture texEnemyBottomHit;
    sf::Texture texEnemyLeftHit;
    sf::Texture texEnemyRightHit;

    void carregarTexturas();

public:
    Gerenciador_Grafico();
    ~Gerenciador_Grafico();

    void limpar();
    void desenhar(sf::RectangleShape forma);
    void desenhar(const sf::Sprite& sprite);
    void desenhar(const sf::Drawable& drawable);
    void desenharEnte(Ente* pe);
    void mostrar();
    bool verificaJanelaAberta();
    sf::RenderWindow* getWindow();

    // Getters de texturas - background
    const sf::Texture& getTexBg()      const { return texBg; }
    const sf::Texture& getTexTerrain() const { return texTerrain; }

    // Getters de texturas - player
    const sf::Texture& getTexPlayerIdle()       const { return texPlayerIdle; }
    const sf::Texture& getTexPlayerRun()        const { return texPlayerRun; }
    const sf::Texture& getTexPlayerJump()       const { return texPlayerJump; }
    const sf::Texture& getTexPlayerFall()       const { return texPlayerFall; }
    const sf::Texture& getTexPlayerHit()        const { return texPlayerHit; }
    const sf::Texture& getTexPlayerDoubleJump() const { return texPlayerDoubleJump; }
    const sf::Texture& getTexPlayerWallJump()   const { return texPlayerWallJump; }

    // Getters de texturas - inimigo
    const sf::Texture& getTexEnemyIdle()      const { return texEnemyIdle; }
    const sf::Texture& getTexEnemyBlink()     const { return texEnemyBlink; }
    const sf::Texture& getTexEnemyTopHit()    const { return texEnemyTopHit; }
    const sf::Texture& getTexEnemyBottomHit() const { return texEnemyBottomHit; }
    const sf::Texture& getTexEnemyLeftHit()   const { return texEnemyLeftHit; }
    const sf::Texture& getTexEnemyRightHit()  const { return texEnemyRightHit; }
};