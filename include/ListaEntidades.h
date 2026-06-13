#pragma once
#include "Lista.h"
#include "Entidade.h"

namespace Kawabanga::Listas {
    class ListaEntidades
    {
        private:
        Lista<Entidades::Entidade> LEs;

        public:
        ListaEntidades();
        ~ListaEntidades();
        void incluir(Entidades::Entidade* pe);
        void percorrer();
        void desenhar();

    };
}