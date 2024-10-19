#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACIDADE 10

struct lista {
	int tamanho;
	int cap : CAPACIDADE;
	int *dados;
};

typedef struct lista lista;

void init(lista *l){
	(*l).tamanho = 0;
	l->dados = malloc(10 * sizeof(int));
}

int buscar(lista *l, int value){
	int i;
	for(i = 0; i < (*l).tamanho;i++){
		if(*((l->dados)+i)== value){
			return i;
			break;
		}
	}
	return -1;
}

int listarTodos(lista *l){
	printf("\n\nLISTINHA: ");
	int i;
	for( i = 0 ; i < (*l).tamanho;i++){
		printf("%d ", *((l->dados)+i));
	}
	printf("\n\n");
	return 0;
}

int ordenar(lista *l){
	int i, j,temp ;
	for(i= 0 ; i < l->tamanho;i++){
		for(j = i ; j < l->tamanho;j++){
			if(*((l->dados)+i) > *((l->dados)+j)){
				temp = *((l->dados) +j);
				*((l->dados) +j) = *((l->dados) +i);
				*((l->dados)+i)= temp;
			}
		}
	}
	return 0;
}

int inserir(lista *l, int value){
	if(buscar( l , value ) == -1){
		*(l->dados + l->tamanho) = value;
		(*l).tamanho++;
		return 0;
	}
	return -1;
}

int alterar(lista *l,int valorAntigo,int valorNovo){
	if(buscar( l , valorAntigo ) != -1){
		*((l->dados) + buscar( l , valorAntigo )) = valorNovo;
		return 0;
	}
	return -1;
}

int excluir(lista *l, int value){
	if(buscar( l , value) != -1){
		int i;
		for(i=buscar( l , value)+1;i<(*l).tamanho;i++){
			*((l->dados) + i - 1 ) = *((l->dados) + i);
			
		}
		l->tamanho--;	
		return 0;
	}
	return -1;
}
int inserirComeco(lista *l,int value){
	int i;
	if(buscar( l , value ) == -1){
		for(i=l->tamanho+1;i>0; i--){
			*((l->dados) + i) = *((l->dados) + i-1);
		}
		*(l->dados) = value;
		(*l).tamanho++;
		return 0;
	}
	return -1;
}

int main(void){
	
	lista listinha;
	init(&listinha);
	int escolhas;
	int num1,num2;
	printf("BEM VINDO A LISTINHA :D\n\n");
	do{
	printf("Digite o que o senhorio deseja fazer com minha listinha linda :D \n\n");
	printf("1. BUSCAR VALOR \n2. INSERIR VALOR \n3. ALTERAR VALOR \n4. EXCLUIR VALOR \n5. ORDENAR LISTA \n6. MOSTRAR LISTA\n7. INSERIR NO COMECO\n0. SAIR \nDIGITE SUA ESCOLHA: ");
	scanf("%d",&escolhas);
	switch(escolhas){
		case 1:
			printf("\nSELECIONADO (BUSCAR VALOR)\n");
			printf("\nDIGITE O VALOR DE PESQUISA: ");
			scanf("%d",&num1);
			buscar(&listinha,num1) != -1? printf("O valor %d foi encontrado no indice %d :D",num1,buscar(&listinha,num1)) : printf("O valor %d NAO foi encontrado na listinha ;-;",num1);
			break;
		case 2:
			printf("\nSELECIONADO (INSERIR VALOR)\n");
			printf("\nDIGITE O VALOR PARA INSERIR: ");
			scanf("%d",&num1);
			inserir(&listinha,num1) != -1? printf("O valor %d foi adicionado na listinha :D",num1) : printf("O valor %d NAO foi adicionado na listinha ;-;",num1);
			break;
		case 3:
			printf("\nSELECIONADO (ALTERAR VALOR)\n");
			printf("\nDIGITE O VALOR QUE SERA ALTERADO: ");
			scanf("%d",&num1);
			printf("\nDIGITE O VALOR NOVO: ");
			scanf("%d",&num2);
			alterar(&listinha,num1,num2) != -1? printf("O valor %d foi substituido pelo %d na listinha :D",num1,num2) : printf("O valor %d NAO foi substituido na listinha ;-;",num1);
			break;
		case 4:
			printf("\nSELECIONADO (EXCUIR VALOR)\n");
			printf("\nDIGITE O VALOR QUE SERA EXCLUIDO: ");
			scanf("%d",&num1);
			excluir(&listinha,num1) != -1? printf("O valor %d foi excluido na listinha :D",num1) : printf("O valor %d NAO foi excluido na listinha ;-;",num1);
			break;
		case 5:
			printf("\nSELECIONADO (ORDENAR LISTINHA)\n");
			ordenar(&listinha) == 0? printf("Listinha ordenada com sucesso :D") : printf("A listinha NAO foi ordenada ;-;");
			break;
		case 6:
			listarTodos(&listinha);
			break;
		case 7:
			printf("\nSELECIONADO (INSERIR NO COMECO)\n");
			printf("\nDIGITE O VALOR PARA INSERIR: ");
			scanf("%d",&num1);
			inserirComeco(&listinha,num1) != -1? printf("O valor %d foi adicionado na listinha :D",num1) : printf("O valor %d NAO foi adicionado na listinha ;-;",num1);
		case 0:
			printf("\nADEUS :D");
			break;
		default:
			printf("\nVALOR INVALIDO ;-; TENTE NOVAMENTE");
			break;
	}
	printf("\n\n");
		
	}while(escolhas != 0);
	
	
	
	return 0;
}
