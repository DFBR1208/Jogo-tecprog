#include "Jogo.h"
#include "Menu.h"
#include "HUD.h"
#include "Ente.h"
#include <fstream>
#include <string>

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
        estadoAtual = JOGO_INICIO;
        faseAtual = JOGO_INICIO; //apenas para ter uma inicialização válida
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
            switch (estadoAtual) {
            case JOGO_INICIO:
                pMenu->executar();
                pMenu->desenhar();
                break;
            case JOGO_FASE1:
                pFase1->executar();
                pHUD->executar();
                if (pFase1->isFaseConcluida()) {
                    int n_jogadores = (pJog2!=nullptr) ? 2:1;
                    iniciarFase2(n_jogadores);
                }
                if((pJog1&&pJog1->getNumVidas()<=0)||(pJog2&&pJog2->getNumVidas()<=0)) {
                    faseAtual=estadoAtual;
                    estadoAtual=JOGO_MENUGERAL;
                    pMenu->setEstado(MENU_GAMEOVER);
                }    
                else {
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                        faseAtual=estadoAtual;
                        estadoAtual=JOGO_MENUGERAL;
                        pMenu->setEstado(MENU_PAUSE);
                    }
                    pFase1->desenhar();
                    pHUD->desenhar();
                }
                break;
            
            case JOGO_FASE2:
                pFase2->executar();
                pHUD->executar();
                if(pFase2->isFaseConcluida()) {
                    faseAtual=estadoAtual;
                    estadoAtual=JOGO_MENUGERAL;
                    pMenu->setEstado(MENU_VITORIA);
                }
                if((pJog1&&pJog1->getNumVidas()<=0)||(pJog2&&pJog2->getNumVidas()<=0)) {
                    faseAtual=estadoAtual;
                    estadoAtual=JOGO_MENUGERAL;
                    pMenu->setEstado(MENU_GAMEOVER);
                }    
                else {
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                        faseAtual=estadoAtual;
                        estadoAtual=JOGO_MENUGERAL;
                        pMenu->setEstado(MENU_PAUSE);
                    }                    
                    pFase2->desenhar();
                    pHUD->desenhar();
                }
                break;
                case JOGO_MENUGERAL:
                    GG->focarCameraJogo();
                    if (faseAtual == JOGO_FASE1) {
                        pFase1->desenhar();
                    } else if (faseAtual == JOGO_FASE2) {
                        pFase2->desenhar();
                    }
                    pHUD->desenhar();
                    pMenu->executar();
                    pMenu->desenhar();
            }
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
            estadoAtual = JOGO_FASE1;
        }
    }

    void Jogo::iniciarFase2(int n_jogs) {
        delete pFase2; pFase2 = nullptr;
        delete pHUD;   pHUD   = nullptr;
        if (pJog1!=nullptr&&pJog1->getNumVidas()<=0) {
            delete pJog1;
            pJog1=nullptr;
        }
        if (pJog2!=nullptr&&pJog2->getNumVidas()<=0) {
            delete pJog2;
            pJog2=nullptr;
        }
        if(pJog1 == nullptr && n_jogs >= 1) {
            pJog1 = new Jogador(true);
        }
        else if (pJog1) {
            pJog1->paraFase2();
        }
        if(pJog2 == nullptr && n_jogs == 2) {
            pJog2 = new Jogador(false);
        }
        else if (pJog2){
            pJog2->paraFase2();
        }
        

        pFase2 = new FaseSegunda(pJog1, pJog2);
        pHUD   = new HUD(pJog1, pJog2);
        estadoAtual = JOGO_FASE2;

    }

    void Jogo::carregarJogo(int n_jogs) {
        std::ifstream arquivo("saves/save_jogo.txt");
        if (!arquivo.is_open()) return;

        std::string tok;
        int qualFase = 1;
        arquivo >> tok >> qualFase;
        arquivo.close();

        delete pFase1; pFase1 = nullptr;
        delete pFase2; pFase2 = nullptr;
        delete pJog1;  pJog1  = nullptr;
        delete pJog2;  pJog2  = nullptr;
        delete pHUD;   pHUD   = nullptr;

        pJog1 = new Jogador(true);
        if (n_jogs == 2) pJog2 = new Jogador(false);

        if (qualFase == 1) {
            pFase1 = new FasePrimeira(pJog1, pJog2, true);
            pFase1->carregarFase();
            estadoAtual = JOGO_FASE1;
        } else if (qualFase == 2) {
            pFase2 = new FaseSegunda(pJog1, pJog2, true);
            pFase2->carregarFase();
            estadoAtual = JOGO_FASE2;
        }

        pHUD = new HUD(pJog1, pJog2);
    }

    void Jogo::setEstado(EstadoJogo novoEstado) {
        estadoAtual = novoEstado;
    }

    EstadoJogo Jogo::getFaseAtual() {
        return faseAtual;
    }

    Jogador* Jogo::getpJog1() {
        return pJog1;
    }

    Jogador* Jogo::getpJog2() {
        return pJog2;
    }

    FasePrimeira* Jogo::getpFase1() {return pFase1;}
    FaseSegunda* Jogo::getpFase2() {return pFase2;}
}
