#include <stdio.h>

int main(void){
  float r1,r2,R;
  do{
    printf("Digite o valor de r1: ");
    scanf("%f", &r1);
    if(r1==0)break;
    printf("Digite o valor de r2: ");
    scanf("%f", &r2);
    if(r2==0)break;
    R = (r1*r2)/(r1+r2);
    printf("R = %.1f\n",R);
  }while(R != 0);
  
  
  return 0;
}