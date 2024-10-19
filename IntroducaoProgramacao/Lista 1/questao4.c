/*
ALUNO:  ARIEL ROCHA DE MORAES
CURSO: ENGENHARIA DA COMPUTAÇÃO
CADEIRA: INTRODUÇÃO A PROGRAMAÇÃO
*/
#include <stdio.h>
#include <stdlib.h>

float mediaPonderada(int a , int b , int c){
    float PesoA = 1;
    float PesoB = 2;
    float PesoC = 3;
    float mp = (a * PesoA + b *PesoB + c * PesoC)/(PesoA + PesoB + PesoC);
    return (mp);
}
int main(void){
    int valores[3],i;
    for(i=0;i<3;i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%d", &valores[i]);
    }
    float  MP = mediaPonderada(valores[0],valores[1],valores[2]);
    printf("\nA media ponderada deu: %.2f",MP);
return 0;
}
