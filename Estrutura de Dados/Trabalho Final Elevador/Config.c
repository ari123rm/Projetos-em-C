#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Config.h"

int buildElevador(Andar **predio, Elevador *elevador, Config **config,char estado,int andarInicial) {
  if (!(*predio))return -1;
    elevador->andar = procurarAndar(predio, andarInicial);
    elevador->estado = estado;
    elevador->passageiros = NULL;
    elevador->rota = NULL;
    elevador->percorrido = 0;
  return 0;
}
int chamadoElevador(Andar **predio, Elevador *elevador,Elevador **listaElevadores, Config **config) {
  if (!(*predio))
    return -1;
  if (!(elevador))
    return -2;
  if (elevador->passageiros) {
    return -3;
  }
  Andar *aux;
  aux = *predio;
  int verificador;
  do{
    verificador = 0;
    while(aux && !aux->pEspera) { 
      aux = aux->prox;
    }
    if(aux){
      for (int i = 0; i < (*config)->elevadores; i++) {
        if (abs(aux->numero - (*listaElevadores + i)->andar->numero) < abs(aux->numero - elevador->andar->numero) || (*config)->economico) { // se tirar esse if o codigo entra em modo economico dos elevadores
          switch((*listaElevadores + i)->estado){
            case 'S':
              if(aux->numero >= (*listaElevadores + i)->andar->numero){
                 aux= aux->prox;
                 verificador = 1;
              }
            break;
            case 'D':
              if(aux->numero <= (*listaElevadores + i)->andar->numero){
                aux= aux->prox;
                verificador = 1;
              }
            break;
          }
        }
      }
    }
  }while(verificador);
  
  if (aux){ 
    if (aux->numero >= 0) {
      if (aux->numero - elevador->andar->numero == 0) {
        elevador->estado = direcao(&(aux->pEspera)) > 0? 'S':'D';
      } else {
        if (aux->numero - elevador->andar->numero > 0) {
          elevador->estado = 'S';
        } else {
          elevador->estado = 'D';
        }
      }
    }
    return 0;
  }
  return -6;
}
int estadoElevador(Andar **predio, Elevador *elevador, Elevador **listaElevador,  Config **config) {
  if (!(*predio))
    return -1;
  if (!(elevador))
    return -2;
  switch (elevador->estado) {
    case 'P':
      if (elevador->passageiros) {
        if (direcao(&(elevador->passageiros)) < 0) {
          elevador->estado = 'D';
        } else {
          elevador->estado = 'S';
        }
      } else {
        chamadoElevador(predio, elevador, listaElevador, config);
      }
      break;
    case 'D':
      if (!elevador->passageiros) {
        if (chamadoElevador(predio, elevador, listaElevador, config) != 0)
          elevador->estado = 'P';
      }
      break;
    case 'S':
      if (!elevador->passageiros) {
        if (chamadoElevador(predio, elevador, listaElevador, config) != 0)
          elevador->estado = 'P';
      }
      break;
  }
  return 0;
}
void iniciar(Andar **predio, Config **config, Pessoa **fila,  Elevador **elevador) {
  *predio = NULL;
  *config = NULL;
  *fila = NULL;
  *elevador = NULL;
}
void buildConfig(Config **config) {
  *config = malloc(sizeof(Config));
  (*config)->elevadores = 0;
}
int mensagem(Andar **predio, Config **config, Pessoa **fila,unsigned long int tick) {
  if (!(*predio))
    return -1;
  if (!(*config))
    return -2;
  if (!(*fila))
    return -3;
  while((*fila)->tick == tick ){
    transferir(&procurarAndar(predio,(*fila)->andarEnt)->pEspera, fila, *fila);
    if (!(*fila)) return -4;
  }
  return 0;
}

