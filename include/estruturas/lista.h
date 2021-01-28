#include "estruturas/nodo.h"

template <typename T> 
class Lista {
    private:
        Nodo* primeiroItem;
        Nodo* ultimoItem;
        int numeroElementos;

        Nodo* posicionar(int posicao);

    public:
        Lista();
        ~Lista();

        T obterItem(int posicao);
        T obterPrimeiroItem();
        T obterUltimoItem()

        void inserirItem(T item, int posicao);
        void inserirItemPrimeiraPosicao(T item);
        void inserirItemUltimaPosicao(T item);

        void imprimirLista();
        void imprimirListaReversa();
        void limparLista();

}