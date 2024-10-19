/*
ALUNO:  ARIEL ROCHA DE MORAES
CURSO: ENGENHARIA DA COMPUTAÇÃO
CADEIRA: INTRODUÇÃO A PROGRAMAÇÃO
*/
#include <stdio.h>
#include <stdlib.h>

void verificador(float n1, float n2){
    if (n1 == n2){
        printf("Os dois pesos sao iguais");
    }
    if( n1 > n2){
      printf("O peso de %.2fkg eh maior que o peso de %.2fkg", n1, n2);
    }
    if( n1 < n2){
      printf("O peso de %.2fkg eh maior que o peso de %.2fkg", n2, n1);
    }
}
int main(void){
    float pesos[2];
    int i;
    for(i=0;i< 2; i++){
        printf("Digite o peso %d: ",i+1);
        scanf("%f", &pesos[i]);
    }
        verificador(pesos[0], pesos[1]);
}
