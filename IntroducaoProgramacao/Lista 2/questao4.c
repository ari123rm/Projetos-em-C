/*
ALUNO:  ARIEL ROCHA DE MORAES
CURSO: ENGENHARIA DA COMPUTAÇÃO
CADEIRA: INTRODUÇÃO A PROGRAMAÇÃO
*/
#include <stdio.h>
#include <stdlib.h>

void verificadorNota(float n1, float n2){
    float media = (n1 + n2)/2;
    if(media >= 6){
        printf("O ALUNO FOI APROVADO");
    }else{
        printf("O ALUNO FOI REPROVADO");
    }
}
int main(void){
    float notas[2];
    int i;
    for(i=0;i< 2; i++){
        printf("Digite a nota %d: ",i+1);
        scanf("%f", &notas[i]);
    }
    verificadorNota(notas[0],notas[1]);


return 0;
}
