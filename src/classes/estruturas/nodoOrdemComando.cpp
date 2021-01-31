#include "estruturas/nodoOrdemComando.h"

using namespace extracaoZ;


NodoOrdemComando::NodoOrdemComando() {
    this->ordem = nullptr;
    this->proximaOrdem = nullptr;
    this->ordemAnterior = nullptr;
}

NodoOrdemComando::NodoOrdemComando(OrdemComando* ordem) {
    this->ordem = ordem;
    this->proximaOrdem = nullptr;
    this->ordemAnterior = nullptr;
}

NodoOrdemComando::~NodoOrdemComando() {
    delete this->ordem;
    delete this->ordemAnterior;
    delete this->proximaOrdem;
}

void NodoOrdemComando::setProximaOrdem(NodoOrdemComando* proximaOrdem) {
    this->proximaOrdem = proximaOrdem;
}

void NodoOrdemComando::setOrdemAnterior(NodoOrdemComando* ordemAnterior) {
    this->ordemAnterior = ordemAnterior;
}

void NodoOrdemComando::setOrdemComando(OrdemComando* ordem) {
    this->ordem = ordem;
}

NodoOrdemComando* NodoOrdemComando::getProximaOrdem() {
    return this->proximaOrdem;
}

NodoOrdemComando* NodoOrdemComando::getOrdemAnterior() {
    return this->ordemAnterior;
}

OrdemComando* NodoOrdemComando::getOrdemComando() {
    return this->ordem;
}
