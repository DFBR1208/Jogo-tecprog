#include "Gerenciador_Colisoes.h"

namespace Kawabanga::Gerenciadores {
    using namespace Entidades::Personagens;
    using namespace Entidades::Obstaculos;
    using namespace Entidades;

    Gerenciador_Colisoes::Gerenciador_Colisoes(Jogador* pJogo1, Jogador* pJogo2) : pJog1(pJogo1), pJog2(pJogo2) {}

    Gerenciador_Colisoes::~Gerenciador_Colisoes() {}

    void Gerenciador_Colisoes::incluirInimigo(Inimigo* pi) {
        LIs.push_back(pi);
    }

    void Gerenciador_Colisoes::incluirObstaculo(Obstaculo* po) {
        LOs.push_back(po);
    }

    const bool Gerenciador_Colisoes::verificarColisao(Entidade* pe1, Entidade* pe2) {
        return pe1->getBounds().intersects(pe2->getBounds());
    }

    void Gerenciador_Colisoes::tratarColisoesJogsInimgs() {
        for (Inimigo* ini : LIs) {
            if (ini && verificarColisao(pJog1, ini)) 
                if(!ini->getTomandoDano()) {
                     if(pJog1->getIsPoderoso())
                        pJog1->atacar(ini);
                    else 
                        ini->danificar(pJog1);
                }
                else {
                    sf::FloatRect boundsIni = ini->getBounds();
                    sf::FloatRect boundsJog1 = pJog1->getBounds();
                    
                    float overlapTop    = (boundsJog1.top + boundsJog1.height) - boundsIni.top;
                    float overlapBottom = (boundsIni.top + boundsIni.height) - boundsJog1.top;
                    float overlapLeft   = (boundsJog1.left + boundsJog1.width) - boundsIni.left;
                    float overlapRight  = (boundsIni.left + boundsIni.width) - boundsJog1.left;

                    float minOverlapV = std::min(overlapTop, overlapBottom);
                    float minOverlapH = std::min(overlapLeft, overlapRight);

                    if (minOverlapV < minOverlapH) {
                        if (overlapTop < overlapBottom)
                            pJog1->pararNoChao(boundsIni.top);
                        else
                            pJog1->baterCabeca(boundsIni.top + boundsIni.height);
                    }
                    else {
                        if (overlapLeft < overlapRight)
                            pJog1->pararNaParede(boundsIni.left - boundsJog1.width);
                        else
                            pJog1->pararNaParede(boundsIni.left + boundsIni.width);
                    }
                    
                }
            if (ini && pJog2 && verificarColisao(pJog2, ini))
                if(!ini->getTomandoDano()) {
                    if(pJog2->getIsPoderoso())
                        pJog2->atacar(ini);
                    else
                        ini->danificar(pJog2);
                }
                else {
                    sf::FloatRect boundsIni = ini->getBounds();
                    sf::FloatRect boundsJog2 = pJog2->getBounds();

                    float overlapTop    = (boundsJog2.top + boundsJog2.height) - boundsIni.top;
                    float overlapBottom = (boundsIni.top + boundsIni.height) - boundsJog2.top;
                    float overlapLeft   = (boundsJog2.left + boundsJog2.width) - boundsIni.left;
                    float overlapRight  = (boundsIni.left + boundsIni.width) - boundsJog2.left;

                    float minOverlapV = std::min(overlapTop, overlapBottom);
                    float minOverlapH = std::min(overlapLeft, overlapRight);

                    if (minOverlapV < minOverlapH) {
                        if (overlapTop < overlapBottom)
                            pJog2->pararNoChao(boundsIni.top);
                        else
                            pJog2->baterCabeca(boundsIni.top + boundsIni.height);
                    }
                    else {
                        if (overlapLeft < overlapRight)
                            pJog2->pararNaParede(boundsIni.left - boundsJog2.width);
                        else
                            pJog2->pararNaParede(boundsIni.left + boundsIni.width);
                    }
                
            }
        }
    }

    void Gerenciador_Colisoes::tratarColisoesJogsObstacs() {
        for (Obstaculo* obs : LOs) {
            if (obs && verificarColisao(pJog1, obs))
                obs->obstaculizar(pJog1);
            if (obs && pJog2 && verificarColisao(pJog2, obs))
                obs->obstaculizar(pJog2);
        }
    }

    void Gerenciador_Colisoes::incluirProjetil(Projetil* pj) {
        LPs.insert(pj);
    }

    void Gerenciador_Colisoes::tratarColisoesJogsProjeteis() {
        for (Projetil* proj : LPs) {
            if (!proj || !proj->isAtivo()) continue;
            if (verificarColisao(pJog1, proj)) {
                pJog1->tomarDano();
                proj->getChefao()->projetilAtingiu();
            }
            if (pJog2 && verificarColisao(pJog2, proj))
                pJog2->tomarDano();
        }
    }

    void Gerenciador_Colisoes::executar() {
        if (!pJog1) return;
        tratarColisoesJogsInimgs();
        tratarColisoesJogsObstacs();
        tratarColisoesJogsProjeteis();
    }
    void Gerenciador_Colisoes::removerInimigo(Inimigo* pIni) {
        auto it = std::find(LIs.begin(), LIs.end(), pIni);
        if (it != LIs.end()) {
            LIs.erase(it);
        }
    }
}