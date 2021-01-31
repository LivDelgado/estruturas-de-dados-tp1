#include "planeta/mapa.h"

#include <stdio.h> 
#include <stdlib.h> 

using namespace extracaoZ;

#define RECURSO 'R'
#define OBSTACULO 'O'
#define ALIEN_HOSTIL 'H'
#define VAZIO '.'
#define BASE 'B'

Mapa::Mapa(int x, int y) {
    this->tamanhoX = x;
    this->tamanhoY = y;
    this->criarMapa(x, y);
}

Mapa::~Mapa() {
    for (int i = 0; i < this->tamanhoX; i++) {
        delete this->mapa[i];
    }
    delete []this->mapa;
}

char** Mapa::criarMapa(int x, int y) {
    char** matriz = new char*[x];
    for(int i = 0; i < x; i++) {
        matriz[i] = new char[y];
    }
    this-> mapa = matriz;
    return this->mapa;
}

char Mapa::getCaractereMapa(int x, int y) {
    this->verificarPosicaoValida(x, y);
    return this->mapa[x][y];
}

void Mapa::verificarPosicaoValida(int x, int y) {
    if (x >= this->tamanhoX || y >= this->tamanhoY) {
        throw "Essa posição não existe no mapa!";
    }
}

void Mapa::setCaractereMapa(int x, int y, char caractere) {
    verificarPosicaoValida(x, y);
    this->mapa[x][y] = caractere;
}

char Mapa::obterCaractereNaPosicao(int x, int y) {
    verificarPosicaoValida(x, y);
    return this->mapa[x][y];
}

bool Mapa::verificarCoordenadaTemRecurso(int x, int y) {
    char caractere = this->obterCaractereNaPosicao(x, y);
    return caractere == RECURSO;
}

bool Mapa::verificarCoordenadaTemObstaculo(int x, int y) {
    char caractere = this->obterCaractereNaPosicao(x, y);
    return caractere == OBSTACULO;
}

bool Mapa::verificarCoordenadaTemAlien(int x, int y) {
    char caractere = this->obterCaractereNaPosicao(x, y);
    return caractere == ALIEN_HOSTIL;
}

bool Mapa::verificarCoordenadaVazia(int x, int y) {
    char caractere = this->obterCaractereNaPosicao(x, y);
    return caractere == VAZIO;
}

bool Mapa::verificarCoordenadaBase(int x, int y) {
    char caractere = this->obterCaractereNaPosicao(x, y);
    return caractere == BASE || (x == 0 && y == 0);
}

void Mapa::esvaziarPosicao(int x, int y) {
    this->setCaractereMapa(x, y, VAZIO);
}

