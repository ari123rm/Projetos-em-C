#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const char jogadas[3][10] = {"PEDRA","PAPEL","TESOURA"};
int main(void) {
  char player[10];
  printf("Vamos jogar JOKENPO\nDigite PEDRA, PAPEL ou TESOURA:\n");
  fflush(stdin);
  fgets(player,10,stdin);
  player[strlen(player)-1] = '\0';
  char pc[10];
  srand(time(NULL));
  int random = rand()%3;
  strcpy(pc,jogadas[random]);
  printf("O jogador jogou %s\nO PC jogou %s\n\n",player,pc);
  if(strcmp(player, pc) == 0){
    printf("EMPATE");
  }
  for(int i = 0;i<3;i++){
    if(strcmp(player, jogadas[i])==0){
      if(random == i+1 || (random == 2 && i == 0)){
        printf("PC venceu");
      }
      if(i == random+1|| (i == 2 && random == 0)){
        printf("Jogador venceu");
      }
    }
  }
  return 0;
}