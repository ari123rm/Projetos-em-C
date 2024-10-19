#include <stdio.h>

void matriz(void){
  int linhas, colunas;
  int l,c;
  char caract;
  printf("Quantas colunas sua matriz tera: ");
  scanf("%d", &linhas);
  printf("Quantas linhas sua matriz tera: ");
  scanf("%d", &colunas);
  printf("Qual caractere sua matriz tera: ");
  scanf(" %c", &caract);
  for(c=0;c<colunas;c++){
      for(l=0;l<linhas;l++){
        printf("%c", caract);
      }
      printf("\n"); 
  } 
}
void piramide(void){
  int l,c,s,k,linhas;
    linhas = 7;
    k=linhas*2;
    for(l=0;l<=linhas;l++){
        for(c=0;c<=2*l;c++){
            while(s<k){
              printf(" ");
              s++;
            } 
            printf("X");
        }
        printf("\n");
      k--;
      s=0;
    }
}

void caracteresprogressivos(void){
  int l,c,n;
  char caract;
  printf("Numero de linhas: ");
  scanf("%d",&n);
  printf("Caractere: ");
  scanf(" %c",&caract);
  
  for(l=1;l<=n;l++){
    for(c=0;c<2*l;c++){
      printf("%c", caract);
    }
    printf("\n");
  }
}

int main(void){
  int escolha;
  do{
    printf("Escolha que programa deseja fazer\n\n 1 para Caracteres Progressivos\n 2 para piramide\n 3 para matriz\n 0 para sair\n\nDigite aqui sua escolha: ");
    scanf("%d", &escolha);
    printf("\n");
    switch(escolha){
      case 1:
        printf("Escolhido foi Caracteres Progressivos! \n\n");
        caracteresprogressivos();
        break;
      case 2:
        printf("Escolhido foi Piramide! \n\n");
        piramide();
        break;
      case 3:
        printf("Escolhido foi Matriz! \n\n");
        matriz();
        break;
      case 0:
        break;
      default:
        printf("Escolha invalida");
        break;
    }
    printf("\n");
    
  }while(escolha != 0);
  
  printf("Fim do programa!");
  
  
  
return 0;
}