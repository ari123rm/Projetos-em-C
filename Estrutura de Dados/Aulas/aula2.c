#include <stdio.h>
#include <stdlib.h>
void alloc(int **v){
	*v = malloc(3*sizeof(int));
	*(*v+0) = 1;
	*(*v+1) = 2;
	*(*v+2) = 3;
}
int main(void){
	int *vet; 
	int i;
	alloc(&vet);
	for(i = 0 ; i <3 ; i++){
		printf("%d ", *(vet + i));
	}
	return 0;
}
