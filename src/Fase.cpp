#include "Fase.h"
#include "Rosquinha.h"
#include "Espinhos.h"
#include "Bola_de_Espinhos.h"
#include "Pedroso.h"
#include "Pedrado.h"
#include "Pedrao.h"
#include "Projetil.h"
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

namespace Kawabanga::Fases {

    using namespace Entidades::Personagens;
    using namespace Entidades::Obstaculos;
    Fase::Fase(Jogador* pJo1, Jogador* pJo2, bool fromSave) : Ente(), GC(pJo1, pJo2), pJog1(pJo1), pJog2(pJo2), faseConcluida(false) {
        for (int i = 0; i < NUM_PLATS; i++) plats[i] = nullptr;
        if (!fromSave) {
            criarRosquinhas();
            criarCenario();
        }
        if(pJog1)
            lista_enti.incluir(pJog1);
        if(pJog2)
            lista_enti.incluir(pJog2);
    }

    Fase::~Fase() {}

    void Fase::criarPedrosos() {
        auto addIniF = [&](Rosquinha* plat) {
            Pedroso* ini = new Pedroso(0.f, 0.f);
            (*ini) = plat;
            lista_enti.incluir(ini);
            GC.incluirInimigo(ini);
        };

        addIniF(plats[1]);
        addIniF(plats[3]);
        addIniF(plats[7]);
        if (rand()%10 == 1) {addIniF(plats[3]);}

    }


    void Fase::criarRosquinhas() {
        auto addPlat = [&](int idx, float x, float y, float w) {
            Rosquinha* p = new Rosquinha(x, y, w);
            plats[idx] = p;
            lista_enti.incluir(p);
            GC.incluirObstaculo(p);
        };
        addPlat(0, 100.f, 650.f, 200.f);
        addPlat(1, 350.f, 550.f, 450.f);
        addPlat(2, 880.f, 470.f, 500.f);
        addPlat(3, 410.f, 370.f, 600.f);
        addPlat(4, 410.f, 270.f, 100.f);
        if (rand() % 10 < 5) {
            addPlat(5, 660.f, 270.f, 100.f);
        }
        addPlat(6, 509.f, 170.f, 100.f);
        addPlat(7, 1400.f, 530.f, 400.f);
        addPlat(8, 1600.f, 430.f, 250.f);
        addPlat(9, 1900.f, 330.f, 300.f);
        addPlat(10, 2200.f, 230.f, 300.f);
    }

    void Fase::criarCenario() {}

    void Fase::carregarFase() {
        using namespace Entidades;
        using namespace Entidades::Obstaculos;
        using namespace Entidades::Personagens;

        std::ifstream arquivo("saves/save_jogo.txt");
        if (!arquivo.is_open()) return;
        //dicionario para lincar id com a entidade
        std::map<int, Entidade*> mapa;
        //pair guarda dois valores juntos
        std::vector<std::pair<Inimigo*, int>> iniPlat;
        std::vector<std::pair<Projetil*, int>> projChefao;

        if (pJog1) mapa[pJog1->getId()] = pJog1;
        if (pJog2) mapa[pJog2->getId()] = pJog2;

        // primeira passagem: cria os objetos
        std::string linha;
        std::getline(arquivo, linha);
        {
            std::stringstream ss(linha);
            std::string tok;
            ss >> tok >> qualfase;
        }

        while (std::getline(arquivo, linha)) {
            if (linha.empty()) continue;
            std::stringstream ss(linha);
            std::string tipo;
            ss >> tipo;

            if (tipo == "JOGADOR1" && pJog1) {
                pJog1->carregarDataBuffer(ss);
                mapa[pJog1->getId()] = pJog1;
            } else if (tipo == "JOGADOR2" && pJog2) {
                pJog2->carregarDataBuffer(ss);
                mapa[pJog2->getId()] = pJog2;
            } else if (tipo == "ROSQUINHA") {
                auto* e = new Rosquinha();
                e->carregarDataBuffer(ss);
                lista_enti.incluir(e);
                GC.incluirObstaculo(e);
                mapa[e->getId()] = e;
            } else if (tipo == "ESPINHOS") {
                auto* e = new Espinhos();
                e->carregarDataBuffer(ss);
                lista_enti.incluir(e);
                GC.incluirObstaculo(e);
                mapa[e->getId()] = e;
            } else if (tipo == "BOLA") {
                auto* e = new Bola_de_Espinhos();
                e->carregarDataBuffer(ss);
                lista_enti.incluir(e);
                GC.incluirObstaculo(e);
                mapa[e->getId()] = e;
            } else if (tipo == "PEDROSO") {
                auto* e = new Pedroso();
                e->carregarDataBuffer(ss);
                lista_enti.incluir(e);
                GC.incluirInimigo(e);
                mapa[e->getId()] = e;
                iniPlat.push_back({e, e->getIdPlataformaCarregada()});
            } else if (tipo == "PEDRADO") {
                auto* e = new Pedrado();
                e->carregarDataBuffer(ss);
                lista_enti.incluir(e);
                GC.incluirInimigo(e);
                mapa[e->getId()] = e;
                iniPlat.push_back({e, e->getIdPlataformaCarregada()});
            } else if (tipo == "PEDRAO") {
                auto* e = new Pedrao();
                e->carregarDataBuffer(ss);
                lista_enti.incluir(e);
                GC.incluirInimigo(e);
                mapa[e->getId()] = e;
                iniPlat.push_back({e, e->getIdPlataformaCarregada()});
            } else if (tipo == "PROJETIL") {
                auto* e = new Projetil();
                e->carregarDataBuffer(ss);
                lista_enti.incluir(e);
                GC.incluirProjetil(e);
                mapa[e->getId()] = e;
                projChefao.push_back({e, e->getIdChefaoCarregado()});
            }
        }
        arquivo.close();

        // segunda passagem: resolve ponteiros
        for (int i = 0; i < (int)iniPlat.size(); ++i) {
            Inimigo* ini   = iniPlat[i].first;
            int      platId = iniPlat[i].second;
            if (platId == -1) continue;
            auto it = mapa.find(platId);
            if (it != mapa.end()) {
                auto* rosq = dynamic_cast<Rosquinha*>(it->second);
                if (rosq) ini->setPlataformaPtr(rosq);
            }
        }

        for (int i = 0; i < (int)projChefao.size(); ++i) {
            Projetil* proj    = projChefao[i].first;
            int       chefaoId = projChefao[i].second;
            if (chefaoId == -1) continue;
            auto it = mapa.find(chefaoId);
            if (it != mapa.end()) {
                auto* pedrao = dynamic_cast<Pedrao*>(it->second);
                if (pedrao) {
                    proj->setChefao(pedrao);
                    pedrao->setProjetil(proj);
                }
            }
        }
    }

    bool Fase::isFaseConcluida() const { return faseConcluida; }

    void Fase::salvarFase() {
        std::ofstream arquivo("saves/save_jogo.txt", std::ios::trunc);
        if(!arquivo.is_open()){
            return;
        }
        arquivo<<"FASE "<<qualfase<<std::endl;
        arquivo.close();
        auto pAux = lista_enti.getPrimeiroElemento();
        while(pAux!=nullptr){
            Entidades::Entidade* pEnt=pAux->getDado();

            if(pEnt!=nullptr)
                pEnt->salvar();
            pAux=pAux->getProx();
        }
    }
}

