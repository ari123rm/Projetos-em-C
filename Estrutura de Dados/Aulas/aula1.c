#include <stdio.h>

void soma(int *n1,int *n2){
	*n1 = *n1 + *n2;
}

int main(void){
	int n2 = 2;
	int *n1 = &n2;
	//soma(&n1,&n2);
	printf("%p",n1);
	return 0;
}

