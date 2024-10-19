#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Predio.h"


int buildPredio(Andar **predio, int quantidadeAndar) {
  for (int i = 0; i < quantidadeAndar; i++) {
    Andar *novoA = malloc(sizeof(Andar));
    novoA->numero = i;
    novoA->pEspera = NULL;
    novoA->ant = NULL;
    novoA->prox = NULL;
    if (!(*predio)) {
      *predio = novoA;
    } else {
      Andar *aux;
      aux = *predio;
      while (aux->prox) {
        aux = aux->prox;
      }
      novoA->ant = aux;
      aux->prox = novoA;
    }
  }
  return 0;
}
Andar *procurarAndar(Andar **predio, int andar) {
  if (!(*predio))
    return NULL;
  Andar *aux;
  aux = *predio;
  while (aux && aux->numero != andar) {
    aux = aux->prox;
  }
  return aux;
}
int mostrarAndar(Andar **predio, int id) {
  if (!(*predio))
    return -1;
  Andar *aux;
  aux = *predio;
  while (aux && aux->numero != id) {
    aux = aux->prox;
  }
  if (!aux || aux->numero != id)
    return -2;
  printf("\nAndar %d\n    Chegaram:%d | Esperando:%d", aux->numero,
         contarPessoas(aux->pEntregues), contarPessoas(aux->pEspera));
  printf("\n");
  return 0;
}
int verificaChamado(Andar *andar) {
  Andar *aux1;
  aux1 = andar->prox;
  int ret = 0;
  Pessoa *auxP;
  auxP = andar->pEspera->prox;
  while (auxP && !((direcao(&andar->pEspera) > 0 && direcao(&auxP) > 0) ||
                   (direcao(&andar->pEspera) < 0 && direcao(&auxP) < 0))) {
    auxP = auxP->prox;
  }
  if (auxP) {
    return 0;
  }
  
  while (aux1 && !aux1->pEspera) {
    if (aux1->pEspera) {
      if ((direcao(&andar->pEspera) > 0 && direcao(&aux1->pEspera) > 0) ||
          (direcao(&andar->pEspera) < 0 && direcao(&aux1->pEspera) < 0)) {

        return -2;
      }
      ret = verificaChamado(aux1);
    }
    aux1 = aux1->prox;
  }
  if (!aux1) {
    return -3;
  }
  if (ret)
    return -4;
  return 0;
}
