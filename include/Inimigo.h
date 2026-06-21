#pragma once
#include "Personagem.h"
#include "Jogador.h"
#include "Rosquinha.h"
#include <ostream>

namespace Kawabanga::Entidades::Personagens {
    class Inimigo : public Personagem {
    protected:
        int   nivel_maldade;
        float velocidadeX;

        Obstaculos::Rosquinha* pRosquinha;

        sf::RectangleShape forma;
        int   frameAtual;
        int   temporizador;
        static const int FRAME_SIZE    = 42;
        static const int TOTAL_FRAMES  = 4;
        static const int DURACAO_FRAME = 10;
        sf::Clock timerDano;
        bool tomandoDano;
        const float duracaoDano = 1.0f;
        int idPlataformaCarregada;

    public:
        Inimigo(int n_vid);
        Inimigo(float px, float py, int n_vid);
        virtual ~Inimigo();

        void executar()                override;
        void mover()                   override;
        void mover(Obstaculos::Rosquinha* p);
        sf::FloatRect getBounds() const override;

        Inimigo& operator=(Obstaculos::Rosquinha* p);
        void     setPlataforma(Obstaculos::Rosquinha* p);
        void     setPlataformaPtr(Obstaculos::Rosquinha* p);
        int      getIdPlataformaCarregada() const;
        friend std::ostream& operator<<(std::ostream& os, const Inimigo& ini);

        virtual void danificar(Jogador* p) = 0;
        void salvarDataBuffer();
        virtual void carregarDataBuffer(std::stringstream& ss) override;
        virtual void salvar()            = 0;
        virtual void tomarDano();
        bool getTomandoDano() const;
        int getNumVidas() const;
    };
}
