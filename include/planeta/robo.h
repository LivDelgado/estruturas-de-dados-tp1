#include "estruturas/filaOrdensComando.h"
#include "estruturas/pilhaOrdensComando.h"
#include "fluxoJogo/ordemComando.h"

#ifndef ROBO
#define ROBO

namespace extracaoZ {
    class Robo {
        private:
            int indice;
            bool emMissao;
            int posicaoX;
            int posicaoY;
            int numeroItensColetados;
            int numeroAlienigenasDerrotados;
            FilaOrdensComando ordensComando;
            FilaOrdensComando ordensComandoPrioritarios;
            PilhaOrdensComando historicoExecucao;

        public:
            Robo();
            Robo(int indice);
            ~Robo();

            int obterIndice();
            bool obterEmMissao();
            int setPosicaoX();
            int setPosicaoY();
            int obterNumeroItensColetados();
            int obterNumeroAlienigenasDerrotados();

            int incrementarNumeroItensColetados();
            int incrementarNumeroAlienigenasDerrotados();
            void zerarNumeroItensColetados();
            void zerarNumeroAlienigenasDerrotados();
            void setPosicao(int x, int y);
            void roboEmMissao(bool emMissao);

            void adicionarOrdemDeComando(OrdemComando);
            void adicionarOrdemDeComandoPrioritaria(OrdemComando);
    };
}


#endif
