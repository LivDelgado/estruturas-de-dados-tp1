#ifndef FILA_ORDENS
#define FILA_ORDENS

#include "estruturas/nodoOrdemComando.h"
#include "fluxoJogo/ordemComando.h"

namespace extracaoZ {

    class FilaOrdensComando {
        private:
            NodoOrdemComando* primeiraOrdem;
            NodoOrdemComando* ultimaOrdem;

            bool filaVazia();

        public:
            FilaOrdensComando();
            ~FilaOrdensComando();

            void enfileirarOrdemComando(OrdemComando* ordem);
            OrdemComando* desenfileirarOrdemComando();

            void limpar();
    };
    
}

#endif
