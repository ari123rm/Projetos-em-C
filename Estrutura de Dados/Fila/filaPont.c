#include <stdio.h>


struct no {
  char nome[256];
  int idade;
  struct no *prox;
};
typedef struct no No;

void iniciar(No **fila) { 
  *fila = NULL; 
}

void add(No **fila) {
  No *aux, *novo = malloc(sizeof(No));
  printf("Digite o nome: ");
  scanf("%s", novo->nome);
  printf("Digite a idade: ");
  scanf("%d", &novo->idade);
  novo->prox = NULL;
  if (*fila != NULL) {
    aux = *fila;
    while (aux->prox != NULL) {
      aux = aux->prox;
    }
    aux->prox = novo;
  } else {
    *fila = novo;
  }
}
void peek(No **fila) {
  if (*fila != NULL) {
    printf("\nPEEKADO\n");
    printf("Nome: %s\n", (*fila)->nome);
    printf("Idade: %d\n", (*fila)->idade);
  } else {
    printf("Fila vazia\n");
  }
}
void remover(No **fila) {
  if (*fila != NULL) {
    No *aux = *fila;
    *fila = aux->prox;
    free(aux);
  } else {
    printf("Fila Vazia\n");
  }
}
void listar(No **fila) {
  if (*fila != NULL) {
    No *aux = *fila;
    while (aux != NULL) {
      printf("\n");
      printf("Nome: %s\n", aux->nome);
      printf("Idade: %d\n", aux->idade);
      printf("\n");
      aux = aux->prox;
    }

  } else {
    printf("Fila vazia\n");
  }
}
int main(void) {
  No *fila;
  iniciar(&fila);
  int resultado;
  do {
    printf("\nFILA COM PONTEIRO :D\n\n");
    printf("ESCOLHAS:\n 1-ADD\n 2-PEEK\n 3-REMOVER\n 4-LISTAR\n "
           "9-SAIR\n\nDIGITE: ");
    scanf("%d", &resultado);
    switch (resultado) {
    case 1:
      add(&fila);
      break;
    case 2:
      peek(&fila);
      break;
    case 3:
      remover(&fila);
      break;
    case 4:
      listar(&fila);
      break;
    case 9:
      resultado = -1;
      break;
    default:
      printf("Resultado INVALIDO\n\n");
      break;
    }
  } while (resultado != -1);
  while(fila != NULL){
    remover(&fila);
  }
  printf("\nFIM DO PROGRAMA\n");
  return 0;
}