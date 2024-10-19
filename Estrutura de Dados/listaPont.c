#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
    struct no *ant;
}No;

void iniciar(No **lista){
    *lista = NULL;
}

int inserir_comeco(No **lista, int valor) {
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;
    if(!(*lista)) {
        *lista = novo;
        return 0;
    }else {
        novo->prox = *lista;
        (*lista)->ant = novo;
        *lista = novo;
        return 1;
    }
    return -1;
}
int inserir_final(No **lista, int valor) {
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;
    if(!(*lista)) {
        *lista = novo;
        return 0;
    }else {
        No *aux;
        aux = *lista;
        while(aux->prox) {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->ant = aux;
        return 1;
    }
    return -1;
}

int remover(No **lista, int valor) {
    No *aux;
    aux = *lista;
    if(!(*lista)) {
        free(*lista);
        return 0;
    }
    while(aux->prox && aux->valor != valor) {
        aux = aux->prox;
    }
    if(aux->valor == valor) {
        if(aux->ant) {
            aux->ant->prox = aux->prox ;
        }else {
            *lista = aux->prox;
        }
        if(aux->prox)aux->prox->ant = aux->ant;
        free(aux);
        return 1;
    }else {
        return -1;
    }
}

int inserir_ordenado(No **lista,int valor) {
    No *novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;
    if(!(*lista)) {
        *lista = novo;
        return 0;
    }
    No *aux;
    aux = *lista;
    while(aux->prox && aux->valor <= valor) {
        aux = aux->prox;
    }
    if(!(aux->ant) && aux->valor > valor) {
        novo->prox = *lista;
        (*lista)->ant = novo;
        *lista = novo;
        return 1;
    }
    if(!(aux->prox) && aux->valor <= valor) {
        aux->prox = novo;
        novo->ant = aux;
        return 2;
    }
    aux->ant->prox = novo;
    novo->ant = aux->ant;
    aux->ant = novo;
    novo->prox = aux;
    return 3;

}
int listar(No **lista) {
    No *aux;
    aux = *lista;
    if(!(*lista)) {
        printf("Lista vazia\n");
        return 0;
    }
    printf("\n");
    printf("[ ");
    while(aux) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf(" ] ");
    return 1;
}

int main(void) {
    No *lista;
    iniciar(&lista);
    int resultado,valor;
    do {
        printf("\nLista COM PONTEIRO :D\n\n");
        printf("ESCOLHAS:\n 1-ADD COMECO\n 2-ADD FINAL\n 3-REMOVER\n 4-ADD ORDENADO\n 5-Listar\n"
               " 9-SAIR\n\nDIGITE: ");
        scanf("%d", &resultado);
        switch (resultado) {
            case 1:

                printf("Valor a ser inserido:");
                scanf("%d",&valor);
                inserir_comeco(&lista,valor);
            break;
            case 2:

                printf("Valor a ser inserido:");
                scanf("%d",&valor);
                inserir_final(&lista,valor);
            break;
            case 3:

                printf("Valor a ser removido:");
                scanf("%d",&valor);
                remover(&lista,valor);
            break;
            case 4:
                printf("Valor a ser inserido:");
                scanf("%d",&valor);
                inserir_ordenado(&lista,valor);
            break;
            case 5:
                listar(&lista);
                break;
            case 9:
                resultado = -1;
            break;
            default:
                printf("Resultado INVALIDO\n\n");
            break;
        }

    } while (resultado != -1);
    while (lista != NULL) {
        remover(&lista,lista->valor);
    }
    printf("\nFIM DO PROGRAMA\n");
    return 0;
}