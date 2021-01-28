#include "estruturas/nodo.h"

using namespace extracaoZ;

template <class T> 
Nodo<T>::Nodo(T item) {
    this->item = item;
    this->proximoItem = NULL;
    this->itemAnterior = NULL;
}


// tipos de nodo que serão utilizados no programa
template class Nodo<int>;