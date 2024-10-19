#include <stdio.h>

float calculadora(float a, float b, char op){
  switch(op){
    case '+':
      return a+b;
      break;
    case '-':
      return a-b;
      break;
    case '*':
    case 'x':
      return a*b;
      break;
    case '/':
      return a/b;
      break;
  }
  return 0;
}
int main(void) {
  printf("Calculadora fodinha\n");
  printf("Digite seu calculo: ");
  float a, b;
  char op;
  scanf("%f %c %f", &a, &op, &b);
  printf("Resultado: %.2f", calculadora(a, b, op));
  return 0;
}