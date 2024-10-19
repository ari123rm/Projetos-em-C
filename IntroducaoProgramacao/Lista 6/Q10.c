#include <stdio.h>
//questao 10
#define DIRETO 7
#define EXAME 5
#define REPROVADO 3
const int PESOS[5] = {1,1,1,1,1};

int situacao(float notas[3],float exame){
  int i,somaN,somaP;
  somaN = somaP = 0;
  for(i=0;i<3;i++){
    somaN += notas[i]*PESOS[i];
    somaP += PESOS[i];
  }
  float media = somaN/somaP;
  if(media>= DIRETO){
    return 3;
  }else{
    if(media>=REPROVADO&& exame!=-1 ){
      int mediaF = (media + exame)/(PESOS[3]+PESOS[4]);
      if(mediaF >= EXAME){
        return 2;
      }else{
        return 1;
      }
    }else{
      return 0;
    }
  }
}
int main(void){
  float notas[3],exame;
  int i;
  for(i=0;i<3;i++){
    printf("Digite a %d nota: ",i+1);
    scanf("%f", &notas[i]);
  }
    printf("Digite a nota do exame(-1 para caso nao tenha feito): ");
    scanf("%f", &exame);
    printf("\n");

    switch(situacao(notas,exame)){
      case 0:
        printf("REPROVADO DIRETO");
        break;
      case 1:
        printf("REPROVADO EM EXAME");
        break;
      case 2:
        printf("APROVADO EM EXAME");
        break;
      case 3:
        printf("APROVADO DIRETO");
        break; 
    }
  return 0;
}