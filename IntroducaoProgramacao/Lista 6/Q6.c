#include <stdio.h>
//questao 6

void letraA(distancias[5][5]){
  int cidadeInicial,cidadeFinal;
  do{
    printf("Digite a cidade inicial(1 a 5): ");
    scanf("%d",&cidadeInicial);
    printf("Digite a cidade final(1 a 5): ");
    scanf("%d",&cidadeFinal);
    printf("\nA distancia eh : %d\n\n", distancias[cidadeInicial-1][cidadeFinal-1]);
  }while(cidadeInicial != 0 && cidadeFinal != 0 );
}
void letraB(int distancias[5][5]){
  int cidadeInicial,cidadeFinal,repet=0,i,repeticao[repet][2],verificador;
  do{
    verificador = 1;
    printf("Digite a cidade inicial(1 a 5): ");
    scanf("%d",&cidadeInicial);
    printf("Digite a cidade final(1 a 5): ");
    scanf("%d",&cidadeFinal);
    for(i=0;i<=repet;i++){
      if(((repeticao[i][0] == cidadeInicial)&& (repeticao[i][1] == cidadeFinal))||((repeticao[i][1] == cidadeInicial)&&(repeticao[i][0] == cidadeFinal))){
        printf("\ndistancia ja dada\n\n");
        verificador = 0;
      }
    }
    if(verificador == 1){
    printf("\nA distancia eh : %d\n\n", distancias[cidadeInicial-1][cidadeFinal-1]);
    repeticao[repet][0] = cidadeInicial;
    repeticao[repet][1] = cidadeFinal;
    repet++;
    }
 
  }while(cidadeInicial != 0 && cidadeFinal != 0 );
}
void letraC(int distancias[5][5]){
  int paradas,i,soma;
    soma = 0 ;
    printf("Quantas cidades ira passar: ");
    scanf("%d",&paradas);
  int cidades[paradas];
      printf("Digite a cidade inicial(1 a 5): ");
      scanf("%d",&cidades[0]);
    for(i=1;i<paradas;i++){
      printf("Digite a cidade da %d parada(1 a 5): ", i);
      scanf("%d",&cidades[i]);
      soma = distancias[cidades[i-1]-1][cidades[i]-1] + soma;
    }
    printf("\nA distancia final eh : %d\n\n", soma);
}
int main(void){
  int distancias[5][5] = {
  {00, 15, 30, 05, 12},
  {15, 00, 10, 17, 28},
  {30, 10, 00, 03, 11},
  {05, 17, 03, 00, 80},
  {12, 28, 11, 80, 00}
  };
  char alternativa;
  printf("Que alternativa deseja?(A ou B ou C)\n");
  scanf("%c", &alternativa);
  printf("\n");
  switch(alternativa){
    case 'A':
      letraA(distancias);
      break;
    case 'B':
      letraB(distancias);
      break;
    case 'C':
      letraC(distancias);
      break;
    default:
      printf("alternativa invalida");
      break;
  }
  
  
  return 0;
}