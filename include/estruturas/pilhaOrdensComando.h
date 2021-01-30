#include "estruturas/nodoOrdemComando.h"
#include "fluxoJogo/ordemComando.h"

#ifndef PILHA_ORDENS
#define PILHA_ORDENS

namespace extracaoZ {

    class PilhaOrdensComando {
        private:
            NodoOrdemComando* primeiraOrdem;
            NodoOrdemComando* ultimaOrdem;

        public:
            PilhaOrdensComando();
            ~PilhaOrdensComando();

            void empilharOrdemComando(OrdemComando);
            OrdemComando desempilharOrdemComando();

            void limpar();

    };
    
}

#endif
