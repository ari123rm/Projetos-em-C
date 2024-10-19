#include <stdio.h>
#define TAM 7

struct pilha{
  int capacidade;
  int *vetor;
  int fim;
};
typedef struct pilha Pilha;

void iniciar(Pilha *pilha,int cap){
  pilha->capacidade = cap;
  pilha->fim = -1;
  pilha->vetor = malloc(cap*sizeof(int));
}

void add(Pilha *pilha) {
  if(pilha->fim == -1){
    iniciar(pilha, TAM);
  }
  if (pilha->fim < pilha->capacidade - 1) {
    (pilha->fim)++;
    printf("Valor a ser inserido: ");
    scanf("%d", pilha->vetor + pilha->fim);
    printf("\n\n");
  } else {
    printf("VALOR MAX ALCANCADO\n\n");
  }
}
void peek(Pilha *pilha) { 
  if(pilha->fim > -1)
    printf("Valor PEEKADO: %d\n\n", *(pilha->vetor + pilha->fim)); 
}
int remover(Pilha *pilha) {
  int *i = malloc(sizeof(int));
  int *retorno = malloc(sizeof(int));
  *retorno = *(pilha->vetor + pilha->fim);
  if(pilha->fim == -1){
    free(pilha->vetor);
    return -1;
  }else{
   
    (pilha->fim)--;
    free(i);
    return 0;
  }
  free(retorno);
}
void listar(Pilha *pilha) {
  int *i = malloc(sizeof(int));
  printf("\nLISTA : [");
  for ((*i) = 0; *i <= pilha->fim; (*i)++) {
    printf(" %d ", *(pilha->vetor + *i));
  }
  printf("]\n\n");
  free(i);
}
int main(void) {
  Pilha pilha;
  iniciar(&pilha,TAM);
  int resultado;
  do {
    printf("PILHA COM VETOR :D\n\n");
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
      remover(&pilha) != -1 ? printf("\nValor Removido\n\n")  : printf("Pilha Vazia\n\n");
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
  while (pilha.fim != -1){
    remover(&pilha);
  }
  printf("\nFIM DO PROGRAMA\n");
  return 0;
}