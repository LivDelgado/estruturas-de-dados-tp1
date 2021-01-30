#include "fluxoJogo/leitorArquivos.h"

#include <string>
#include <fstream>

using namespace extracaoZ;

LeitorArquivos::LeitorArquivos() {
    this->numeroLinhas = 0;
}
LeitorArquivos::~LeitorArquivos() {}


void LeitorArquivos::contarNumeroLinhas(std::string caminhoArquivo) {
    std::ifstream arquivo;
    arquivo.open(caminhoArquivo);
    std::string linha;

    if (arquivo.is_open()) {
        while(getline(arquivo, linha)) {
            this->numeroLinhas++;
        }
        arquivo.close();
    }
}

std::string* LeitorArquivos::lerArquivo(std::string caminhoArquivo) {
    contarNumeroLinhas(caminhoArquivo);
    if (this->numeroLinhas == 0) {
        throw "Arquivo vazio!";
    }

    std::string* linhasArquivo = new std::string[this->numeroLinhas];

    std::ifstream arquivo;
    arquivo.open(caminhoArquivo);
    std::string linha;

    int i = 0;

    if (arquivo.is_open()) {
        while(getline(arquivo, linha)) {
            linhasArquivo[i] = linha;
            i++;
        }
        arquivo.close();
    }

    return linhasArquivo;
}

int LeitorArquivos::getNumeroLinhasArquivo() {
    return this->numeroLinhas;
}