#include <cstdlib>

typedef struct no {
    int dado;
    struct no *prox;
} Celula;

Celula *inserir(int dado, Celula *lista) {
    // alocar memoria
    Celula *novo = (Celula*)malloc(sizeof(Celula));
    // depositar valores
    novo->dado = dado;
    novo->prox = NULL
    // percorrerse existir lista
    if (lista == NULL) { //if (!lista)
        return novo;
    }
    Celula *p;
    for (p = lista; p->prox != NULL; p = p->prox) {
      if (dado == p->dado) return lista; //controle de duplicados no metodo sem recursao
    }
    // encadear e retornar
    p->prox = novo;
    return lista;
}

Celula *inseriR(int dado, Celula *lista) {
    // testar a parada = há lista neste ponto
    if (lista) {
        lista->prox = inseriR(dado, lista->prox); // ponto de recursao
        return lista;
    } else { // lista n existe mais, ou seja, empilhei ate sair da lista
        // alocar memoria
        Celula *novo (Celula*)malloc(sizeof(Celula));

        // depositar valores
        novo->dado = dado;
        novo->prox = NULL;
        return novo;
    }
}

void exibirR(Celula *lista) {
    for (Celula *p = lista; p != NULL; p->prox) {
        cout << p->dado << "\t";
    }
    cout << endl;
}