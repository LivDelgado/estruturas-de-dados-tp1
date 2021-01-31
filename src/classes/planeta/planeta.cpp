#include "planeta/planeta.h"
#include "planeta/mapa.h"
#include "planeta/base.h"
#include "planeta/robo.h"

#define NUMERO_ROBOS 50

using namespace extracaoZ;

Planeta::Planeta() {
    this->robos = new Robo[NUMERO_ROBOS];
    this->inicializarRobos();
    this->base = new Base();
    this->mapa = nullptr;
}

Planeta::~Planeta() {
    delete this->robos;
    delete this->base;
    delete this->mapa;
}

void Planeta::inicializarRobos() {
    for (int i = 0; i < NUMERO_ROBOS; i++) {
        this->robos[i].setIndice(i);
    }
}

Mapa* Planeta::obterMapa() {
    return this->mapa;
}

Robo* Planeta::obterRobo(int indiceRobo) {
    if (indiceRobo < 0 || indiceRobo > NUMERO_ROBOS) {
        throw "Esse robô não existe!";
    }
    return &(this->robos[indiceRobo]);
}

Base* Planeta::obterBase() {
    return this->base;
}


void Planeta::setMapa(Mapa* mapa) {
    this->mapa = mapa;
}

bool Planeta::verificarRoboEmExploracao(int indiceRobo) {
    return this->robos[indiceRobo].obterEmMissao();
}
