#include "fluxoExtracao/leitorArquivos.h"
#include "planeta/mapa.h"

#include <string>

#ifndef LEITOR_MAPA
#define LEITOR_MAPA

namespace extracaoZ {
    class LeitorMapa : LeitorArquivos {
        private:
            Mapa* criarMapa(std::string* linhasArquivo);

        public:
            LeitorMapa();
            ~LeitorMapa();

            Mapa* inicializarMapa(std::string caminhoArquivo);
    };
}


#endif
