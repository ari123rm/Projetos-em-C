#include <stdio.h>
int maiorNumero(int n[5]){
  int i,j,aux;
  for(i=0;i<5;i++){
    for(j=0;j<i;j++){
      if(n[i]<n[j]){
        aux = n[i];
        n[i] = n[j];
        n[j] = aux;
      }
    }
  }
  return n[4];
}
int main(void){
  int numeros[5],i;
  for(i=0;i<5;i++){
    printf("Digite o %d numero: ", i+1);
    scanf("%d", &numeros[i]);
  }
  printf("O maior numero eh %d", maiorNumero(numeros));
  return 0;
}