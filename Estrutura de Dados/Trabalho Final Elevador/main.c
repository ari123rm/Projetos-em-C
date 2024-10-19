#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Config.c"
#include "Elevador.c"
#include "Predio.c"
#include "Pessoa.c"
/*
*  Constantes:
*    StringTam = 10000 | Config.h
*    maxElevadores = 6 | Elevador.h
*    maxAndar = 25     | Predio.h
*    minAndar = 5      | Predio.h
*/

int main(void) {
  setlocale(LC_ALL, "Portuguese");
  char string[stringTam];
  //Ponteiros do programa
  Config *config;
  Andar *predio;
  Pessoa *fila; //Fila de pessoas que não entraram nos andares ainda
  Elevador *elevadores;
  iniciar(&predio, &config, &fila,&elevadores); //seta todos os ponteiros para NULL
  int verificador;//Verifica se a string é válida
  do{
    printf("Digite a String:\n");
    fgets(string, stringTam, stdin);
    string[strcspn(string, "\n")] = '\0';
    
    verificador = processarString(string, &predio, &elevadores, &config, &fila);//verificador < 0 -> invalida
    if(verificador < 0){//TRATAMENTO DE ERRO
      printf("Erro na entrada de dados, tente novamente:  %d\n" , verificador);
      
      if(verificador == -1)printf("ERRO: QUANTIDADE DE ANDARES\n");
      if(verificador == -3)printf("ERRO: DADOS INVADIDOS");
      
      if(verificador/10 == -1 && verificador != -1)printf("ERRO: NO ELEVADOR %d\n", -1* verificador%10 );
      
      if(verificador/10 == -2 && verificador != -2)printf("ERRO: QUANTIDADE DE ELEVADORES\n");
      
      if(verificador/1000000 == -1 &&verificador != -1 && verificador != -10)printf("ERRO: NA PESSOA %d DO TICK %d\n", -1 *verificador%1000  ,-1 * (verificador/1000) % 1000);

      
      fim( &predio, &elevadores, &config, &fila);
    }
  }while(verificador < 0);
  do {
    printf("Modo Economico: 1 - ON | 0 - OFF \n");//modo economico tenta usar o minimo de energia possivel
    scanf("%d", &(config->economico));
    if(config->economico != 1 && config->economico != 0)printf("\nERRO na selecao");
  }while(config->economico != 1 && config->economico != 0);
  unsigned long int ticks = -1; //Contador de TICKS
  do {
    ticks++;
    mensagem(&predio, &config, &fila, ticks);//Verifica se tem alguem para sair da fila
    mostrarPredio(&predio, &elevadores, &config,&fila);//mostra os dados do predio
    tick(&predio, &elevadores, &config);//executa funções do elevador no tick
    printf("\nTick: %ld\n", ticks);//printa o tick
    sleep(1);
  } while (programaParado(&elevadores, &config) != 1 || contarPessoas(fila) != 0);
  
 
  printarRota(&elevadores, ticks,config->elevadores);//mostra toda a rota de todos os elevadores
 
  
  fim(&predio, &elevadores, &config, &fila); //Libera a memoria alocada
  printf("\nFIM DO PROGRAMA\n");
  printf("\nPressione qualquer tecla para finalizar o programa\n");
  getch();
  return 0;
}
