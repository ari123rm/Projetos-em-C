#include <stdio.h>

int main(void){
    int qntddNotas,notaBaixa;
    float nota, soma;
    qntddNotas = notaBaixa = soma = 0;
    char saida;
    do{
        qntddNotas++;
        printf("Digite uma nota entre 0 e 10, caso queira saber as estatisticas digite (-1) \n");
        scanf("%f", &nota);
      if((nota <= 10 && nota >=0) || nota == -1){
        if(nota == -1){
            qntddNotas--;
            printf("Foram publicadas %d notas \n", qntddNotas);
            printf("A media das notas deu %.1f \n", soma/qntddNotas);
            printf("A quantidade de notas abaixo da media foi %d \n", notaBaixa);

            printf("\nDigite C para continuar e S para sair: ");
            scanf(" %c", &saida);
        }else{
            soma = soma + nota;
            if(nota<5){
                notaBaixa++;
            }
        }
      }else{
        printf("\nNota invalida!\n\n");
        qntddNotas--;
      }
    }while(saida!='S');
return 0;
}