#include "fluxoJogo/decodificadorComandos.h"
#include "fluxoJogo/ordemComando.h"
#include "fluxoJogo/comando.h"
#include "planeta/planeta.h"

#include <string>

#ifndef EXEC_COMANDO
#define EXEC_COMANDO

namespace extracaoZ {
    class ExecutorComandos {
        private:
            DecodificadorComandos* decodificador;
            Planeta* planeta;

            void executarComandos(Comando* comandos);
            void executarComando(Comando* comando);

            void executarOrdemDireta(Comando* comando);
            void executarOrdemComando(Comando* comando);
            
            void ativarRobo(Comando* comando);
            void imprimirRelatorioRobo(Comando* comando);
            void retornarRoboParaBase(Comando* comando);

            void verificarExecutarListaComandosRobo(Comando* comando);
            void executarListaComandosRobo(Comando* comando);

            OrdemComando* converterComandoEmOrdem(Comando* comando);
            
            void executarOrdemComando(OrdemComando* ordem, int indiceRobo);
            
            void moverRobo(OrdemComando* comando, Robo* robo);
            void roboColetarRecurso(OrdemComando* comando, Robo* robo);
            void roboEliminarAlien(OrdemComando* comando, Robo* robo);

        public:
            ExecutorComandos(Planeta* planeta);
            ~ExecutorComandos();

            void executarComandos(std::string caminhoArquivo);
    };
}

#include "planeta/planeta.h"

#endif
