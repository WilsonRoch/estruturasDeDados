#include <cstdlib>
using namespace std;
 
typedef struct no {
    int dado;
    struct no *prox;
} Celula;
 
Celula *inserir(int dado, Celula *lista) {
    //alocar memoria
    Celula *novo = (Celula*)malloc(sizeof(Celula));
   
    //depositar valores
    novo->dado = dado;
    novo->prox = NULL;
 
    //percorrer se existir lista
    if (lista == NULL) { //if (!lista)
        return novo;
    }
    Celula *p;
    for (p = lista; p->prox != NULL; p = p->prox) {
        if (dado == p->dado) return lista; //controle de duplicados no método sem recursão
    }
 
    //encadear e retornar
    p->prox = novo;
    return lista;
}
 
Celula *inserirR(int dado, Celula *lista) {
    //testar a parada = há lista neste ponto
    if (lista && dado > lista->dado) {
        if (dado == lista->dado){
            return lista; //começa o desempilhamento sem a inserção
        }
        lista->prox = inserirR(dado, lista->prox); //ponto de recursão
        return lista;
    } else { //lista não existe mais, ou seja, empilhei até sair da lista
        //alocar memoria
        Celula *novo = (Celula*)malloc(sizeof(Celula));
   
        //depositar valores
        novo->dado = dado;
 
        if (lista && dado < lista->dado) {
            novo->prox = lista;
        }
        else {
            novo->prox = NULL;
        }
        return novo;
    }
}
 
void exibir(Celula *lista) {
    for (Celula *p = lista; p != NULL; p = p->prox) {
        cout << p->dado << "\n";
    }
    cout << endl;
}
 
void exibirR(Celula *lista) {
    if (lista) {
        cout << lista->dado << "\n";
        exibirR(lista->prox);        
    }
}

int contarR(Celula *lista) {
  if(lista) {
    return 1 + contarR(lista->prox);
  }
  return 0;
}

bool estaContidoR(int numero, Celula *lista) {
  // verifica se a lista existe
  if (lista) {
    if (numero == lista->dado) {
      return 1; //começa o desempilhamento sem a inserção
    } else {
      return estaContidoR(numero, lista->prox);
    }
  }
  return 0; // empilhou ate o final da lista e nao encontrou  numero, desempilha com 0
}

int maxR(Celula *lista) {
  if (lista) {
    if (lista->prox) {
      return maxR(lista->prox);
    }
  }
  return lista->dado; // emiplha até a ultima posicao onde está o maior elemento da lista
}

int minR(Celula *lista) {
  if (lista) {
    return lista->dado; // pq esta ordenado
  }
  return -27; // lista vazia
}

Celula *removerR(int numero, Celula *lista) {
  if (lista) {
    // localiza numero e remove
    if (numero == lista->dado) {
      Celula *proximo = lista->prox;
      free(lista);
      return proximo;
    } else {
      lista -> prox = removerR(numero, lista->prox);
      return lista; 
    }
  }
  return NULL; // chegou ao final do empilhamento e nao encontrou o numero para remover
}