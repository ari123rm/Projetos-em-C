/*
ALUNO:  ARIEL ROCHA DE MORAES
CURSO: ENGENHARIA DA COMPUTAÇÃO
CADEIRA: INTRODUÇÃO A PROGRAMAÇÃO
*/
#include <stdio.h>
#include <stdio.h>
#include <math.h>

// OPERADORES

float mais(int a, int b){
    float s = a + b;
    return s;
}
float menos(int a, int b){
    float n = a - b;
    return n;
}
float vezes(int a, int b){
    float m = a * b;
    return m;
}
float sobre(int a, int b){
    float d = a / b;
    return d;
}


// DEFINE A RESPOSTA
float resposta(int o , int num1, int num2){
    static float resultado;
    if(o == 1){
        resultado = mais(num1 , num2);
    }
    if(o == 2){
        resultado = menos(num1 , num2);
    }
    if(o == 3){
        resultado = vezes(num1 , num2);
    }
    if(o == 4){
        resultado = sobre(num1 , num2);
    }
    return resultado;
}

// CLIENTE
int main(void){
    int n;
    float n1, n2;
    printf("digite o primeiro numero: ");
    scanf("%f", &n1);
    printf("digite o segundo numero: ");
    scanf("%f", &n2);
    printf("Para dizer o operador digite conforme a tabela abaixo\n soma = 1 \n subtracao = 2\n multiplicacao = 3 \n divisao = 4\nSeu operador eh: ");
    scanf("%d", &n);
    printf("\n");
    printf("O resultado da operacao eh %.2f", resposta(n,n1,n2) );
}
