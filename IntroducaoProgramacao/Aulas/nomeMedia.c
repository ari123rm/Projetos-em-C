#include <stdio.h>
#include <string.h>

int main(void) {
  struct ficha {
    char nome[20];
    float notas[4];
    float soma;
    float media;
  };
  struct ficha aluno[8];
  char aux[20];
  for (int k = 0; k < 8; k++) {
    aluno[k].soma = 0;
    printf("Digite seu nome: ");
    scanf("%s", aluno[k].nome);
    for (int i = 0; i < 4; i++) {
      printf("Digite a %d nota: ", i + 1);
      scanf("%f", &aluno[k].notas[i]);
      aluno[k].soma += aluno[k].notas[i];
    }
    aluno[k].media = aluno[k].soma / 4;
    for(int i=0;i<10;i++){
    for(int j=0;j<i;j++){
        if(strcmp(aluno[i].nome,aluno[j].nome)<0){
          strcpy(aux, aluno[i].nome);
          strcpy(aluno[i].nome, aluno[j].nome);
          strcpy(aluno[j].nome, aux);
        }
      }
    }
  }
  for(int k=0;k<8;k++){
    printf("Ola %s, sua media foi de %.1f\n\n", aluno[k].nome, aluno[k].media);
  }
  return 0;
}