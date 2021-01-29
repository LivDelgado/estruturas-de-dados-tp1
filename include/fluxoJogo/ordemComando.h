#include "enums/acao.h"

#ifndef ORDEM
#define ORDEM

namespace extracaoZ {
    class OrdemComando {
        private:
            Acao acao;
            int posicaoX;
            int posicaoY;
        public:
            OrdemComando();
            ~OrdemComando();

            int obterPosicaoX();
            int obterPosicaoY();
            void mudarPosicao(int x, int y);
            Acao obterAcao();
    };
}


#endif
