#ifndef COMANDO
#define COMANDO

namespace extracaoZ {
    class Comando {
        private:
            int indiceRobo;
            int posicaoX;
            int posicaoY;
            bool temPrioridade;
            bool direta;
        public:
            Comando();
            ~Comando();
    };
}


#endif
