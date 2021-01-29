#include "fluxoJogo/comando.h"

#include <string>

#ifndef EXEC_COMANDO
#define EXEC_COMANDO

namespace extracaoZ {
    class ExecutorComandos {
        private:
            void incluirComandoListaRobo(Comando);
            void executarListaComandosRobo(Comando);
            
            void ativarRobo(Comando);
            void imprimirRelatorioRobo(Comando);
            void retornarRoboParaBase(Comando);
            
        public:
            ExecutorComandos();
            ~ExecutorComandos();

            void executarComandos(Comando*);
            
    };
}


#endif
