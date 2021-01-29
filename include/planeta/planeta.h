#include "estruturas/listaRobos.h"

#ifndef PLANETA
#define PLANETA

namespace extracaoZ {
    class Planeta {
        private:
            ListaRobos robos;
            // Base base;
            // Mapa mapa;
        public:
            Planeta();
            ~Planeta();

            bool verificarRoboEmExploracao(int indiceRobo);
            ListaRobos listarRobosEmExploracao();
            // Mapa obterMapa();
    };
}


#endif
