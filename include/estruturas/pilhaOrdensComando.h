#ifndef PILHA_ORDENS
#define PILHA_ORDENS

#include "estruturas/nodoOrdemComando.h"
#include "fluxoJogo/ordemComando.h"

namespace extracaoZ {

    class PilhaOrdensComando {
        private:
            NodoOrdemComando* ultimaOrdem;

            bool pilhaVazia();

        public:
            PilhaOrdensComando();
            ~PilhaOrdensComando();

            void empilharOrdemComando(OrdemComando* ordem);
            OrdemComando* desempilharOrdemComando();

            void limpar();
    };
    
}

#endif
