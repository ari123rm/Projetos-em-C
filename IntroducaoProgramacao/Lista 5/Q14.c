#include <stdio.h>

int main(void){
  char time;
  float quantidadeTotal,flu,fla,vas,bot,outros;
  quantidadeTotal = flu = fla = vas = bot = outros = 0;
do{
  printf("Digite seu time do coracao conforme a tabela abaixo\n N para Fluminense\n M para Flamengo\n V para Vasco\n B para Botafogo\n O para outros\n R para imprimir o resultado\nDigite aqui a sua letra: ");
  scanf(" %c", &time);
  if(time != 'R'){
    quantidadeTotal++;
    switch(time){
      case 'N':
        flu++;
        break;
      case 'M':
        fla++;
        break;
      case 'V':
        vas++;
        break;
      case 'B':
        bot++;
        break;
      case 'O':
        outros++;
        break;
      default:
        printf("\nEscolha invalida!\n\n");
        quantidadeTotal--;
        break;
    }
  }
}while(time != 'R');
  printf("\nA quantidade total de votos foram %.f\n",quantidadeTotal);
  printf("\nA quantidade de cada time foi:\nFluminense: %.f\nFlamengo: %.f\nVasco: %.f\nBotafogo: %.f\nOutros: %.f\n",flu,fla,vas,bot,outros);
  printf("\nA porcentagem foi de:\n%.2f%% para o Fluminense\n%.2f%% para o Flamengo\n%.2f%% para o Vasco\n%.2f%% para o Botafogo\n%.2f%% para Outros\n",(flu*100)/quantidadeTotal,(fla*100)/quantidadeTotal,(vas*100)/quantidadeTotal,(bot*100)/quantidadeTotal,(outros*100)/quantidadeTotal);
  
  return 0;
}