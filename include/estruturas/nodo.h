#ifndef NODO
#define NODO

namespace extracaoZ {
    template <class T> 
    class Nodo {
        private:
            Nodo<T>* proximoItem;
            Nodo<T>* itemAnterior;

            T item;

        public:
            Nodo();
            Nodo(T item);
            ~Nodo();

            void setProximoItem(Nodo<T>* proximoItem);
            void setItemAnterior(Nodo<T>* itemAnterior);

            void setItem(T item);
            
            Nodo<T>* getProximoItem();
            Nodo<T>* getItemAnterior();

            T getItem();

    };
}

#include "estruturas/nodo.tcc"

#endif