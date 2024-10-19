#include <stdio.h>
//questao 5
void letraA(int tabuleiro[8][8]){
  int l,c,PouB,vazio;
  PouB = vazio = 0;
  for(l=0;l<8;l++){
    for(c=0;c<8;c++){
      if(tabuleiro[l][c] == 1 || tabuleiro[l][c] == 4){
        PouB++;
      }
      if(tabuleiro[l][c] == 0){
        vazio++;
      }
    }
  }
  printf("Tem %d peoes ou bispos e %d posicoes vazias", PouB,vazio);
}
void letraB(int tabuleiro[8][8]){
  int l,c,peoes,cavalos,torres,bispos,reis,rainhas,vazio;
  peoes = cavalos = torres = bispos = reis = rainhas = vazio = 0;
  for(l=0;l<8;l++){
    for(c=0;c<8;c++){
      switch(tabuleiro[l][c]){
        case 0:
          vazio++;
          break;
        case 1:
          peoes++;
          break;
        case 2:
          cavalos++;
          break;
        case 3:
          torres++;
          break;
        case 4:
          bispos++;
          break;
        case 5:
          reis++;
          break;
        case 6:
          rainhas++;
          break;
      }
    }
  }
  printf("Tiveram:\n%d peoes\n%d cavalos\n%d torres\n%d bispos\n%d reis\n%d rainhas\n%d posicoes vazias",peoes,cavalos,torres,bispos,reis,rainhas,vazio);
}
int main(void){
  int tabuleiro[8][8]= {
  {1, 3, 0, 5, 4, 0, 2, 1},
  {1, 0, 1, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 1, 0, 6, 0},
  {1, 0, 0, 1, 1, 0, 0, 1},
  {0, 1, 0, 4, 0, 0, 1, 0},
  {0, 0, 3, 1, 0, 0, 1, 1},
  {1, 0, 6, 6, 0, 0, 1, 0},
  {1, 0, 5, 0, 1, 1, 0, 6}};
  char alternativa;
  printf("Que alternativa deseja?(A ou B)\n");
  scanf("%c", &alternativa);
  printf("\n");
  switch(alternativa){
    case 'A':
      letraA(tabuleiro);
      break;
    case 'B':
      letraB(tabuleiro);
      break;
    default:
      printf("alternativa invalida");
      break;
  }
  return 0;
}