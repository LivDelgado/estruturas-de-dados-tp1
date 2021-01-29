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
            // Lista<OrdemComando> ordensComando;
            // Pilha<OrdemComando> historicoExecucao;
        public:
            Robo();
            Robo(int indice);
            ~Robo();

            int obterIndice();
            bool obterEmMissao();
            int obterPosicaoX();
            int obterPosicaoY();
            int obterNumeroItensColetados();
            int obterNumeroAlienigenasDerrotados();

            int incrementarNumeroItensColetados();
            int incrementarNumeroAlienigenasDerrotados();
            void zerarNumeroItensColetados();
            void zerarNumeroAlienigenasDerrotados();
            void mudarPosicao(int x, int y);
            void roboEmMissao(bool emMissao);

            // void adicionarOrdemDeComando(OrdemComando);
            // void adicionarOrdemDeComandoPrioritaria(OrdemComando);
    };
}


#endif
