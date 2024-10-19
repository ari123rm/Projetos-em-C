#include <stdio.h>

int main(void){
  int idade, soma,contador;
  soma = contador = 0;
  float media;
  char saida;
  do{
  do{
      printf("Digite a idade: ");
      scanf("%d", &idade);
      switch(idade){
        case 0:
          contador--;
          break;
        default:
          soma = soma + idade;
          break;
      }
      contador++;
  }while(idade != 0);
  media = soma / contador;
  printf("A media das idade deu %.2f", media);
  printf("\n");
  printf("Deseja continuar? (C para continuar e S para sair)\n");
  scanf(" %c", &saida);
  }while(saida != 'S');
return 0;
}