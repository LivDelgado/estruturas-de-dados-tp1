#include <iostream>

#include "estruturas/listaRobos.h"
#include "planeta/robo.h"

using namespace extracaoZ;

int main(int argc, char* argv[]) {
    std::cout << "Hello world";
    ListaRobos* lista = new ListaRobos();
    lista->imprimirLista();
    /*
    Robo* robo = new Robo(0);
    std::cout << "indice " << robo->obterIndice();
    lista->inserirItemPrimeiraPosicao(*robo);
    */
}