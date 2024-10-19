#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pessoa.h"
int direcao(Pessoa **pessoa) {
  return (*pessoa)->andarSai - (*pessoa)->andarEnt;
}


int contarPessoas(Pessoa *lista) {
  int cont = 0;
  Pessoa *aux;
  aux = lista;
  if (!(lista))
    return 0;
  while (aux) {
    aux = aux->prox;
    cont++;
  }
  return cont;
}

int transferir(Pessoa **lista1, Pessoa **lista2, Pessoa *pessoa) {
  if (!(*lista2))
    return -1; // lista vazia
  if (!pessoa)
    return -2; // pessoa nao existe
  Pessoa *aux;
  aux = *lista2;
  if (!(aux->prox)) {
    *lista2 = NULL;
    pessoa->prox = NULL;
    aux->prox = *lista1;
    *lista1 = aux;
    return 0;
  }
  if (aux == pessoa) {
    *lista2 = aux->prox;
    pessoa->prox = NULL;
    aux->prox = *lista1;
    *lista1 = aux;
    return 0;
  }
  while (aux->prox && aux->prox != pessoa) {
    aux = aux->prox;
  }
  if (aux == pessoa) {
    *lista2 = aux->prox;
    aux->prox = pessoa->prox;
    pessoa->prox = *lista1;
    *lista1 = pessoa;
    return 1;
  }
  aux->prox = aux->prox->prox;
  pessoa->prox = *lista1;
  *lista1 = pessoa;
  return 2;
}



int addPessoa(Pessoa **fila,int andarEnt, int andarSai, int tick, char id[4]){
  Pessoa *novoP = malloc(sizeof(Pessoa));
  novoP->andarEnt = andarEnt;
  novoP->andarSai = andarSai;
  novoP->tick = tick;
  strcpy(novoP->id, id);
  novoP->prox = NULL;
  if(!(*fila)){
    *fila = novoP;
    return 0;
  }
  Pessoa *aux;
  aux = *fila;
  while(aux->prox){
    aux = aux->prox;
  }
  aux->prox = novoP;
  return 1;
}



