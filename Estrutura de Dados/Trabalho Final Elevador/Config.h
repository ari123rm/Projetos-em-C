#ifndef CONFIG_H
#define CONFIG_H

#define stringTam 10000

/*
 *  Estrutura de dados para armazenar as configurações do programa
 * andares = Total de andares do predio
 * elevadores = quantidade de elevadores do predio
 * economico = ativa e desativa modo economico
*/

typedef struct config {
  int andares;
  int elevadores;
    int economico;
} Config;

#include "Elevador.h"

//Coloca todos os parametros no elevador
int buildElevador(Andar **predio, Elevador *elevador, Config **config,char estado,int andarInicial);

//Verifica os chamados no andar
int chamadoElevador(Andar **predio, Elevador *elevador,Elevador **listaElevadores, Config **config) ;

//Muda os estados do elevador conforme a nescessidade do programa
int estadoElevador(Andar **predio, Elevador *elevador, Elevador **listaElevador,  Config **config);

//Move o elevador para a direção do estado 
int moverElevador(Andar **predio, Elevador *elevador, Config **config);

//Adiciona uma pessoa dentro do elevador
int addPessoaElevador(Elevador *elevador, int andar, Config **config) ;

//Adiciona pessoa no andar
int addPessoaAndar(Andar **predio, int andarEnt, int andarSai, int tick,Config **config) ;
//Seta todos os ponteiros para NULL
void iniciar(Andar **predio, Config **config, Pessoa **fila, Elevador **elevador);

//Coloca todos os parametros da config
void buildConfig(Config **config);

//Verifica se existe alguem para sair da fila de espera
int mensagem(Andar **predio, Config **config, Pessoa **fila,unsigned long int tick);
//Executa todas as funçoes do elevador por tick
int tick(Andar **predio, Elevador **elevador, Config **config);
//Verifica se todos  os elevadores estao parado
int programaParado(Elevador **elevador, Config **config);

//processa a string e configura o programa 
int processarString(char string[stringTam], Andar **predio, Elevador **elevador,Config **config, Pessoa **fila);

//Libera a memoria alocada do programa
int fim(Andar **predio, Elevador **elevador, Config **config, Pessoa **fila);

//Printa o estado do programa atual
int mostrarPredio(Andar **predio, Elevador **elevador, Config **config,Pessoa **fila);

#endif