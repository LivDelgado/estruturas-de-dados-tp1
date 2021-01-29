#include <iostream>

#include "estruturas/lista.h"
#include "estruturas/listaRobos.h"
#include "estruturas/nodo.h"

#include "planeta/robo.h"

using namespace std;
using namespace extracaoZ;

int main(int argc, char* argv[]) {
    system("clear");

    cout << "Hello world";
    ListaRobos* lista = new ListaRobos();
    lista->inserirItemPrimeiraPosicao(Robo());
}