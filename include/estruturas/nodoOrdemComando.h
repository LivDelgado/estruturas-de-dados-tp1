#ifndef NODO_ORDEM
#define NODO_ORDEM

#include "fluxoExtracao/ordemComando.h"

namespace extracaoZ {
    class NodoOrdemComando {
        private:
            NodoOrdemComando* proximaOrdem;
            NodoOrdemComando* ordemAnterior;

            OrdemComando* ordem;

        public:
            NodoOrdemComando();
            NodoOrdemComando(OrdemComando* ordem);
            ~NodoOrdemComando();

            void setProximaOrdem(NodoOrdemComando* proximaOrdem);
            void setOrdemAnterior(NodoOrdemComando* ordemAnterior);
            void setOrdemComando(OrdemComando* ordem);
            
            NodoOrdemComando* getProximaOrdem();
            NodoOrdemComando* getOrdemAnterior();
            OrdemComando* getOrdemComando();

    };
}

#endif