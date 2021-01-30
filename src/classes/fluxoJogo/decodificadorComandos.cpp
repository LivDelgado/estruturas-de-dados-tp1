#include "fluxoJogo/decodificadorComandos.h"
#include "fluxoJogo/leitorArquivos.h"
#include "fluxoJogo/comando.h"
#include "enums/acao.h"

#include <sstream>
#include <string>


#define CARACTERE_PRIORIDADE '*'

#define MOVER "MOVER"
#define COLETAR "COLETAR"
#define ELIMINAR "ELIMINAR"
#define ATIVAR "ATIVAR"
#define EXECUTAR "EXECUTAR"
#define RELATORIO "RELATORIO"
#define RETORNAR "RETORNAR"

#define DELIMITADOR_POSICAO ','
using namespace extracaoZ;

DecodificadorComandos::DecodificadorComandos() {
    this->leitor = new LeitorArquivos();
    this->quantidadeComandos = 0;
}

DecodificadorComandos::~DecodificadorComandos() {
    delete this->leitor;
}

std::string* DecodificadorComandos::lerArquivo(std::string caminhoArquivo) {
    return this->leitor->lerArquivo(caminhoArquivo);
}

Comando* DecodificadorComandos::decodificarComandos(std::string caminhoArquivo) {
    std::string* linhasComando = this->lerArquivo(caminhoArquivo);

    return this->interpretarComandos(linhasComando);
}

int DecodificadorComandos::getQuantidadeComandos() {
    return this->quantidadeComandos;
}

Comando* DecodificadorComandos::interpretarComandos(std::string* linhasComando) {
    this->quantidadeComandos = this->leitor->getNumeroLinhasArquivo();

    if (this->quantidadeComandos <= 0) {
        throw "Não há nenhum comando a ser executado!";
    }

    Comando* comandos = new Comando[this->quantidadeComandos];

    for (int comandoAtual = 0; comandoAtual < this->quantidadeComandos; comandoAtual++) {
        comandos[comandoAtual] = *(this->interpretarComando(linhasComando[comandoAtual]));
    }

    return comandos;
}

Comando* DecodificadorComandos::interpretarComando(std::string linhaComando) {
    std::istringstream linha(linhaComando);
    std::string valor;

    std::string instrucao;
    std::string robo;
    std::string posicao;


    int contadorColunas = 0;

    while (getline(linha, valor, ' ')) {
        if (valor.empty()) {
            break;
        }

        if (contadorColunas == 0) {
            instrucao = valor;
        } else if (contadorColunas == 1) {
            robo = valor;
        } else {
            posicao = valor;
        }

        contadorColunas++;
    }

    Comando* comando = new Comando();

    this->decodificarInstrucao(*comando, instrucao);
    this->decodificarRobo(*comando, robo);
    this->decodificarPosicao(*comando, posicao);

    return comando;
}

void DecodificadorComandos::decodificarInstrucao(Comando &comando, std::string instrucao) {
    if (instrucao.empty()) {
        return;
    }

    const char *caracteres = instrucao.c_str();
    if (caracteres[0] == CARACTERE_PRIORIDADE) {
        comando.setTemPrioridade(true);
        instrucao = instrucao.substr(1);
    }

    comando.setAcao(this->converterAcaoParaEnum(instrucao));
}

Acao DecodificadorComandos::converterAcaoParaEnum(std::string instrucao) {
    if (instrucao == MOVER) {
        return (Acao)0;
    } else if (instrucao == COLETAR) {
        return (Acao)1;
    } else if (instrucao == ELIMINAR) {
        return (Acao)2;
    } else if (instrucao == ATIVAR) {
        return (Acao)3;
    } else if (instrucao == EXECUTAR) {
        return (Acao)4;
    } else if (instrucao == RELATORIO) {
        return (Acao)5;
    } else if (instrucao == RETORNAR) {
        return (Acao)6;
    } else {
        throw "Ação inválida";
    }
}

void DecodificadorComandos::decodificarRobo(Comando &comando, std::string robo) {
    if (robo.empty()) {
        return;
    }

    int indiceRobo = std::stoi(robo);
    if (indiceRobo < 0 || indiceRobo > 49) {
        throw "Não é possível executar instrução para esse robô - ele não existe!";
    }
    comando.setIndiceRobo(indiceRobo);
}

void DecodificadorComandos::decodificarPosicao(Comando &comando, std::string posicao) {
    if (posicao.empty()) {
        return;
    }

    int posicaoDelimitador = posicao.find(DELIMITADOR_POSICAO);
    std::string x_str = posicao.substr(1, posicaoDelimitador);
    std::string y_str = posicao.substr(posicaoDelimitador+1, posicao.length()-2);

    comando.setPosicaoX(std::stoi(x_str));
    comando.setPosicaoY(std::stoi(y_str));
}

