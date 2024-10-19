/*
ALUNO:  ARIEL ROCHA DE MORAES
CURSO: ENGENHARIA DA COMPUTAÇÃO
CADEIRA: INTRODUÇÃO A PROGRAMAÇÃO
*/
#include <stdio.h>
#include <stdlib.h>

void verificador(float n1, float n2){
    if (n1 == n2){
        printf("As duas alturas sao iguais");
    }
    if( n1 > n2){
      printf("A altura de %.2fm eh maior que a altura de %.2fm", n1, n2);
    }
    if( n1 < n2){
      printf("A altura de %.2fm eh maior que a altura de %.2fm", n2, n1);
    }
}
int main(void){
    float alturas[2];
    int i;
    for(i=0;i< 2; i++){
        printf("Digite a %d altura: ",i+1);
        scanf("%f", &alturas[i]);
    }
        verificador(alturas[0], alturas[1]);
}

