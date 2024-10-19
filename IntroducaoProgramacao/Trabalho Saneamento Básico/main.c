/*
Cadeira: Iniciação a programação
Professor: Allyson Bonetti
Alunos:
  Ariel Rocha de Moraes 
  André Lucas Sales Barros
*/
#include <stdio.h>

#define AGUA1 4.99
#define AGUA2 6.48
#define AGUA3 7
#define AGUA4 12.02
#define AGUA5 21.23

#define ESG1 5.54
#define ESG2 7.09
#define ESG3 7.69
#define ESG4 13.20
#define ESG5 23.34

float agua(int m){
  float valorA;
  printf("Leitura Água: %d\n", m);
  
  if(m>=0 && m<=10){
     valorA=m*AGUA1;
     printf("faixa1: %d\nfaixa2: 0\nfaixa3: 0\nfaixa4: 0\nfaixa5: 0\n",m);
  }
  if(m>=11 && m<=15){
    valorA=(m-10)*AGUA2 + 10*AGUA1;
    printf("faixa1: 10\nfaixa2: %d\nfaixa3: 0\nfaixa4: 0\nfaixa5: 0\n",m-10);
  }
  if(m>=16 && m<=20){
    valorA=(m-15)*AGUA3 + 5*AGUA2 + 10*AGUA1;
    printf("faixa1: 10\nfaixa2: 5\nfaixa3: %d\nfaixa4: 0\nfaixa5: 0\n",m-15);
  }
  if(m>=21 && m<=50){
    valorA=(m-20)* AGUA4+5*AGUA3 + 5*AGUA2 + 10*AGUA1;
    printf("faixa1: 10\nfaixa2: 5\nfaixa3: 5\nfaixa4: %d\nfaixa5: 0\n",m-20);
  }
  if(m>50){
    valorA=(m-50)*AGUA5+30* AGUA4+5*AGUA3 + 5*AGUA2 + 10*AGUA1;
    printf("faixa1: 10\nfaixa2: 5\nfaixa3: 5\nfaixa4: 30\nfaixa5: %d\n",m-50);
  }
 printf("Total Água: %.2f\n\n", valorA) ;
return valorA;

  
}
float esgoto(int k){
  int m;
  k=k*0.8;
  m = k + 0.5;
  float valorE;
  printf("Leitura esgoto: %d\n", m);
  
  if(m>=0 && m<=10){
     valorE=m*ESG1;
     printf("faixa1: %d\nfaixa2: 0\nfaixa3: 0\nfaixa4: 0\nfaixa5: 0\n",m);
  }
  if(m>=11 && m<=15){
    valorE=(m-10)*ESG2 + 10*ESG1;
    printf("faixa1: 10\nfaixa2: %d\nfaixa3: 0\nfaixa4: 0\nfaixa5: 0\n",m-10);
  }
  if(m>=16 && m<=20){
    valorE=(m-15)*ESG3 + 5*ESG2 + 10*ESG1;
    printf("faixa1: 10\nfaixa2: 5\nfaixa3: %d\nfaixa4: 0\nfaixa5: 0\n",m-15);
  }
  if(m>=21 && m<=50){
    valorE=(m-20)* ESG4+5*ESG3 + 5*ESG2 + 10*ESG1;
    printf("faixa1: 10\nfaixa2: 5\nfaixa3: 5\nfaixa4: %d\nfaixa5: 0\n",m-20);
  }
  if(m>50){
    valorE=(m-50)*ESG5+30* ESG4+5*ESG3 + 5*ESG2 + 10*ESG1;
    printf("faixa1: 10\nfaixa2: 5\nfaixa3: 5\nfaixa4: 30\nfaixa5: %d\n",m-50);
  }
 printf("Total esgoto: %.2f\n\n", valorE) ;
return valorE;
}




int main(void) {
  float m;
  printf("Informe a leitura do Hidrômetro: ");
  scanf("%f", &m);
  printf("Tipo de Tarifa: Residencial Normal\n");
  
  printf("Total da Conta: %.2f \n", agua(m)+esgoto(m));
  
  return 0;
}