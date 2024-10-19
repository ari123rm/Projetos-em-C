#include <stdio.h>
//questao 8
int main(void){
  int matriz[5][5],l,c;
  for(l=0;l<5;l++){
    for(c=0;c<5;c++){
      printf("Digite o valor da matriz(%d,%d): ",l,c);
      scanf("%d",&matriz[l][c]);
    }  
  }
  printf("\nMatriz:\n\n");
  for(l=0;l<5;l++){
    printf("| ");
    for(c=0;c<5;c++){
        printf("%d ", matriz[l][c]);
    }
    printf(" |\n");
  }
  int matrizTrans[5][5];
  for(l=0;l<5;l++){
    for(c=0;c<5;c++){
      matrizTrans[l][c] = matriz[c][l];
    }
  }
  printf("\nMatriz Transposta:\n\n");
  for(l=0;l<5;l++){
    printf("| ");
    for(c=0;c<5;c++){
        printf("%d ", matrizTrans[l][c]);
    }
    printf(" |\n");
  }

  return 0;
}