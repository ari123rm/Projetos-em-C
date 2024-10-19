#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACIDADE 10
#define PROVAS 5

struct aluno{
	char matricula[20];
	char nome[255];
	float notas[PROVAS];
};
typedef struct aluno aluno;

struct lista {
	int tamanho;
	int cap;
	aluno *dados;
};
typedef struct lista lista;


void init(lista *l){
	(*l).tamanho = 0;
	l->cap = CAPACIDADE;
	l->dados = malloc( (l->cap) * sizeof(aluno));
}


int buscar(lista *l, aluno aluninho){
	int i;
	for(i = 0; i < (*l).tamanho;i++){
		if( !(strcmp(((l->dados)+i)->matricula,aluninho.matricula))){
			return i;
			break;
		}
	}
	return -1;
}

int listarTodos(lista *l){
	printf("\n\nALUNINHOS: ");
	int i;
	for( i = 0 ; i < (*l).tamanho;i++){
		printf("\n{\n");
		printf("matricula :  %s ,\n");
		printf("nome : %s\n", ((l->dados)+i)->nome);
		printf("}\n");
	}
	printf("\n\n");
	return 0;
}
/*
int ordenar(lista *l){
	int i, j;
	aluno temp;
	for(i= 0 ; i < l->tamanho;i++){
		for(j = i ; j < l->tamanho;j++){
			if(strcmp(*((l->dados)+i)->nome, *((l->dados)+j)->nome) >0 ){
				temp = *((l->dados) +j);
				*((l->dados) +j) = *((l->dados) +i);
				*((l->dados)+i)= temp;
			}
		}
	}
	return 0;
}
*/
int inserirAluno(lista *l, aluno aluninho){
	if(buscar( l , aluninho ) == -1){
		strcpy(((l->dados)+(l->tamanho))->matricula, aluninho.matricula);
		strcpy(((l->dados)+(l->tamanho))->nome , aluninho.nome);
		(*l).tamanho++;
		
		return 0;
	}
	return -1;
}
/*
int alterar(lista *l,char *matricula,char *nomeNovo){
	if(buscar( l , matricula ) != -1){
		*((l->dados) + buscar( l , matricula ))->nome = nomeNovo;
		return 0;
	}
	return -1;
}

int excluir(lista *l, char *matricula){
	if(buscar( l , matricula) != -1){
		int i;
		for(i=buscar( l , matricula)+1;i<(*l).tamanho;i++){
			*((l->dados) + i - 1) = *((l->dados) + i);
			
		}
		l->tamanho--;	
		return 0;
	}
	return -1;
}
int inserirComeco(lista *l,char *matriculaNova,char *nomeNovo){
	int i;
	if(buscar( l , matriculaNova ) == -1){
		for(i=l->tamanho+1;i>0; i--){
			*((l->dados) + i) = *((l->dados) + i-1);
		}
		*(l->dados)->matricula = matriculaNova;
		*(l->dados)->nome = nomeNovo;
		(*l).tamanho++;
		return 0;
	}
	return -1;
}
*/
int main(void){
	
	lista listinha;
	init(&listinha);
	int escolhas;
	int num1,num2;
	aluno aluninho;
	printf("BEM VINDO A ALUNINHOS :D\n\n");
	do{
	printf("Digite o que o senhorio deseja fazer com meus alunos lindos :D \n\n");
	printf("1. BUSCAR ALUNO \n2. INSERIR ALUNO \n3. ALTERAR ALUNO \n4. EXCLUIR ALUNO \n5. ORDENAR LISTA DE ALUNOS \n6. MOSTRAR LISTA DE ALUNOS\n7. INSERIR ALUNO NO COMECO\n0. SAIR \nDIGITE SUA ESCOLHA: ");
	scanf("%d",&escolhas);
	switch(escolhas){
		case 1:
			printf("\nSELECIONADO (BUSCAR ALUNO)\n");
			printf("\nDIGITE A MATRICULA DE PESQUISA: ");
			scanf(" %s",aluninho.matricula);
			buscar(&listinha,aluninho) != -1? printf("O Aluno %s foi encontrado no indice %d :D",aluninho.matricula,buscar(&listinha,aluninho)) : printf("O aluno %s NAO foi encontrado na listinha ;-;",aluninho.matricula);
			break;
		case 2:
			printf("\nSELECIONADO (INSERIR ALUNO)\n");
			printf("\nDIGITE A MATRICULA PARA INSERIR: ");
			scanf(" %s",aluninho.matricula);
			printf("\nDIGITE O NOME PARA INSERIR: ");
			scanf(" %s",aluninho.nome);
			inserirAluno(&listinha,aluninho) != -1? printf("O aluno %s foi adicionado na listinha com a matricula %s :D",aluninho.nome, aluninho.matricula) : printf("O aluno %s com a matricula %s NAO foi adicionado na listinha ;-;",aluninho.nome, aluninho.matricula);
			break;
		/*
		case 3:
			printf("\nSELECIONADO (ALTERAR ALUNO)\n");
			printf("\nDIGITE O VALOR QUE SERA ALTERADO: ");
			scanf("%d",&num1);
			printf("\nDIGITE O VALOR NOVO: ");
			scanf("%d",&num2);
			alterar(&listinha,num1,num2) != -1? printf("O valor %d foi substituido pelo %d na listinha :D",num1,num2) : printf("O valor %d NAO foi substituido na listinha ;-;",num1);
			break;
	
		case 4:
			printf("\nSELECIONADO (EXCUIR ALUNO)\n");
			printf("\nDIGITE O VALOR QUE SERA EXCLUIDO: ");
			scanf("%d",&num1);
			excluir(&listinha,num1) != -1? printf("O valor %d foi excluido na listinha :D",num1) : printf("O valor %d NAO foi excluido na listinha ;-;",num1);
			break;
		case 5:
			printf("\nSELECIONADO (ORDENAR LISTINHA DE ALUNOS)\n");
			ordenar(&listinha) == 0? printf("Listinha ordenada com sucesso :D") : printf("A listinha NAO foi ordenada ;-;");
			break;
		*/
		case 6:
			listarTodos(&listinha);
			break;
		/*
		case 7:
			printf("\nSELECIONADO (INSERIR ALUNO NO COMECO)\n");
			printf("\nDIGITE A MATRICULA PARA INSERIR: ");
			scanf(" %s",matricula);
			printf("\nDIGITE O NOME PARA INSERIR: ");
			scanf(" %s",nome);
			inserirComeco(&listinha,&matricula,&nome) != -1? printf("O valor %d foi adicionado na listinha :D",num1) : printf("O valor %d NAO foi adicionado na listinha ;-;",num1);
		*/
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
