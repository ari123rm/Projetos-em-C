#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <string.h>

typedef struct sudoku{
	int **jogador;
	int **resposta;
	int dificuldade;
	int erros;
	int pontos;
}Sudoku;

typedef struct user{
	char nome[255];
	int pontuacaoMax;
}User;

void init(Sudoku **jogo,User **usuario){

	*jogo = NULL;
	*usuario = NULL;
}

int iniciar(Sudoku **jogo, int dificuldade){
	Sudoku *novoJogo = malloc(sizeof(Sudoku));
	novoJogo->jogador = malloc(9*sizeof(int*));
	novoJogo->resposta = malloc(sizeof(int*)*9);
	novoJogo->	erros = 0;
	novoJogo->		dificuldade = dificuldade;
	novoJogo->	pontos = 0;
	int i,j;
	for( i= 0 ; i < 9 ; i++){
		*(novoJogo->jogador + i) = malloc(sizeof(int)*9);
		*(novoJogo->resposta+ i) = malloc(sizeof(int)*9);
		for(j=0;j<9;j++){
			novoJogo->jogador[i][j] =0;
			novoJogo->resposta[i][j] = 0;
		}
	}
	if(!(*jogo)){
		*jogo = novoJogo;
		return 0;
	}
	resetar(jogo);
	*jogo = novoJogo;
	return 1;
}

int resetar(Sudoku **jogo){
	if(!(*jogo))return -1;
	int i ;
	for(i=0;i<9;i++){
	free((*jogo)->jogador[i]);
	free((*jogo)->resposta[i]);	
	}
	free((*jogo)->jogador);
	free((*jogo)->resposta);
	free(*jogo);
	*jogo = NULL;
	return 0;
}

int randomizar(Sudoku **jogo){
	srand(time(NULL));
	int **tabuleiro = (*jogo)->resposta;
	int i,j;
	for(i = 0 ; i < 9;i ++){
		for(j=0;j<9;j++){
			if(i/3 == j/3){
				do{
					tabuleiro[i][j] = rand()%9 + 1;
				}while(verificarPosicao(tabuleiro,i,j,tabuleiro[i][j]));
			}
		}
	}
	resolver(tabuleiro);
	return 0;
}

int resolver(int **tabuleiro){
	int i,j,num;
	for(i = 0;i<9;i++){
		for(j=0;j<9;j++){
			if(!tabuleiro[i][j]){
				for(num = 1 ; num <10;num++){
					if(!verificarPosicao(tabuleiro,i,j,num)){
						tabuleiro[i][j] = num;
						if(resolver(tabuleiro)){
							return 1;
						}else{
							tabuleiro[i][j] = 0;
						}
					}
				}
				return 0;
			}
		}
	}
	return 1;
}

int verificarPosicao(int **tabuleiro, int i,int j,int num){
	int valor = num;
	int k;
	for(k = 0;k<9;k++){
		if((valor == tabuleiro[i][k] && k != j) || (valor == tabuleiro[k][j] && i != k) )return -1;	
	}
	int linha,coluna;
	for(linha = 0;linha<9 ; linha++){
		for(coluna = 0;coluna<9;coluna++){
			if( i/3 == linha/3 && j /3 ==  coluna/3 && valor == tabuleiro[linha][coluna] && (i!=linha && j != coluna ) ) return -1;
		}
	}
	return 0;	
}

int verificarTabuleiro(int *tabuleiro){
	
}

int revelarJogador(Sudoku **jogo){
	int revelar;
	switch((*jogo)->dificuldade){
		case 1:
			revelar = 50;
			break;
		case 2:
			revelar = 30;
			break;
		case 3:
			revelar = 20;
			break;
		case 4:
			revelar = 10;
			break;
	}
	revelacao(jogo,revelar);
	return 0;
}

int revelacao(Sudoku **jogo, int revelar){
	srand(time(NULL));
	int i,j;
	while(revelar>0){
		do{
			i = rand() %9;
			j = rand() %9;
		}while((*jogo)->jogador[i][j] == (*jogo)->resposta[i][j] );
		(*jogo)->jogador[i][j] = (*jogo)->resposta[i][j];
		revelar--;
	}
	return 0;
}

