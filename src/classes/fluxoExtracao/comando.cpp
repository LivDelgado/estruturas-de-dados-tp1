#include "fluxoExtracao/comando.h"
#include "enums/acao.h"

using namespace extracaoZ;

Comando::Comando() : Comando(0, false, false) {}

Comando::Comando(int indiceRobo, bool temPrioridade, bool direta)
    : Comando(indiceRobo, temPrioridade, direta, 0, 0) {}

Comando::Comando(int indiceRobo, bool temPrioridade, bool direta, int posicaoX, int posicaoY)
    : Comando(indiceRobo, temPrioridade, direta, posicaoX, posicaoY, (Acao)0) {}

Comando::Comando(int indiceRobo, bool temPrioridade, bool direta, int posicaoX, int posicaoY, Acao acao) {
    this->indiceRobo = indiceRobo;
    this->posicaoX = posicaoX;
    this->posicaoY = posicaoY;
    this->temPrioridade = temPrioridade;
    this->direta = direta;
    this->acao = acao;
}

Comando::~Comando() {}


void Comando::setIndiceRobo(int indiceRobo) {
    this->indiceRobo = indiceRobo;
}

void Comando::setPosicaoX(int posicaoX) {
    this->posicaoX = posicaoX;
}

void Comando::setPosicaoY(int posicaoY) {
    this->posicaoY = posicaoY;
}

void Comando::setTemPrioridade(bool temPrioridade) {
    this->temPrioridade = temPrioridade;
}

void Comando::setDireta(bool direta) {
    this->direta = direta;
}

void Comando::setAcao(Acao acao) {
    this->acao = acao;
}


int Comando::getIndiceRobo() {
    return this->indiceRobo;
}

int Comando::getPosicaoX() {
    return this->posicaoX;
}

int Comando::getPosicaoY() {
    return this->posicaoY;
}

bool Comando::getTemPrioridade() {
    return this->temPrioridade;
}

bool Comando::getDireta() {
    return this->direta;
}

Acao Comando::getAcao() {
    return this->acao;
}

