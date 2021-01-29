#include "estruturas/nodo.h"
#include "planeta/robo.h"

#include <cstddef>

using namespace extracaoZ;

template <class T> 
Nodo<T>::Nodo(T item) {
    this->item = item;
    this->proximoItem = NULL;
    this->itemAnterior = NULL;
}

template <class T>
void Nodo<T>::setProximoItem(Nodo<T>* proximoItem) {
    this->proximoItem = proximoItem;
}

template <class T>
void Nodo<T>::setItemAnterior(Nodo<T>* itemAnterior) {
    this->itemAnterior = itemAnterior;
}

template <class T>
void Nodo<T>::setItem(T item) {
    this->item = item;
}


template <class T>
Nodo<T>* Nodo<T>::getProximoItem() {
    return this->proximoItem;
}

template <class T>
Nodo<T>* Nodo<T>::getItemAnterior() {
    return this->itemAnterior;
}

template <class T>
T Nodo<T>::getItem() {
    return this->item;
}

// tipos de nodo que serão utilizados no programa
template class Nodo<Robo>;