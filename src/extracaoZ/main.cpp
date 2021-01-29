#include <iostream>

#include "estruturas/lista.h"
#include "estruturas/listaRobos.h"
#include "estruturas/nodo.h"

#include "planeta/robo.h"

using namespace extracaoZ;

int main(int argc, char* argv[]) {
    std::cout << "Hello world";
    ListaRobos lista = ListaRobos();
    lista.inserirItemPrimeiraPosicao(Robo());
}