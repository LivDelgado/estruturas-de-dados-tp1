#ifndef FILA_ORDENS
#define FILA_ORDENS

#include "estruturas/nodoOrdemComando.h"
#include "fluxoJogo/ordemComando.h"

namespace extracaoZ {

    class FilaOrdensComando {
        private:
            NodoOrdemComando* primeiraOrdem;
            NodoOrdemComando* ultimaOrdem;


        public:
            FilaOrdensComando();
            ~FilaOrdensComando();

            void enfileirarOrdemComando(OrdemComando* ordem);
            OrdemComando* desenfileirarOrdemComando();

            bool filaVazia();
            void limpar();
    };
    
}

#endif
