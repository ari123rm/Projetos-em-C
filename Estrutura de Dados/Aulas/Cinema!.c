#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct sdados{
	char matricula[30];
	char nome[255];
	char fone[15];
	float notas[3];
};
struct no{
	struct sdados dados;
	struct no *prox;
};
typedef struct no no;

void init(no **data){
	*data = malloc(sizeof(no));
	
}

void mostrarAluno(no **local){
	
	printf(" Aluno:\n Matricula: %s\n  Nome: %s\n  Telefone: %s\n  Notas: [%.2f |%.2f |%.2f]\n\n",(*local)->dados.matricula,(*local)->dados.nome,(*local)->dados.fone,(*local)->dados.notas[0],(*local)->dados.notas[1],(*local)->dados.notas[2]);
}

int criarAluno(no **data){
	if(data != NULL){
		char stringEntrada[255];
		float nota;
		printf("\nDigite a Matricula: ");
		scanf(" %s", &stringEntrada);
		strcpy((*data)->dados.matricula,stringEntrada);
		printf("\nDigite o Nome: ");
		scanf(" %s", &stringEntrada);
		strcpy((*data)->dados.nome,stringEntrada);
		printf("\nDigite o Numero de Telefone: ");
		scanf(" %s", &stringEntrada);
		strcpy((*data)->dados.fone,stringEntrada);
		int i;
		for( i= 0;i<3;i++){
		printf("\nDigite a %d nota: ",i+1);
		scanf(" %f",&nota);
		(*data)->dados.notas[i] = nota;
		}
		(*data)->prox = NULL;
		mostrarAluno(data);
		return 0;
	}else{
		return -1;
	}
	
}



int mostrarLista(no **data){
	if(data != NULL){
		no *aux = NULL;
		aux = malloc(sizeof(no));
		aux->prox = *data;
		int cont = 0;
		do{
			printf("\nALUNO %d: \n",++cont);
			mostrarAluno(&(aux->prox));
			aux = aux->prox;
			printf("\n\n");
		}while(aux->prox != NULL);
		return 0;
	}else{
		return -1;
	}
	
}

int inserirFinal(no **data){
	if(*data != NULL){
		no *aux = *data;
	
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = malloc(sizeof(no));
		criarAluno(&(aux->prox));
		free(aux);
		return 0;
	}else{
		init(data);
		criarAluno(data);
		return 0;
	}
	return -1;
}

int tamanho(no **data){
	if(*data != NULL){
	
		int cont = 1;
		
		no *aux = *data;
		
		while(aux->prox != NULL){
			aux = aux->prox;
			cont++;
		}
		return cont;
	}else{
		return -1;
	}
}

int inserirComeco(no **data){
	if(*data != NULL){
		no *novo = NULL;
		novo = malloc(sizeof(no));
		criarAluno(&novo);
		(novo->prox) = *data;
		*data = novo;
		free(novo);
		return 0;
	}else{
		init(data);
		criarAluno(data);
		return 0;
		
	}	
	return -1;
}

int buscarAluno(no **data){
	
}
int main(void){
	int escolha;
	no *local = NULL;
	printf("BEM VINDO AO BANCO DE DADOS DOS ALUNOS!\n");
	/*
		local = malloc(sizeof(no));
		printf("\nVejo que nao tem nenhum aluno... \nEntao vamos criar o primeiro :D\n");
		criarAluno(local);
	*/
	do{
		printf("\nEscolha o que deseja fazer no seu banco de dados\n");
		printf("1.Buscar com matricula\n2.Inserir no FINAL da lista\n3.Inserir no COMECO da lista\n4.Editar Aluno\n5.Mostrar Tamanho\n6.Remover Aluno\n7.Mostrar Lista\n9.Sair\n\nESCOLHA: ");
		scanf("%d",&escolha);
		switch(escolha){
			case 1:
				buscarAluno(&local);
				break;
			case 2:
				inserirFinal(&local)?printf("\nNao consegui adicionar o aluno(veja se a lista foi iniciada!)\n"):printf("\nAluno adicionado com sucesso!\n");
				break;
			case 3:
				inserirComeco(&local)?printf("\nNao consegui adicionar o aluno!\n"):printf("\nAluno adicionado com sucesso!\n");
				break;
			case 4:
				
				break;
			case 5:
				tamanho(&local)?printf("\nLISTA VAZIA\n"):printf("\nTAMANHO DA LISTA: %d\n",tamanho(&local));
				break;
			case 6:
				
				break;
			case 7:
				mostrarLista(&local)?printf("\nNao consegui mostrar lista\n"):printf("\n");
				break;
			case 9:
				printf("\nFIM DO PROGRAMA\n");
				break;
			default:
				printf("\nESCOLHA INVALIDA\n");
				break;
		}
	}while(escolha != 9);
	free(local);
	
	
	
	
	return 0;
}
