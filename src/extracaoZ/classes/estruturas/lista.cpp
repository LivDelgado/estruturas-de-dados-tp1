#include "estruturas/lista.h"
#include "estruturas/nodo.h"

#include "planeta/robo.h"
#include <iostream>
#include <cstddef>

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
    int contador = 1;
    
    if (posicao > this->numeroElementos || posicao <= 0) {
        throw "Não existe essa posição na lista!";
    }
    
    Nodo<T>* itemAtual = this->primeiroItem;
    while (contador < posicao) {
        itemAtual = itemAtual->getProximoItem();
        contador++;
    }

    return itemAtual;
}

template <class T>
T* Lista<T>::obterItem(int posicao) {
    if (this->numeroElementos == 0) {
        throw "Lista vazia";
    }
    Nodo<T>* elemento = this.posicionar(posicao);
    return elemento->getItem();
}

template <class T>
T* Lista<T>::obterPrimeiroItem() {
    Nodo<T>* elemento = this->primeiroItem;
    return elemento->getItem();
}

template <class T>
T* Lista<T>::obterUltimoItem() {
    Nodo<T>* elemento = this->ultimoItem;
    return elemento->getItem();
}

template <class T>
void Lista<T>::inserirItem(T item, int posicao) {
    if (posicao == this->numeroElementos) {
        this.inserirItemUltimaPosicao(item);
    } else if (posicao == 1) {
        this.inserirItemPrimeiraPosicao(item);
    } else {
        Nodo<T>* elemento = posicionar(posicao);

        Nodo<T>* elementoAnterior = elemento->getItemAnterior();
        Nodo<T>* novoElemento = new Nodo<T>(item);

        novoElemento->setProximoItem(elemento);
        elementoAnterior->setProximoItem(novoElemento);
        elemento->setItemAnterior(novoElemento);

        numeroElementos++;
    }
}

template <class T>
void Lista<T>::inserirItemPrimeiraPosicao(T item) {
    Nodo<T>* novoElemento = new Nodo<T>(item);

    if (this->primeiroItem == NULL) {
        this->primeiroItem = novoElemento;
    } else {
        Nodo<T>* primeiroItemAtual = this->primeiroItem;
        primeiroItemAtual->setItemAnterior(novoElemento);
        novoElemento->setProximoItem(primeiroItemAtual);
        this->primeiroItem = novoElemento;
    }

    if (novoElemento->getProximoItem() == NULL) {
        this->ultimoItem = novoElemento;
    }

    this->numeroElementos++;
}

template <class T>
void Lista<T>::inserirItemUltimaPosicao(T item) {
    Nodo<T>* novoElemento = new Nodo<T>(item)

    if (this->numeroElementos == 0) {
        this.inserirItemPrimeiraPosicao(item);
    } else {
        this->ultimoItem->setProximoItem(novoElemento);
        novoElemento->setItemAnterior(this->ultimoItem);
        this->ultimoItem = novoElemento;
    }

    this->numeroElementos++;
}

template <class T>
void Lista<T>::imprimirLista() {
    Nodo<T>* elementoAtual = this->primeiroItem;
    while (elementoAtual->getProximoItem()) {
        std::cin >> elementoAtual->getItem();
        elementoAtual = elementoAtual->getProximoItem();
    }
}

template <class T>
void Lista<T>::imprimirListaReversa() {
    Nodo<T>* elementoAtual = this->ultimoItem;
    while (elementoAtual->getItemAnterior()) {
        std::cin >> elementoAtual->getItem();
        elementoAtual = elementoAtual->getItemAnterior();
    }
}

template <class T>
void Lista<T>::limparLista() {
    Nodo<T>* elementoAtual = this->ultimoItem;
    while (elementoAtual != NULL) {
        Nodo<T>* aux = elementoAtual;
        elementoAtual = elementoAtual->getItemAnterior();
        delete aux;
    }
}


template <class T>
Nodo<T>* Lista<T>::removerItem(int posicao) {
    if (this->numeroElementos == 0) {
        throw "LISTA VAZIA";
    }
    if (posicao == 1) {
        return this->removerPrimeiroItem();
    } else if (posicao == this->numeroElementos) {
        return this->removerPrimeiroItem();
    } else {
        Nodo<T>* elementoAtual = this->posicionar(posicao);
        elementoAtual->getProximoItem()->setItemAnterior(elementoAtual->getItemAnterior());
        elementoAtual->getItemAnterior()->setProximoItem(elementoAtual->getProximoItem);
        return elementoAtual;
    }

}

template <class T>
Nodo<T>* Lista<T>::removerPrimeiroItem() {
    if (this->numeroElementos == 0) {
        throw "LISTA VAZIA";
    }
    Nodo<T>* auxiliar = this->primeiroItem;
    this->primeiroItem = auxiliar->getProximoItem();
    this->primeiroItem->setItemAnterior(NULL);
    return auxiliar;
}

template <class T>
Nodo<T>* Lista<T>::removerUltimoItem() {
    if (this->numeroElementos == 0) {
        throw "LISTA VAZIA";
    }
    Nodo<T>* auxiliar = this->ultimoItem;
    this->ultimoItem = auxiliar->getItemAnterior();
    this->ultimoItem->setProximoItem(NULL);
    return auxiliar;
}


// tipos de lista que serão utilizados no programa
template class Lista<Robo>;