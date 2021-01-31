#include "estruturas/pilhaOrdensComando.h"
#include "estruturas/nodoOrdemComando.h"

using namespace extracaoZ;

PilhaOrdensComando::PilhaOrdensComando() {
    this->limpar();
    this->ultimaOrdem = nullptr;
}

PilhaOrdensComando::~PilhaOrdensComando() {
    delete this->ultimaOrdem;
}

bool PilhaOrdensComando::pilhaVazia() {
    return this->ultimaOrdem == nullptr;
}

void PilhaOrdensComando::empilharOrdemComando(OrdemComando* ordem) {
    NodoOrdemComando* novaOrdem = new NodoOrdemComando(ordem);
    if (this->pilhaVazia()) {
        this->ultimaOrdem = novaOrdem;
    } else {
        NodoOrdemComando* auxiliar = this->ultimaOrdem;
        novaOrdem->setOrdemAnterior(auxiliar);
        this->ultimaOrdem = novaOrdem;
    }
}

OrdemComando* PilhaOrdensComando::desempilharOrdemComando() {
    if (this->pilhaVazia()) {
        throw "Pilha vazia";
    }
    NodoOrdemComando* auxiliar = this->ultimaOrdem;
    this->ultimaOrdem = auxiliar->getOrdemAnterior();

    auxiliar->setOrdemAnterior(nullptr);

    return auxiliar->getOrdemComando();
}

void PilhaOrdensComando::limpar() {
    while (!this->pilhaVazia()) {
        this->desempilharOrdemComando();
    }
}