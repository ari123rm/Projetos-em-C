/*
ALUNO:  ARIEL ROCHA DE MORAES
CURSO: ENGENHARIA DA COMPUTAÇÃO
CADEIRA: INTRODUÇÃO A PROGRAMAÇÃO
*/
#include <stdio.h>
#include <stdlib.h>

#define IDADEMIN 16
#define IDADEMAX 69
void verificadorIdade(int idade){
    if(IDADEMIN <= idade && idade <= IDADEMAX){
        printf("Pode doar sangue");
    }else{
        printf("Nao pode doar sangue");
    }
}
int main(void){
    int idade;
    printf("A idade eh: ");
    scanf("%d", &idade);
    printf("\n");
    verificadorIdade(idade);
    printf("\n");

return 0;
}
