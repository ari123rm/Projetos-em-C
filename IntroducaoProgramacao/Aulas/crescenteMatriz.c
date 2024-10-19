#include <stdio.h>

int main(void){
  int vetor[5],i,j,aux;
  for(i=0;i<5;i++){
    printf("Digite o %d valor: ",i+1);
    scanf("%d", &vetor[i]);
  }
  for(i=0;i<5;i++){
    for(j=0;j<i;j++){
      if(vetor[j]>vetor[i]){
        aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
      }
    }
  }
  printf("\nLista organizada: ");
  for(i=0;i<5;i++){
    printf(" %d", vetor[i]);
  }
  return 0;
}