#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>


void organizadorCrescente(int n[], int k){
    int i,j,aux;
    for(i=0; i < k ; i++){
        for(j=i+1 ; j < k ; j++ ){
            if(n[i] > n[j]){
                aux = n[i];
                n[i] = n[j];
                n[j] = aux;
            }
        }
    }
}

int dadosDnD(int n,int k){
	char v;
	if(k == 20){
		printf("Sua jogada é com vantagem ou desvantagem?\n Digite V para vantagem\n Digite D para desvantagem\n Digite N para rolagem normal\nDigite aqui: ");
		scanf("%s", &v);
		switch(v){
			case 'V':
				printf("\nJogada em vantagem\n");

				n++;
				break;
			case 'D':
				printf("\nJogada em desvantagem\n");
				n--;
				if(n == 0){
                    n = 2;
				}
				break;
			case 'N':
				printf("\nJogada normal\n");
				break;
            default:
                printf("\nJogada invalida\n");
                printf("Vamos assumir que a jogada é normal então\n\n");
                break;
		}

	}else{
		v = 'N';
	}

    int soma,i,j,jogadas[n],retorno;

    for(i=0;i< n ;i++){
        jogadas[i] = (rand() % k)+1;
    }

    organizadorCrescente(jogadas , n);

    printf("O dado deu os seguintes valores: ");
    for(i = 0; i < n ; i++){
        printf("[%d]", jogadas[i]);
    }
    printf("\n");



    soma = 0;
    if(k != 20){
       for(i = 0 ; i < n ; i++){
        soma = soma + jogadas[i];
       }
       retorno = soma;
    }else{
        switch(v){
			case 'V':
				retorno = jogadas[n-1];
				break;
			case 'D':
				retorno = jogadas[0];
				break;
			default:
				retorno = jogadas[n-1];
				break;
		}
    }
    return retorno;
}

int dadosOP(int n, int k){
  char v;
  int D;
	if(k == 20){
		printf("Sua jogada é com vantagem ou desvantagem?\n Digite V para vantagem\n Digite D para desvantagem\n Digite N para rolagem normal\nDigite aqui: ");
		scanf("%s", &v);
		switch(v){
			case 'V':
				printf("\nJogada em vantagem\n");
				printf("Vantagem de quantos dados: ");
				scanf("%d", &D);
				n = n + D;
				break;
			case 'D':
				printf("\nJogada em desvantagem\n");
				printf("Desvantagem de quantos dados: ");
				scanf("%d", &D);
				n = n - D;
				if(n <= 0){
                    n = 2;
                    D = 1;
				}
				break;
			case 'N':
				printf("\nJogada normal\n");
				break;
            default:
                printf("\nJogada invalida\n");
                printf("Vamos assumir que a jogada é normal então\n\n");
                break;
		}

	}else{
		v = 'N';
	}

    int soma,i,j,jogadas[n],retorno;

    for(i=0;i< n ;i++){
        jogadas[i] = (rand() % k)+1;
    }

    organizadorCrescente(jogadas , n);

    printf("O dado deu os seguintes valores: ");
    for(i = 0; i < n ; i++){
        printf("[%d]", jogadas[i]);
    }
    printf("\n");

    soma = 0;

    if(k != 20){
       for(i = 0 ; i < n ; i++){
        soma = soma + jogadas[i];
       }
       retorno = soma;
    }else{
        switch(v){
			case 'V':
				retorno = jogadas[n-1];
				break;
			case 'D':
				retorno = jogadas[n-(D+1)];
				break;
			default:
				retorno = jogadas[n-1];
				break;
        }
    }
    return retorno;
}


int dadosCoC(int n, int k){
  char v;
	if(k == 100){
		printf("Sua jogada é com vantagem ou desvantagem?\n Digite V para vantagem\n Digite D para desvantagem\n Digite N para rolagem normal\nDigite aqui: ");
		scanf("%s", &v);
		switch(v){
			case 'V':
				printf("\nJogada em vantagem\n");
				n++;
				break;
			case 'D':
				printf("\nJogada em desvantagem\n");
				n--;
				if(n == 0){
                    n = 2;
				}
				break;
			case 'N':
				printf("\nJogada normal\n");
				break;
            default:
                printf("\nJogada invalida\n");
                printf("Vamos assumir que a jogada é normal então\n\n");
                break;
		}

	}else{
		v = 'N';
	}

    int soma,i,j,jogadas[n],retorno;

    if(k == 100){
        int d10a,d10b,d100;
        for(i=0;i< n ;i++){
            d10a = rand() % 10;
            d10b = rand() % 10;
            d100 = d10a*10 + d10b;
            if(d100==00)d100=100;
            jogadas[i] = d100;
        }
    }else{
        for(i=0;i< n ;i++){
            jogadas[i] = (rand() % k)+1;
        }
    }

    organizadorCrescente(jogadas , n);

    printf("O dado deu os seguintes valores: ");
    for(i = 0; i < n ; i++){
        printf("[%d]", jogadas[i]);
    }
    printf("\n");

    soma = 0;
    if(k != 100){
       for(i = 0 ; i < n ; i++){
        soma = soma + jogadas[i];
       }
       retorno = soma;
    }else{
        switch(v){
			case 'V':
				retorno = jogadas[0];
				break;
			case 'D':
				retorno = jogadas[n-1];
				break;
			default:
				retorno = jogadas[0];
				break;
		}
    }
    return retorno;
}
int rolagem(int n, int r,char P){
    int dado;
    switch(P){
        case 'D':
            dado = dadosDnD(n,r);
            break;
        case 'O':
            dado = dadosOP(n,r);
            break;
        case 'C':
            dado = dadosCoC(n,r);
            break;
    }
    return dado;

}

int main(void){
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));
    int qntdDados, tpDados;
    char d ,s ;
do{


    printf("Digite o sistema que você deseja em letra maiúscula\n\n ORDEM PARANORMAL digite O\n D&D digite D\n CALL OF CTHULHU digite C\n\nDigite aqui: ");
    scanf("%s", &d);

    switch(d){
    case 'O':printf("Escolhido foi Ordem paranormal");break;
    case 'D':printf("Escolhido foi D&D");break;
    case 'C':printf("Escolhido foi Call of Cthulhu");break;
    default:
        printf("JOGADA INVALIDA!\n");
        goto fim;
    }

    printf("\n\n");
    printf("Digite quantos dados deseja rodar: ");
    scanf("%d", &qntdDados);
    printf("Que tipo de dados deseja rolar?\n\n digite apenas a quantidade de lados que ele possui\n\nDigite aqui: ");
    scanf("%d", &tpDados);

    printf("\nO dado deu: %d", rolagem(qntdDados,tpDados,d));
    printf("\n\n");

fim:
    s = 'S';
    printf("Deseja fazer outra rolagem:\n S para sim \n N para n�o\nDigite sua resposta: ");
    scanf("%s", &s);
    switch(s){
        case 'N': printf("\nFim das rolagens\n");break;
        case 'S': printf("\nVamos fazer mais uma rolagem\n\n");break;
    }
    system("cls");
}while(s == 'S');
return 0;
}