#ifndef NODO_ORDEM
#define NODO_ORDEM

#include "fluxoJogo/ordemComando.h"

namespace extracaoZ {
    class NodoOrdemComando {
        private:
            NodoOrdemComando* proximaOrdem;

            OrdemComando ordem;

        public:
            NodoOrdemComando();
            NodoOrdemComando(OrdemComando ordem);
            ~NodoOrdemComando();

            void setProximaOrdem(NodoOrdemComando* proximaOrdem);
            void setOrdemComando(OrdemComando ordem);
            
            NodoOrdemComando* getProximaOrdem();
            OrdemComando getOrdemComando();

    };
}

#endif