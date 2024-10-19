#include <stdio.h>
//questao 2
int pesquisa(int P,int vetor[7]){
  int i,retorno = -1;
  for(i=0;i<7;i++){
    if(vetor[i] == P){
      retorno = i;
      break;
    }
  }
  return retorno;
}

int main(void){
  int vetor[7],i,j;
  for(i=0;i<7;i++){
    printf("Digite o %d numero do vetor: ", i+1);
    scanf("%d",&vetor[i]);
  }
  printf("\nA:\n");
  for(i=0;i<7;i++){
    printf("vetor[%d] = %d\n",i, vetor[i]);
  }
  printf("\nB:\n");
  int P;
  printf("Digite o numero de pesquisa: ");
  scanf("%d", &P);
  printf("%d\n", pesquisa(P, vetor));
  printf("\nC:\n");
  int vetorAux[7],soma;
  for(i=0;i<7;i++){
    soma = 0;
    for(j=0;j<=i;j++){
      soma = vetor[j] +soma; 
    }
    vetorAux[i]= soma;
    printf(" %d ", vetorAux[i]);
  }
  return 0;
}