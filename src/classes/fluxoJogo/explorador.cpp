#include "fluxoJogo/explorador.h"
#include "fluxoJogo/leitorMapa.h"
#include "fluxoJogo/executorComandos.h"
#include "planeta/planeta.h"


using namespace extracaoZ;

Explorador::Explorador() {
    this->planeta = new Planeta();
    this->leitorMapa = new LeitorMapa();
    this->executor = new ExecutorComandos(this->planeta);
}

Explorador::~Explorador() {
    delete this->planeta;
    delete this->leitorMapa;
    delete this->executor;
}

void Explorador::iniciarExtracaoZ(std::string caminhoArquivoMapa, std::string caminhoArquivoComandos) {
    Mapa* mapa = this->leitorMapa->inicializarMapa(caminhoArquivoMapa);
    this->planeta->setMapa(mapa);

    delete mapa;

    this->executor->executarComandos(caminhoArquivoComandos);
}
