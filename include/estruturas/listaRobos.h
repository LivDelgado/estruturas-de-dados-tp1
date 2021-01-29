#include "estruturas/lista.h"
#include "planeta/robo.h"

#ifndef LISTA_ROBOS
#define LISTA_ROBOS

namespace extracaoZ {

    class ListaRobos : public Lista<Robo> {
        public:
            ListaRobos();
            ~ListaRobos();

            // Robo* procurarRobo(int indiceRobo)
    };
    
}

#endif