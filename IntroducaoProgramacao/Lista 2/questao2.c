/*
ALUNO:  ARIEL ROCHA DE MORAES
CURSO: ENGENHARIA DA COMPUTAÇÃO
CADEIRA: INTRODUÇÃO A PROGRAMAÇÃO
*/
#include <stdio.h>
#include <stdlib.h>

void verificador(int num){
    int i;
    for( i = 0; i < num+1; i++){
        int k = i * 2;
        if(k == num){
            printf("par");
            break;
        }
        if(k == num+1){
            printf("impar");
        }
    }
}
int main(void){
    int n;
    printf("Digite um numero: ");
    scanf("%d",&n);
    printf("O numero eh ");
    verificador(n);


return 0;
}
