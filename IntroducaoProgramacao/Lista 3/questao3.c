/*
ALUNO:  ARIEL ROCHA DE MORAES
CURSO: ENGENHARIA DA COMPUTAÇÃO
CADEIRA: INTRODUÇÃO A PROGRAMAÇÃO
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool testePrimo(unsigned int n){
    int i,resto;
    bool retorno;
    retorno = true;
    for(i=2;i<n;i++){
        resto = n % i;
        if(resto == 0){
            retorno = false;
        }
        }
return retorno;
}
int main(void){
    unsigned int numero;
    printf("Escreva um numero e testaremos se ele eh primo: ");
    scanf("%d", &numero);
    if(testePrimo(numero) == true){
        printf("Parabens, %d eh primo", numero);
    }else{
        printf("Que pena! O %d nao eh primo", numero);
    }
return 0;
}
