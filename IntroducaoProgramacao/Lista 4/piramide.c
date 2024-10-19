#include <stdio.h>

int main(void){
  int l,c,s,k,linhas;
  linhas = 7;
  k=linhas*2;
  for(l=0;l<=linhas;l++){
      for(c=0;c<=2*l;c++){
          while(s<k){
            printf(" ");
            s++;
          } 
          printf("X");
      }
      printf("\n");
    k--;
    s=0;
  }
  return 0;
}