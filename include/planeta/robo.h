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
            FilaOrdensComando* ordensComando;
            PilhaOrdensComando* ordensComandoPrioritarios;
            FilaOrdensComando* historicoExecucao;

        public:
            Robo();
            Robo(int indice);
            ~Robo();

            int obterIndice();
            bool obterEmMissao();
            int getPosicaoX();
            int getPosicaoY();
            int obterNumeroItensColetados();
            int obterNumeroAlienigenasDerrotados();

            int incrementarNumeroItensColetados();
            int incrementarNumeroAlienigenasDerrotados();
            void zerarNumeroItensColetados();
            void zerarNumeroAlienigenasDerrotados();
            void setPosicao(int x, int y);
            void setIndice(int indice);
            void roboEmMissao(bool emMissao);

            void adicionarOrdemDeComando(OrdemComando* ordemComando);
            void adicionarOrdemDeComandoPrioritaria(OrdemComando* ordemComando);
            void adicionarOrdemDeComandoNoHistorico(OrdemComando* ordemComando);

            FilaOrdensComando* getOrdensComando();
            PilhaOrdensComando* getOrdensComandoPrioritarios();
            FilaOrdensComando* getHistoricoExecucao();

            void limparHistorico();
    };
}

#include "fluxoJogo/executorComandos.h"

#endif
