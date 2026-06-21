#include "FaseSegunda.h"
#include <cstdlib>

namespace Kawabanga::Fases {
    using namespace Entidades::Personagens;
    using namespace Entidades::Obstaculos;
    using namespace Entidades;
    FaseSegunda::FaseSegunda(Jogador* pJog1, Jogador* pJog2) : Fase(pJog1, pJog2) {
        qualfase=2;
        criarInimigos();
        criarObstaculo();

        texturaBg.loadFromFile("assets/bg/Pink.png");
        texturaBg.setRepeated(true);
        spriteBg.setTexture(texturaBg);
        spriteBg.setTextureRect(sf::IntRect(0, 0, (int)MUNDO_LARGURA, (int)MUNDO_ALTURA));
        spriteBg.setColor(sf::Color(200, 160, 220));

        chao.setSize(sf::Vector2f(MUNDO_LARGURA, 750.f));
        chao.setFillColor(sf::Color(60, 20, 80));
        chao.setPosition(0.f, 750.f);
    }

    FaseSegunda::~FaseSegunda() {}

    void FaseSegunda::criarInimigos() {
        criarPedrosos();
        criarPedraos();
    }

    void FaseSegunda::criarPedraos() {
        int sorteio = (rand() % (maxChefoes-2)) + 3; //garante ao menos 3 instancias
        int criados = 0;
        for (int i = 1; i < NUM_PLATS && criados < sorteio; i += 2) {
            if (!plats[i]) continue;
            Pedrao* ch = new Pedrao(0.f, 0.f);
            (*ch) = plats[i];

            Projetil* pProj = criarProjetil();
            ch->setProjetil(pProj);
            pProj->setChefao(ch);

            lista_enti.incluir(ch);
            GC.incluirInimigo(ch);
            ++criados;
        }
    }

    void FaseSegunda::criarObstaculo() {
        criarBolas();
    }

    void FaseSegunda::criarBolas() {
        auto addOD = [&](float x, float y) {
            Bola_de_Espinhos* od = new Bola_de_Espinhos(x, y, 35.f);
            lista_enti.incluir(od);
            GC.incluirObstaculo(od);
        };
        addOD(410.f, 235.f);
        addOD(1300.f, 435.f);
        addOD(690.f, 335.f);
        if (rand()%10 == 1) {addOD(1700.f, 335.f);}
    }

    Projetil* FaseSegunda::criarProjetil() {
        Projetil* proj1 = new Projetil();
        lista_enti.incluir(proj1);
        GC.incluirProjetil(proj1);
        return proj1;
    }

    void FaseSegunda::executar() {
        lista_enti.percorrer();
        GC.executar();
                auto pAux = lista_enti.getPrimeiroElemento();
        int inimigosVivos = 0;
        while (pAux!=nullptr) {
            Entidades::Entidade* ent = pAux->getDado();
            auto pProx = pAux->getProx();
            Inimigo* pIni = dynamic_cast<Inimigo*>(ent);
            if (pIni && pIni->getNumVidas() <= 0) {
                if(pJog1) {
                    pJog1->adicionarPontos(100);
                }

                GC.removerInimigo(pIni);
                lista_enti.remover(pIni);
                delete pIni;
            }
            else if (pIni) {
                inimigosVivos++;
            }
            pAux = pProx;
        }

        sf::Vector2f posJogador = pJog1 ? pJog1->getPosicao() : sf::Vector2f(0.f, 0.f);

        if(pJog2) {
            sf::Vector2f posJog2 = pJog2->getPosicao();
            posJogador.x = (posJog2.x + posJogador.x) / 2.f;
            posJogador.y = (posJog2.y + posJogador.y) / 2.f;
        }        
        pGG->atualizarCamera(posJogador, MUNDO_LARGURA, MUNDO_ALTURA);
        if(inimigosVivos == 0) {
            faseConcluida = true;
        }
    }

    void FaseSegunda::desenhar() {
        pGG->desenhar(spriteBg);
        pGG->desenhar(chao);
        lista_enti.desenhar();
    }
}
