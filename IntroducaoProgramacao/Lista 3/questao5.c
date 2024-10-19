/*
ALUNO:  ARIEL ROCHA DE MORAES
CURSO: ENGENHARIA DA COMPUTAÇÃO
CADEIRA: INTRODUÇÃO A PROGRAMAÇÃO
*/
#include <stdio.h>
#include <stdlib.h>
void verificadorIdade(int idade){
    if(5<=idade && 7>= idade){
        printf("Infantil A");
    }
    if(8<=idade && 10>= idade){
        printf("Infantil B");
    }
    if(11<=idade && 13>= idade){
        printf("Juvenil A");
    }
    if(14<=idade && 17>= idade){
        printf("Juvenil B");
    }
    if(idade >= 18){
        printf("Adulto");
    }
    }

int main(void){
    int idade;
    printf("Qual a idade do nadador: ");
    scanf("%d", &idade);
    printf("\n");
    printf("A categoria que ele ira diputar sera a categoria ");
    verificadorIdade(idade);
    printf("\n");

return 0;
}
