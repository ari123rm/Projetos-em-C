/*
ALUNO:  ARIEL ROCHA DE MORAES
CURSO: ENGENHARIA DA COMPUTAÇÃO
CADEIRA: INTRODUÇÃO A PROGRAMAÇÃO
*/
#include <stdio.h>
#include <stdlib.h>

void verificadorQuadrado(float L[4]){
    if(L[0]==L[1] && L[1] == L[2] && L[2] == L[3]){
        printf("O quadrilatero eh um quadrado");
    }else{
        printf("O quadrilatero nao eh um quadrado");
    }
}
int main(void){
    float lados[4];
    int i;
    for(i=0;i< 4; i++){
        printf("Digite o lado %d: ",i+1);
        scanf("%f", &lados[i]);
    }
    verificadorQuadrado(lados);
return 0;
}
