#include <stdio.h>
// questao 3
int main(void) {
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
  printf("\n");
  for(l=0;l<linhasA;l++){
    for(c=0;c<colunasA;c++){
      printf("Digite o valor da matriz A(%d,%d): ",l,c);
      scanf("%d",&A[l][c]);
    }  
  }
  printf("\n");
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
  printf("\nA:\n\n");
  printf("Matriz soma: \n\n");
  if(linhasA == linhasB && colunasA == colunasB){
    int C[linhasA][colunasA];
    for(l=0;l<linhasB;l++){
      printf("| ");
      for(c=0;c<colunasB;c++){
        C[l][c] = A[l][c] + B[l][c];
        printf("%d ",C[l][c]);
      }  
      printf(" |\n");
    }
  }else{
    printf("Nao eh possivel somar\n");
  }
  int somaDiag = 0,i;
  printf("\nB:\n");
  printf("\nsoma das diagonais Matriz A:");
  if(linhasA == colunasA){
    for(i=0;i<linhasA;i++){
      somaDiag = A[i][i] + somaDiag;
    }
    printf("\nDiagonal principal: %d", somaDiag);
    somaDiag=0;
    for(i=0;i<linhasA;i++){
      somaDiag = A[linhasA-(i + 1)][i] + somaDiag;
    }
    printf("\nDiagonal secundaria: %d", somaDiag);
  }else{
    printf("\nNao foi possivel somar as diagonais");
  }
  somaDiag = 0;
  printf("\n\nsoma das diagonais Matriz B:");
  if(linhasB == colunasB){
    for(i=0;i<linhasB;i++){
      somaDiag = B[i][i] + somaDiag;
    }
    printf("\nDiagonal principal: %d", somaDiag);
    somaDiag=0;
    for(i=0;i<linhasB;i++){
      somaDiag = B[linhasB-(i + 1)][i] + somaDiag;
    }
    printf("\nDiagonal secundaria: %d\n", somaDiag);
  }else{
    printf("\nNao foi possivel somar as diagonais\n");
  }
  printf("\nC:\n");
  if(colunasA == linhasB){
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
    printf("Nao foi possivel multiplicar as raizes");
  }
  
  return 0;
}