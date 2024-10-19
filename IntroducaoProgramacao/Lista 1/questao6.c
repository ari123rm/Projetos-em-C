/*
ALUNO:  ARIEL ROCHA DE MORAES
CURSO: ENGENHARIA DA COMPUTAÇÃO
CADEIRA: INTRODUÇÃO A PROGRAMAÇÃO
*/
#include <stdio.h>
#include <stdlib.h>

int main(void){
    float gastoM, gastoE, total , saldoM, saldoE, porcentM, porcentE;
    printf("Despesas do Marido: ");
    scanf("%f", &gastoM);
    printf("Despesas da Esposa: ");
    scanf("%f", &gastoE);
    total = gastoM + gastoE;
    porcentM = (gastoM/total)*100;
    porcentE = (gastoE/total)*100;
    saldoM = (total/2) - gastoM;
    saldoE = (total/2) - gastoE;
    printf("\nO total a pagar eh de %.2f reais\nO valor que cada um ira pagar eh de %.2f reais", total, total/2);
    if(saldoM < 0){
        printf("\nA esposa deve pagar para o marido %.2f reais", (-1 * saldoM) );
    }
    if(saldoE < 0){
        printf("\nO marido deve pagar para a esposa %.2f reais", (-1 * saldoE) );
    }
    printf("\nA porcentagem de gasto do marido foi %.2f\nA porcentagem de gasto da esposa foi de %.2f", porcentM, porcentE);
return 0;
}
