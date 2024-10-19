#include <stdio.h>

int main(void){
  int x,y,i,N=1;
  printf("Digite o valor de X: ");
  scanf("%d", &x);
  printf("Digite o valor de Y: ");
  scanf("%d", &y);
  for(i=1;i<=y;i++){
    N = N * x;
  }
  printf("x^y = %d", N);  
  return 0;
}