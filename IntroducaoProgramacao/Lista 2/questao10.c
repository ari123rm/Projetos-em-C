/*
ALUNO:  ARIEL ROCHA DE MORAES
CURSO: ENGENHARIA DA COMPUTAÇÃO
CADEIRA: INTRODUÇÃO A PROGRAMAÇÃO
*/
#include <stdio.h>
#include <stdlib.h>
float media(int a, int b, int c){

    float soma = a + b + c;
    float m = soma/3;
    return (m);
}
int main(){
    int i;
    int numeros[3];
    for(i = 0; i < 3; i++){
        printf("Digite a %d nota: ", (i+1));
        scanf("%d", &numeros[i]);
    }

    float M = media(numeros[0], numeros[1], numeros[2]);
    printf("A media das notas foi: %.2f", M);


return 0;
}
