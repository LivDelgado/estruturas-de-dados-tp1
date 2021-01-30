#include "fluxoJogo/leitorArquivos.h"
#include "planeta/mapa.h"

#include <string>

#ifndef LEITOR_MAPA
#define LEITOR_MAPA

namespace extracaoZ {
    class LeitorMapa {
        private:
            LeitorArquivos* leitor;
            std::string* lerArquivo(std::string caminhoArquivo);
            Mapa* criarMapa(std::string* linhasArquivo);

        public:
            LeitorMapa();
            ~LeitorMapa();

            Mapa* inicializarMapa(std::string caminhoArquivo);
    };
}


#endif
