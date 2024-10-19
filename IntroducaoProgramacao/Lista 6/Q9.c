#include <stdio.h>
//questao 9
int main(void){
  int linhasA,colunasA,l,c;
  printf("Digite a quantidade de linhas da matriz A: ");
  scanf("%d",&linhasA);
  printf("Digite a quantidade de colunas da matriz A: ");
  scanf("%d",&colunasA);
  printf("\n");
  int matriz[linhasA][colunasA];
  for(l=0;l<linhasA;l++){
    for(c=0;c<colunasA;c++){
      printf("Digite o valor da matriz A(%d,%d): ",l,c);
      scanf("%d",&matriz[l][c]);
    }  
  }
  int vetor[linhasA*colunasA];
  for(l=0;l<linhasA;l++){
    for(c=0;c<colunasA;c++){
        vetor[(l*colunasA)+c] = matriz[l][c];
    }
  }
  printf("\nMatriz unidimensional: ");
  for(l=0;l<linhasA*colunasA;l++){
    printf("%d ",vetor[l]);
  }
  
  return 0;
}