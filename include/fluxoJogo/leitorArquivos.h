#include <string>

#ifndef LEITOR
#define LEITOR

namespace extracaoZ {
    class LeitorArquivos {
        private:

        public:
            LeitorArquivos();
            ~LeitorArquivos();

            std::string* lerArquivo(std::string caminhoArquivo);
    };
}


#endif
