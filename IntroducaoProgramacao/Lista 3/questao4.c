/*
ALUNO:  ARIEL ROCHA DE MORAES
CURSO: ENGENHARIA DA COMPUTAÇÃO
CADEIRA: INTRODUÇÃO A PROGRAMAÇÃO
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double* baskara(double a,double b , double c){
    double *X = (double*) malloc(sizeof(double) * 2);
    double delta = (pow(b,2))-(4*a*c);
    *X = ((b*-1) + sqrt(delta))/(2*a);
    *(X+1) = ((b*-1) - sqrt(delta))/(2*a);
    return X;
}
int main(void){
    double a,b,c,x1,x2;
    printf("Seguindo o formato: aX^2 + bX + c\nQuais valores de a, b e c?\nValor de a: ");
    scanf("%lf", &a);
    printf("Valor de b: ");
    scanf("%lf", &b);
    printf("Valor de c: ");
    scanf("%lf", &c);
    double *raizes = baskara(a,b,c);
    x1 = raizes[0];
    x2 = raizes[1];
    printf("As raizes da expressao: %.1lfX^2+ %.1lfX + %.1lf\nSao: %lf e %lf.", a,b,c,x1,x2);
    printf("\n");
return 0;
}
