#ifndef BASE
#define BASE

#include "estruturas/filaOrdensComando.h"

namespace extracaoZ {
    class Base {
        private:
            int numeroItensColetados;
            int numeroAlienigenasDerrotados;
            FilaOrdensComando* historicoExecucao;
        
        public:
            Base();
            ~Base();

            int adicionarItensColetados(int quantidade);
            int adicionarAlienigenasDerrotados(int quantidade);

            int obterItensColetados();
            int obterAlienigenasDerrotados();
    };
}


#endif
