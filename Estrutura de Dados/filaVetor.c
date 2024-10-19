#include <stdio.h>
#define TAM 7

struct fila{
  int vetor[TAM];
  int fim;
};
typedef struct fila Fila;

void iniciar(Fila *fila){
  fila->fim = -1;
}

void add(Fila *fila) {
  if (fila->fim < TAM - 1) {
    (fila->fim)++;
    printf("Valor a ser inserido: ");
    scanf("%d", &(fila->vetor[fila->fim]));
    printf("\n\n");
  } else {
    printf("VALOR MAX ALCANCADO\n\n");
  }
}
void peek(Fila *fila) { printf("Valor PEEKADO: %d\n\n", (fila->vetor[0])); }
int remover(Fila *fila) {
  int *i = malloc(sizeof(int));
  int *retorno = malloc(sizeof(int));
  *retorno = fila->vetor[0];
  for ((*i) = 0; *i < fila->fim; (*i)++) {
    fila->vetor[*i] = fila->vetor[*i + 1];
  }
  (fila->fim)--;
  free(i);
  return *retorno;
  free(retorno);
}
void listar(Fila *fila) {
  int *i = malloc(sizeof(int));
  printf("\nLISTA : [");
  for ((*i) = 0; *i <= fila->fim; (*i)++) {
    printf(" %d ", fila->vetor[*i]);
  }
  printf("]\n\n");
  free(i);
}
int main(void) {
  Fila fila;
  iniciar(&fila);
  int resultado;
  do {
    printf("FILA COM VETOR :D\n\n");
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
      printf("Valor REMOVIDO: %d\n\n", remover(&fila));
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
  printf("\nFIM DO PROGRAMA\n");
  return 0;
}