#include <stdio.h>

int main(void) {
  int i,numero,soma=0;
  printf("Digite o numero : ");
  scanf("%d", &numero);
  if(numero < 500){
  for(i=0;i<=numero;i++){
    soma = soma + i;
  }
     printf("O somatorio deu %d", soma);
  }else{
    printf("Numero invalido!");
  }
 
  return 0;
}