#include "planeta/robo.h"

using namespace extracaoZ;

Robo::Robo() : Robo(0) {}

Robo::Robo(int indice) {
    this->indice = indice;
    this->emMissao = false;
    this->posicaoX = 0;
    this->posicaoY = 0;
    this->numeroItensColetados = 0;
    this->numeroAlienigenasDerrotados = 0;
    this->ordensComando = new FilaOrdensComando();
    this->ordensComandoPrioritarios = new PilhaOrdensComando();
    this->historicoExecucao = new FilaOrdensComando();
}

Robo::~Robo() {
    delete this->ordensComando;
    delete this->ordensComandoPrioritarios;
    delete this->historicoExecucao;
}

int Robo::obterIndice() {
    return this->indice;
}

bool Robo::obterEmMissao() {
    return this->emMissao;
}

void Robo::setIndice(int indice) {
    this->indice = indice;
}

int Robo::getPosicaoX() {
    return this->posicaoX;
}

int Robo::getPosicaoY() {
    return this->posicaoY;
}

int Robo::obterNumeroItensColetados() {
    return this->numeroItensColetados;
}

int Robo::obterNumeroAlienigenasDerrotados() {
    return this->numeroAlienigenasDerrotados;
}

int Robo::incrementarNumeroItensColetados() {
    this->numeroItensColetados++;
    return this->numeroItensColetados;
}

int Robo::incrementarNumeroAlienigenasDerrotados() {
    this->numeroAlienigenasDerrotados++;
    return this->numeroAlienigenasDerrotados;
}

void Robo::zerarNumeroItensColetados() {
    this->numeroItensColetados = 0;
}

void Robo::zerarNumeroAlienigenasDerrotados() {
    this->numeroItensColetados = 0;
}

void Robo::setPosicao(int x, int y) {
    this->posicaoX = x;
    this->posicaoY = y;
}

void Robo::roboEmMissao(bool emMissao) {
    this->emMissao = emMissao;
}

void Robo::adicionarOrdemDeComando(OrdemComando* ordemComando) {
    this->ordensComando->enfileirarOrdemComando(ordemComando);
}

void Robo::adicionarOrdemDeComandoPrioritaria(OrdemComando* ordemComando) {
    this->ordensComandoPrioritarios->empilharOrdemComando(ordemComando);
}

void Robo::adicionarOrdemDeComandoNoHistorico(OrdemComando* ordemComando) {
    this->historicoExecucao->enfileirarOrdemComando(ordemComando);
}


FilaOrdensComando* Robo::getOrdensComando() {
    return this->ordensComando;
}

PilhaOrdensComando* Robo::getOrdensComandoPrioritarios() {
    return this->ordensComandoPrioritarios;
}

FilaOrdensComando* Robo::getHistoricoExecucao() {
    return this->historicoExecucao;
}

void Robo::limparHistorico() {
    this->historicoExecucao->limpar();
}

