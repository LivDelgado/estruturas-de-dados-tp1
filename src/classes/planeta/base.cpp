#include "planeta/base.h"
#include "estruturas/filaOrdensComando.h"

using namespace extracaoZ;

Base::Base() {
    this->historicoExecucao = new FilaOrdensComando();
}

Base::~Base() {
    delete this->historicoExecucao;
}
