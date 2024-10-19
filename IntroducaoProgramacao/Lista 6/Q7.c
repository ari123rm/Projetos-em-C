#include <stdio.h>
#include <string.h>
//questao 7
int main(void){
  int n = 20;
  int idade[n],i,j,k,aux;
  char avaliacao[5][10] = {"pessimo","ruim","regular","bom","otimo"};
  char nota[n][10];
  for(i=0;i<n;i++){
    printf("\nDigite a %d idade: ",i+1);
    scanf("%d", &idade[i]);
    printf("Digite a %d nota (pessimo, ruim, regular, bom, otimo):\n",i+1);
    scanf("%s", nota[i]);
  }
  int quantidade[5],categorificadoIdade[5][n];
  float porcentagemNota[5];
  
  for(i=0;i<5;i++){
    quantidade[i]=porcentagemNota[i]=0;
  }
  
  for(i=0;i<n;i++){
    if(strcmp(avaliacao[0],nota[i]) == 0){
        quantidade[0]++;
        porcentagemNota[0] += 100/n;
        categorificadoIdade[0][quantidade[0]-1] = idade[i];
    }
    if(strcmp(avaliacao[1],nota[i]) == 0){
        quantidade[1]++;
        porcentagemNota[1] += 100/n;
        categorificadoIdade[1][quantidade[1]-1] = idade[i];
    }
    if(strcmp(avaliacao[2],nota[i]) == 0){
        quantidade[2]++;
        porcentagemNota[2] += 100/n;
        categorificadoIdade[2][quantidade[2]-1] = idade[i];
    }
    if(strcmp(avaliacao[3],nota[i]) == 0){
        quantidade[3]++;
        porcentagemNota[3] += 100/n;
        categorificadoIdade[3][quantidade[3]-1] = idade[i];
    }
    if(strcmp(avaliacao[4],nota[i]) == 0){
        quantidade[4]++;
        porcentagemNota[4] += 100/n;
        categorificadoIdade[4][quantidade[4]-1] = idade[i];
    
    }
  }
  for(i=0;i<5;i++){
    for(j=0;j<quantidade[i];j++){
      for(k=0;k<j;k++){
        if(categorificadoIdade[i][k]>categorificadoIdade[i][j]){
          aux = categorificadoIdade[i][k];
          categorificadoIdade[i][k] = categorificadoIdade[i][j];
          categorificadoIdade[i][j] = aux;
        }
      }
    }
  }
  printf("\nA:\n");
  printf("\nTiveram %d notas otimo\n", quantidade[4]);
  printf("\nB:\n");
  printf("\nTiveram %.f%% de diferença entre pessoas que votaram bom e regular\n",porcentagemNota[3]-porcentagemNota[2]);
  printf("\nC:\n");
  float soma=0;
  for(i=0;i<quantidade[1];i++){
      soma = categorificadoIdade[1][i] + soma;
  }
  if(quantidade[1]==0){
    printf("\nNao tiveram nota ruim\n");
  }else{
  printf("\nA media da idade das pessoas que votaram ruim foi %.1f\n",soma/quantidade[1]);
  }
  printf("\nD:\n");
  printf("\nA porcentagem de pessoas que votaram pessimo: %.f%%",porcentagemNota[0]);
  printf("\nA maior idade que utilizou essa nota foi %d\n", categorificadoIdade[0][quantidade[0]-1]);
  printf("\nE:\n");
  printf("\nA diferenca de idade entre a maior otima e maior ruim eh: %d\n", categorificadoIdade[4][quantidade[4]-1]-categorificadoIdade[1][quantidade[1]-1]);


  return 0;
}