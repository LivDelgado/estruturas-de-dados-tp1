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
            OrdemComando(Acao acao, std::string comando);
            OrdemComando(Acao acao, std::string comando, int posicaoX, int posicaoY);
            ~OrdemComando();
            
            void setAcao(Acao acao);
            void setPosicaoX(int x);
            void setPosicaoY(int y);
            void setPosicao(int x, int y);
            void setComando(std::string comando);
            
            Acao getAcao();
            int getPosicaoX();
            int getPosicaoY();
            std::string getComando();
    };
}


#endif
