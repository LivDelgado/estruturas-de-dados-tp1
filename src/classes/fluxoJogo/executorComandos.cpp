#include "fluxoJogo/executorComandos.h"
#include "fluxoJogo/decodificadorComandos.h"
#include "fluxoJogo/ordemComando.h"
#include "fluxoJogo/comando.h"
#include "enums/acao.h"

#include <iostream>

using namespace extracaoZ;

ExecutorComandos::ExecutorComandos(Planeta* planeta) {
    this->planeta = planeta;
    this->decodificador = new DecodificadorComandos();
}

ExecutorComandos::~ExecutorComandos() {
    delete this->decodificador;
    delete this->planeta;
}

void ExecutorComandos::executarComandos(std::string caminhoArquivo) {
    Comando* comandos = decodificador->decodificarComandos(caminhoArquivo);
    this->executarComandos(comandos);
}

void ExecutorComandos::executarComandos(Comando* comandos) {
    if (this->decodificador->getQuantidadeComandos() == 0) {
        throw "Nenhum comando a executar!";
    }
    for (int comandoAtual = 0; comandoAtual < decodificador->getQuantidadeComandos(); comandoAtual++) {
        executarComando(&comandos[comandoAtual]);
    }
}

void ExecutorComandos::executarComando(Comando* comando) {
    if (comando->getDireta()) {
        this->executarOrdemDireta(comando);
    }
    else {
        Robo* robo = this->planeta->obterRobo(comando->getIndiceRobo());
        OrdemComando* ordem = this->converterComandoEmOrdem(comando);
        if (comando->getTemPrioridade()) {
            robo->adicionarOrdemDeComandoPrioritaria(ordem);
        } else {
            robo->adicionarOrdemDeComando(ordem);
        }
    }
}

void ExecutorComandos::executarOrdemDireta(Comando* comando) {
    switch (comando->getAcao()) {
        case ATIVAR:
            this->ativarRobo(comando);
            break;
        case EXECUTAR:
            this->executarListaComandosRobo(comando);
            break;
        case RELATORIO:
            this->imprimirRelatorioRobo(comando);
            break;
        case RETORNAR:
            this->retornarRoboParaBase(comando);
        default:
            throw "Ordem de direta inválida";
    }
}

void ExecutorComandos::executarListaComandosRobo(Comando* comando) {
    Robo* robo = this->planeta->obterRobo(comando->getIndiceRobo());
    while(!robo->getOrdensComandoPrioritarios()->pilhaVazia()) {
        OrdemComando* ordem = robo->getOrdensComandoPrioritarios()->desempilharOrdemComando();
        this->executarOrdemComando(ordem, comando->getIndiceRobo());
    }

    while(!robo->getOrdensComando()->filaVazia()) {
        OrdemComando* ordem = robo->getOrdensComando()->desenfileirarOrdemComando();
        this->executarOrdemComando(ordem, comando->getIndiceRobo());
    }

}

void ExecutorComandos::executarOrdemComando(OrdemComando* ordem, int indiceRobo) {
    Robo* robo = this->planeta->obterRobo(indiceRobo);
    switch (ordem->getAcao()) {
        case MOVER:
            this->moverRobo(ordem, robo);
            break;
        case COLETAR:
            this->roboColetarRecurso(ordem, robo);
            break;
        case ELIMINAR:
            this->roboEliminarAlien(ordem, robo);
            break;
        default:
            throw "Ordem de comando inválida";
    }
}


void ExecutorComandos::moverRobo(OrdemComando* comando, Robo* robo) {
    std::string mensagem = "ROBO " + robo->obterIndice();
    if (this->planeta->obterMapa()->verificarCoordenadaTemObstaculo(comando->getPosicaoX(), comando->getPosicaoY())) {
        mensagem += ": IMPOSSIVEL MOVER PARA ";
    } else {
        robo->setPosicao(comando->getPosicaoX(), comando->getPosicaoY());
        mensagem += ": MOVEU PARA ";
    }
    mensagem += '(' + comando->getPosicaoX() + ',' + comando->getPosicaoY() + '\n';
    comando->setComando(mensagem);

    robo->adicionarOrdemDeComandoNoHistorico(comando);
}