int mostrar(int **tabuleiro){
	if(!tabuleiro)return -1;
	printf("\n\n");
	int i,j;
	
	for(i = 0;i<10;i++){
		printf(" %d ", i);
		if((i)%3 == 0 || i == 0){
			printf("|");
		}
	}
	printf("\n");
	for(i = 0;i<10;i++){
		printf("---");
		if((i)%3 == 0){
			printf("+");
		}
	}
	printf("\n");
	for(i=0;i<9;i++){
		for(j=-1;j<9;j++){
			j>=0? printf(" %d ",tabuleiro[i][j]): printf(" %d |", i+1);
			if((j+1)%3 == 0 &&j != 0 && j != -1){
				printf("|");
			}
		}
		
		if( (i+1)%3 == 0 &&i != 0){
			printf("\n");
			for(j = 0;j<10;j++){
				printf("---");
				if((j)%3 == 0){
					printf("+");
				}
			}
			
			
		}
		
		printf("\n");
	}
	printf("\n");
	return 0;
}

int addUser(User **usuario, char nome[255]){
	User *novoUser = malloc(sizeof(User));
	strcpy(novoUser->nome, nome);
	novoUser->pontuacaoMax = 0;
	if(!(*usuario)){
		*usuario = novoUser;
		return 0;
	}
	removerUsuario(usuario);
	*usuario = novoUser;
	return 1;
}

int removerUsuario(User **usuario){
	free(*usuario);
	*usuario = NULL;
	return 0;
}

int jogada(Sudoku **jogo,int linha,int coluna, int numero){
	if((*jogo)->resposta[linha][coluna] != numero){
		(*jogo)->erros++;
		return 0;
	}
	(*jogo)->jogador[linha][coluna] = numero;
	return 1;
}

int jogoAcabar(Sudoku **jogo){
	int i,j;
	for(i = 0 ; i < 9 ; i ++){
		for(j=0;j<9;j++){
			if((*jogo)->jogador[i][j] != (*jogo)->resposta[i][j])return -1;
		}
	}
	return 0;
}


int main(void){
	Sudoku *jogo;
	User *usuario;
	init(&jogo,&usuario);
	char nome[255];
	int dificuldade,continuar,numero,linha,coluna;
	do{
		printf("Digite seu nome: ");
		fgets(nome,255,stdin);
		nome[strlen(nome) - 1] = '\0';
		addUser(&usuario,nome);
		printf("Seu nome eh %s, esta correto? \n 1-SIM\n 0-NAO\nDigite o numero da resposta: ", usuario->nome);
		scanf("%d",&continuar);
	}while(continuar != 1);
	printf("\n\n");
	do{
		printf("\nBEM VINDO AO SUDOKU GAMEPLAYS");
		do{
			printf("\n ESCOLHA SUA DIFICULDADE:\n 1-FACIL\n 2-MEDIO\n 3-DIFICIL\n 4-INSANO\nDIGITE O NUMERO DA SUA ESCOLHA: ");
			scanf("%d", &dificuldade);
		
		}while(dificuldade>4 && dificuldade<1);
		iniciar(&jogo,dificuldade);
		randomizar(&jogo);
		revelarJogador(&jogo);
		do{
			
			mostrar(jogo->jogador);
			printf("\nERROS: %d\nDIGITE SUA JOGADA:",jogo->erros);
			do{
				printf("\n DIGITE A LINHA:");
				scanf("%d",&linha);
				printf(" DIGITE A COLUNA:");
				scanf("%d",&coluna);
				printf(" DIGITE O NUMERO:");
				scanf("%d",&numero);
			}while(numero< 0 || numero>9 || linha < 0 || linha > 9 || coluna < 0|| coluna > 9 );
			if(!jogada(&jogo,linha - 1,coluna - 1 ,numero)){
				printf("\nVOCE ERROU!");
				jogo->pontos -= 50;
			}else{
				jogo->pontos+= 100;
			} 
		}while(jogoAcabar(&jogo));
		if(jogo->pontos > usuario->	pontuacaoMax){
			usuario->	pontuacaoMax = jogo->pontos;
		}
		printf("\nParabens %s, Voce conseguiu %d PONTOS.\n ERROS: %d\n DIFICULDADE: %d\n SUA PONTUACAO MAX: %d\nDESEJA TENTAR NOVAMENTE?\n 1-SIM\n 0-NAO\nDIGITE O NUMERO DA SUA ESCOLHA: ",
		usuario->nome,jogo->pontos,jogo->erros,jogo->dificuldade,usuario->pontuacaoMax);
		scanf("%d",continuar);
		resetar(&jogo);
	}while(continuar);
	
	
	removerUsuario(&usuario);
	resetar(&jogo);
	return 0;
}