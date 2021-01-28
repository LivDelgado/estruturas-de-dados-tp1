#include "estruturas/lista.h"
#include "estruturas/nodo.h"
#include <iostream>

using namespace extracaoZ;

template <class T>
Lista<T>::Lista() {
    this->primeiroItem = NULL;
    this->ultimoItem = this->primeiroItem;
    this->numeroElementos = 0;
}

template <class T>
Lista<T>::~Lista() {
    this.limparLista();
    delete this->ultimoItem;
    delete this->primeiroItem;
}

template <class T>
Nodo<T>* Lista<T>::posicionar(int posicao) {
    int contador = 1
    
    if (posicao > this->numeroElementos || posicao <= 0) {
        throw "Não existe essa posição na lista!"
    }
    
    Nodo* itemAtual = this->primeiroItem;
    while (contador < posicao) {
        itemAtual = itemAtual->proximoItem;
        contador++;
    }

    return itemAtual;
}

template <class T>
T* Lista<T>::obterItem(int posicao) {
    if (this->numeroElementos == 0) {
        throw "Lista vazia";
    }
    Nodo* elemento = this.posicionar(posicao);
    return elemento->item;
}

template <class T>
T* Lista<T>::obterPrimeiroItem() {
    Nodo* elemento = this->primeiroItem;
    return elemento->item;
}

template <class T>
T* Lista<T>::obterUltimoItem() {
    Nodo* elemento = this->ultimoItem;
    return elemento->item;
}

template <class T>
void Lista<T>::inserirItem(T item, int posicao) {
    if (posicao == this->numeroElementos) {
        this.inserirItemUltimaPosicao(item);
    } else if (posicao == 1) {
        this.inserirItemPrimeiraPosicao(item);
    } else {
        Nodo* elemento = posicionar(posicao);

        Nodo* elementoAnterior = elemento->itemAnterior;
        Nodo novoElemento = new Nodo(item);

        novoElemento->proximoItem = elemento;
        elementoAnterior->proximoItem = novoElemento;
        elemento->itemAnterior = novoElemento;

        numeroElementos++;
    }
}

template <class T>
void Lista<T>::inserirItemPrimeiraPosicao(T item) {
    Nodo novoElemento = new Nodo(item);

    if (this->primeiroItem == NULL) {
        this->primeiroItem = novoElemento;
    } else {
        Nodo* primeiroItemAtual = this->primeiroItem;
        primeiroItemAtual->itemAnterior = novoElemento;
        novoElemento->proximoItem = primeiroItemAtual;
        this->primeiroItem = novoElemento;
    }

    if (novoElemento->proximoItem == NULL) {
        this->ultimoItem = novoElemento;
    }

    this->numeroElementos++;
}

template <class T>
void Lista<T>::inserirItemUltimaPosicao(T item) {
    Nodo novoElemento = new Nodo(item)

    if (this->numeroElementos == 0) {
        this.inserirItemPrimeiraPosicao(item);
    } else {
        this->ultimoItem->proximoItem = novoElemento;
        novoElemento->itemAnterior = this->ultimoItem;
        this->ultimoItem = novoElemento;
    }

    this->numeroElementos++;
}

template <class T>
void Lista<T>::imprimirLista() {
    Nodo* elementoAtual = this->primeiroItem;
    while (elementoAtual->proximoItem) {
        std::cin >> elementoAtual->item;
        elementoAtual = elementoAtual->proximoItem;
    }
}

template <class T>
void Lista<T>::imprimirListaReversa() {
    Nodo* elementoAtual = this->ultimoItem;
    while (elementoAtual->itemAnterior) {
        std::cin >> elementoAtual->item;
        elementoAtual = elementoAtual->itemAnterior;
    }
}

template <class T>
void Lista<T>::limparLista() {
    Nodo* elementoAtual = this->ultimoItem;
    while (elementoAtual != NULL) {
        Nodo* aux = elementoAtual;
        elementoAtual = elementoAtual->itemAnterior;
        delete aux;
    }
}


// tipos de lista que serão utilizados no programa
template class Lista<int>;