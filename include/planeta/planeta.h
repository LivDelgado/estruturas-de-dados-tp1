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

            void inicializarRobos();

        public:
            Planeta();
            ~Planeta();

            Robo* obterRobo(int indiceRobo);
            Mapa* obterMapa();
            Base* obterBase();

            void setMapa(Mapa* mapa);

            bool verificarRoboEmExploracao(int indiceRobo);
    };
}


#endif
