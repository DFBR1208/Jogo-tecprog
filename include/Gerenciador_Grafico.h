#pragma once
#include <SFML/Graphics.hpp>

namespace Kawabanga {
    class Ente;
}

namespace Kawabanga::Gerenciadores {
    class Gerenciador_Grafico {
    private:
        sf::RenderWindow* window;
        sf::View camera;

        sf::Texture texBg;
        sf::Texture texTerrain;
        sf::Texture texPlataforma;

        sf::Texture texPlayerIdle;
        sf::Texture texPlayerRun;
        sf::Texture texPlayerJump;
        sf::Texture texPlayerFall;
        sf::Texture texPlayerHit;
        sf::Texture texPlayerDoubleJump;
        sf::Texture texPlayerWallJump;

        sf::Texture texEnemyIdle;
        sf::Texture texEnemyBlink;
        sf::Texture texEnemyTopHit;
        sf::Texture texEnemyBottomHit;
        sf::Texture texEnemyLeftHit;
        sf::Texture texEnemyRightHit;

        sf::Texture texObstaculo;
        sf::Texture texProjetil;
        sf::Texture texBoss;
        sf::Texture texObstaculoD;

        void carregarTexturas();

        std::string textoDigitado;

    public:
        Gerenciador_Grafico();
        ~Gerenciador_Grafico();

        void limpar();
        void desenharEnte(Ente* pe);
        void desenharEnte(const sf::Drawable& d);
        void mostrar();
        bool verificaJanelaAberta();
        sf::RenderWindow* getWindow();

        void atualizarCamera(sf::Vector2f posJogador, float mundoLargura, float mundoAltura);
        void resetarViewUI();
        void focarCameraJogo();
        void resetarTextoDigitado();
        const std::string& getTextoDigitado(); 

        const sf::Texture& getTexBg()         const;
        const sf::Texture& getTexTerrain()    const;
        const sf::Texture& getTexPlataforma() const;
        const sf::Texture& getTexObstaculo() const;

        const sf::Texture& getTexPlayerIdle()       const;
        const sf::Texture& getTexPlayerRun()        const;
        const sf::Texture& getTexPlayerJump()       const;
        const sf::Texture& getTexPlayerFall()       const;
        const sf::Texture& getTexPlayerHit()        const;
        const sf::Texture& getTexPlayerDoubleJump() const;
        const sf::Texture& getTexPlayerWallJump()   const;

        const sf::Texture& getTexEnemyIdle()      const;
        const sf::Texture& getTexEnemyBlink()     const;
        const sf::Texture& getTexEnemyTopHit()    const;
        const sf::Texture& getTexEnemyBottomHit() const;
        const sf::Texture& getTexEnemyLeftHit()   const;
        const sf::Texture& getTexEnemyRightHit()  const;

        
        const sf::Texture& getTexBoss()  const;
        const sf::Texture& getTexProjetil()  const;
        const sf::Texture& getTexObstaculoD()  const;
        
    };
}
