#include <stdio.h>

int main(void){
  int i,tabuada,numero;
  printf("Numero que deseja a tabuada: ");
  scanf("%d", &numero);
  for(i=1;i<=10;i++){
    tabuada = numero * i;
    printf("%d x %d = %d\n",i,numero,tabuada);
  }
  return 0;
}