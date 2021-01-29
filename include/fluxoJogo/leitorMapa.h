#include "planeta/mapa.h"

#include <string>

#ifndef LEITOR_MAPA
#define LEITOR_MAPA

namespace extracaoZ {
    class LeitorMapa {
        private:

        public:
            LeitorMapa();
            ~LeitorMapa();

            std::string* lerArquivo(std::string caminhoArquivo);
            Mapa criarMapa(std::string*);
    };
}


#endif
