#ifndef EXPLORADOR
#define EXPLORADOR

#include "fluxoJogo/leitorMapa.h"
#include "fluxoJogo/executorComandos.h"
#include "planeta/planeta.h"

namespace extracaoZ {
    class Explorador {
        private:
            Planeta* planeta;
            LeitorMapa* leitorMapa;
            ExecutorComandos* executor; 

        public:
            Explorador();
            ~Explorador();

            void iniciarExtracaoZ(std::string caminhoArquivoMapa, std::string caminhoArquivoComandos);
    };
}

#endif