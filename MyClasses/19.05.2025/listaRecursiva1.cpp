#include <iostream>
#include "listas.h"

using_namespace std;

int main() {
    Celula * lista = NULL;

    lista = inseriR(10, lista);
    lista = inseriR(5, lista);
    lista = inseriR(7, lista);
    lista = inseriR(10, lista);

    exibiR(lista);

    return 1
}

