#include "estruturas/filaOrdensComando.h"
#include "estruturas/nodoOrdemComando.h"

using namespace extracaoZ;

FilaOrdensComando::FilaOrdensComando() {
    this->primeiraOrdem = nullptr;
    this->ultimaOrdem = this->primeiraOrdem;
}

FilaOrdensComando::~FilaOrdensComando() {
    this->limpar();
    delete this->primeiraOrdem;
    delete this->ultimaOrdem;
}

bool FilaOrdensComando::filaVazia() {
    return this->primeiraOrdem == nullptr;
}

void FilaOrdensComando::enfileirarOrdemComando(OrdemComando* ordem) {
    NodoOrdemComando* novaOrdem = new NodoOrdemComando(ordem);
    if (this->filaVazia()) {
        this->primeiraOrdem = novaOrdem;
        this->ultimaOrdem = this->primeiraOrdem;
    } else {
        NodoOrdemComando* auxiliar = this->ultimaOrdem;
        auxiliar->setProximaOrdem(novaOrdem);
        this->ultimaOrdem = novaOrdem;
    }
}

OrdemComando* FilaOrdensComando::desenfileirarOrdemComando() {
    if (this->filaVazia()) {
        throw "Fila vazia";
    }
    NodoOrdemComando* auxiliar = this->primeiraOrdem;
    this->primeiraOrdem = auxiliar->getProximaOrdem();

    return auxiliar->getOrdemComando();
}

void FilaOrdensComando::limpar() {
    if (this->filaVazia()) {
        return;
    }
    NodoOrdemComando* atual = this->primeiraOrdem;
    while (atual != nullptr) {
        this->primeiraOrdem->setProximaOrdem(atual->getProximaOrdem());
        delete atual;
        atual = this->primeiraOrdem->getProximaOrdem();
    }
}