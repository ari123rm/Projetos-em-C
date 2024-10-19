#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Elevador.h"

int entrarElevador(Andar **predio, Elevador *elevador) {
  if (!(*predio))
    return -1;
  if (!(elevador))
    return -2;
  Pessoa *aux;
  int entrou = 0;
  do {
    aux = peek(elevador, &elevador->andar->pEspera);
    if (aux) {
      transferir(&(elevador->passageiros), &elevador->andar->pEspera, aux);
      entrou++;
    }
  } while (aux);
  if(entrou>0)return entrou;
  return 0;
}

int sairElevador(Andar **predio, Elevador *elevador) {
  if (!(*predio))
    return -1;
  if (!(elevador))
    return -2;
  if (!elevador->passageiros)
    return -3;
  Pessoa *aux, *aux1;
  aux = elevador->passageiros;
  int saiu = 0;
  while (aux) {
    if (aux->andarSai == elevador->andar->numero) {
      aux1 = aux->prox;
      transferir(&elevador->andar->pEntregues, &elevador->passageiros, aux);
      saiu++;
      aux = aux1;
    } else {
      aux = aux->prox;
    }
  }
  if(saiu>0){
    return saiu;
  }
  return 0;
}
int mostrarElevador(Elevador *elevador, int id) {
  if (!elevador)
    return -1;
  printf("\nElevador %d", id);
  printf("\n  Andar: %d | Passageiros: %d | Estado: %c | Percorrido: %d |\n  Passageiros: ",
         elevador->andar->numero, contarPessoas(elevador->passageiros),
         elevador->estado, elevador->percorrido);
  Pessoa *aux;
  aux = elevador->passageiros;
  while (aux) {
    printf("%d -> %d |", aux->andarEnt, aux->andarSai);
    aux = aux->prox;
  }
  printf("\n");
  return 0;
}
int addRota(Elevador *elevador, int importante){
  Rota *aux;
  
  Rota *novoR = malloc(sizeof(Rota));
  novoR->andar = elevador->andar->numero;
  novoR->prox = NULL;
  novoR->importante = importante;
  if(!elevador)return -1;
  if(!elevador->rota){
    elevador->rota = novoR;
    return 1;
  }
  
  aux = elevador->rota;
  while(aux->prox){
    aux = aux->prox;
  }
  if(aux->andar != elevador->andar->numero){
     elevador->percorrido++;
  }   
   aux->prox = novoR;
  return -2;
}
int contarRota(Elevador *elevador){
  if(!elevador)return -1;
  Rota *aux;
  aux = elevador->rota;
  int cont = 0;
  while(aux){
    cont++;
    aux = aux->prox;
  }
  return cont;
}
void printarRota(Elevador **elevador,unsigned long int ticks,int quantidadeElevadores){
  int soma = 0;
  for(int j = 0; j < quantidadeElevadores;j++){
    if((*elevador + j)){
      Rota *auxR;
      auxR = (*elevador +j)->rota;
      if(auxR) {
        printf("\nROTA DO ELEVADOR %d: \n", j+1);
        printf("\n");
        int i = -1;
        while(auxR){
          i++;
          if(auxR->importante || i == 0  || i == ticks){
            auxR->andar == 0 ? printf(" T(%d) -> ",i):printf(" %d(%d) -> ", auxR->andar,i);
          }
          auxR = auxR->prox;
        }
        printf("\n");
        printf("\nTempo de deslocamento do elevador %d: %d\n",j+1,i);
        printf("Numero de andares percorrido pelo elevador %d: %d\n",j+1,(*elevador +j)->percorrido);
        soma += (*elevador +j)->percorrido;
      }
    }
  }
  printf("\nRESUMO DO CONJUNTO DE ELEVADORES: \n");
  printf("\nNumero de andares percorridos: %d\n",soma);
  printf("Tempo de deslocamento total: %ld\n",ticks);
}
Pessoa *peek(Elevador *elevador, Pessoa **lista) {
  if (!(*lista))
    return NULL; // lista vazia
  Pessoa *aux;
  aux = *lista;
  switch (elevador->estado) {
  case 'P':
    if (direcao(&aux) > 0) {
      elevador->estado = 'S';
    } else {
      elevador->estado = 'D';
    }
    return aux;
    break;
  case 'D':
    while (aux && direcao(&aux) > 0) {
      aux = aux->prox;
    }
    return aux;
    break;
  case 'S':
    while (aux && direcao(&aux) < 0) {
      aux = aux->prox;
    }
    return aux;
    break;
  default:
    return NULL;
    break;
  }
}

