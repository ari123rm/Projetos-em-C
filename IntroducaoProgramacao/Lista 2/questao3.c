/*
ALUNO:  ARIEL ROCHA DE MORAES
CURSO: ENGENHARIA DA COMPUTAÇÃO
CADEIRA: INTRODUÇÃO A PROGRAMAÇÃO
*/
#include <stdio.h>
#include <stdlib.h>

void verificador(int n1, int n2){
    if (n1 == n2){
        printf("Os dois numeros sao iguais");
    }
    if( n1 > n2){
      printf("O %d eh maior que o %d", n1, n2);
    }
    if( n1 < n2){
      printf("O %d eh maior que o %d", n2, n1);
    }
}
int main(void){
    int i, numeros[2];
    for(i=0;i< 2; i++){
        printf("Digite o %d numero: ",i+1);
        scanf("%d", &numeros[i]);
    }
        verificador(numeros[0], numeros[1]);
}
