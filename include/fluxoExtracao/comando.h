#include "enums/acao.h"

#ifndef COMANDO
#define COMANDO

namespace extracaoZ {
    class Comando {
        private:
            Acao acao;
            int indiceRobo;
            int posicaoX;
            int posicaoY;
            bool temPrioridade;
            bool direta;
        public:
            Comando();
            Comando(int indiceRobo, bool temPrioridade, bool direta);
            Comando(int indiceRobo, bool temPrioridade, bool direta, int posicaoX, int posicaoY);
            Comando(int indiceRobo, bool temPrioridade, bool direta, int posicaoX, int posicaoY, Acao acao);
            ~Comando();

            void setIndiceRobo(int indiceRobo);
            void setPosicaoX(int posicaoX);
            void setPosicaoY(int posicaoY);
            void setTemPrioridade(bool temPrioridade);
            void setDireta(bool direta);
            void setAcao(Acao acao);

            int getIndiceRobo();
            int getPosicaoX();
            int getPosicaoY();
            bool getTemPrioridade();
            bool getDireta();
            Acao getAcao();
    };
}


#endif
