#include "estruturas/nodo.h"

#ifndef LISTA
#define LISTA

namespace extracaoZ {

    template <class T>
    class Lista {
        private:
            Nodo<T>* primeiroItem;
            Nodo<T>* ultimoItem;
            int numeroElementos;

            Nodo<T>* posicionar(int posicao);

        public:
            Lista();
            ~Lista();

            T* obterItem(int posicao);
            T* obterPrimeiroItem();
            T* obterUltimoItem();

            void inserirItem(T item, int posicao);
            void inserirItemPrimeiraPosicao(T item);
            void inserirItemUltimaPosicao(T item);

            void imprimirLista();
            void imprimirListaReversa();
            void limparLista();
    };
    
}

#endif
