#include "planeta/mapa.h"
#include "planeta/base.h"
#include "planeta/robo.h"

#ifndef PLANETA
#define PLANETA

namespace extracaoZ {
    class Planeta {
        private:
            Robo* robos;
            Base* base;
            Mapa* mapa;
        public:
            Planeta();
            ~Planeta();

            Robo* obterRobo(int indiceRobo);
            bool verificarRoboEmExploracao(int indiceRobo);
            Mapa* obterMapa();
    };
}


#endif
