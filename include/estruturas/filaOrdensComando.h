#include "estruturas/nodoOrdemComando.h"
#include "fluxoJogo/ordemComando.h"

#ifndef FILA_ORDENS
#define FILA_ORDENS

namespace extracaoZ {

    class FilaOrdensComando {
        private:
            NodoOrdemComando* primeiraOrdem;
            NodoOrdemComando* ultimaOrdem;

        public:
            FilaOrdensComando();
            ~FilaOrdensComando();

            void enfileirarOrdemComando(OrdemComando);
            OrdemComando desenfileirarOrdemComando();

            void limpar();
    };
    
}

#endif
