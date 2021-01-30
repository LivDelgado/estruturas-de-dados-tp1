#ifndef MAPA
#define MAPA

namespace extracaoZ {
    class Mapa {
        private:
            int** mapa;
        public:
            Mapa(int x, int y);
            ~Mapa();

            int** criarMapa(int x, int n);
            bool verificarCoordenadaTemRobo(int x, int y);
            bool verificarCoordenadaTemObstaculo(int x, int y);
            bool verificarCoordenadaTemAlien(int x, int y);
            bool verificarCoordenadaVazia(int x, int y);
            bool verificarCoordenadaBase(int x, int y);
    };
}


#endif
