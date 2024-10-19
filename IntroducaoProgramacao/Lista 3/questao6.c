/*
ALUNO:  ARIEL ROCHA DE MORAES
CURSO: ENGENHARIA DA COMPUTAÇÃO
CADEIRA: INTRODUÇÃO A PROGRAMAÇÃO
*/
#include <stdio.h>
#include <stdlib.h>
int *duracao(int inicio[2], int termino[2]){
    int *tempo = (int*) malloc(sizeof(int)*2);
    if(inicio[0] < 24 && termino[0]< 24 && inicio[1]< 60 && termino[1]<60){
        if(inicio[0]<= termino[0]){
            *tempo = termino[0]- inicio[0];
        }else{
            *tempo = 24-inicio[0] + termino[0];
        }
        if(inicio[1]<= termino[1]){
            *(tempo+1) = termino[1]- inicio[1];
        }else{
            *(tempo+1) = 60-inicio[1] + termino[1];
        }
    }
        return tempo;

}

int main(void){
    int comeco[2],fim[2];
    printf("Digite o horario que comecou o jogo no formato HORAS:MIN\n");
    scanf("%d:%d",&comeco[0],&comeco[1]);
    printf("Digite o horario que acabou o jogo no formato HORAS:MIN\n");
    scanf("%d:%d",&fim[0],&fim[1]);
    int *horario = duracao(comeco,fim);
    int hora = horario[0];
    int min = horario[1];
    printf("A duracao do jogo foi de %d:%2d horas",hora,min);

return 0;
}
