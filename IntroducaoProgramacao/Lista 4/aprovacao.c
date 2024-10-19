#include <stdio.h>

#define APROVADO 7

int main(void){
  int contador;
  float nota,soma;
  char continuar;
  soma = contador = 0;
  do{
      
      printf("Digite sua nota: ");
      scanf("%f", &nota);
    if(nota<=10 && nota>=0){
      soma = soma +nota;
      contador++;
      if(soma/contador>=APROVADO && contador%10 == 0){
        printf("Aprovado");
        printf("\n");
        printf("Deseja continuar? (C para continuar e S para sair)\n");
        scanf(" %c", &continuar);
      }else{if(contador%10 == 0){
        printf("Reprovado");
        printf("\n");
        printf("Deseja continuar? (C para continuar e S para sair)\n");
        scanf(" %c", &continuar);
      }
      }
    }else{
      printf("Nota invalida!\n");
    }
      
    
  }while(continuar != 'S');
  
  
return 0;
}