#ifndef MAPA
#define MAPA

namespace extracaoZ {
    class Mapa {
        private:
            int tamanhoX;
            int tamanhoY;
            char** mapa;

            void verificarPosicaoValida(int x, int y);
            char obterCaractereNaPosicao(int x, int y);
        public:
            Mapa(int x, int y);
            ~Mapa();

            char** criarMapa(int x, int y);
            void setCaractereMapa(int x, int y, char caractere);

            bool verificarCoordenadaTemRecurso(int x, int y);
            bool verificarCoordenadaTemObstaculo(int x, int y);
            bool verificarCoordenadaTemAlien(int x, int y);
            bool verificarCoordenadaVazia(int x, int y);
            bool verificarCoordenadaBase(int x, int y);
    };
}


#endif
