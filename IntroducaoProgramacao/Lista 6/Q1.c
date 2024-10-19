#include <stdio.h>
//Questao 1
int main(void) {
  int numeros[] = {2, 4, 35, 50, 23, 17, 9, 12, 27, 5};
  int tam = sizeof(numeros)/sizeof(numeros[0]);
  int i,j,aux,soma=0;
  for(i=0;i<tam;i++){
    for(j=0;j<=i;j++){
      if(numeros[i]<numeros[j]){
        aux = numeros[i];
        numeros[i] = numeros[j];
        numeros[j] = aux;
      }
    }
  soma = numeros[i] + soma;
  }
  printf("A: %d\n",numeros[tam-1]);
  printf("B: %d\n",soma/tam);
  printf("C:");
  for(i=0;i<tam;i++){
      printf(" %d",numeros[i]);
  }
  printf("\n");
  int primos;
  printf("D:");
  for(i=0;i<tam;i++){
    for(j=2;j<numeros[i];j++){
      if(numeros[i] % j == 0 ){
        primos = 0;
      }
    }
  primos = (primos != 0)? printf(" %d", numeros[i]) : 1;
  }
  return 0;
}