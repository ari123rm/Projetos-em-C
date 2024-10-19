#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char tabuleiro[3][3];

void reiniciar(void) {
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      tabuleiro[i][j] = ' ';
    }
  }
}

int verificar(void) {
  int i, j;

  if (tabuleiro[0][0] == tabuleiro[1][1] &&
      tabuleiro[0][0] == tabuleiro[2][2]) {
    if (tabuleiro[0][0] == 'X')
      return 1;
    if (tabuleiro[0][0] == 'O')
      return 2;
  }

  if (tabuleiro[0][2] == tabuleiro[1][1] &&
      tabuleiro[0][2] == tabuleiro[2][0]) {
    if (tabuleiro[0][2] == 'X')
      return 1;
    if (tabuleiro[0][2] == 'O')
      return 2;
  }

  for (i = 0; i < 3; i++) {
    if (tabuleiro[i][0] == tabuleiro[i][1] &&
        tabuleiro[i][0] == tabuleiro[i][2]) {
      if (tabuleiro[i][0] == 'X')
        return 1;
      if (tabuleiro[i][0] == 'O')
        return 2;
    }
    if (tabuleiro[0][i] == tabuleiro[1][i] &&
        tabuleiro[0][i] == tabuleiro[2][i]) {
      if (tabuleiro[0][i] == 'X')
        return 1;
      if (tabuleiro[0][i] == 'O')
        return 2;
    }
  }
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
      if (tabuleiro[i][j] == ' ')
        return 3;
    }
  }
  return 0;
}

void mostrar(void) {
  int i, j, k = 0;

  printf("\n    1 | 2 | 3 \n\n");
  for (i = 0; i < 5; i++) {
    if (i % 2 == 0) {
      printf("%d  ", k + 1);
    } else {
      printf("   ");
    }
    for (j = 0; j < 3; j++) {
      switch (i % 2) {
      case 1:
        printf("---");
        if (j != 2)
          printf("|");
        break;
      case 0:
        printf(" %c ", tabuleiro[k][j]);
        if (j != 2)
          printf("|");
        break;
      }
    }
    if (i % 2 == 0)
      k++;
    printf("\n");
  }
}

void jogadaPC(void){
  int ver=0,linha,coluna,i,j,k,l;
  for(i=0;i<3;i++){
      for(j=0;j<3;j++){
        for(k=0;k<3;k++){
          for(l=0;l<3;l++){
            if((tabuleiro[i][j]==tabuleiro[k][l] && tabuleiro[i][j]== 'O'&& tabuleiro[k][l]== 'O') && (i!=k || j!=l) && ver == 0){
              if(i==k){
                if(tabuleiro[i][3-(j+l)]== ' '){
                  tabuleiro[i][3-(j+l)] = 'O';
                  ver = 1;
                }
              }
              if(j==l){
                 if(tabuleiro[3-(i+k)][j]== ' '){
                   tabuleiro[3-(i+k)][j] = 'O';
                   ver = 1;
                 }
              }
              if(i==j && k==l){
                if(tabuleiro[3-(i+k)][3-(j+l)]== ' '){
                  tabuleiro[3-(i+k)][3-(j+l)] = 'O';
                  ver = 1 ;
                }
              }
              if((i+j==3 && k+l==3)){
                if(tabuleiro[3-(i+k)][3-(j+l)]== ' '){
                  tabuleiro[3-(i+k)][3-(j+l)] = 'O';
                  ver = 1 ;
                }
              }
            }
          }
        }
      }
    }
   for(i=0;i<3;i++){
      for(j=0;j<3;j++){
        for(k=0;k<3;k++){
          for(l=0;l<3;l++){
            if((tabuleiro[i][j]==tabuleiro[k][l] && tabuleiro[i][j]== 'X'&& tabuleiro[k][l]== 'X') && (i!=k || j!=l) && ver == 0){
              if(i==k){
                if(tabuleiro[i][3-(j+l)]== ' '){
                  tabuleiro[i][3-(j+l)] = 'O';
                  ver = 1;
                }
              }
              if(j==l){
                 if(tabuleiro[3-(i+k)][j]== ' '){
                   tabuleiro[3-(i+k)][j] = 'O';
                   ver = 1;
                 }
              }
              if(i==j && k==l){
                if(tabuleiro[3-(i+k)][3-(j+l)]== ' '){
                  tabuleiro[3-(i+k)][3-(j+l)] = 'O';
                  ver = 1 ;
                }
              }
              if((i+j==3 && k+l==3)){
                if(tabuleiro[3-(i+k)][3-(j+l)]== ' '){
                  tabuleiro[3-(i+k)][3-(j+l)] = 'O';
                  ver = 1 ;
                }
              }
            }
          }
        }
      }
    }
  while(ver != 1){
      linha = rand() % 3;
      coluna = rand() % 3;
      if(tabuleiro[linha][coluna]== ' '){
        tabuleiro[linha][coluna] = 'O';
        ver = 1 ;
      }
  }
}

