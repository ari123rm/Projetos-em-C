#include <stdio.h>

int main(void){
  int i,numero,fatorial=1;
  printf("Digite o numero que deseja o fatorial: ");
  scanf("%d", &numero);
  for(i=1;i<=numero;i++){
    fatorial = fatorial *i;
  }
  printf("%d! = %d",numero,fatorial);
  
  
  return 0;
}