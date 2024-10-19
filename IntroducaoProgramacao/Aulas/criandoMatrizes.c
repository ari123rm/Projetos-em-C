#include <stdio.h>

int main(void) {
  int matriz[3][3],i,j;
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      printf("Digite o valor(%d,%d): ",i,j);
      scanf("%d",&matriz[i][j]);
    }  
  }
  printf("\nMatriz A: \n\n");
  for(i=0;i<3;i++){
    printf("| ");
    for(j=0;j<3;j++){
        printf("%d ", matriz[i][j]);
    }
    printf(" |\n");
  }
  printf("\nMatriz B: \n\n");
  for(i=0;i<3;i++){
    printf("| ");
    for(j=0;j<3;j++){
      if(i==j){
        printf("%d ", matriz[i][j]*2);
      }else{
        printf("%d ", matriz[i][j]*3);
      }
    }
    printf(" |\n");
  }
  return 0;
}