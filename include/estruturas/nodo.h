#ifndef NODO
#define NODO

namespace extracaoZ {
    template <class T> 
    class Nodo {
        private:
            Nodo<T>* proximoItem;
            Nodo<T>* itemAnterior;

            T item;

            // friend class Lista;

        public:
            Nodo();
            Nodo(T item);
            ~Nodo();

    };
}

#endif