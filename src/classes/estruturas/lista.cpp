#include "estruturas/lista.h"
#include <iostream>

template <typename T> 

Lista::Lista() {
    primeiroItem = NULL;
    ultimoItem = primeiroItem;
    numeroElementos = 0;
}

Lista::~Lista() {
    limparLista();
    delete ultimoItem;
    delete primeiroItem;
}

Nodo* Lista::posicionar(int posicao) {
    contador = 1
    
    if (posicao > numeroElementos || posicao <= 0) {
        throw "Não existe essa posição na lista!"
    }
    
    Nodo& itemAtual = primeiroItem;
    while (contador < posicao) {
        itemAtual = itemAtual->proximoItem;
        contador++;
    }

    return itemAtual;
}

Lista::obterItem(int posicao) {
    if (numeroElementos == 0) {
        throw "Lista vazia";
    }
    Nodo* elemento = posicionar(posicao);
    return elemento->item;
}

Lista::obterPrimeiroItem() {
    Nodo* elemento = primeiroItem;
    return elemento->item;
}

Lista::obterUltimoItem() {
    Nodo* elemento = ultimoItem;
    return elemento->item;
}

void Lista<T>::inserirItem(T item, int posicao) {
    if (posicao == numeroElementos) {
        inserirItemUltimaPosicao(item);
    } else if (posicao == 1) {
        inserirItemPrimeiraPosicao(item);
    } else {
        Nodo* elemento = posicionar(posicao);

        elementoAnterior = elemento->itemAnterior;
        Nodo novoElemento = new Nodo(item);

        novoElemento->proximoItem = elemento;
        elementoAnterior->proximoItem = novoElemento;
        elemento->itemAnterior = novoElemento;

        numeroElementos++;
    }
}

void Lista<T>::inserirItemPrimeiraPosicao(T item) {
    Nodo novoElemento = new Nodo(item)

    if (primeiroItem == NULL) {
        primeiroItem = novoElemento;
    } else {
        primeiroItemAtual = primeiroItem;
        primeiroItemAtual->itemAnterior = novoElemento;
        novoElemento->proximoItem = primeiroItemAtual;
        primeiroItem = novoElemento;
    }

    if (novoElemento->proximoItem == NULL) {
        ultimoItem = novoElemento;
    }

    numeroElementos++;
}

void Lista<T>::inserirItemUltimaPosicao(T item) {
    Nodo novoElemento = new Nodo(item)

    if (numeroElementos == 0) {
        inserirItemPrimeiraPosicao(item);
    } else {
        ultimoItem->proximoItem = novoElemento;
        novoElemento->itemAnterior = ultimoItem;
        ultimoItem = novoElemento;
    }

    numeroElementos++;
}

void Lista::imprimirLista() {
    Nodo* elementoAtual = primeiroItem;
    while (elementoAtual->proximoItem) {
        cin >> elementoAtual->item;
        elementoAtual = elementoAtual->proximoItem;
    }
}

void Lista::imprimirListaReversa() {
    Nodo* elementoAtual = ultimoItem;
    while (elementoAtual->itemAnterior) {
        cin >> elementoAtual->item;
        elementoAtual = elementoAtual->itemAnterior;
    }
}

void Lista::limparLista() {
    Nodo* elementoAtual = ultimoItem;
    while (elementoAtual != NULL) {
        aux = elementoAtual;
        elementoAtual = elementoAtual->itemAnterior;
        delete aux;
    }
}