int moverElevador(Andar **predio, Elevador *elevador, Config **config) {
  if (!(*predio))
    return -2;
  if (!(elevador))
    return -3;

  switch (elevador->estado) {
  case 'P':
    return 0;
    break;
  case 'D':
    if (elevador->andar->numero == 0) {
      return 0;
    }
    elevador->andar = elevador->andar->ant;
    return -1;
    break;
  case 'S':
    if (elevador->andar->numero == (*config)->andares - 1) {
      return 0;
    }
    elevador->andar = elevador->andar->prox;
    return 1;
    break;
  }
  return 0;
}
int tick(Andar **predio, Elevador **elevador, Config **config) {
  if (!(*predio))
    return -1;
  if (!(*elevador))
    return -2;
  if (!(*config))
    return -3;
  int retornos[3];
  for(int i = 0;i<3;i++){
    retornos[i] = 0;
  }
  int tickImportante = 1; // 1 para importante, 0 para não important
  for (int i = 0; i < (*config)->elevadores; i++) {
    
    
    retornos[0] = sairElevador(predio, (*elevador + i));
    retornos[1] = estadoElevador(predio, (*elevador + i), elevador, config);
    retornos[2] = entrarElevador(predio, (*elevador + i));
    
    tickImportante = 0;
    for(int j = 0 ; j < 3 ; j++){
      if(retornos[j] > 0){
        tickImportante = 1;
      }
    }  
    addRota((*elevador + i), tickImportante);
    
    
    moverElevador(predio, (*elevador + i), config);
    
   
  }

  return 0;
}
int addPessoaElevador(Elevador *elevador, int andar, Config **config) {
  if (!elevador)
    return -1;
  if (andar > (*config)->andares || andar < 0) {
    return -2;
  }
  Pessoa *novaP = malloc(sizeof(Pessoa));
  novaP->andarEnt = elevador->andar->numero;
  novaP->andarSai = andar;
  novaP->tick = 0;
  novaP->prox = NULL;
  if (!elevador->passageiros) {
    elevador->passageiros = novaP;
    return 0;
  }
  Pessoa *aux;
  aux = elevador->passageiros;
  while (aux->prox) {
    aux = aux->prox;
  }
  aux->prox = novaP;
  return 1;
}
int addPessoaAndar(Andar **predio, int andarEnt, int andarSai, int tick,Config **config) {
  if (!(*predio))
    return -1; // predio nao existe
  if (andarEnt > (*config)->andares || andarEnt < 0 ||
      andarSai > (*config)->andares || andarSai < 0)
    return -2; // andar nao existe
  if (andarEnt == andarSai)
    return -3; // andar de entrada e saida iguais
  Pessoa *novoP = malloc(sizeof(Pessoa));
  novoP->andarEnt = andarEnt;
  novoP->andarSai = andarSai;
  novoP->tick = tick;
  novoP->prox = NULL;

  Andar *auxA;
  auxA = *predio;
  while (auxA->prox && auxA->numero != andarEnt) {
    auxA = auxA->prox;
  }
  if (auxA->numero != andarEnt) {
    free(novoP);
    return -4; // andar nao encontrado
  }
  if (!auxA->pEspera) {
    auxA->pEspera = novoP;
    return 0;
  }
  Pessoa *auxP;
  auxP = auxA->pEspera;
  while (auxP->prox) {
    auxP = auxP->prox;
  }
  auxP->prox = novoP;
  return 1;
}
int programaParado(Elevador **elevador, Config **config) {
  if (!(*elevador))
    return -1;
  for (int i = 0; i < (*config)->elevadores; i++) {
    if ((*elevador)[i].estado != 'P') {
      return 0;
    }
  }
  return 1;
}
int processarString(char string[stringTam], Andar **predio, Elevador **elevador,Config **config, Pessoa **fila){
  *elevador = malloc(sizeof(Elevador) * maxElevador);
  buildConfig(config);
  
  char *token = strtok(string, " ");
  char *interno;
  char **matriz;
  matriz = malloc(sizeof(char*) * stringTam);
  for(int i = 0; i < stringTam; i++){
    matriz[i] = malloc(sizeof(char) * stringTam);
  }
  int andarInicial,andarSaida,idElevador,Ptick,ent,sai;
  char estado;
  char id[4];
  int cont = 0;
  while (token != NULL){
    strcpy(matriz[cont],token);
     
    
    token = strtok(NULL, " ");
    cont++;
  }
 for(int i = 0; i< cont;i++){
    
    interno = strtok(matriz[i], "_");
   
   
    if (strcmp(interno, "AM") == 0){
      
      interno = strtok(NULL, "_");
      if(atoi(interno) > maxAndar || atoi(interno) < minAndar) return -1;
      (*config)->andares = atoi(interno) + 1 ;
      
      buildPredio(predio, (*config)->andares);
    }else{
      if(interno[0] == 'E'){
        idElevador = atoi(interno +  1) - 1;
        if(idElevador > maxElevador) return - 20 - idElevador - 1;
        interno = strtok(NULL, "_");
        
        andarInicial = interno[0] == 'T'? 0 : atoi(interno);
        if(andarInicial >= (*config)->andares || andarInicial < 0) return - 10 - idElevador - 1;
        interno = strtok(NULL, "_");
        estado = *interno;
        interno = strtok(NULL, "_");
        buildElevador(predio, (*elevador + idElevador), config, estado, andarInicial);
        interno = strtok(interno, ",");
        while(interno){
          andarSaida = interno[0] == 'T'? 0 : atoi(interno);
          if(andarSaida >= (*config)->andares || andarSaida < 0) return - 10 - idElevador - 1;
          if(estado == 'D' && andarSaida > andarInicial) return - 10 - idElevador - 1;
          if(estado == 'S' && andarSaida < andarInicial) return - 10 - idElevador - 1;
          addPessoaElevador((*elevador + idElevador), andarSaida ,config);
          interno = strtok(NULL, ",");
        }
        (*config)->elevadores++;
      }else{
        Ptick = atoi(interno + 1);
        interno = strtok(NULL, "_");
        strcpy(id,interno);
        interno = strtok(NULL, "_");
        interno = strtok(NULL, "_");
        ent = interno[0] == 'T'? 0 : atoi(interno);
        if(ent >= (*config)->andares || ent < 0) return - 1000000 - (Ptick*1000) - atoi(id + 1);
        interno = strtok(NULL, "_");
        sai = interno[0] == 'T'? 0 : atoi(interno);
        if(sai >= (*config)->andares || sai < 0) return - 1000000 - (Ptick*1000) - atoi(id + 1);
        addPessoa(fila, ent, sai,Ptick,id);
      }
    }
  }
  if(!(*predio) || !(*config) || !(*elevador)) return -3;
  printf("\n");
  return 0;
}

