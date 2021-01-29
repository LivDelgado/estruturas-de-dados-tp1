#include "estruturas/listaRobos.h"

#ifndef BASE
#define BASE

namespace extracaoZ {
    class Base {
        private:
            ListaRobos robos;
            int numeroItensColetados;
            int numeroAlienigenasDerrotados;
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
