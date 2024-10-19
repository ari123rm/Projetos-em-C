#include <stdio.h>
#include <math.h>

int main(void){
  int i,numero;
  printf("Que numero deseja saber as potencias: ");
  scanf("%d", &numero);
  for(i=0;i<=9;i++){
    printf("%d^%d = %.lf\n",numero,i,pow(numero,i));
  }
  return 0;
}