
int main(void) {
  int i,numero,soma=0;
  printf("Digite o numero : ");
  scanf("%d", &numero);
  for(i=0;i<=numero;i++){
    soma = soma + i;
  }
     printf("O somatorio deu %d", soma);
  
 
  return 0;
}