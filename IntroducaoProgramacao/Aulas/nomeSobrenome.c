#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
  char nome[20],sobrenome[20];
  
  printf("Insira seu nome: ");
  fgets(nome,20,stdin);
  printf("Insira seu sobrenome: ");
  fgets(sobrenome,20,stdin);
  nome[strlen(nome)-1] = '\0';
  sobrenome[strlen(sobrenome)-1] = '\0';
  printf("tamanho do nome: %d\ntamanho do sobrenome: %d\n\n",strlen(nome),strlen(sobrenome));
  printf("Bem vindo, %s %s",nome, sobrenome);
  
  return 0;
}