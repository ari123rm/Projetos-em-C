/*
ALUNO:  ARIEL ROCHA DE MORAES
CURSO: ENGENHARIA DA COMPUTAÇÃO
CADEIRA: INTRODUÇÃO A PROGRAMAÇÃO
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MIN 18.5
#define MAX 25

float IMC(float altura, float peso){
    float Calculo = peso/ pow(altura,2);
    return Calculo;
}
void verificadorIMC(float imc){
    printf("Seu IMC eh %.2f\n", imc);
    if(imc < MIN){
        printf("A pessoa esta abaixo do peso ideal");
    }else{
        if(imc <= MAX){
            printf("A pessoa esta no peso normal");
        }else{
            printf("A pessoa esta acima do peso ideal");
        }
    }

}
int main(void){
    float peso,altura;
    printf("Seu peso em KG: ");
    scanf("%f", &peso);
    printf("Sua altura em metros: ");
    scanf("%f", &altura);
    verificadorIMC(IMC(altura, peso));

return 0;
}
