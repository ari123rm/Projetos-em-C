#include <stdio.h>

int main(void){
  int l,c,n;
  char caract;
  printf("Numero de linhas: ");
  scanf("%d",&n);
  printf("Caractere: ");
  scanf(" %c",&caract);
  
  for(l=1;l<=n;l++){
    for(c=0;c<2*l;c++){
      printf("%c", caract);
    }
    printf("\n");
  }
  
  return 0;
}