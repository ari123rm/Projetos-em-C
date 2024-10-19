#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void CPFaleatorio(void){
    int aleat[11],j=10,i,soma=0;

                for(i=0;i<9;i++){
					aleat[i]= rand() % 10;
				}
					
				for(i=0;i<9;i++){
					soma += aleat[i] * j;
					j--;
				}
				
				soma = soma % 11;
				if(soma < 2){
					aleat[9] = 0;
				}else{
					aleat[9] = 11 - soma;
				}
				soma = 0;
				j = 11;
				for(i=0;i<10;i++){
					soma += aleat[i] * j;
					j--;
				}
				soma = soma % 11;
				if(soma < 2){
					aleat[10] = 0;
				}else{
					aleat[10] = 11 - soma;
				}
				printf("\nSeu CPF aleatorio: ");
				for(i=0;i<11;i++){
					printf("%d",aleat[i]);
					if(i==2 || i == 5){
						printf(".");
					}
		if(i == 8){
			printf("-");
		}
	}
	printf("\n\n");

}

void CNPJaleatorio(void){
	int aleat[14],j=5,i,soma=0,ver = 0;
	 for(i=0;i<12;i++){
					aleat[i]= rand() % 10;
				}
				
				for(i=0;i<12;i++){
					soma += aleat[i] * j;
					if(j == 2 && ver == 0){
						j = 10;
						ver = 1;
					}
					j--;
				}
				
				soma = soma % 11;
				if(soma < 2){
					aleat[12] = 0;
				}else{
					aleat[12] = 11 - soma;
				}
				soma = ver = 0;
				j = 6;
				for(i=0;i<13;i++){
					soma += aleat[i] * j;
					if(j == 2 && ver == 0){
						j = 10;
						ver = 1;
					}
					j--;
				}
				soma = soma % 11;
				if(soma < 2){
					aleat[13] = 0;
				}else{
					aleat[13] = 11 - soma;
				}
				printf("\nSeu CNPJ aleatorio: ");
				for(i=0;i<14;i++){
					printf("%d",aleat[i]);
					if(i==1 || i == 4){
						printf(".");
					}
					if(i == 7){
			printf("/");
		}
		if(i == 11){
			printf("-");
		}
	}
	printf("\n\n");
}

void verificar(void){
	char numero[20];
	int valor[14],j=0,i,soma=0,ver = 0;
	printf("Digite seu CPF/CNPJ: ");
	fflush(stdin);
  scanf("%s", numero);
	//fgets(numero,20,stdin);
	//numero[strlen(numero)-1] = '\0';
	for(i=0;i<20;i++){
		if(numero[i]!='.'&&numero[i]!='/'&&numero[i]!='-'&&numero[i]!='\0'){
			valor[j] = numero[i] - '0';
			j++;
			
		}	
	}
	if(strlen(numero)==14){
		int v[2];
		j = 10;
		soma = 0;
				for(i=0;i<9;i++){
					soma += valor[i] * j;
					j--;
				}
				
				soma = soma % 11;
				if(soma < 2){
					v[0] = 0;
				}else{
					v[0] = 11 - soma;
				}
				soma = 0;
				j = 11;
				for(i=0;i<10;i++){
					soma += valor[i] * j;
					j--;
				}
				soma = soma % 11;
				if(soma < 2){
					v[1] = 0;
				}else{
					v[1] = 11 - soma;
				}
			if(valor[9] == v[0]&&valor[10] == v[1] ){
			printf("\nCPF VALIDO\n\n");
		}else{
			printf("\nCPF INVALIDO\n\n");
		}
		
		
	}else if(strlen(numero)==18){
		
		soma = ver = 0;
		j=5;
		int v[2];
			for(i=0;i<12;i++){
					soma += valor[i] * j;
					
					if(j == 2 && ver == 0){
						j = 10;
						ver = 1;
					}
					j--;
				}
				
				soma = soma % 11;
				if(soma < 2){
					v[0] = 0;
				}else{
					v[0] = 11 - soma;
				}
				soma = ver = 0;
				j = 6;
				for(i=0;i<13;i++){
					soma += valor[i] * j;
				
						if(j == 2 && ver == 0){
						j = 10;
						ver = 1;
					}
					j--;
				}
				soma = soma % 11;
				if(soma < 2){
					v[1] = 0;
				}else{
					v[1] = 11 - soma;
				}
		if(valor[12] == v[0]&&valor[13] == v[1] ){
			printf("\nCNPJ VALIDO\n\n");
		}else{
			printf("\nCNPJ INVALIDO\n\n");
		}
	}
}

int main(void){
	int opcao;
	srand(time(NULL));
	do{
		printf("Gerador de CPF/CNPJ\n\nDigite 1 para verificar CPF/CNPJ\nDigite 2 para gerar um CPF valido\nDigite 3 para gerar um CNPJ valido\nDigite 0 para sair do programa\n\nDigite sua opcao: ");
		scanf("%d", &opcao);
		switch(opcao){
			case 1:
				verificar();
				break;
			case 2:
				CPFaleatorio();
				break;
			case 3:
				CNPJaleatorio();
				break;
			case 0:
				printf("\nFim do programa\n\n");
				break;
			default:
				printf("\nOpcao invalida, tente novamente\n\n");
				break;
		}
	}while(opcao != 0);
	return 0;
}