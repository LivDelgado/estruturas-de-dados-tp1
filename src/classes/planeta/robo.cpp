#include "planeta/robo.h"

using namespace extracaoZ;

Robo::Robo() {
    this->indice = 0;
    this->emMissao = false;
    this->posicaoX = 0;
    this->posicaoY = 0;
    this->numeroItensColetados = 0;
    this->numeroAlienigenasDerrotados = 0;
}

Robo::Robo(int indice) {
    this->indice = indice;
    this->emMissao = false;
    this->posicaoX = 0;
    this->posicaoY = 0;
    this->numeroItensColetados = 0;
    this->numeroAlienigenasDerrotados = 0;
}

Robo::~Robo() {}

int Robo::obterIndice() {
    return this->indice;
}

bool Robo::obterEmMissao() {
    return this->emMissao;
}

int Robo::setPosicaoX() {
    return this->posicaoX;
}

int Robo::setPosicaoY() {
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