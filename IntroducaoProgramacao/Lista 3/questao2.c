/*
ALUNO:  ARIEL ROCHA DE MORAES
CURSO: ENGENHARIA DA COMPUTAÇÃO
CADEIRA: INTRODUÇÃO A PROGRAMAÇÃO
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PESO1 5
#define PESO2 3
#define PESO3 2

float aritmetica(float nota1,int nota2,int nota3){
    float media = (nota1+nota2+nota3)/3;
    return media;

}
float ponderada(float nota1,int nota2,int nota3){
    float media = (nota1*PESO1 + nota2 * PESO2 + nota3 *PESO3)/(PESO1+PESO2+PESO3);
    return media;
}
float harmonica(float nota1,int nota2,int nota3){
    float media = 3/((1/nota1)+(1/nota2)+(1/nota3));
    return media;
}
int main(void){
    int i;
    char Sn;
do{
    float notas[3];
    for(i=0;i<3;i++){
        printf("Digite a nota%d: ", i+1);
        scanf("%f", &notas[i]);
    }
    char tpMedia;
    printf("Que tipo de media deseja?\n Digite A para media Aritimetica \n Digite P para media ponderada\n Digite H para media harmonica\nDigite aqui: ");
    scanf("%s",&tpMedia);
    printf("\n");
    switch (tpMedia){
    case 'A':
        printf("Escolhido foi media aritmetica");
        printf("\n\n");
        printf("A media deu: %.2f", aritmetica(notas[0],notas[1],notas[2]));
        break;
    case 'P':
        printf("Escolhido foi media ponderada");
         printf("\n\n");
        printf("A media deu: %.2f", ponderada(notas[0],notas[1],notas[2]));

        break;
    case 'H':
        printf("Escolhido foi media harmonica");
        printf("\n\n");
        printf("A media deu: %.2f", harmonica(notas[0],notas[1],notas[2]));

        break;
    default:
        printf("Escolha inválida");
    }
printf("\n\n");
printf("Deseja reiniciar?(S para sim, N para nao)\n");
scanf("%s",&Sn);
system("cls");
}while(Sn != 'N');
return 0;
}
