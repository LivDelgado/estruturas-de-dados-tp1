#ifndef LISTA_ROBOS
#define LISTA_ROBOS

#include "planeta/robo.h"
#include "estruturas/lista.h"

namespace extracaoZ {

    class ListaRobos : public Lista<Robo> {
        using Lista<Robo>::Lista;

        public:
            Robo* procurarRobo(int indiceRobo);
    };
    
}

#endif
