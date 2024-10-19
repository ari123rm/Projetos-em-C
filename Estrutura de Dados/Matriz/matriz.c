#include <stdio.h>
#include <stdlib.h>

typedef struct matriz {
    int **data;
    int linhas;
    int colunas;
}Matriz;
int iniciar(Matriz **matriz) {
    *matriz= malloc(sizeof(Matriz));
    printf("Numero de linhas: \n");
    scanf("%d",&((*matriz)->linhas));
    printf("Numero de colunas: \n");
    scanf("%d",&((*matriz)->colunas));


    (*matriz)->data = malloc((*matriz)->linhas *sizeof(int*));
    for(int i = 0; i < (*matriz)->linhas; i++) {
        *((*matriz)->data + i) = malloc((*matriz)->colunas *sizeof(int));
    }
    // Preenchendo a matriz com valores
    printf("Digite os valores para a matriz:\n");
    for (int i = 0; i < (*matriz)->linhas; i++) {
        for (int j = 0; j < (*matriz)->colunas; j++) {
            printf("Elemento [%d][%d]:\n ", i, j);
            scanf("%d", ((*matriz)->data + i * (*matriz)->colunas + j) );
        }
    }
}
int main(void) {
    Matriz *matriz;
    iniciar(&matriz);
    // Exibindo a matriz
    printf("\nMatriz inserida:\n");
    for (int i = 0; i < matriz->linhas; i++) {
        for (int j = 0; j < matriz->colunas; j++) {
            printf("%d ", *(matriz->data + i * matriz->colunas + j));
        }
        printf("\n");
    }

    for(int i =0;i<matriz->linhas;i++) {
        for(int j = 0 ; j<matriz->colunas;j++) {
            free(matriz->data + i * matriz->colunas + j);
        }
    }
    return 0;
}