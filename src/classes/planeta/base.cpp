#include "planeta/base.h"
#include "estruturas/filaOrdensComando.h"

using namespace extracaoZ;

Base::Base() {
    this->historicoExecucao = new FilaOrdensComando();
}

Base::~Base() {
    delete this->historicoExecucao;
}

int Base::adicionarItensColetados(int quantidade) {
    this->numeroItensColetados += quantidade;
    return this->numeroItensColetados;
}

int Base::adicionarAlienigenasDerrotados(int quantidade) {
    this->numeroAlienigenasDerrotados += quantidade;
    return this->numeroAlienigenasDerrotados;
}

int Base::obterItensColetados() {
    return this->numeroItensColetados;
}

int Base::obterAlienigenasDerrotados() {
    return this->numeroAlienigenasDerrotados;
}

void Base::adicionarOrdemDeComandoNoHistorico(OrdemComando* ordemComando) {
    this->historicoExecucao->enfileirarOrdemComando(ordemComando);
}

FilaOrdensComando* Base::getHistoricoExecucao() {
    return this->historicoExecucao;
}

