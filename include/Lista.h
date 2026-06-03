#pragma once


template <class TL>
class Lista {
    public:
    template <class TE>
    class Elemento {
    private:
        TE* pDado;
        Elemento<TE>* pProx;
    public:
        Elemento() : pDado(nullptr), pProx(nullptr) {}
        ~Elemento() {}
        void incluir(TE* p) { pDado = p;}
        TE* getDado() const { return pDado; }
        Elemento<TE>* getProx()  const { return pProx; }
        void setProx(Elemento<TE>* p) { pProx = p; }
    };
    private:    
    Elemento<TL>* pPrimeiro;
    Elemento<TL>* pUltimo;
    public:
    
    Lista() : pPrimeiro(nullptr), pUltimo(nullptr) {}

    ~Lista() {
        Elemento<TL>* atual = pPrimeiro;
        while (atual != nullptr) {
            Elemento<TL>* prox = atual->getProx();
            delete atual;
            atual = prox;
        }
    }

    void incluir(TL* p) {
        Elemento<TL>* novo = new Elemento<TL>();
        novo->incluir(p);
        if (pUltimo == 0) {
            pPrimeiro = novo;
            pUltimo   = novo;
        } else {
            pUltimo->setProx(novo);
            pUltimo = novo;
        }
    }

    void limpar(TL* p) {
        Elemento<TL>* anterior = nullptr;
        Elemento<TL>* atual    = pPrimeiro;
        while (atual != nullptr) {
            if (atual->getDado() == p) {
                if (anterior == nullptr)
                    pPrimeiro = atual->getProx();
                else
                    anterior->setProx(atual->getProx());
                if (atual == pUltimo)
                    pUltimo = anterior;
                delete atual;
                return;
            }
            anterior = atual;
            atual    = atual->getProx();
        }
    }

    TL* getPrimeiro() const { return pPrimeiro ? pPrimeiro->getDado() : nullptr; }
    TL* getUltimo()   const { return pUltimo   ? pUltimo->getDado()   : nullptr; }

    class Iterador {
    private:
        Elemento<TL>* pAtual;
    public:
        Iterador(Elemento<TL>* inicio) : pAtual(inicio) {}

        bool temProximo() const { return pAtual != nullptr; }

        TL* proximo() {
            TL* dado = pAtual->getDado();
            pAtual   = pAtual->getProx();
            return dado;
        }
    };

    Iterador getIterador() const { return Iterador(pPrimeiro); }
};
