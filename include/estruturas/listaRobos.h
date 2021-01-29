#include "estruturas/lista.h"
#include "planeta/robo.h"

#ifndef LISTA_ROBOS
#define LISTA_ROBOS

namespace extracaoZ {

    class ListaRobos : public Lista<Robo> {
        using Lista<Robo>::Lista;

        public:
            Robo* procurarRobo(int indiceRobo);
    };
    
}

#endif
