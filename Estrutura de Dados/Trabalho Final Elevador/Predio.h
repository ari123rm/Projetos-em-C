#ifndef PREDIO_H
#define PREDIO_H

#define maxAndar 25
#define minAndar 5

#include "Pessoa.h"

/*
 *  Estrutura de dados para armazenar os dados do andar
 * numero = numero do andar
 * pEspera = lista de pessoas esperando para entrar no elevador
 * pEntregues = lista de pessoas que foram entregues pelo elevador no andar
 * ant = ponteiro para o andar anterior
 * prox = ponteiro para o proximo andar
*/
typedef struct andar {
  int numero;
  Pessoa *pEspera;
  Pessoa *pEntregues;
  struct andar *prox;
  struct andar *ant;
} Andar;


//Aloca todos os andares e adiciona numa lista duplamente cadeada
int buildPredio(Andar **predio, int quantidadeAndar);

//Procura o andar pelo numero e devolve um ponteiro para o andar
Andar *procurarAndar(Andar **predio, int andar) ;

//Mostra os dados atuais do andar pelo numero
int mostrarAndar(Andar **predio, int id);

//Verifica se o andar esta vazio
int verificaChamado(Andar *andar);



#endif