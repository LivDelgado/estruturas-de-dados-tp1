#include "estruturas/nodoOrdemComando.h"

using namespace extracaoZ;


NodoOrdemComando::NodoOrdemComando(OrdemComando ordem) {
    this->ordem = ordem;
    this->proximaOrdem = NULL;
}


void NodoOrdemComando::setProximaOrdem(NodoOrdemComando* proximaOrdem) {
    this->proximaOrdem = proximaOrdem;
}


void NodoOrdemComando::setOrdemComando(OrdemComando ordem) {
    this->ordem = ordem;
}



NodoOrdemComando* NodoOrdemComando::getProximaOrdem() {
    return this->proximaOrdem;
}


OrdemComando NodoOrdemComando::getOrdemComando() {
    return this->ordem;
}
