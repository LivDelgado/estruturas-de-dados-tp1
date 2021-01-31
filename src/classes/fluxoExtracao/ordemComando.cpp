#include "fluxoExtracao/ordemComando.h"
#include "enums/acao.h"

using namespace extracaoZ;

OrdemComando::OrdemComando() : OrdemComando((Acao)0, NULL, 0, 0) {}

OrdemComando::OrdemComando(Acao acao, std::string comando) 
    : OrdemComando(acao, comando, 0, 0)  {}

OrdemComando::OrdemComando(Acao acao, std::string comando, int posicaoX, int posicaoY) {
    this->acao = acao;
    this->comando = comando;
    this->posicaoX = posicaoX;
    this->posicaoY = posicaoY;
}

OrdemComando::~OrdemComando() {}

void OrdemComando::setAcao(Acao acao) {
    this->acao = acao;
}

void OrdemComando::setPosicaoX(int x) {
    this->posicaoX = x;
}

void OrdemComando::setPosicaoY(int y) {
    this->posicaoY = y;
}

void OrdemComando::setPosicao(int x, int y) {
    this->posicaoX = x;
    this->posicaoY = y;
}

void OrdemComando::setComando(std::string comando) {
    this->comando = comando;
}

Acao OrdemComando::getAcao() {
    return this->acao;
}

int OrdemComando::getPosicaoX() {
    return this->posicaoX;
}

int OrdemComando::getPosicaoY() {
    return this->posicaoY;
}

std::string OrdemComando::getComando() {
    return this->comando;
}
