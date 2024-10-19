/*
ALUNO:  ARIEL ROCHA DE MORAES
CURSO: ENGENHARIA DA COMPUTAÇÃO
CADEIRA: INTRODUÇÃO A PROGRAMAÇÃO
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    int i ,numeros[4];
    for(i = 0; i < 4; i++){
        printf("Digite o %d numero: ", (i+1));
        scanf("%d", &numeros[i]);
    }
    printf("\n%d %d %d %d \n", numeros[0],numeros[1],numeros[2],numeros[3] );
    printf("\n%d %d %d %d \n", numeros[0]+1,numeros[1]+1,numeros[2]+1,numeros[3]+1 );
    return 0;
}
