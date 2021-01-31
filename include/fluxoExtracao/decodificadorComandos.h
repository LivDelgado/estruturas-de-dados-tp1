#ifndef DECOD_COMANDO
#define DECOD_COMANDO

#include "fluxoExtracao/leitorArquivos.h"
#include "fluxoExtracao/comando.h"

#include <string>


namespace extracaoZ {
    class DecodificadorComandos {
        private:
            LeitorArquivos* leitor;
            int quantidadeComandos;

            Comando* interpretarComando(std::string linhaComando);
            Comando* interpretarComandos(std::string* linhasComando);
            std::string* lerArquivo(std::string caminhoArquivo);

            void decodificarInstrucao(Comando &comando, std::string instrucao);
            void decodificarRobo(Comando &comando, std::string robo);
            void decodificarPosicao(Comando &comando, std::string posicao);

            Acao converterAcaoParaEnum(std::string instrucao);
            
        public:
            DecodificadorComandos();
            ~DecodificadorComandos();

            Comando* decodificarComandos(std::string caminhoArquivo);
            int getQuantidadeComandos();          
    };
}


#endif
