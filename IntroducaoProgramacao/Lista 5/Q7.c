#include <stdio.h>

int main(void){
  int i,j;
  char verificador;
  
  for(i=1;i<100;i++){
    //P de primo
    verificador = 'P';
    for(j=2;j<i;j++){
      if(i%j == 0){
      //N de normal
        verificador = 'N';
      }
    }
    if(verificador == 'P'){
      printf("%d\n",i);
    }
  }
  
  return 0;
}