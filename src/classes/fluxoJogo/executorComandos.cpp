#include "fluxoJogo/executorComandos.h"
#include "fluxoJogo/decodificadorComandos.h"
#include "fluxoJogo/ordemComando.h"
#include "fluxoJogo/comando.h"
#include "enums/acao.h"
#include "constantes/mapa.h"

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
        this->executarComando(&comandos[comandoAtual]);
    }
    imprimirRelatorioFinalBase();
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
    switch ((Acao)comando->getAcao()) {
        case ATIVAR:
            this->ativarRobo(comando);
            break;
        case EXECUTAR:
            this->verificarExecutarListaComandosRobo(comando);
            break;
        case RELATORIO:
            this->imprimirRelatorioRobo(comando);
            break;
        case RETORNAR:
            this->retornarRoboParaBase(comando);
            break;
        default:
            throw "Ordem direta inválida";
    }
}

void ExecutorComandos::ativarRobo(Comando* comando) {
    Robo* robo = this->planeta->obterRobo(comando->getIndiceRobo());
    Base* base = this->planeta->obterBase();

    std::string mensagem = "Base: ROBO " + std::to_string(robo->obterIndice());

    if (robo->obterEmMissao()) {
        mensagem += " JA ESTA EM MISSAO";
    } else {
        robo->setPosicao(0, 0);
        robo->roboEmMissao(true);
        mensagem += " SAIU EM MISSAO";
    }

    OrdemComando* ordem = this->converterComandoEmOrdem(comando);
    ordem->setComando(mensagem);

    base->adicionarOrdemDeComandoNoHistorico(ordem);

    std::cout << mensagem << std::endl;
}

void ExecutorComandos::imprimirRelatorioRobo(Comando* comando) {
    Robo* robo = this->planeta->obterRobo(comando->getIndiceRobo());

    while (!robo->getHistoricoExecucao()->filaVazia()) {
        OrdemComando* ordem = robo->getHistoricoExecucao()->desenfileirarOrdemComando();

        std::cout << ordem->getComando();
    }
}

void ExecutorComandos::retornarRoboParaBase(Comando* comando) {
    Robo* robo = this->planeta->obterRobo(comando->getIndiceRobo());
    Base* base = this->planeta->obterBase();

    std::string mensagem = "Base: ROBO " + std::to_string(robo->obterIndice());
    OrdemComando* ordem = this->converterComandoEmOrdem(comando);

    if (this->planeta->verificarRoboEmExploracao(robo->obterIndice())) {
        base->adicionarItensColetados(robo->obterNumeroItensColetados());
        base->adicionarAlienigenasDerrotados(robo->obterNumeroAlienigenasDerrotados());

        mensagem += " RETORNOU ALIENS " + std::to_string(robo->obterNumeroAlienigenasDerrotados());
        mensagem += " RECURSOS " + std::to_string(robo->obterNumeroItensColetados());

        robo->zerarNumeroItensColetados();
        robo->zerarNumeroAlienigenasDerrotados();
        robo->setPosicao(0, 0);
        robo->limparHistorico();
    } else {
        mensagem += " NAO ESTA EM MISSAO";
    }

    ordem->setComando(mensagem);
    base->adicionarOrdemDeComandoNoHistorico(ordem);

    std::cout << mensagem << std::endl;
}

void ExecutorComandos::verificarExecutarListaComandosRobo(Comando* comando) {
    Base* base = this->planeta->obterBase();

    if (!planeta->verificarRoboEmExploracao(comando->getIndiceRobo())) {
        OrdemComando* ordem = this->converterComandoEmOrdem(comando);

        std::string mensagem = "Base: ROBO " + std::to_string(comando->getIndiceRobo());
        mensagem += " NAO ESTA EM MISSAO";

        ordem->setComando(mensagem);
        base->adicionarOrdemDeComandoNoHistorico(ordem);

        std::cout << mensagem << std::endl;

    } else {
        this->executarListaComandosRobo(comando);
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

    switch ((Acao)ordem->getAcao()) {
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
    std::string mensagem = "ROBO " + std::to_string(robo->obterIndice());

    if (this->planeta->obterMapa()->verificarCoordenadaTemObstaculo(comando->getPosicaoX(), comando->getPosicaoY())) {
        mensagem += ": IMPOSSIVEL MOVER PARA ";
    } else {
        robo->setPosicao(comando->getPosicaoX(), comando->getPosicaoY());
        mensagem += ": MOVEU PARA ";
    }
    mensagem += '(' + std::to_string(comando->getPosicaoX()) + ',' + std::to_string(comando->getPosicaoY()) + ")\n";
    comando->setComando(mensagem);

    robo->adicionarOrdemDeComandoNoHistorico(comando);
}

void ExecutorComandos::roboColetarRecurso(OrdemComando* comando, Robo* robo) {
    std::string mensagem = "ROBO " + std::to_string(robo->obterIndice());

    if (this->planeta->obterMapa()->verificarCoordenadaTemRecurso(comando->getPosicaoX(), comando->getPosicaoY())) {
        mensagem += ": IMPOSSIVEL COLETAR RECURSOS EM ";
    } else {
        robo->incrementarNumeroItensColetados();
        mensagem += ": RECURSOS COLETADOS EM ";
    }

    mensagem += '(' + std::to_string(robo->getPosicaoX()) + ',' + std::to_string(robo->getPosicaoY()) + ")\n";
    comando->setPosicao(robo->getPosicaoX(), robo->getPosicaoY());
    comando->setComando(mensagem);

    robo->adicionarOrdemDeComandoNoHistorico(comando);

    this->planeta->obterMapa()->setCaractereMapa(robo->getPosicaoX(), robo->getPosicaoY(), VAZIO);
}

void ExecutorComandos::roboEliminarAlien(OrdemComando* comando, Robo* robo) {
    std::string mensagem = "ROBO " + std::to_string(robo->obterIndice());
    if (this->planeta->obterMapa()->verificarCoordenadaTemAlien(comando->getPosicaoX(), comando->getPosicaoY())) {
        mensagem += ": IMPOSSIVEL ELIMINAR ALIEN EM ";
    } else {
        robo->incrementarNumeroAlienigenasDerrotados();
        mensagem += ": ALIEN ELIMINADO EM ";
    }
    mensagem += '(' + std::to_string(robo->getPosicaoX()) + ',' + std::to_string(robo->getPosicaoY()) + ")\n";
    comando->setPosicao(robo->getPosicaoX(), robo->getPosicaoY());
    comando->setComando(mensagem);

    robo->adicionarOrdemDeComandoNoHistorico(comando);

    this->planeta->obterMapa()->setCaractereMapa(comando->getPosicaoX(), comando->getPosicaoY(), VAZIO);
}

OrdemComando* ExecutorComandos::converterComandoEmOrdem(Comando* comando) {
    OrdemComando* ordem = new OrdemComando(
        comando->getAcao(),
        "",
        comando->getPosicaoX(),
        comando->getPosicaoY()
    );

    return ordem;
}

void ExecutorComandos::imprimirRelatorioFinalBase() {
    Base* base = this->planeta->obterBase();
    std::cout << "BASE: TOTAL DE ALIENS " << 
        base->obterAlienigenasDerrotados() <<
        " RECURSOS " << base->obterItensColetados() 
        << std::endl;
}

