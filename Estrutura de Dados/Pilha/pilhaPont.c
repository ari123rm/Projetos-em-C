#include <stdio.h>

struct no {
  char nome[256];
  int idade;
  struct no *prox;
};
typedef struct no No;

void iniciar(No **pilha) { *pilha = NULL; }

void add(No **pilha) {
  if(!*pilha){
    iniciar(pilha);
  }
  No *aux, *novo = malloc(sizeof(No));
  printf("Digite o nome: ");
  scanf("%s", novo->nome);
  printf("Digite a idade: ");
  scanf("%d", &novo->idade);
  novo->prox = NULL;
  if (*pilha != NULL) {
    aux = *pilha;
    while (aux->prox != NULL) {
      aux = aux->prox;
    }
    aux->prox = novo;
  } else {
    *pilha = novo;
  }
}
void peek(No **pilha) {
  No *aux = *pilha ;
  if (*pilha != NULL) {
    while(aux->prox != NULL){
      aux = aux->prox;
    }
    printf("\nPEEKADO\n");
    printf("Nome: %s\n", (aux)->nome);
    printf("Idade: %d\n", (aux)->idade);
  } else {
    printf("pilha vazia\n");
  }
}
void remover(No **pilha) {
  if (*pilha != NULL) {
    No *aux ;
    aux= *pilha;
    if(aux->prox == NULL){
      free(*pilha);
    }else{
      while(aux->prox->prox != NULL){
        aux = aux->prox;
      }
      free(aux->prox->prox);
    }
    
    aux->prox = NULL;
  } else {
    free(*pilha);
    printf("pilha Vazia\n");
  }
}
void listar(No **pilha) {
  if (*pilha != NULL) {
    No *aux = *pilha;
    while (aux != NULL) {
      printf("\n");
      printf("Nome: %s\n", aux->nome);
      printf("Idade: %d\n", aux->idade);
      printf("\n");
      aux = aux->prox;
    }

  } else {
    printf("pilha vazia\n");
  }
}
int main(void) {
  No *pilha;
  iniciar(&pilha);
  int resultado;
  do {
    printf("\nPILHA COM PONTEIRO :D\n\n");
    printf("ESCOLHAS:\n 1-ADD\n 2-PEEK\n 3-REMOVER\n 4-LISTAR\n "
           "9-SAIR\n\nDIGITE: ");
    scanf("%d", &resultado);
    switch (resultado) {
    case 1:
      add(&pilha);
      break;
    case 2:
      peek(&pilha);
      break;
    case 3:
      remover(&pilha);
      break;
    case 4:
      listar(&pilha);
      break;
    case 9:
      resultado = -1;
      break;
    default:
      printf("Resultado INVALIDO\n\n");
      break;
    }
  } while (resultado != -1);
  while (pilha != NULL) {
    remover(&pilha);
  }
  printf("\nFIM DO PROGRAMA\n");
  return 0;
}