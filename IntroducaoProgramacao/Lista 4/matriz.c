#include <stdio.h>

int main(void){
  int linhas, colunas;
  int l,c;
  char caract;
  printf("Quantas colunas sua matriz tera: ");
  scanf("%d", &linhas);
  printf("Quantas linhas sua matriz tera: ");
  scanf("%d", &colunas);
  printf("Qual caractere sua matriz tera: ");
  scanf(" %c", &caract);
  for(c=0;c<colunas;c++){
      for(l=0;l<linhas;l++){
        printf("%c", caract);
      }
      printf("\n");
    
  }


  return 0;
}