void jogador(void) {
  int jogador = 0;
  int l, c;
  do {
    printf("\nJogador %d faça sua jogada:\nDigite a coordenada de sua jogada no formato(LINHA,COLUNA): ",(jogador % 2) + 1);
    scanf("%d,%d", &l, &c);
    if (tabuleiro[l - 1][c - 1] != ' ') {
      printf("\nLocal inválido! Tente novamente!\n");
      continue;
    }
    if ((l > 3 || c > 3 || l < 1 || c < 1) || tabuleiro[l - 1][c - 1] != ' ') {
      printf("\nJogada inválida! Tente novamente\n");
      continue;
    } else {
      switch (jogador % 2) {
      case 0:
        tabuleiro[l - 1][c - 1] = 'X';
        break;
      case 1:
        tabuleiro[l - 1][c - 1] = 'O';
        break;
      }
      jogador++;
      mostrar();
      switch (verificar()) {
      case 1:
        printf("\nJogador 1 Venceu!\n");
        break;
      case 2:
        printf("\nJogador 2 Venceu!\n");
        break;
      case 3:
        break;
      case 0:
        printf("\nDeu velha!\n");
        break;
      }
    }
  } while (verificar() == 3);
}

void pc(void) {

  int l, c,ver;
  int linha, coluna;
  do {
    printf("\nJogador faça sua jogada:\nDigite a coordenada de sua jogada no formato(LINHA,COLUNA): ");
    scanf("%d,%d", &l, &c);
    if (tabuleiro[l - 1][c - 1] != ' ') {
      printf("\nLocal inválido! Tente novamente!\n");
      continue;
    }
    if (l > 3 || c > 3 || l < 1 || c < 1) {
      printf("\nJogada inválida! Tente novamente\n");
      continue;
    } else {
      tabuleiro[l - 1][c - 1] = 'X';
      mostrar();
      switch (verificar()) {
      case 1:
        printf("\nJogador  Venceu!\n");
        break;
      case 2:
        printf("\nPC Venceu!\n");
        break;
      case 3:
        jogadaPC();
        mostrar();
        switch (verificar()) {
          case 1:
            printf("\nJogador Venceu!\n");
            break;
          case 2:
            printf("\nPC Venceu!\n");
            break;
          case 3:
            break;
          case 0:
            printf("\nDeu velha!\n");
            break;
        }
        break;
      case 0:
        printf("\nDeu velha!\n");
        break;
      }
    }
  } while (verificar() == 3);
}

int main(void) {
  srand(time(NULL));
  setlocale(LC_ALL, "Portuguese");
  char adversario[10];
  int condicao = 0;
  do {
    printf("Vamos jogar o jogo da velha :D\n\nVocê deseja jogar contra jogador "
           "ou pc?\n");
    fflush(stdin);
    scanf("%s", adversario);
    // fgets(adversario,10,stdin);
    // adversario[strlen(adversario)-1] = '\0';
    printf("\nSua escolha foi %s\n", adversario);
    reiniciar();
    mostrar();
    if (strcmp(adversario, "jogador") == 0) {
      jogador();
    } else {
      if (strcmp(adversario, "pc") == 0) {
        pc();
      } else {
        printf("\nOpcao invalida, tente novamente!\n\n");
      }
    }
    printf("\nDigite 1 para sair ou 2 para jogar novamente: ");
    scanf("%d", &condicao);
    printf("\n\n");
  } while (condicao != 1);
  return 0;
}