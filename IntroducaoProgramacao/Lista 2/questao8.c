/*
ALUNO:  ARIEL ROCHA DE MORAES
CURSO: ENGENHARIA DA COMPUTAÇÃO
CADEIRA: INTRODUÇÃO A PROGRAMAÇÃO
*/
#include <stdio.h>
#include <stdlib.h>

void crescente(int valores[3]){
    int i,j;
    for(i = 0 ; i < 3; i++){
        for(j = i+1; j < 3; j++){
            if(valores[i]> valores[j]){
                int aux = valores[i];
                valores[i] = valores[j];
                valores[j] = aux;

            }
        }
    }
    printf("A ordem crescente dos numeros eh: %d, %d, %d", valores[0], valores[1], valores[2]);
}
int main(void){
    int i,numeros[3];
    for(i=0;i< 3; i++){
        printf("Digite o numero %d: ",i+1);
        scanf("%d", &numeros[i]);
    }
    crescente(numeros);
return 0;
}
