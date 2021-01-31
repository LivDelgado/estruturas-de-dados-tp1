#include "fluxoJogo/leitorMapa.h"
#include "fluxoJogo/executorComandos.h"
#include "planeta/planeta.h"
#include "planeta/mapa.h"
#include "planeta/base.h"
#include "planeta/robo.h"

#define NUMERO_ROBOS 50

using namespace extracaoZ;

Planeta::Planeta() {
    this->robos = new Robo[NUMERO_ROBOS];
    this->base = new Base();
    this->mapa = nullptr;
//    LeitorMapa* leitor = new LeitorMapa();
//    this->mapa = leitor->inicializarMapa()
}

Planeta::~Planeta() {
    delete this->robos;
    delete this->base;
    delete this->mapa;
}

Mapa* Planeta::obterMapa() {
    return this->mapa;
}

bool Planeta::verificarRoboEmExploracao(int indiceRobo) {
    Robo robo = this->robos[indiceRobo];
    return robo.obterEmMissao();
}

Robo* Planeta::obterRobo(int indiceRobo) {
    if (indiceRobo < 0 || indiceRobo > NUMERO_ROBOS) {
        throw "Esse robô não existe!";
    }
    return &this->robos[indiceRobo];
}