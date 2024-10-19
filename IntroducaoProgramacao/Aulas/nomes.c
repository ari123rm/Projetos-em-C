#include <stdio.h>
#include <string.h>

int main(void){
  char nomes[10][40],aux[40];
  int i,j;
  for(i=0;i<10;i++){
    printf("Digite o %d nome: ",i+1);
    fgets(nomes[i],40,stdin);
    nomes[i][strlen(nomes[i])-1] =  '\0';
  }
  for(i=0;i<10;i++){
    for(j=0;j<i;j++){
        if(strcmp(nomes[i],nomes[j])<0){
          strcpy(aux, nomes[i]);
          strcpy(nomes[i], nomes[j]);
          strcpy(nomes[j], aux);
      }
    }
  }
  for(i=0;i<10;i++){
    printf("\n%s",nomes[i]);
  }
  char pesquisa[40];
  printf("\nDigite um nome: ");
  fgets(pesquisa,40,stdin);
  pesquisa[strlen(pesquisa)-1] = '\0';
  j=0;
  for(i=0;i<10;i++){
    if(strcmp(nomes[i],pesquisa)==0){
      printf("\nNome %s esta presente na lista na posição %d!", pesquisa,i);
      j=1;
      break;
    }
  }
  if(j==0)
    printf("\nNome %s nao presente na lista",pesquisa);
  return 0;
}