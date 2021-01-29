#include "fluxoJogo/comando.h"

#include <string>

#ifndef DECOD_COMANDO
#define DECOD_COMANDO

namespace extracaoZ {
    class DecodificadorComandos {
        private:
            Comando interpretarComando(std::string);
            
        public:
            DecodificadorComandos();
            ~DecodificadorComandos();

            std::string* lerArquivo(std::string caminhoArquivo);
            Comando* interpretarComandos(std::string*);
            
    };
}


#endif
