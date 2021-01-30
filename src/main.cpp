#include <cstdlib>

#include <iostream>

#include "estruturas/filaOrdensComando.h"
#include "fluxoJogo/ordemComando.h"
#include "fluxoJogo/leitorMapa.h"
#include "fluxoJogo/decodificadorComandos.h"
#include "planeta/mapa.h"
#include "fluxoJogo/comando.h"

int main(int argc, char* argv[]) {
    std::system("clear");

    if (argc < 3) {
        std::cout << "Número de parâmetros insuficiente!" << std::endl;
        std::cout << "Devem ser informados os caminhos do arquivo de mapa e do arquvo de comandos." << std::endl;
        return 1;
    }

    std::string caminhoArquivoMapa = argv[1];
    std::string caminhoArquivoComandos = argv[2];

    extracaoZ::LeitorMapa* leitorMapa = new extracaoZ::LeitorMapa();
    extracaoZ::DecodificadorComandos* decodificador = new extracaoZ::DecodificadorComandos();
    try {
        extracaoZ::Mapa* mapa = leitorMapa->inicializarMapa(caminhoArquivoMapa);
        extracaoZ::Comando* comandos = decodificador->decodificarComandos(caminhoArquivoComandos);

        std::cout << decodificador->getQuantidadeComandos() << std::endl;
        std::cout << comandos[0].getAcao() << ", " << comandos[0].getIndiceRobo() << std::endl;
    } catch (char const* excecao){
        std::cout << excecao << std::endl;
        return 0;
    }

    //extracaoZ::FilaOrdensComando* fila = new extracaoZ::FilaOrdensComando();
    //extracaoZ::OrdemComando* ordem = new extracaoZ::OrdemComando();
    //fila->enfileirarOrdemComando(ordem);
}