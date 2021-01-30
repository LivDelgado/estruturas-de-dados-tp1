#ifndef ORDEM
#define ORDEM

#include "enums/acao.h"
#include <string>

namespace extracaoZ {
    class OrdemComando {
        private:
            Acao acao;
            int posicaoX;
            int posicaoY;
            std::string comando;

        public:
            OrdemComando();
            ~OrdemComando();

            int setPosicaoX();
            int setPosicaoY();
            void setPosicao(int x, int y);
            Acao getAcao();
            std::string getComando();
            void setComando(std::string comando);
    };
}


#endif
