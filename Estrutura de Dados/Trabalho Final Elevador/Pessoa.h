#ifndef PESSOA_H
#define PESSOA_H


/*
 *  Estrutura de dados para armazenar os dados da pessoa
 * id = identificação da pessoa
 * tick = tick em que a pessoa será introduzida no andar
 * andarEnt = andar que a pessoa entrou
 * andarSai = andar que a pessoa quer ir
 *
*/

typedef struct pessoa {
  char id[5];
  int tick;
  int andarEnt;
  int andarSai;
  struct pessoa *prox;
} Pessoa;


//Indica a direção da pessoa (negativo= desce; positivo= sobe)
int direcao(Pessoa **pessoa);

//Conta a quantidade de pessoas na lista
int contarPessoas(Pessoa *lista);

//Transfere a pessoa da lista 2 para a lista 1
int transferir(Pessoa **lista1, Pessoa **lista2, Pessoa *pessoa);

//adiciona uma pessoa na lista 
int addPessoa(Pessoa **fila,int andarEnt, int andarSai, int tick, char id[4]);



#endif