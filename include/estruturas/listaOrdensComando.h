#include "estruturas/lista.h"
#include "fluxoJogo/ordemComando.h"

#ifndef LISTA_ORDENS
#define LISTA_ORDENS

namespace extracaoZ {

    class ListaOrdensComando : public Lista<OrdemComando> {
        public:
            ListaOrdensComando();
            ~ListaOrdensComando();
    };
    
}

#endif
