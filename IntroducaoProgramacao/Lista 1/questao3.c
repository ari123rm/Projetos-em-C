/*
ALUNO: ARIEL ROCHA DE MORAES
CURSO: ENGENHARIA DA COMPUTAÇÃO
CADEIRA: INTRODUÇÃO A PROGRAMAÇÃO
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double mediaGeometrica(int a,int b, int c){
    double multi = a * b * c;
    double mg = multi/3;
    return (mg);
}
int main(void){
    int i;
    int valores[3];
    for(i=0; i < 3; i++){
        printf("Digite o valor %d: ", i+1);
        scanf("%d", &valores[i]);
    }
    double MG = mediaGeometrica(valores[0], valores[1], valores[2]);
    printf("\nA media geometrica eh: %.2lf", MG);

return 0;
}
