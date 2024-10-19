#include <stdio.h>

int main(void){
  int linha,coluna,lado;
  printf("Digite o lado do quadrado: ");
  scanf("%d", &lado);
  for(linha=0;linha<lado;linha++){
    for(coluna=0;coluna<lado;coluna++){
      printf("*");
    }
    printf("\n");
  }
  return 0;
}