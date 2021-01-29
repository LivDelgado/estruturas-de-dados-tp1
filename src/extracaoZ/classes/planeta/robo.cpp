#include "planeta/robo.h"
#include <iostream>

using namespace extracaoZ;

Robo::Robo() {
    this->indice = 0;
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

int Robo::obterPosicaoX() {
    return this->posicaoX;
}

int Robo::obterPosicaoY() {
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

void Robo::mudarPosicao(int x, int y) {
    this->posicaoX = x;
    this->posicaoY = y;
}

void Robo::roboEmMissao(bool emMissao) {
    this->emMissao = emMissao;
}