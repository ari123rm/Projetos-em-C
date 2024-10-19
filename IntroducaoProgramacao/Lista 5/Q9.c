#include <stdio.h>

int main(void){
  int numero,i;
  printf("Digite o numero: ");
  scanf("%d", &numero);
  for(i=0;i<=numero;i=i+2){
    printf("%d\n",i);
  }
  return 0;
}