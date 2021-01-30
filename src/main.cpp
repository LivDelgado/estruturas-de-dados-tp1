#include <cstdlib>

#include <iostream>

#include "estruturas/filaOrdensComando.h"
#include "fluxoJogo/ordemComando.h"
#include "fluxoJogo/leitorMapa.h"
#include "planeta/mapa.h"

int main(int argc, char* argv[]) {
    std::system("clear");

    if (argc < 3) {
        std::cout << "Número de parâmetros insuficiente!" << std::endl;
        std::cout << "Devem ser informados os caminhos do arquivo de mapa e do arquvo de comandos." << std::endl;
        return 1;
    }

    std::string caminhoArquivoMapa = argv[1];
    //std::string caminhoArquivoComandos = argv[2];

    extracaoZ::LeitorMapa* leitorMapa = new extracaoZ::LeitorMapa();
    try {
        extracaoZ::Mapa* mapa = leitorMapa->inicializarMapa(caminhoArquivoMapa);
    } catch (char const* excecao){
        std::cout << excecao << std::endl;
        return 0;
    }

    //extracaoZ::FilaOrdensComando* fila = new extracaoZ::FilaOrdensComando();
    //extracaoZ::OrdemComando* ordem = new extracaoZ::OrdemComando();
    //fila->enfileirarOrdemComando(ordem);
}