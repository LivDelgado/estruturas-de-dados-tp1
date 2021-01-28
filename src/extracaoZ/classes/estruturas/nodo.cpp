#include "estruturas/nodo.h"

template <typename T> 
Nodo::Nodo(T item) {
    item = item;
    proximoItem = NULL;
    itemAnterior = NULL;
}