int fim(Andar **predio, Elevador **elevador, Config **config, Pessoa **fila){
  int retorno = 0;
  Andar *auxA;
  Pessoa *auxP;
  Elevador *auxE;
  Rota *auxR;
  if((*predio)){
    auxA = *predio;
    while(auxA){
      auxP = auxA->pEspera;
      while(auxP){
        auxA->pEspera = auxP->prox;
        free(auxP);
        auxP = auxA->pEspera;
      }
      auxP = auxA->pEntregues;
      while(auxP){
        auxA->pEntregues = auxP->prox;
        free(auxP);
        auxP = auxA->pEntregues;
      }
      *predio = auxA->prox;
      free(auxA);
      auxA = *predio;
    }
    retorno += 1;
  }
  if((*elevador)){
    for(int i = 0; i< (*config)->elevadores;i++){
      auxE = (*elevador + i);
      auxP = auxE->passageiros;
      while(auxP){
        auxE->passageiros = auxP->prox;
        free(auxP);
        auxP = auxE->passageiros;
      }
      auxR = auxE->rota;
      while(auxR){
        auxE->rota = auxR->prox;
        free(auxR);
        auxR = auxE->rota;
      }
    }
    free(*elevador);
    retorno += 2;
  }
  if((*config)){
    free(*config);
    retorno += 4;
  };
  if((*fila)){
    auxP = *fila;
    while(auxP){
      *fila = auxP->prox;
      free(auxP);
      auxP = *fila;
    }
    retorno += 8;
  };
  iniciar(predio, config, fila, elevador);
  return retorno;
}
int mostrarPredio(Andar **predio, Elevador **elevador, Config **config,Pessoa **fila) {
  if (!(*predio))
    return -1;
  if (!(*config))
    return -2;
  if (!elevador)
    return -3;
  for(int i = 0; i < (*config)->andares; i++){
    mostrarAndar(predio, i);
  }
  printf("\n");
  for (int i = 0; i < (*config)->elevadores; i++) {
    mostrarElevador((*elevador) + i, i + 1);
  }
  printf("\nFila: %d\n",contarPessoas(*fila));
  return 0;
}