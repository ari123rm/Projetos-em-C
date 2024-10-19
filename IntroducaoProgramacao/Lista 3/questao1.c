/*
ALUNO:  ARIEL ROCHA DE MORAES
CURSO: ENGENHARIA DA COMPUTAÇÃO
CADEIRA: INTRODUÇÃO A PROGRAMAÇÃO
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.1415

float volume(float r){
    float V = (4 * PI * pow(r,3))/3;
    return V;
}
int main(void){
    float raio;
    printf("Digite o raio: ");
    scanf("%f", &raio);
    printf("O volume da esfera eh: %.2f", volume(raio) );
return 0;
}
