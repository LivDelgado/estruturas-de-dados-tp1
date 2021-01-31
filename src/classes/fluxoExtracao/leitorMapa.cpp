#include "fluxoExtracao/leitorMapa.h"
#include "planeta/mapa.h"

#include <sstream>
#include <string>

using namespace extracaoZ;

#define DIMENSOES_MAPA = 2;
#define MAPA_INVALIDO "Mapa inválido!"
#define DELIMITADOR ' '

LeitorMapa::LeitorMapa() {
    this->leitor = new LeitorArquivos();
}
LeitorMapa::~LeitorMapa() {
    delete this->leitor;
}

std::string* LeitorMapa::lerArquivo(std::string caminhoArquivo) {
    return this->leitor->lerArquivo(caminhoArquivo);
}

Mapa* LeitorMapa::criarMapa(std::string* linhasArquivo) {
    int numeroLinhas = this->leitor->getNumeroLinhasArquivo();

    if (numeroLinhas < 2) {
        throw "Não é possível criar o mapa, estão faltando informações";
    }

    std::string primeiraLinhaArquivo = linhasArquivo[0];
    int posicaoDelimitador = primeiraLinhaArquivo.find(DELIMITADOR);
    std::string x_str = primeiraLinhaArquivo.substr(0, posicaoDelimitador);
    std::string y_str = primeiraLinhaArquivo.substr(posicaoDelimitador+1);

    int x = std::stoi(x_str);
    int y = std::stoi(y_str);

    if ((numeroLinhas-1) != x) {
        throw MAPA_INVALIDO;
    }

    Mapa* mapa = new Mapa(x, y);

    for (int contadorLinhas = 0; contadorLinhas < numeroLinhas-1; contadorLinhas++) {
        std::istringstream linha(linhasArquivo[contadorLinhas+1]);
        std::string caracterePosicaoMapa;

        int contadorColunas = 0;

        while (getline(linha, caracterePosicaoMapa, ' ')) {
            if (caracterePosicaoMapa.empty() || contadorColunas >= y) {
                break;
            }

            char caractere = caracterePosicaoMapa.c_str()[0];

            mapa->setCaractereMapa(contadorLinhas, contadorColunas, caractere);
            contadorColunas++;
        }

        if (contadorColunas < y) {
            throw MAPA_INVALIDO;
        }

    }

    return mapa;
}

Mapa* LeitorMapa::inicializarMapa(std::string caminhoArquivo) {
    return this->criarMapa(this->lerArquivo(caminhoArquivo));
}