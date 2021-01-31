#include <cstdlib>
#include <iostream>

#include "fluxoExtracao/explorador.h"

int main(int argc, char* argv[]) {
    std::system("clear");

    if (argc < 3) {
        std::cout << "Número de parâmetros insuficiente!" << std::endl;
        std::cout << "Devem ser informados os caminhos do arquivo de mapa e do arquvo de comandos." << std::endl;
        return 1;
    }

    std::string caminhoArquivoMapa = argv[1];
    std::string caminhoArquivoComandos = argv[2];

    try {
        extracaoZ::Explorador* explorador = new extracaoZ::Explorador();
        explorador->iniciarExtracaoZ(caminhoArquivoMapa, caminhoArquivoComandos);
    } catch (char const* excecao){
        std::cout << excecao << std::endl;
        return 0;
    }
}