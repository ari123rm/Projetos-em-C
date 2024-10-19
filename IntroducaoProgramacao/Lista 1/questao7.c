/*
ALUNO:  ARIEL ROCHA DE MORAES
CURSO: ENGENHARIA DA COMPUTAÇÃO
CADEIRA: INTRODUÇÃO A PROGRAMAÇÃO
*/
#include <stdio.h>
#include <stdlib.h>

#define ASSINATURA 21.40
#define PULSOS 0.03
#define CELLPULSO 0.40

float preco(int pulso, int pulsoCell){
    int excedente;
    if(pulso > 90){
        excedente = pulso - 90;
    }else{
        excedente = 0;
    }

    float valor = ASSINATURA + (excedente * PULSOS) + (pulsoCell * CELLPULSO);
    return (valor);
}
int main(void){
    int p,c;
    printf("Quantos pulsos interurbanos feitos: ");
    scanf("%d", &p);
    printf("\n");
    printf("Quantas ligacoes feitas para celulares: ");
    scanf("%d", &c);
    printf("\n");
    printf("O valor da conta telefonica sera de %.2f", preco(p,c));
return 0;
}
