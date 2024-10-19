/*
ALUNO:  ARIEL ROCHA DE MORAES
CURSO: ENGENHARIA DA COMPUTAÇÃO
CADEIRA: INTRODUÇÃO A PROGRAMAÇÃO
*/
#include <stdio.h>
#include <stdlib.h>

float notaSemestre(float a, float b){
    int Peso1 = 2;
    int Peso2 = 3;
    float notaS = (a * Peso1 + b *Peso2)/ (Peso1 + Peso2);
    return (notaS);
}
int main(void){
    float nota[2];
    int i;
    for(i=0;i<2;i++){
        printf("Digite o valor da nota %d: ", i+1);
        scanf("%f", &nota[i]);
    }
    if ((0 <= nota[0] && nota[0] <= 10)&&(0 <= nota[1] && nota[1] <= 10)){
        float NotaS = notaSemestre(nota[0], nota[1]);
        printf("\nA nota 1 foi %.1f e a nota 2 foi %.1f \nA nota bimestral foi %.1f", nota[0], nota[1], NotaS);
    }
}
