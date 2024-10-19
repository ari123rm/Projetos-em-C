#ifndef ELEVADOR_H
#define ELEVADOR_H

#define maxElevador 6

#include "Predio.h"

/*
*  Estrutura de dados para armazenar os dados da rota do elevador
* andar = andar que o elevador foi
* importante = indica se a rota é importante, ou seja, teve mudanças no elevador
* prox = ponteiro para o proximo andar da rota
*/
typedef struct rota{
  int andar;
  int importante;  
  struct rota *prox;
}Rota;

/*
* Esta estrutura armazena os dados do elevador
* andar = andar que o elevador esta
* estado = estado do elevador
* passageiros = lista de pessoas que estao no elevador
* rota = lista de andares que o elevador esta percorreu
* percorrido = total de andares que o elevador percorreu
*/
typedef struct elevador {
  Andar *andar;
  char estado; // p = parado, d = descendo, s = subindo
  Pessoa *passageiros;
  Rota *rota;
  int percorrido;
} Elevador;

//Coloca as pessoas esperando no andar atual para dentro do elevador
int entrarElevador(Andar **predio, Elevador *elevador);

//Tira as pessoas que estão querendo sair no andar atual do elevador
int sairElevador(Andar **predio, Elevador *elevador);

//Mostra os dados do elevador
int mostrarElevador(Elevador *elevador, int id);

//Verifica se tem alguem chamando o elevador na direção dele
Pessoa *peek(Elevador *elevador, Pessoa **lista);

//adiciona rota do elevador
int addRota(Elevador *elevador,int importante);

//Conta quantas rotas tem no elevador
int contarRota(Elevador *elevador);

//printa as rotas do elevador
void printarRota(Elevador **elevador, unsigned long int ticks,int quantidadeElevadores);

#endif