#include "Jogo.h"
#include "Menu.h"
#include "HUD.h"
#include "Ente.h"

namespace Kawabanga {
    using namespace Gerenciadores;
    using namespace Entidades::Personagens;
    using namespace Fases;

    Jogo::Jogo()
        : GG(new Gerenciador_Grafico()),
        pJog1(nullptr), pJog2(nullptr),
        pFase1(nullptr), pFase2(nullptr),
        pMenu(new Menu(this)), pHUD(nullptr) {
        Ente::setGerenciadorGrafico(GG);
    }

    Jogo::~Jogo() {
        delete pHUD;
        delete pFase1;
        delete pFase2;
        delete GG;
        delete pJog1;
        delete pJog2;
        delete pMenu;
    }

    void Jogo::executar() {
        while (GG->verificaJanelaAberta()) {
            GG->limpar();
            pMenu->executar();
            pMenu->desenhar();
            GG->mostrar();
        }
    }

    void Jogo::iniciarFase1(int n_jogs) {
        delete pFase1; pFase1 = nullptr;
        delete pJog1;  pJog1  = nullptr;
        delete pJog2;  pJog2  = nullptr;
        delete pHUD;   pHUD   = nullptr;

        if (n_jogs >= 1) {
            pJog1  = new Jogador(true);
            pFase1 = new FasePrimeira(pJog1, n_jogs == 2 ? (pJog2 = new Jogador(false)) : nullptr);
            pHUD   = new HUD(pJog1, pJog2);
        }

        while (GG->verificaJanelaAberta()) {
            GG->limpar();
            pFase1->executar();
            pHUD->executar();
            pFase1->desenhar();
            pHUD->desenhar();
            GG->mostrar();
        }
    }

    void Jogo::iniciarFase2(int n_jogs) {
        delete pFase2; pFase2 = nullptr;
        delete pJog1;  pJog1  = nullptr;
        delete pJog2;  pJog2  = nullptr;
        delete pHUD;   pHUD   = nullptr;

        if (n_jogs >= 1) {
            pJog1  = new Jogador(true);
            pFase2 = new FaseSegunda(pJog1, n_jogs == 2 ? (pJog2 = new Jogador(false)) : nullptr);
            pHUD   = new HUD(pJog1, pJog2);
        }

        while (GG->verificaJanelaAberta()) {
            GG->limpar();
            pFase2->executar();
            pHUD->executar();
            pFase2->desenhar();
            pHUD->desenhar();
            GG->mostrar();
        }
    }
}
