#include <stdio.h>
int main(void){
  int linhasA,colunasA,l,c,linhasB,colunasB;
    printf("Digite a quantidade de linhas da matriz A: ");
    scanf("%d",&linhasA);
    printf("Digite a quantidade de colunas da matriz A: ");
    scanf("%d",&colunasA);
    printf("Digite a quantidade de linhas da matriz B: ");
    scanf("%d",&linhasB);
    printf("Digite a quantidade de colunas da matriz B: ");
    scanf("%d",&colunasB);
  int A[linhasA][colunasA], B[linhasB][colunasB];
if(colunasA == linhasB){
  for(l=0;l<linhasA;l++){
    for(c=0;c<colunasA;c++){
      printf("Digite o valor da matriz A(%d,%d): ",l,c);
      scanf("%d",&A[l][c]);
    }  
  }
  for(l=0;l<linhasB;l++){
    for(c=0;c<colunasB;c++){
      printf("Digite o valor da matriz B(%d,%d): ",l,c);
      scanf("%d",&B[l][c]);
    }  
  }
  printf("\nMatriz A: \n\n");
  for(l=0;l<linhasA;l++){
    printf("| ");
    for(c=0;c<colunasA;c++){
        printf("%d ", A[l][c]);
    }
    printf(" |\n");
  }
  printf("\nMatriz B: \n\n");
  for(l=0;l<linhasB;l++){
    printf("| ");
    for(c=0;c<colunasB;c++){
      printf("%d ", B[l][c]);
    }
    printf(" |\n");
  }
  printf("\n");
  int multiplicado[linhasA][colunasB],i,mult=0;
  for(l=0;l<linhasA;l++){
    for(c=0;c<colunasB;c++){
      for(i=0;i<linhasA;i++){
        mult = A[l][i] * B[i][c] + mult; 
      }
      multiplicado[l][c] = mult;
      mult = 0;
    }
  }
  printf("\nMatriz multiplicada: \n\n");
  for(l=0;l<linhasA;l++){
    printf("| ");
    for(c=0;c<colunasB;c++){
        printf("%d ", multiplicado[l][c]);
    }
    printf(" |\n");
  }
  
}else{
  printf("Multiplicacao impossivel");
}
    
  
  return 0;
}