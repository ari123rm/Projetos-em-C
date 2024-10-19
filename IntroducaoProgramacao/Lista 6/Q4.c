#include <stdio.h>
// questao 4
int main(void){
  int n;
  printf("Digite o quantos valores tera o vetor: ");
  scanf("%d", &n);
  if(n <= 20){
    int vetor[n],i,aux;
    for(i=0;i<n;i++){
      printf("Digite o %d valor do vetor: ",i+1);
      scanf("%d",&vetor[i]);
    }
    for(i=1;i<n;i++){
      if(vetor[i]<vetor[i-1]){
        aux = vetor[i];
        vetor[i] = vetor[i-1];
        vetor[i-1] = aux;
      }
    }
    printf("Vetor no metodo bubble-sort: ");
    for(i=0;i<n;i++){
      printf(" %d", vetor[i]);
    }
  }else{
      printf("Vetor grande demais");
  }
  return 0;
}