#include <stdio.h>

int main(void){
  int idade,quantidade,menor,maior;
  float soma;
  soma=quantidade=0;
  do{
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    switch(idade){
      case 0:
        break;
      default:
        quantidade++;
        soma = soma + idade;
        if(idade > maior||quantidade == 1){
          maior = idade;
        }
        if(idade < menor||quantidade == 1){
          menor = idade;
        }
      break;
    }
  }while(idade != 0);
  printf("\n\nNumero total de pessoas entrevistadas: %d\n", quantidade);
  printf("Media das idades: %.1f\n",soma/quantidade);
  printf("A menor idade foi: %d\nA maior idade foi: %d\n",menor,maior);

  return 0;
}