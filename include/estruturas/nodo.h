template <typename T> 

class Nodo {
    private:
        Nodo* proximoItem;
        Nodo* itemAnterior;

        T item;

    public:
        Nodo()
        Nodo(T item)
        ~Nodo()

    friend class Lista;

}